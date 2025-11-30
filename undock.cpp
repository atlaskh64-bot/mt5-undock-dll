#include <windows.h>

extern "C" __declspec(dllexport) int DetachChart2(HWND hwnd, int mode)
{
    if (hwnd == NULL)
        return -1;

    RECT rc;
    if (!GetWindowRect(hwnd, &rc))
        return -2;

    LONG style = GetWindowLong(hwnd, GWL_STYLE);
    style |= WS_POPUP;
    style &= ~WS_CHILD;
    SetWindowLong(hwnd, GWL_STYLE, style);

    SetWindowPos(hwnd, HWND_TOPMOST,
                 rc.left + 50, rc.top + 50,
                 rc.right - rc.left, rc.bottom - rc.top,
                 SWP_SHOWWINDOW);

    SetForegroundWindow(hwnd);
    return 1;
}
