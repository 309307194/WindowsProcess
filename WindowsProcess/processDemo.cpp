///mark:1-19(第四天)windows进程控制-控制台进程

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
	WCHAR commandline[] = L"cmd";
	
	ret = CreateProcess(NULL, commandline, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
	if (ret)
	{
		CloseHandle(pi.hThread);
		CloseHandle(pi.hProcess);
		printf("%d\n", pi.dwThreadId);
		printf("%d\n", pi.dwProcessId);
	}
	else
	{
		printf("启动失败\n");
	}
	return 0;
}