#include <windows.h>
#include <iostream>


int main(int argc, char *argv[]) {

    INPUT input;

    using namespace std;

    double fScreenWidth = GetSystemMetrics(SM_CXSCREEN) - 1;
    double fScreenHeight = GetSystemMetrics(SM_CYSCREEN) - 1;

    input.type = INPUT_MOUSE;
    input.mi.mouseData = 0;
    input.mi.dx = 100.0f * (65536.0f / fScreenWidth); //https://docs.microsoft.com/en-us/windows/win32/api/winuser/ns-winuser-mouseinput
    input.mi.dy = 100.0f * (65536.0f / fScreenHeight);
    input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE;

    POINT initialPosition;
    GetCursorPos(&initialPosition);
    cout << initialPosition.x << endl;


    Sleep(100);

    HWND hwndObj = FindWindowA(NULL, "Synthmaster 2.9"); //first arg: Window class, second arg: Window title.
    HWND previousForegroundWindow = GetForegroundWindow();

    //SetForegroundWindow(hwndObj);
    Sleep(100);

    SendInput(1, &input, sizeof(input));
    Sleep(100);

    //SetForegroundWindow(previousForegroundWindow);


    return 0;
}