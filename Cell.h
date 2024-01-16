#ifndef CELL_H
#define CELL_H

#include <set>
class Cell
{
    private:
        int keyValue, boardValue, row, col, box;
        bool clueStatus;
        std::set<int> possibleValues, notedValues;
        Cell* rowCells[9];
        Cell* colCells[9];
        Cell* boxCells[9];

    public:
        Cell();
        Cell &operator=(const Cell &RHC);

        void setIDs(int r, int b, int c);
        void setRowCells(Cell* rc[9]);
        void setColCells(Cell* cc[9]);
        void setBoxCells(Cell* bc[9]);
        void resetVals();

        int getKeyVal();
        int getBoardVal();

        void setKeyVal(int val);
        void setBoardVal(int val);

        void setClueStatus(bool status);
        bool getClueStatus();

        std::set<int> getPVals();
        void setPVals(std::set<int> newPVals);
        void removePVal(int val);
        void clearPVals();
        bool isPVal(int val);

        std::set<int> getNVals();
        void setNVals(std::set<int> newNVals);
        void addNVal(int val);
        void removeNVal(int val);
        void clearNVals();
        bool isNVal(int val);

        Cell** getRowCells();
        Cell** getColCells();
        Cell** getBoxCells();

        void updateCellPVs();
        void updateCellNVs();
        void updateAffectedPVs();
        void updateAffectedNVs();
        void fillKeyVal(int val);
        void fillBoardVal(int val);
};

#endif