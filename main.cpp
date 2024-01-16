#include <windows.h>
#include <iostream>
#include <vector>
#include <string>
#include "Sudoku.h"

struct MenuState
{
    bool running;
    int difficulty, mouseX, mouseY;
    void* memory;
    BITMAPINFO bitmap_info;
};
struct GameState
{
    bool running, isWinner, placingNotes;
    size_t startTick;
    int height, width, size, mouseX, mouseY, upTime;
    void* memory;
    BITMAPINFO bitmap_info;
    Sudoku sudokuGame = Sudoku();
};

MenuState menuState;
GameState gameState;

inline int clamp(int min, int val, int max)
{
    if(val < min) return min;
    if(val > max) return max;
    return val;
}

#include "renderer.cpp"

void resizeWindow(HWND hWindowHandle)
{
    RECT rect;
    GetClientRect(hWindowHandle, &rect);
    gameState.width = rect.right - rect.left;
    gameState.height = rect.bottom - rect.top;
    gameState.size = gameState.width * gameState.height * sizeof(size_t);
    gameState.isWinner = false;

    if(gameState.memory)
        VirtualFree(gameState.memory, 0, MEM_RELEASE);

    gameState.memory = VirtualAlloc(0, gameState.size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    gameState.bitmap_info.bmiHeader.biSize = sizeof(gameState.bitmap_info.bmiHeader);
    gameState.bitmap_info.bmiHeader.biWidth = gameState.width;
    gameState.bitmap_info.bmiHeader.biHeight = gameState.height;
    gameState.bitmap_info.bmiHeader.biPlanes = 1;
    gameState.bitmap_info.bmiHeader.biBitCount = 32;
    gameState.bitmap_info.bmiHeader.biCompression = BI_RGB;
}

std::vector<int> getCellUnderMouse() 
{
    std::vector<int> cellID = {-1, -1};
    int x = gameState.mouseX, y = gameState.mouseY, i;

    if(gameState.mouseY > boardSize)
        return cellID;

    x -= thickLineWidth, y-= thickLineWidth;
    for(i = 0; i < 9; i++)
    {   
        if(x < i * (cellSize + thinLineWidth) + (i / 3)*(thickLineWidth - thinLineWidth) + cellSize)
        {
            if(x > i * (cellSize + thinLineWidth) + (i / 3)*(thickLineWidth - thinLineWidth))
                cellID.at(0) = i;
        }
    }
    for(i = 0; i < 9; i++)
    {   
        if(y < i * (cellSize + thinLineWidth) + (i / 3)*(thickLineWidth - thinLineWidth) + cellSize)
        {
            if(y > i * (cellSize + thinLineWidth) + (i / 3)*(thickLineWidth - thinLineWidth))
                cellID.at(1) = i;
        }
    }
    return cellID;
}

LRESULT CALLBACK MenuProcedure(HWND hWindowHandle, UINT Message, WPARAM wParam, LPARAM lParam)
{
    LRESULT result = 0;
    switch(Message)
    {
        case WM_CREATE:
        {
            drawMenu();
            break;
        }

        case WM_MOUSEMOVE:
        {
            menuState.mouseX = (int)(short)HIWORD(lParam);
            menuState.mouseY = (int)(short)LOWORD(lParam);
            break;
        }

        case WM_KEYDOWN:
        {
            if(wParam == 32)
            {
                menuState.running = false;
                gameState.running = true;
                PostQuitMessage(0);
            }
            break;
        }

        case WM_DESTROY:
        {
            menuState.running = false;
            PostQuitMessage(0);
        }

        default:
            result = DefWindowProc(hWindowHandle, Message, wParam, lParam);

    }
    return result;
}

LRESULT CALLBACK GameProcedure(HWND hWindowHandle, UINT Message, WPARAM wParam, LPARAM lParam)
{
    LRESULT result = 0;
    switch(Message)
    {
        case WM_MOUSEMOVE:
        {
            gameState.mouseX = (int)(short)HIWORD(lParam);
            gameState.mouseY = (int)(short)LOWORD(lParam);
            break;
        }

        case WM_KEYDOWN:
        {
            if(wParam == 16)
            {
                gameState.placingNotes = !gameState.placingNotes;
                break;
            }

            std::vector<int> cellID = getCellUnderMouse();
            if(cellID.at(0) == -1 || cellID.at(1) == -1)
                break;

            Cell* selectedCell = gameState.sudokuGame.getCell(cellID.at(0), cellID.at(1));

            if(selectedCell->getClueStatus())
                break;

            if((wParam >= 48 && wParam < 58) || (wParam >= 96 && wParam < 106))
            {
                if(wParam < 58)
                    wParam -= 48;
                else
                    wParam -= 96;
                
                if(!gameState.placingNotes)
                {
                    selectedCell->fillBoardVal(wParam);
                    selectedCell->clearNVals();
                }
                else
                {
                    if(wParam == 0)
                        selectedCell->clearNVals();
                    else if(selectedCell->isNVal(wParam))
                        selectedCell->removeNVal(wParam);
                    else
                        selectedCell->addNVal(wParam);
                }
            }

            if(gameState.sudokuGame.isWinner())
                gameState.isWinner = true;

            break;
        }

        case WM_SIZE:
        {
            resizeWindow(hWindowHandle);
            break;
        }

        case WM_DESTROY:
        {
            gameState.running = false;
            PostQuitMessage(0);
            break;
        }

        default:
            result = DefWindowProcW(hWindowHandle, Message, wParam, lParam);
    }
    return result;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR args, int ncmdshow)
{
    WNDCLASSW MenuWindow = {};
    MenuWindow.style = CS_HREDRAW | CS_VREDRAW;
    MenuWindow.lpszClassName = L"W";
    MenuWindow.lpfnWndProc = MenuProcedure;

    WNDCLASSW GameWindow = {};
    GameWindow.style = CS_HREDRAW | CS_VREDRAW;
    GameWindow.lpszClassName = L"Sudoku Game";
    GameWindow.lpfnWndProc = GameProcedure;

    RegisterClassW(&GameWindow);
    RegisterClassW(&MenuWindow);

    HWND appWindow = CreateWindowW( MenuWindow.lpszClassName, L"Sudoku",
                                    WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT,
                                    CW_USEDEFAULT, boardSize + windowExtraWidth, boardSize + timerHeight + windowExtraHeight,
                                    0, 0, hInstance, 0);

    
    HDC hdc = GetDC(appWindow);
    
    menuState.running = true;
    gameState.running = false;

    MSG message;
    
    while(menuState.running)
    {
        while(PeekMessage(&message, appWindow, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }
        StretchDIBits(hdc, 0, 0, gameState.width, gameState.height, 0, 0, gameState.width, gameState.height, gameState.memory, &gameState.bitmap_info, DIB_RGB_COLORS, SRCCOPY);
    }

    DestroyWindow(appWindow);
    appWindow = CreateWindowW( GameWindow.lpszClassName, L"Sudoku",
                                    WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT,
                                    CW_USEDEFAULT, boardSize + windowExtraWidth, boardSize + timerHeight + windowExtraHeight,
                                    0, 0, hInstance, 0);

    hdc = GetDC(appWindow);

    gameState.sudokuGame.startGame();
    gameState.startTick = GetTickCount();

    while(gameState.running)
    {
        while(PeekMessage(&message, appWindow, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }

        gameState.upTime = (GetTickCount() - gameState.startTick)/1000;

        drawGame();
        StretchDIBits(hdc, 0, 0, gameState.width, gameState.height, 0, 0, gameState.width, gameState.height, gameState.memory, &gameState.bitmap_info, DIB_RGB_COLORS, SRCCOPY);

        if(gameState.isWinner)
        {
            for(int i = 0; i < 10; i++)
            {   
                drawGame();
                StretchDIBits(hdc, 0, 0, gameState.width, gameState.height, 0, 0, gameState.width, gameState.height, gameState.memory, &gameState.bitmap_info, DIB_RGB_COLORS, SRCCOPY);
                Sleep(100);
            }
            Sleep(3000);
            gameState.running = false;
            PostQuitMessage(0);
        }
    }
    return 0;
}