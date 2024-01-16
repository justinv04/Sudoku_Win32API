#include "Cell.h"

Cell::Cell()
{
    row = -1, col = -1, box = -1;
    clueStatus = true;
    resetVals();
}

Cell &Cell::operator=(const Cell &RHC)
{
    this->keyValue = RHC.keyValue, this->boardValue = RHC.boardValue;
    this->possibleValues = RHC.possibleValues, this->notedValues = RHC.notedValues;
    this->row = RHC.row, this->col = RHC.col, this->box = RHC.box;
    return *this;
}

void Cell::setIDs(int r, int c, int b) {row = r, col = c, box = b;}

void Cell::setRowCells(Cell* rc[9])
{
    for(int i = 0; i < 9; i++)
        rowCells[i] = rc[i];
}

void Cell::setColCells(Cell* cc[9])
{
    for(int i = 0; i < 9; i++)
        colCells[i] = cc[i];
}

void Cell::setBoxCells(Cell* bc[9])
{
    for(int i = 0; i < 9; i++)
        boxCells[i] = bc[i];
}

void Cell::resetVals()
{
    keyValue = 0, boardValue = 0;
    possibleValues = {1,2,3,4,5,6,7,8,9}, notedValues = {};
}

int Cell::getKeyVal() {return keyValue;}

int Cell::getBoardVal() {return boardValue;}

void Cell::setKeyVal(int val) {keyValue = val;}

void Cell::setBoardVal(int val) {boardValue = val;}

void Cell::setClueStatus(bool status) {clueStatus = status;}

bool Cell::getClueStatus() {return clueStatus;}

std::set<int> Cell::getPVals() {return possibleValues;}

void Cell::setPVals(std::set<int> newPVals) {possibleValues = newPVals;}

void Cell::removePVal(int val) {possibleValues.erase(val);}

void Cell::clearPVals() {possibleValues.clear();}

bool Cell::isPVal(int val)
{
    if(possibleValues.count(val) == 1)
        return true;
    return false;
}

std::set<int> Cell::getNVals() {return notedValues;}

void Cell::setNVals(std::set<int> newNVals) {notedValues = newNVals;}

void Cell::addNVal(int val) {notedValues.insert(val);}

void Cell::removeNVal(int val) {notedValues.erase(val);}

void Cell::clearNVals() {notedValues.clear();}

bool Cell::isNVal(int val)
{
    if(notedValues.count(val) == 1)
        return true;
    return false;
}

Cell** Cell::getRowCells() {return rowCells;}

Cell** Cell::getColCells() {return colCells;}

Cell** Cell::getBoxCells() {return boxCells;}

void Cell::updateCellPVs()
{
    std::set<int> newVals = {1,2,3,4,5,6,7,8,9};
    for(int i = 0; i < 9; i++)
    {
        newVals.erase(rowCells[i]->getKeyVal());
        newVals.erase(colCells[i]->getKeyVal());
        newVals.erase(boxCells[i]->getKeyVal());
    }
    possibleValues = newVals;
}

void Cell::updateCellNVs()
{
    std::set<int> newVals = {1,2,3,4,5,6,7,8,9};
    for(int i = 0; i < 9; i++)
    {
        newVals.erase(rowCells[i]->getBoardVal());
        newVals.erase(colCells[i]->getBoardVal());
        newVals.erase(boxCells[i]->getBoardVal());
    }
    notedValues = newVals;
}

void Cell::updateAffectedPVs()
{
    for(int i = 0; i < 9; i++)
    {
        rowCells[i]->removePVal(keyValue);
        colCells[i]->removePVal(keyValue);
        boxCells[i]->removePVal(keyValue);
    }
    clearPVals();
}

void Cell::updateAffectedNVs()
{
    for(int i = 0; i < 9; i++)
    {
        rowCells[i]->removeNVal(boardValue);
        colCells[i]->removeNVal(boardValue);
        boxCells[i]->removeNVal(boardValue);
    }
    clearNVals();
}

void Cell::fillKeyVal(int val)
{
    setKeyVal(val);
    updateAffectedPVs();
}

void Cell::fillBoardVal(int val)
{
    setBoardVal(val);
    updateAffectedNVs();
}
