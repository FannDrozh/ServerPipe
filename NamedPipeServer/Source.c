#define SIZE_BUFFER 140
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	system("chcp 1251");
	//������� 1
	/*HANDLE hNamedPipe;
	LPSTR lpszPipeName = L"\\\\.\\pipe\\MyPipe";
	DWORD size_buffer = SIZE_BUFFER;
	LPWSTR buffer = (CHAR*)calloc(size_buffer, sizeof(CHAR));
	char message[SIZE_BUFFER];
	BOOL Connected;
	DWORD actual_readen;
	BOOL SuccessRead;
	while (TRUE)
	{
		hNamedPipe = CreateNamedPipe(lpszPipeName, PIPE_ACCESS_DUPLEX, PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT, PIPE_UNLIMITED_INSTANCES, SIZE_BUFFER, SIZE_BUFFER, INFINITE, NULL);
		Connected = ConnectNamedPipe(hNamedPipe, NULL);
		if (Connected)
		{
			SuccessRead = ReadFile(hNamedPipe, buffer, size_buffer, &actual_readen, NULL);
			if (SuccessRead)
			{
				printf("\n������ �����: ");
				printf(buffer);
				printf("\n");
				printf("\n������� ��������� ��� ������: \n");
				gets(message);
				buffer = &message;
				WriteFile(hNamedPipe, buffer, size_buffer, &actual_readen, NULL);
			}
		}
		else
		{
			printf("\n������ ���������� �� �������\n");
		}
		CloseHandle(hNamedPipe);
	}*/
	//������� 2
	HANDLE hNamedPipe;
	LPSTR lpszPipeName = L"\\\\.\\pipe\\MyPipe";
	DWORD size_buffer = SIZE_BUFFER;
	LPWSTR buffer = (CHAR*)calloc(size_buffer, sizeof(CHAR));
	char message[SIZE_BUFFER];
	BOOL Connected;
	DWORD actual_readen;
	BOOL SuccessRead;
	while (TRUE)
	{
		hNamedPipe = CreateNamedPipe(lpszPipeName, PIPE_ACCESS_DUPLEX, PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT, PIPE_UNLIMITED_INSTANCES, SIZE_BUFFER, SIZE_BUFFER, INFINITE, NULL);
		Connected = ConnectNamedPipe(hNamedPipe, NULL);
		if (Connected)
		{
			SuccessRead = ReadFile(hNamedPipe, buffer, size_buffer, &actual_readen, NULL);
			if (SuccessRead)
			{
				printf("\n������ ��� �����: ");
				printf(buffer);
				if (scanf_s(buffer, '%s') != 1)
				{
					scanf_s("�� ����� �� ���������� ������", &message);
					buffer = &message;
					WriteFile(hNamedPipe, buffer, size_buffer, &actual_readen, NULL);
					CloseHandle(hNamedPipe);
				}
				else 
				{
					float num = atof(buffer);
					float pow = num * num;
					sprintf(message, "%f", pow);
					buffer = &message;
					printf("\n");
					WriteFile(hNamedPipe, buffer, size_buffer, &actual_readen, NULL);
				}				
			}
		}
		else
		{
			printf("\n������ ���������� �� �������\n");
		}
		CloseHandle(hNamedPipe);
	}
}