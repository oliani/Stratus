#include <iostream>
#include "windows.h"
#include "time.h"
#include <string>
#include "conio.h"
#include <ctime>
#include <chrono>

using namespace std;
void spinScr(HWND windowHandle)
{

    RECT window;

    GetWindowRect(windowHandle, &window); // Making marks from a rectangle and sabing on window
    SendMessage(windowHandle, WM_MOUSEMOVE, 0, MAKELPARAM(window.right-1, window.bottom/ 2));
}


int MMove(HWND windowHandle)
{

    RECT window;

    /* Get Screen Size */
    GetWindowRect(windowHandle, &window); // Making marks from a rectangle and sabing on window
    window.bottom -= 70;

    /* Calculate Random move */
    int randxn = rand() % 2;
    int randyn = rand() % 2;

    if (randxn != 1)
        randxn = -1;
    if (randyn != 1)
        randyn = -1;

    int randx = (window.bottom / 2) + (rand() % 50) * randxn + 50;
    int randy = (window.right / 2) + (rand() % 50) * randyn + -50;

    /********************/

    /* Make move */
    SendMessage(windowHandle, WM_MOUSEMOVE, 0, MAKELPARAM(randx, randy));

    return 1;
}

int RMBClick(HWND windowHandle)
{
    srand (time(NULL));
    int rand1 = rand() % 100 + 200;
    SendMessage(windowHandle, WM_RBUTTONDOWN, 0,0); // mouse click hold

    Sleep(rand1); //waiting

    SendMessage(windowHandle, WM_RBUTTONUP,0,0); // mouse click release

    rand1 = rand() % 100 + 200;

    Sleep(rand1);


    return 1;
}


int main()
{
    SetConsoleTitleA("Stratus");
    srand (time(NULL));
    LPCSTR targetWindow = "Priston Tale";
    HWND windowHandle = FindWindowA(NULL,targetWindow);
    cout << "Press enter to start...";
    system("pause");
    int i =0;

    cout << "\nStarting time: " << chrono::system_clock::to_time_t(chrono::system_clock::now()) << "\n\n\n";
    while(i == 0)
    {
        if(kbhit())
            i++;
         srand (time(NULL));
         spinScr(windowHandle);
         Sleep(rand() % 150);

         MMove(windowHandle);
         RMBClick(windowHandle);
         spinScr(windowHandle);
         cout << chrono::system_clock::to_time_t(chrono::system_clock::now()) << " - Right Click Done\n";

         srand (time(NULL));
         Sleep(rand() % 150);

         spinScr(windowHandle);
         MMove(windowHandle);
         RMBClick(windowHandle);
         cout << chrono::system_clock::to_time_t(chrono::system_clock::now()) << " - Right Click Done\n";

         spinScr(windowHandle);
         Sleep(rand()%100 + 500);

    }

    cout << "Execution done";
    system("pause");
    return 0;
}
