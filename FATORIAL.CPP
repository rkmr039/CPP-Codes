#include <Windows.h>
#include <Tlhelp32.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <time.h>
 
bool GetPID();
 
BYTE ReadGameState();
BYTE AmountWorkers();
WORD ReadTime();
 
void Search();
void SearchLeft();
void ScoreScreen();
void Back();
void Surrender();
void SelectWorker();
void Attack(unsigned int mapX, unsigned int mapY);
 
void WinLoss();
 
DWORD PID;
HWND hWindow;
HANDLE hProcess;
int Win, Loss;
 
int main()
{
        Win = 0;
        Loss = 0;
        int lastBreak = 0, countBreak = 0, doubleBreak = 0;
        int randBreak = rand() % 15 + 20, randDoubleBreak = rand() % 2 + 1;
 
        if (GetPID())
        {
                hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, PID);
 
                if (hProcess != NULL)
                {                              
                        std::cout << "Opened StarCraft II process." << std::endl;
 
                        Sleep(5000);
 
                        std::cout << std::endl << "Bot started" << std:: endl;
 
                        srand(time(NULL));
 
                        for (int i = 0; 1; i++)
                        {
                                if (lastBreak + 10 <= i && i % randBreak == 0)
                                {
                                        randBreak = rand() % 15 + 10;
                                        lastBreak = i;
                                        countBreak++;
                                        int Break = (rand() % 400 + 1800)* 1000;
                                        if (countBreak % randDoubleBreak == 0 && countBreak != 0)
                                        {
                                                doubleBreak++;
                                                Break *= 2;
                                                randDoubleBreak = rand() % 2 + 1;
                                                if (doubleBreak >= 2)
                                                {
                                                        doubleBreak = 0;
                                                        Break = (rand() % 900 + 4000) * 1000;
                                                }
                                        }
                                        tm *current = new tm;
                                        time_t now;
                                        time(&now);
                                        //localtime_s(current, &now);
                                        std::cout << std::endl << current->tm_hour << ":" << current->tm_min << ":" << current->tm_sec << "             Break for " << Break / 1000 << " seconds." << std::endl;
                                        delete current;
                                        Sleep(Break);
                                }
 
                                unsigned int mapX, mapY;
                                bool surrender = true;
                                clock_t newSearch = clock() + 120 * CLOCKS_PER_SEC;
                                       
                                Search();
 
                                while (!ReadTime())
                                {
                                        if (clock() >= newSearch)
                                        {
                                                SearchLeft();
                                                Back();
                                                Search();
                                                newSearch = clock() + 120 * CLOCKS_PER_SEC;
                                        }
                                }
 
                                tm *current = new tm;
                                time_t now;
                                time(&now);
                                //localtime_s(current, &now);
 
                                std::cout << std::endl << current->tm_hour << ":" << current->tm_min << ":" << current->tm_sec << "     Game: " << i + 1 << std::endl;
                                delete current;
 
                                ReadProcessMemory(hProcess, (LPVOID) 0x01D764D4, &mapX, sizeof(mapX), NULL);
                                ReadProcessMemory(hProcess, (LPVOID) 0x01D764D8, &mapY, sizeof(mapY), NULL);
 
                                Sleep(rand() % 200 + 100);
 
                                SelectWorker();
                                       
                                Sleep(rand() % 300 + 200);
                                       
                                Attack(mapX, mapY);
                               
                                while (!ReadGameState() && surrender)
                                {
                                        if (!AmountWorkers() || ReadTime() > (rand() % 60 + 330))
                                        {
                                                Sleep(rand() % 2000 + 2000);
                                                Surrender();
                                                surrender = false;
                                        }
                                }
 
                                Sleep(rand() % 1000 + 1000);
 
                                WinLoss();
 
                                Sleep(rand() % 1000 + 1000);
 
                                ScoreScreen();
 
                                std::cout << "          Won: " << Win << " Lost: " << Loss << std::endl;
 
                                Sleep(rand() % 5000 + 10000);
 
                                Back();
 
                                Sleep(rand() % 3000 + 3500);
                        }
 
                        CloseHandle(hProcess);
                }
                else
                {
                        std::cout << "Failed to open StarCraft II process." << std::endl;
                }
        }
        else
        {
                std::cout << "Couldn't find StarCraft II." << std::endl;
        }
 
        system("pause");
 
        return 0;
}
 
bool GetPID()
{
        hWindow = FindWindow("StarCraft II", NULL);
 
        if (hWindow != NULL)
        {
                if (GetWindowThreadProcessId(hWindow, &PID))
                {
                        return true;
                }
        }
 
        return false;
}
 
BYTE ReadGameState()
{
        BYTE GameState;
        ReadProcessMemory(hProcess, (LPVOID) 0x026A8F96, &GameState, sizeof(GameState), NULL);
        return GameState;
}
 
void ScoreScreen()
{
        SendMessage(hWindow, WM_KEYDOWN, 0x53, 0);
        SendMessage(hWindow, WM_CHAR, 0x53, 0);
        SendMessage(hWindow, WM_KEYUP, 0x53, 0);
}
 
void Search()
{
        SetCapture(hWindow);
        SendMessage(hWindow, WM_MOUSEMOVE, 0, MAKELPARAM(145, 609));
        Sleep(5);
        SendMessage(hWindow, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(145, 609));
        Sleep(5);
        SendMessage(hWindow, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(145, 609));
        ReleaseCapture();
}
 
void SearchLeft()
{
        SetCapture(hWindow);
        SendMessage(hWindow, WM_KEYDOWN, VK_RETURN, 0);
        SendMessage(hWindow, WM_CHAR, VK_RETURN, 0);
        SendMessage(hWindow, WM_KEYUP, VK_RETURN, 0);
        ReleaseCapture();
}
 
void Back()
{
        SetCapture(hWindow);
        SendMessage(hWindow, WM_MOUSEMOVE, 0, MAKELPARAM(159, 628));
        Sleep(5);
        SendMessage(hWindow, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(159, 628));
        Sleep(5);
        SendMessage(hWindow, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(159, 628));
        ReleaseCapture();
}
 
void Surrender()
{
        SendMessage(hWindow, WM_KEYDOWN, VK_F10, 0);
        SendMessage(hWindow, WM_CHAR, VK_F10, 0);
        SendMessage(hWindow, WM_KEYUP, VK_F10, 0);
        Sleep(5);
        SendMessage(hWindow, WM_KEYDOWN, 0x4E, 0);
        SendMessage(hWindow, WM_CHAR, 0x4E, 0);
        SendMessage(hWindow, WM_KEYUP, 0x4E, 0);
}
 
void SelectWorker()
{
        SendMessage(hWindow, WM_KEYDOWN, VK_SHIFT, 0);
        SendMessage(hWindow, WM_KEYDOWN, VK_F1, 0);
        SendMessage(hWindow, WM_KEYUP, VK_F1, 0);
        SendMessage(hWindow, WM_KEYUP, VK_SHIFT, 0);
 
        Sleep(5);
 
        SendMessage(hWindow, WM_KEYDOWN, VK_SHIFT, 0);
        SendMessage(hWindow, WM_KEYDOWN, VK_F1, 0);
        SendMessage(hWindow, WM_KEYUP, VK_F1, 0);
        SendMessage(hWindow, WM_KEYUP, VK_SHIFT, 0);
 
        Sleep(5);
 
        SendMessage(hWindow, WM_KEYDOWN, VK_SHIFT, 0);
        SendMessage(hWindow, WM_KEYDOWN, VK_F1, 0);
        SendMessage(hWindow, WM_KEYUP, VK_F1, 0);
        SendMessage(hWindow, WM_KEYUP, VK_SHIFT, 0);
 
        Sleep(5);
 
        SendMessage(hWindow, WM_KEYDOWN, VK_SHIFT, 0);
        SendMessage(hWindow, WM_KEYDOWN, VK_F1, 0);
        SendMessage(hWindow, WM_KEYUP, VK_F1, 0);
        SendMessage(hWindow, WM_KEYUP, VK_SHIFT, 0);
 
        Sleep(5);
 
        SendMessage(hWindow, WM_KEYDOWN, VK_SHIFT, 0);
        SendMessage(hWindow, WM_KEYDOWN, VK_F1, 0);
        SendMessage(hWindow, WM_KEYUP, VK_F1, 0);
        SendMessage(hWindow, WM_KEYUP, VK_SHIFT, 0);
 
        Sleep(5);
 
        SendMessage(hWindow, WM_KEYDOWN, VK_SHIFT, 0);
        SendMessage(hWindow, WM_KEYDOWN, VK_F1, 0);
        SendMessage(hWindow, WM_KEYUP, VK_F1, 0);
        SendMessage(hWindow, WM_KEYUP, VK_SHIFT, 0);
}
 
void Attack(unsigned int mapX, unsigned int mapY)
{
        BYTE Length;
        char Name[64];
        unsigned int cameraX, cameraY, width, height;
 
        ReadProcessMemory(hProcess, (LPVOID) 0x026A8FB8, &Length, sizeof(Length), NULL);
        ReadProcessMemory(hProcess, (LPVOID) 0x026A8FC0, Name, Length, NULL);
 
        if (!strncmp(Name, "Anuroth", 7))
        {
                ReadProcessMemory(hProcess, (LPVOID) 0x026A9890, &cameraX, sizeof(cameraX), NULL);
                ReadProcessMemory(hProcess, (LPVOID) 0x026A9894, &cameraY, sizeof(cameraY), NULL);
        }
        else
        {
                ReadProcessMemory(hProcess, (LPVOID) 0x026A8F80, &cameraX, sizeof(cameraX), NULL);
                ReadProcessMemory(hProcess, (LPVOID) 0x026A8F84, &cameraY, sizeof(cameraY), NULL);
        }
 
        width = 19 +  174 * cameraX / mapX;
        height = 710 - 170 * cameraY / mapY;
 
        std::cout << "          width: " << width << " height: " << height << std::endl;
 
        SendMessage(hWindow, WM_KEYDOWN, 0x41, 0);
        SendMessage(hWindow, WM_CHAR, 0x41, 0);
        SendMessage(hWindow, WM_KEYUP, 0x41, 0);
 
        SetCapture(hWindow);
        SendMessage(hWindow, WM_MOUSEMOVE, 0, MAKELPARAM(width, height));
        Sleep(5);
        SendMessage(hWindow, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(width, height));
        Sleep(5);
        SendMessage(hWindow, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(width, height));
        ReleaseCapture();
}
 
void WinLoss()
{
        BYTE Length, WinLost;
        char Name[64];
 
        ReadProcessMemory(hProcess, (LPVOID) 0x026A8FB8, &Length, sizeof(Length), NULL);
        ReadProcessMemory(hProcess, (LPVOID) 0x026A8FC0, Name, Length, NULL);
        ReadProcessMemory(hProcess, (LPVOID) 0x026A8F96, &WinLost, sizeof(WinLost), NULL);
       
        if (!strncmp(Name, "Anuroth", 7))
        {
                if (WinLost == 1)
                {
                        Win++;
                }
                else
                {
                        Loss++;
                }
        }
        else
        {
                if (WinLost == 2)
                {
                        Win++;
                }
                else
                {
                        Loss++;
                }
        }
}
 
BYTE AmountWorkers()
{
        BYTE Length, Amount;
        char Name[64];
 
        ReadProcessMemory(hProcess, (LPVOID) 0x026A8FB8, &Length, sizeof(Length), NULL);
        ReadProcessMemory(hProcess, (LPVOID) 0x026A8FC0, Name, Length, NULL);
 
        if (!strncmp(Name, "acc name", 7))
        {
                ReadProcessMemory(hProcess, (LPVOID) 0x026A9368, &Amount, sizeof(Amount), NULL);
        }      
        else
        {
                ReadProcessMemory(hProcess, (LPVOID) 0x026A9C78, &Amount, sizeof(Amount), NULL);
        }
 
        return Amount;
}
 
WORD ReadTime()
{
        WORD Time;
        ReadProcessMemory(hProcess, (void*)0x01DE8012, &Time, sizeof(Time), NULL);
        return Time;
}
