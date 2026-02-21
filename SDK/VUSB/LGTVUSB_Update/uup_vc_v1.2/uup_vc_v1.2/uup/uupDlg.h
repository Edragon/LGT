
// uupDlg.h : header file
//

#pragma once

#include "lusb0_usb.h"
#include "afxcmn.h"
#include "afxwin.h"
#include "lgtglobal.h"

#define		LGTUSB_PID	0x15dc
#define		LGTUSB_VID	0x17c0

#define WM_ISP_PROGRESS	WM_USER + 1
#define WM_USB_ADDDEVICE WM_USER + 2
#define WM_USB_DELDEVICE WM_USER + 3

#define IDC_PROGRESSCTRL WM_USER + 100

// CuupDlg dialog
class CuupDlg : public CDialogEx
{
// Construction
public:
	CuupDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_UUP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT OnIspProgress(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnAddUsbDevice(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnDelUsbDevice(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedUpdate();
	afx_msg void OnBnClickedOpen();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();

private:
	int errDevCount;
	CProgressCtrl *pProgressBar;

	uupDevMap_t usbDevInfo;
	std::vector<CString> usbISP;

	bool usbDevSync(usb_dev_handle *dev);
	bool usbReadChipGUID(usb_dev_handle *dev, DWORD &dwChipGUID);

public:
	uupByteArray_t fmData;

	CListCtrl m_devListCtrl;
	CEdit m_fmPathCtrl;
	CButton m_btnUpdateCtrl;
	CButton m_btnOpenFile;
	CComboBox m_cboChip;
	CStatic m_stxChip;
};
