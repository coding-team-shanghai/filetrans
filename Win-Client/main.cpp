#include <windows.h>
#include <bits/stdc++.h>
#include <io.h>
#include "main.h"
using namespace std;

BOOL DoFileSave(HWND hwnd, char szFileName[MAX_PATH*10]) {
	OPENFILENAME ofn;

	ZeroMemory(&ofn, sizeof(ofn));
	szFileName[0] = 0;

	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = hwnd;
	ofn.lpstrFilter = "All Files(*.*)\0*.*\0\0";
	ofn.lpstrFile = szFileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrDefExt = "";
	ofn.lpstrTitle = (char*)"ѡ�񱣴�λ�� - Filetrans Windows Client (Receiver) V1.0";

	ofn.Flags = OFN_EXPLORER|OFN_PATHMUSTEXIST|OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT;
	if(GetSaveFileName(&ofn)) {
		return FALSE;
	}
	return TRUE;
}

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	//oM1aJ4dA4bP0bC1jN1qC2iU2dN2jE3
	if (_access("C:\\.filetrans\\FILE", F_OK) == -1) {
		MessageBox(NULL, "  Fatal: File not found: C:\\.filetrans\\FILE\n  If you started this program yourself, please remember \n    Not opening it by yourself.\n  Else: please connact us to debug: eric_ni2008@163.com.", "Filetrans Windows Client (Receiver) V1.0", MB_OK|MB_ICONHAND);
		return 0;
	}
	retrysave:
	int tocheck = MessageBox(NULL, "  ���û��������������ļ���\n  ����ǰ�Ƿ���Ҫ�鿴�йظ��ļ�����Ϣ���Ƽ��������û����ⷢ�ͣ���","Filetrans Windows Client (Receiver) V1.0",MB_YESNO|MB_ICONWARNING|MB_DEFBUTTON1|MB_TOPMOST);
	if (tocheck != IDNO) {
		ShellExecute(NULL, TEXT("open"), TEXT("C:\\.filetrans\\win-accept.ini"), TEXT(""),TEXT(""), SW_SHOWNORMAL);
		if (MessageBox(NULL, "  ���Ƿ�Ҫ���ܸ��ļ���", "Filetrans Windows Client (Receiver) V1.0", MB_YESNO | MB_ICONQUESTION|MB_TOPMOST|MB_DEFBUTTON3) != IDYES) {
			MessageBox(NULL, "  File Acception terminated.\n  ���ǽ�Ϊ��������յ�����ʱ�ļ����������ں�̨��ɡ�", "Filetrans Windows Client (Receiver) V1.0", MB_ICONINFORMATION|MB_TOPMOST);
			remove("C:\\.filetrans\\FILE");
			return 0;
		}
	}
	char savefilepath[MAX_PATH*10];
	DoFileSave(NULL, savefilepath);
	/*
	if ((strcmp(savefilepath, NULL)==0) || (strcmp(savefilepath, "")==0) || (strcmp(savefilepath, "\0")==0)) {
		if (MessageBox(NULL, "  ����ʧ�ܡ��Ƿ����ԣ�           ", "Filetrans Windows Client (Receiver) V1.0", MB_YESNO|MB_TOPMOST) == IDNO) {
			MessageBox(NULL, "  File Acception terminated.\n  ���ǽ�Ϊ��������յ�����ʱ�ļ����������ں�̨��ɡ�", "Filetrans Windows Client (Receiver) V1.0", MB_ICONINFORMATION|MB_TOPMOST);
			remove("C:\\.filetrans\\FILE");
			return 0;
		} else {
			goto retrysave;
		}
	}
	*/
	if (MessageBox(NULL, savefilepath, "ȷ�ϱ�����", MB_OKCANCEL | MB_ICONQUESTION | MB_DEFBUTTON1 | MB_TOPMOST) == IDCANCEL) {
		MessageBox(NULL, "  File Acception terminated.\n  ���ǽ�Ϊ��������յ�����ʱ�ļ����������ں�̨��ɡ�", "Filetrans Windows Client (Receiver) V1.0", MB_ICONINFORMATION|MB_TOPMOST);
		remove("C:\\.filetrans\\FILE");
		return 0;
	}
	CopyFile("C:\\.filetrans\\FILE", savefilepath, 0);
	MessageBox(NULL, "  �ļ�������ɣ�                          ", "Filetrans Windows Client (Receiver) V1.0", MB_ICONINFORMATION | MB_OK | MB_TOPMOST);
	remove("C:\\.filetrans\\FILE");
	return 0;
}
