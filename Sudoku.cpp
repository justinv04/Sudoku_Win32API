#include "Sudoku.h"

Sudoku::Sudoku()
{
    int val = 1, row, col;
    for(row = 0; row < 9; row++)
    {
        for(col = 0; col < 9; col++)
        {
            board[9 * row + col].setKeyVal(val);
            val == 9 ? val = 1 : val++;
        }
        row % 3 == 2 ? val += 4 : val += 3;
        val %= 9;
    }

    Cell *currRow[9], *currCol[9], *currBox[9];
    for(row = 0; row < 9; row++)
    {
        for(col = 0; col < 9; col++)
        {
            currRow[col] = &board[9 * row + col];
            currCol[col] = &board[9 * col + row];
            currBox[col] = &board[9*(3*(row/3)+(col/3)) + 3*(row%3)+(col%3)];
        }
        for(col = 0; col < 9; col++)
        {
            board[9 * row + col].setRowCells(currRow);
            board[9 * col + row].setColCells(currCol);
            board[9*(3*(row/3)+(col/3)) + 3*(row%3)+(col%3)].setBoxCells(currBox);
        }
    }
}

void Sudoku::startGame()
{
    srand(time(0));
    generateKey();
    generateBoard(1);
}

void Sudoku::generateKey()
{
    Cell *currCell;
    std::set<Cell*> lowestPVCells;
    int val = rand() % 9 + 1, i, PVSize, minPVSize, row, col;

    while(!isKeyGenerated())
    {
        if(lowestPVCells.size() == 0)
        {
            for(i = 0; i < 81; i++)
            {
                board[i].resetVals();
                lowestPVCells.insert(&board[i]);
            }
        }

        currCell = *std::next(lowestPVCells.begin(), rand() % lowestPVCells.size());

        while(!currCell->isPVal(val))
            val == 9 ? val = 1 : val++;

        currCell->fillKeyVal(val);
        lowestPVCells.erase(currCell);

        minPVSize = 9;
        for(row = 0; row < 9; row++)
        {
            for(col = 0; col < 9; col++)
            {
                currCell = &board[9 * row + col];
                PVSize = currCell->getPVals().size();
                if(PVSize < minPVSize && PVSize != 0)
                {
                    minPVSize = PVSize;
                    lowestPVCells.clear();
                }
                if(PVSize == minPVSize)
                    lowestPVCells.insert(currCell);
            }
        }
    }
}

void Sudoku::generateBoard(int difficulty)
{
    Cell *currCell;
    int remainingCount, targetCount, lastRemovedVal;

    switch(difficulty)
    {
        case 1:
            targetCount = 45;
            break;
        default:
            targetCount = 0;
    }

    for(remainingCount = 0; remainingCount < 81; remainingCount++)
    {
        currCell = &board[remainingCount];
        currCell->setBoardVal(currCell->getKeyVal());
    }

    while(remainingCount > targetCount)
    {
        currCell = &board[rand() % 81];
        lastRemovedVal = currCell->getBoardVal();
        currCell->setBoardVal(0);

        if(solver.solve(board, difficulty))
        {
            remainingCount--;
            currCell->setClueStatus(false);
        }
        else
            currCell->fillBoardVal(lastRemovedVal);
    }
}

bool Sudoku::isKeyGenerated()
{
    for(int i = 0; i < 81; i++)
    {
        if(board[i].getKeyVal() == 0)
            return false;
    }
    return true;
}

Cell* Sudoku::getCell(int row, int col) {return &board[9 * row + col];}

int Sudoku::getCellKeyValue(int row, int col) {return board[9 * row + col].getKeyVal();}

int Sudoku::getCellBoardValue(int row, int col) {return board[9 * row + col].getBoardVal();}

bool Sudoku::isWinner()
{
    Cell *currCell;
    for(int i = 0; i < 81; i++)
    {
        currCell = &board[i];
        if(currCell->getBoardVal() != currCell->getKeyVal())
            return false;
    }
    return true;
}


