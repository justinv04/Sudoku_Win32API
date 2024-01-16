#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <algorithm>
#include <ctime>
#include "Cell.h"
#include "SudokuSolver.h"

struct Move
{
    Cell *cell;
    int prevVal, newVal;
};

class Sudoku
{
    private:
        Cell board[81];

        void generateKey();
        void generateBoard(int difficulty);

        bool isKeyGenerated();
        bool isBoardGenerated();
        SudokuSolver solver;

    public:
        Sudoku();
        void startGame();

        Cell* getCell(int row, int col);
        int getCellKeyValue(int row, int col);
        int getCellBoardValue(int row, int col);
        bool isWinner();
};

#endif