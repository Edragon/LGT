@echo off

:: ��ȡ��һ��hex��·�������ֵ�x_path

for /f "delims=" %%i in ('dir /s/b *.hex') do (
set x_path=%%~fi				
goto end
)
:end

xic2mic --mh -cm LGT8P653A -f %x_path%

:: xic2mic.exe���õ�ͬһ��·��
