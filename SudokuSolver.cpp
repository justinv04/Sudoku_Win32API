#include "SudokuSolver.h"

SudokuSolver::SudokuSolver() 
{   
    int r, c;
    Cell *currRow[9], *currCol[9], *currBox[9];
    for(r = 0; r < 9; r++)
    {
        for(c = 0; c < 9; c++)
        {
            currRow[c] = &board[9 * r + c];
            currCol[c] = &board[9 * c + r];
            currBox[c] = &board[9*(3*(r/3)+(c/3)) + 3*(r%3)+(c%3)];
        }
        for(c = 0; c < 9; c++)
        {
            board[9 * r + c].setRowCells(currRow);
            board[9 * c + r].setColCells(currCol);
            board[9*(3*(r/3)+(c/3)) + 3*(r%3)+(c%3)].setBoxCells(currBox);
        }
    }
}

bool SudokuSolver::solve(Cell* board, int difficulty)
{

    for(int i = 0; i < 81; i++)
        this->board[i] = board[i];

    isSolved = false;
    identifyInitialNVs();

    switch(difficulty)
    {
        case 1:
            easySolve();
            break;
        case 2:
            mediumSolve();
            break;
        case 3:
            hardSolve();
            break;
        default:
            return false;
    }
    return isSolved;
}


bool SudokuSolver::checkIfSolved()
{
    for(int i = 0; i < 81; i++)
    {
        if(board[i].getKeyVal() != board[i].getBoardVal())
            return false;
    }
    return true;
}

void SudokuSolver::easySolve()
{
    for(int i = 0; i < 9; i++)
        fillSingleValues(board[9 * i].getRowCells());

    fillSingleCandidates();
}

void SudokuSolver::mediumSolve()
{

}

void SudokuSolver::hardSolve()
{

}

void SudokuSolver::identifyInitialNVs()
{
    for(int i = 0; i < 81; i++)
        board[i].updateCellNVs();
}

void SudokuSolver::fillSingleValues(Cell** affectedCells)
{
    std::set<int> currNVals;
    Cell* currCell = affectedCells[0];

    for(int i = 0; i < 9; i++)
    {
        if(isSolved)
            return;

        currCell = affectedCells[i];
        currNVals = currCell->getNVals();
        if(currNVals.size() == 1)
        {
            currCell->fillBoardVal(*currNVals.begin());
            isSolved = checkIfSolved();

            fillSingleValues(currCell->getRowCells());
            fillSingleValues(currCell->getColCells());
            fillSingleValues(currCell->getBoxCells());
        }
    }
}

void SudokuSolver::fillSingleCandidates()
{
    if(isSolved)
        return;
    
    Cell **currBox, *singleCandidateCell;
    int count, val, i, j;
    bool repeatLoop = true;

    while(repeatLoop)
    {
        repeatLoop = false;

        for(val = 1; val < 10; val++)
        {
            for(i = 0; i < 9; i++)
            {
                count = 0;
                currBox = board[27 * (i / 3) + (i % 3)].getBoxCells();

                for(j = 0; j < 9; j++)
                {
                    if(currBox[j]->getNVals().count(val) == 1)
                    {
                        count++;
                        singleCandidateCell = currBox[j];
                    }

                    if(count > 1)
                        break;
                }

                if(count == 1)
                {
                    singleCandidateCell->fillBoardVal(val);
                    fillSingleValues(singleCandidateCell->getRowCells());
                    fillSingleValues(singleCandidateCell->getColCells());
                    fillSingleValues(singleCandidateCell->getBoxCells());
                    repeatLoop = true;
                }
                
                if(isSolved)
                    return;
            }
        }
    }
}


