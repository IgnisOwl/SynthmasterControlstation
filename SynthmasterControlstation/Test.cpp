#include <windows.h>


int main(int argc, char *argv[]) {

    INPUT input;

    input.type = INPUT_KEYBOARD;
    input.ki.wVk = 0x55;  //KeyboardInput key number
    input.ki.dwFlags = 0; //0=press;

    Sleep(1000);

    HWND hwndObj = FindWindowA(NULL, "Synthmaster 2.9"); //first arg: Window class, second arg: Window title.
    HWND previousForegroundWindow = GetForegroundWindow();

    SetForegroundWindow(hwndObj);

        SendInput(1, &input, sizeof(INPUT));
        Sleep(500);
        input.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &input, sizeof(INPUT));

    SetForegroundWindow(previousForegroundWindow);


    return 0;
}