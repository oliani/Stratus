#include <iostream>
#include "windows.h"
#include <string>


using namespace std;

int main()
{
    LPCSTR targetWindowName = "Calculadora";
    HWND hWindowHandle = FindWindow(NULL, targetWindowName);
    HWND editClass = FindWindowEx(hWindowHandle, NULL, "Edit", NULL);
    Sleep(2000);
    SendMessage(editClass, WM_KEYDOWN,VK_ADD,0);
    Sleep(500);
    SendMessage(editClass, WM_KEYUP,VK_ADD,0);
    cout << "esc pressed";

    Sleep(2000);

    cout << "######################\n";
    cout << "#   EXECUTION DONE   #\n";
    cout << "######################\n";
    cout << "[Alt + 0] Toggle On/Off\n\n";

    cout << hWindowHandle;


    return 0;
}
