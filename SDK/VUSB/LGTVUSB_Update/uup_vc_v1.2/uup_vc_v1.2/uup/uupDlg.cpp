
// uupDlg.cpp : implementation file
//

#include "stdafx.h"
#include "uup.h"
#include "uupDlg.h"
#include "uupDev.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// working task to do firmware programming
UINT __cdecl BackThreadProc(LPVOID pParam)
{
	int addr = 0;
	uupByteArray_t seg, rseg;

	lgt::PLGTPARAM pTmp = (lgt::PLGTPARAM)pParam;
	int pid = pTmp->pid;
	struct usb_device *dev = pTmp->dev;
	CuupDlg *pDlg = (CuupDlg *)(pTmp->pParam);
	lgt::PLGTChipConfig chip = pTmp->chip;

	CuupDev *uupDev = new CuupDev(false, chip->bsize, chip->psize);
	if(uupDev->open(dev)) {
		int length = pDlg->fmData.size();

		// program page aligned data
		while(length >= chip->psize) {
			// 1. erase target page
			uupDev->ispEraseFlashPage(addr + 0xc00);
			Sleep(50);
			seg = lgt::vector_mid(pDlg->fmData, addr, chip->psize);
			// 2. program page
			uupDev->ispWriteFlashPage(seg, addr+0xc00);
			Sleep(10);

			// 3. data verify
			uupDev->ispReadFLASHPage(rseg, addr+0xc00, chip->psize);
			if(!lgt::vector_compare(seg, rseg)) {
				pDlg->PostMessage(WM_ISP_PROGRESS, pid, -1);
				return -1;
			} else {
				addr += chip->psize;
				length -= chip->psize;
				pDlg->PostMessage(WM_ISP_PROGRESS, pid, chip->psize);
				Sleep(10);
			}
		}

		// program remaining data
		if (length > 0) {
			uupDev->ispEraseFlashPage(addr + 0xc00);
			Sleep(50);
			seg = lgt::vector_mid(pDlg->fmData, addr, length);
			uupDev->ispWriteFlashPage(seg, addr+0xc00);
			pDlg->PostMessage(WM_ISP_PROGRESS, pid, length);
			Sleep(10);

			uupDev->ispReadFLASHPage(rseg, addr+0xc00, length);
			if(!lgt::vector_compare(seg, rseg)) {
				pDlg->PostMessage(WM_ISP_PROGRESS, pid, -1);
				return -1;
			} else {
				pDlg->PostMessage(WM_ISP_PROGRESS, pid, length);
				Sleep(10);
			}
		}

		uupDev->close();
	}

	if(pTmp) {
		delete pTmp;
	}

	return 0;
}

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CuupDlg dialog
CuupDlg::CuupDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CuupDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CuupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DEVLIST, m_devListCtrl);
	DDX_Control(pDX, IDC_FMPATH, m_fmPathCtrl);
	DDX_Control(pDX, IDC_UPDATE, m_btnUpdateCtrl);
	DDX_Control(pDX, IDC_OPEN, m_btnOpenFile);
	DDX_Control(pDX, IDC_COMBO1, m_cboChip);
	DDX_Control(pDX, IDC_STATIC1, m_stxChip);
}

BEGIN_MESSAGE_MAP(CuupDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_UPDATE, &CuupDlg::OnBnClickedUpdate)
	ON_BN_CLICKED(IDC_OPEN, &CuupDlg::OnBnClickedOpen)
	ON_WM_DESTROY()
	ON_MESSAGE(WM_ISP_PROGRESS, OnIspProgress)
	ON_MESSAGE(WM_USB_ADDDEVICE, OnAddUsbDevice)
	ON_MESSAGE(WM_USB_DELDEVICE, OnDelUsbDevice)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CuupDlg message handlers

BOOL CuupDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	usb_init();

	m_devListCtrl.InsertColumn(0, _T("No."), LVCFMT_LEFT, 40);
	m_devListCtrl.InsertColumn(1, _T("Device Name"), LVCFMT_LEFT, 240);
	m_devListCtrl.InsertColumn(2, _T("Firmware Version"), LVCFMT_LEFT, 100);

	CRect rt, rt0;
	m_btnOpenFile.GetWindowRect(&rt0);
	ScreenToClient(&rt0);
	rt.top = rt0.top;
	rt.left = rt0.left;
	m_fmPathCtrl.GetWindowRect(&rt0);
	ScreenToClient(&rt0);
	rt.bottom = rt0.bottom;
	rt.right = rt0.right;

	pProgressBar = new CProgressCtrl();
	pProgressBar->Create(NULL, rt, this, IDC_PROGRESSCTRL);
	pProgressBar->ShowWindow(SW_HIDE);
	pProgressBar->SetRange(0, 100);
	pProgressBar->SetStep(1);

	m_cboChip.AddString(CString("LGT8F08A"));
	m_cboChip.AddString(CString("LGT8F88A"));
	m_cboChip.AddString(CString("LGT8FX8D"));
	m_cboChip.SetCurSel(0);

	SetTimer(100, 100, NULL);
	m_btnOpenFile.EnableWindow(false);
	m_btnUpdateCtrl.EnableWindow(false);
	m_fmPathCtrl.EnableWindow(false);
	m_cboChip.EnableWindow(false);
	m_stxChip.EnableWindow(false);

	lgt::lgt_chipmap_init();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CuupDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CuupDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CuupDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CuupDlg::OnBnClickedUpdate()
{
	CString chipName;

	// TODO: Add your control notification handler code here
	if(fmData.size() == 0)
		return;

	// update chip settings 
	int index = m_cboChip.GetCurSel();
	m_cboChip.GetLBText(index, chipName);

	if(chipName.IsEmpty())
		return;

	lgt::PLGTChipConfig chip = &lgt::lgt_chipmap[chipName];

	m_btnUpdateCtrl.EnableWindow(false);

	KillTimer(100);

	m_btnOpenFile.ShowWindow(SW_HIDE);
	m_fmPathCtrl.ShowWindow(SW_HIDE);

	errDevCount = 0;

	// initial libusb bus device
	CuupDev *uupdev = new CuupDev(true);
	int devCount = m_devListCtrl.GetItemCount();
	if(pProgressBar) {
		pProgressBar->SetStep(1);
		pProgressBar->SetPos(0);
		pProgressBar->SetRange32(0, fmData.size()*devCount);
		pProgressBar->ShowWindow(SW_SHOWNORMAL);
	}

	for(int i = 0; i < devCount; i++) {
		lgt::PLGTPARAM tsTmp = new lgt::LGTPARAM;
		tsTmp->pid = i;
		tsTmp->pParam = (LPVOID)this;
		tsTmp->chip = chip;

		CString devName = m_devListCtrl.GetItemText(i, 1);
		struct usb_device *udev = uupdev->devFromFileName(devName);
		tsTmp->dev = udev;
		CWinThread *ps = AfxBeginThread(BackThreadProc, (LPVOID)tsTmp);
	}
}

void CuupDlg::OnBnClickedOpen()
{
	// TODO: Add your control notification handler code here
	TCHAR szFilters[] = _T("Binary File (*.bin)|*.bin||");
	
	CFileDialog fileDlg(TRUE, _T("Firmware File"), _T("*.bin"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilters);

	if(fileDlg.DoModal() == IDOK)
	{
		fmData.clear();
		
		CString pathName = fileDlg.GetPathName();
		m_fmPathCtrl.SetWindowText(pathName);

		CFile file;
		if(file.Open(pathName, CFile::modeRead)) {
			DWORD dwRead;
			char buffer[512];

			do {
				dwRead = file.Read(buffer, 512);
				fmData.insert(fmData.end(), buffer, buffer+dwRead);
			} while (dwRead > 0);

			//if(fmData.size()%2 != 0)
			int rems = fmData.size()%4;
			for(int i = 0; i < rems; i++)
				fmData.push_back((BYTE)0xff);

			file.Close();
		}
	}
}

void CuupDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: Add your message handler code here
}

LRESULT CuupDlg::OnIspProgress(WPARAM wParam, LPARAM lParam)
{
	// TODO: Add your message handler code here
	int iParam = (int)lParam;
	int oldPos = pProgressBar->GetPos();
	int curPos = oldPos + iParam;

	if(iParam >= 0) {
		pProgressBar->SetPos(curPos);
	} else {
		// error handler
		CString err;
		err.Format(_T("Device (%d): Error!!"), (int)wParam);
		AfxMessageBox(err);
		errDevCount++;
	}

	if(curPos == fmData.size() * (m_devListCtrl.GetItemCount() - errDevCount)) {
		pProgressBar->ShowWindow(SW_HIDE);
		m_btnOpenFile.ShowWindow(SW_SHOWNORMAL);
		m_fmPathCtrl.ShowWindow(SW_SHOWNORMAL);	
		m_btnUpdateCtrl.EnableWindow(true);
		SetTimer(100, 100, NULL);
	}

	return 0;
}


void CuupDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	struct usb_bus *busIt;
	struct usb_device *devIt;

	CString key;
	CString strDev;
	CString strChip;
	DWORD dwChipGUID;

	usb_find_busses();
	usb_find_devices();

	usbDevInfo.clear();
	for(busIt = usb_get_busses(); busIt; busIt = busIt->next) {
		for( devIt = busIt->devices; devIt; devIt = devIt->next) {
			WORD vid = devIt->descriptor.idVendor;
			WORD pid = devIt->descriptor.idProduct;
			
			if(vid == LGTUSB_VID && pid == LGTUSB_PID) {
				usbDevInfo[CString(devIt->filename)] = devIt;
			}
		}
	}

	// step 1: cleanup usb_isp device if it's unusable
	for (int i = 0; i < (int)usbISP.size(); i++) {
		key = usbISP[i];
		if(lgt::map_haskey(usbDevInfo, key))
			continue;
		SendMessage(WM_USB_DELDEVICE, 0, (LPARAM)&key);
		usbISP.erase(usbISP.begin() + i);
	}

	// step 2: add new usb_isp device
	uupDevMap_t::iterator  it;

	for(it = usbDevInfo.begin(); it != usbDevInfo.end(); it++) {
		key = (*it).first;
		if(lgt::vector_haskey(usbISP, key)) {
			// TODO : update chip infomation if necessary!
			continue;
		}

		usb_dev_handle *dev = usb_open((*it).second);
		if(!dev) {
			// TODO: error handle
		} else if(usbDevSync(dev)) {
			usbReadChipGUID(dev, dwChipGUID);
			usbISP.push_back(key);
			SendMessage(WM_USB_ADDDEVICE, dwChipGUID, (LPARAM)&key);

			usb_close(dev);
		}
	}

	CDialogEx::OnTimer(nIDEvent);
}

LRESULT CuupDlg::OnAddUsbDevice(WPARAM wParam, LPARAM lParam)
{
	TCHAR tTitle[3];
	CString temp;
	CString *pStr = (CString *)lParam;

	int i = m_devListCtrl.GetItemCount();
	temp.Format(_T("%d"), i);
	TCHAR *ptStr = pStr->GetBuffer(0);
	tTitle[0] = ptStr[14];
	tTitle[1] = ptStr[15];
	tTitle[2] = 0;
	m_devListCtrl.InsertItem(i, tTitle);

	m_devListCtrl.SetItemText(i, 1, pStr->GetBuffer(0));

	temp.Format(_T("%0x"), wParam);
	temp.MakeUpper();
	m_devListCtrl.SetItemText(i, 2, _T("0x")+temp);

	m_btnOpenFile.EnableWindow(true);
	m_btnUpdateCtrl.EnableWindow(true);
	m_fmPathCtrl.EnableWindow(true);
	m_cboChip.EnableWindow(true);
	m_stxChip.EnableWindow(true);

	return 0;
}

LRESULT CuupDlg::OnDelUsbDevice(WPARAM /* not used */, LPARAM lParam)
{
	CString *pStr = (CString *)lParam;

	for (int i = 0; i < m_devListCtrl.GetItemCount(); i++)
	{
		if(*pStr == m_devListCtrl.GetItemText(i, 1)) {
			m_devListCtrl.DeleteItem(i);
			break;
		}
	}

	if(0 == m_devListCtrl.GetItemCount()) {
		m_btnOpenFile.EnableWindow(false);
		m_btnUpdateCtrl.EnableWindow(false);
		m_fmPathCtrl.EnableWindow(false);
		m_cboChip.EnableWindow(false);
		m_stxChip.EnableWindow(false);
	}

	return 0;
}

bool CuupDlg::usbDevSync(usb_dev_handle *udev)
{
	char tmp[1];

	int retVal = usb_control_msg(udev, 0xc0, 0x02, 0, 0, tmp, 1, 5000);

	return retVal > 0 && tmp[0] == 'I';
}

bool CuupDlg::usbReadChipGUID(usb_dev_handle *udev, DWORD &dwChipGUID)
{
	char tmp[4];

	int retVal = usb_control_msg(udev, 0xc0, 0x06, 0, 0, tmp, 4, 5000);

	if(retVal > 0) {
		dwChipGUID = tmp[0] << 24;
		dwChipGUID |= tmp[1] << 16;
		dwChipGUID |= tmp[2] << 8;
		dwChipGUID |= tmp[3];
	}
	
	return retVal > 0;
}
