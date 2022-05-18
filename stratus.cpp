#include <iostream>
#include "windows.h"
#include "time.h"
#include <string>
#include "conio.h"
#include <ctime>
#include <chrono>

using namespace std;

int MMove(HWND windowHandle)
{    
    RECT window;

    /* Get Screen Size */
    GetWindowRect(windowHandle, &window); // Making marks from a rectangle and sabing on window
    
    /* window contains the center of the screen */

    /* Calculate Random move */
    int randx = rand() % 3;
    int randy = rand() % 3;

    if (randx != 1)
        randx = -1;

    if (randy != 1)
        randy = -1;

    int numx = (rand() % 100 * randx) + (window.right / 3);
    int numy = (rand() % 100 * randy) + (window.bottom / 3);

    /********************/

    /* Make move */
    SendMessage(windowHandle, WM_MOUSEMOVE, 0, MAKELPARAM(numx, numy));

    return 1;
}

int RMBClick(HWND windowHandle)
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int rand1 = rand() % 100 + 300;
    SendMessage(windowHandle, WM_RBUTTONDOWN, 0, 0); // mouse click hold

    Sleep(rand1); //waiting

    SendMessage(windowHandle, WM_RBUTTONUP, 0, 0); // mouse click release

    rand1 = rand() % 100 + 300;

    Sleep(rand1);


    return 1;
}

void KbdRight(HWND windowHandle)
{
    srand(static_cast<unsigned int>(time(nullptr)));
    SendMessage(windowHandle, WM_KEYDOWN, 0x25, 0x002C0001);
    Sleep(rand()%3000);
    SendMessage(windowHandle, WM_KEYUP, 0x25, 0xC02C0001);
}

void combo(HWND windowHandle) 
{
    SendMessage(windowHandle, WM_KEYDOWN, 0x25, 0x002C0001);
    MMove(windowHandle);
    RMBClick(windowHandle);
    Sleep(rand() % 300 + 300);
    SendMessage(windowHandle, WM_KEYUP, 0x25, 0xC02C0001);
    Sleep(rand() % 1000);

}


int main()
{
    SetConsoleTitleA("Stratus");

    srand(static_cast<unsigned int>(time(nullptr)));
    LPCSTR targetWindow = "Priston Tale";
    HWND windowHandle = FindWindowA(NULL, targetWindow);
    bool exit = false;
    MSG msg = { 0 };
    RegisterHotKey(NULL, 1, MOD_ALT | MOD_NOREPEAT, 0x42);

    while (windowHandle != 0) 
    {
        combo(windowHandle);
    }
    

    cout << "\n\nExecution done!\n\n";
    system("pause");
    return 0;
}

