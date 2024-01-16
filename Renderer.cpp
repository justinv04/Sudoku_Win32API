#define color_black     0x000000
#define color_white     0xffffff
#define color_gray      0xb0b0b0
#define color_red       0xff0000
#define color_orange    0xf58231
#define color_yellow    0xffe119
#define color_lime      0xbfef45
#define color_green     0x3cb44b
#define color_cyan      0x42d4f4
#define color_blue      0x4363d8
#define color_purple    0x911eb4
#define color_pink      0xf032e6

#define windowExtraHeight   23
#define windowExtraWidth    11

#define thickLineWidth      30
#define thinLineWidth       10
#define cellSize            50
#define cellBuffer          (cellSize / 5)
#define noteSize            (cellSize / 4)
#define noteBuffer          ((cellSize - 3 * noteSize) / 4)
#define boardSize           (4 * thickLineWidth + 6 * thinLineWidth + 9 * cellSize)

#define timerHeight    100

#define align_left                0
#define align_right               boardSize
#define align_center_X            (boardSize / 2)
#define align_top                 0
#define align_bottom              (boardSize + timerHeight)
#define align_center_Y            ((boardSize + timerHeight) / 2)     


#include "Cell.h"

void clearScreen(size_t color)
{
    size_t* currPixel = (size_t*)(gameState.memory);
    for(int y = 0; y < gameState.height; y++)
    {
        for(int x = 0; x < gameState.width; x++)
        {
            *currPixel++ = color;
        }
    }
}

void drawRectangle(int x0, int y0, int x1, int y1, int color)
{
    x0 = clamp(0, x0, gameState.width);
    y0 = clamp(0, y0, gameState.height);
    x1 = clamp(0, x1, gameState.width);
    y1 = clamp(0, y1, gameState.height);

    size_t* currPixel;
    for(int y = gameState.height - y1; y < gameState.height - y0; y++)
    {
        currPixel = (size_t*)gameState.memory + x0 + y*gameState.width;
        for(int x = x0; x < x1; x++)
        {
            *currPixel++ = color;
        }
    }
}

void drawNumber(int num, int x0, int y0, int x1, int y1, int color)
{
    int xDiff = (x1 - x0);
    int yDiff = (y1 - y0);

    switch(num)
    {
        case 0:
            drawRectangle(x0 + (int)(xDiff/10), y0, x0 + (int)(xDiff/4 + xDiff/10), y1, color);
            drawRectangle(x1 - (int)(xDiff/4 + xDiff/10), y0, x1 - (int)(xDiff/10), y1, color);
            drawRectangle(x0 + (int)(xDiff/10), y0, x1 - (int)(xDiff/10), y0 + (int)(xDiff/5), color);
            drawRectangle(x0 + (int)(xDiff/10), y1 - (int)(xDiff/5), x1 - (int)(xDiff/10), y1, color);
            break;
        case 1:
            drawRectangle(x0, y0, x1 - (int)(3*xDiff/5), y0 + (int)(yDiff/5), color);
            drawRectangle(x0 + (int)(2*xDiff/5), y0, x0 + (int)(3*xDiff/5), y1, color);
            drawRectangle(x0, y0 + (int)(4*yDiff/5), x1 , y1, color);
            break;
        case 2:
            drawRectangle(x0, y0, x1, y0 + (int)(yDiff/5), color);
            drawRectangle(x0, y0 + (int)(2*yDiff/5), x1, y0 + (int)(3*yDiff/5), color);
            drawRectangle(x0, y0 + (int)(4*yDiff/5), x1, y1, color);
            drawRectangle(x0 + (int)(4*xDiff/5), y0, x1, y0 + (int)(yDiff/2), color);
            drawRectangle(x0, y0 + (int)(yDiff/2), x0 + (int)(xDiff/5), y1, color);
            break;
        case 3:
            drawRectangle(x0, y0, x1, y0 + (int)(yDiff/5), color);
            drawRectangle(x0, y0 + (int)(2*yDiff/5), x1, y0 + (int)(3*yDiff/5), color);
            drawRectangle(x0, y0 + (int)(4*yDiff/5), x1, y1, color);
            drawRectangle(x0 + (int)(4*xDiff/5), y0, x1, y1, color);
            break;
        case 4:
            drawRectangle(x0, y0 + (int)(2*yDiff/5), x1, y0 + (int)(3*yDiff/5), color);
            drawRectangle(x0 + (int)(4*xDiff/5), y0, x1, y1, color);
            drawRectangle(x0, y0, x0 + (int)(xDiff/5), y0 + (int)(yDiff/2), color);
            break;
        case 5:
            drawRectangle(x0, y0, x1, y0 + (int)(yDiff/5), color);
            drawRectangle(x0, y0 + (int)(2*yDiff/5), x1, y0 + (int)(3*yDiff/5), color);
            drawRectangle(x0, y1 - (int)(yDiff/5), x1, y1, color);
            drawRectangle(x1 - (int)(xDiff/5), y0 + (int)(yDiff/2), x1, y1, color);
            drawRectangle(x0, y0, x0 + (int)(xDiff/5), y0 + (int)(yDiff/2), color);
            break;
        case 6:
            drawRectangle(x0, y0, x1, y0 + (int)(yDiff/5), color);
            drawRectangle(x0, y0 + (int)(2*yDiff/5), x1, y0 + (int)(3*yDiff/5), color);
            drawRectangle(x0, y1 - (int)(yDiff/5), x1, y1, color);
            drawRectangle(x1 - (int)(xDiff/5), y0 + (int)(yDiff/2), x1, y1, color);
            drawRectangle(x0, y0, x0 + (int)(xDiff/5), y1, color);
            break;
        case 7:
            drawRectangle(x0, y0, x1, y0 + (int)(yDiff/5), color);
            drawRectangle(x1 - (int)(xDiff/5), y0, x1, y1, color);
            break;
        case 8:
            drawRectangle(x0, y0, x1, y0 + (int)(yDiff/5), color);
            drawRectangle(x0, y0 + (int)(2*yDiff/5), x1, y0 + (int)(3*yDiff/5), color);
            drawRectangle(x0, y1 - (int)(yDiff/5), x1, y1, color);
            drawRectangle(x1 - (int)(xDiff/5), y0, x1, y1, color);
            drawRectangle(x0, y0, x0 + (int)(xDiff/5), y1, color);
            break;
        case 9:
            drawRectangle(x0, y0, x1, y0 + (int)(yDiff/5), color);
            drawRectangle(x0, y0 + (int)(2*yDiff/5), x1, y0 + (int)(3*yDiff/5), color);
            drawRectangle(x0, y1 - (int)(yDiff/5), x1, y1, color);
            drawRectangle(x1 - (int)(xDiff/5), y0, x1, y1, color);
            drawRectangle(x0, y0, x0 + (int)(xDiff/5), y0 + (int)(yDiff/2), color);
            break;
    }
}

void drawLetter(char letter, int x0, int y0, int x1, int y1, int color)
{
    switch(letter)
    {
        case 'a':
        {
            break;
        }
        case 'b':
        {
            break;
        }
        case 'c':
        {
            break;
        }
        case 'd':
        {
            break;
        }
        case 'e':
        {
            break;
        }
        case 'f':
        {
            break;
        }
        case 'g':
        {
            break;
        }
        case 'h':
        {
            break;
        }
        case 'i':
        {
            break;
        }
        case 'j':
        {
            break;
        }
        case 'k':
        {
            break;
        }
        case 'l':
        {
            break;
        }
        case 'm':
        {
            break;
        }
        case 'n':
        {
            break;
        }
        case 'o':
        {
            break;
        }
        case 'p':
        {
            break;
        }
        case 'q':
        {
            break;
        }
        case 'r':
        {
            break;
        }
        case 's':
        {
            break;
        }
        case 't':
        {
            break;
        }
        case 'u':
        {
            break;
        }
        case 'v':
        {
            break;
        }
        case 'w':
        {
            break;
        }
        case 'x':
        {
            break;
        }
        case 'y':
        {
            break;
        }
        case 'z':
        {
            break;
        }
        default:
            drawRectangle(x0, y0, x1, y1, color);
    }
}

void drawString(char* message, int x0, int y0, int x1, int y1, int color, double spacing)
{
    if(spacing > 1.0 || spacing < 0.0)
        return;

    int length = 0;
    while(message[length] != '\0')
        length++;

    int spaceAmount = (int)((x1 - x0) * (1 / spacing)) / (length - 1);

    for(int i = 0; i < length; i++)
        drawLetter(message[i], x0 + spaceAmount * i, y0, x0 + spaceAmount  * (i + 1), y1, color);
}

void drawSquares()
{
    int colorArray[9] = {color_red, color_orange, color_yellow, color_lime, color_green, color_cyan, color_blue, color_purple, color_pink};
    int x = thickLineWidth, y = thickLineWidth, valueColor, noteColor, keyVal, boardVal;
    Cell* currCell;

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            drawRectangle(x, y, x + cellSize, y + cellSize, color_white);

            currCell = gameState.sudokuGame.getCell(i, j);
            boardVal = currCell->getBoardVal(), keyVal = currCell->getKeyVal();

            if(gameState.placingNotes)
            {
                valueColor = color_gray;
                noteColor = color_black;
            }
            else
            {
                valueColor = boardVal == keyVal ? color_black : color_red;
                noteColor = color_gray;
            }

            if(gameState.isWinner)
                valueColor = colorArray[rand() % 9];

            if(boardVal != 0)
                drawNumber(boardVal, x + cellBuffer, y + cellBuffer, x - cellBuffer + cellSize, y - cellBuffer + cellSize, valueColor);
            else
            {
                for(int noteVal : currCell->getNVals())
                {
                    noteVal--;
                    drawNumber(noteVal + 1, x + noteBuffer * ((noteVal % 3) + 1) + noteSize * (noteVal % 3), y + noteBuffer * ((noteVal / 3) + 1) + noteSize * (noteVal / 3),
                                      x + noteBuffer * ((noteVal % 3) + 1) + noteSize * ((noteVal % 3) + 1), y + noteBuffer * ((noteVal / 3) + 1) + noteSize * ((noteVal / 3) + 1),
                               noteColor);
                }
            }

            x += cellSize;
            if(j % 3 == 2)
                x += thickLineWidth;
            else
                x += thinLineWidth;
        }

        x = thickLineWidth;
        y += cellSize;
        i % 3 == 2 ? y += thickLineWidth : y += thinLineWidth;
    }
}

void drawGameBoard()
{
    drawRectangle(0, 0, 9*cellSize + 6*thinLineWidth + 4*thickLineWidth, 9*cellSize + 6*thinLineWidth + 4*thickLineWidth, color_black);
    drawSquares();
}

void drawTimer()
{
    int digitColor = gameState.isWinner ? color_blue : color_black;

    drawRectangle(0, boardSize, boardSize, boardSize + timerHeight, color_white);
    drawRectangle(boardSize/2 - 10, boardSize + 20, boardSize/2 + 10, boardSize + 40, digitColor);
    drawRectangle(boardSize/2 - 10, boardSize + 50, boardSize/2 + 10, boardSize + 70, digitColor);

    int clockDigits[4] = {gameState.upTime / 600 % 10, (gameState.upTime / 60) % 10, (gameState.upTime / 10) % 10, gameState.upTime % 10};

    drawNumber(clockDigits[0], boardSize/2 - 130, boardSize + 20, boardSize/2 - 80, boardSize + 70, digitColor);
    drawNumber(clockDigits[1], boardSize/2 - 70, boardSize + 20, boardSize/2 - 20, boardSize + 70, digitColor);
    drawNumber(clockDigits[2], boardSize/2 + 20, boardSize + 20, boardSize/2 + 70, boardSize + 70, digitColor);
    drawNumber(clockDigits[3], boardSize/2 + 80, boardSize + 20, boardSize/2 + 130, boardSize + 70, digitColor);
}

void drawMenu()
{
    clearScreen(color_white);
}

void drawGame()
{
    clearScreen(color_white);
    drawGameBoard();
    drawTimer();
}