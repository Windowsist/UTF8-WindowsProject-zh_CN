// WindowsProject.cpp : 定义应用程序的入口点。
//

// 不再使用 UNICODE, 改用UTF8
#ifdef UNICODE
#undef UNICODE
#endif
#ifdef _UNICODE
#undef _UNICODE
#endif

#include "framework.h"

int APIENTRY WinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPSTR lpCmdLine,
                     _In_ int nCmdShow)
{
    MessageBoxA(nullptr, "English\r\n简体中文\r\n繁體中文\r\n한국어\r\n😀😁😂🤣", "UTF8 WindowsProject 😀😀", MB_OK);
    return 0;
}
