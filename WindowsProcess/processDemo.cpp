///mark:1-19(������)windows���̿���-����̨����

#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	int ret = 0;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = TRUE;
	ZeroMemory(&pi, sizeof(pi));
	//WCHAR commandline[] = L"cmd";
	//
	//ret = CreateProcess(NULL, commandline, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);

	//WCHAR commandline[] = L"c:/windows/notepad.exe 1.txt";
	//ret = CreateProcess(NULL, commandline, NULL, NULL, FALSE, NULL, NULL, NULL, &si, &pi);
	/*WCHAR commandline[] = L"c:/windows/notepad.exe";
	ret = CreateProcess(commandline, NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &si, &pi);*/

	WCHAR commandline1[] = L"c:/windows/notepad.exe";
	WCHAR commandline2[] = L"calc";
	ret = CreateProcess(commandline1, commandline2, NULL, NULL, FALSE, NULL, NULL, NULL, &si, &pi);


	if (ret)
	{
		CloseHandle(pi.hThread);
		CloseHandle(pi.hProcess);
		printf("%d\n", pi.dwThreadId);
		printf("%d\n", pi.dwProcessId);
	}
	else
	{
		printf("����ʧ��\n");
	}
	return 0;
}