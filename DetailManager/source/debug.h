#pragma once

#include <windows.h>

inline void show(const int number)
{
	wchar_t content[256];
	wsprintfW(content, L"%d", number);
	wchar_t title[20];
	mbstowcs(title, __func__, sizeof(__func__));//includes null
	MessageBox(NULL, content, title, MB_OK);
}
