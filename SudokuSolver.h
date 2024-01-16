#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

#include <iostream>
#include <set>
#include "cell.h"

class SudokuSolver
{
    private:
        Cell board[81];
        bool isSolved;

        bool checkIfSolved();
        void easySolve();
        void mediumSolve();
        void hardSolve();

        void identifyInitialNVs();
        void fillSingleValues(Cell** affectedCells);
        void fillSingleCandidates();
    
    public:
        SudokuSolver();
        bool solve(Cell* board, int difficulty);
};
#endif