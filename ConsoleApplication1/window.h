#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.22621.436' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#ifndef UNICODE
#define UNICODE
#endif 

#define CALC_BUTTON 1


#include <windows.h>
#include <iostream>
#include "romberg.h"
#include "input.h"


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

class Window {
public:
	Window();
	bool processMessages();
private:
	const wchar_t* CLASS_NAME = L"Metode Romberg";
	HINSTANCE m_hInstance;
	HWND m_hwnd;
	HWND m_editBox;
	HWND m_button;
	HWND m_startX;
	HWND m_endX;
	HWND m_result;
};



