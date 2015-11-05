//
// Created by duong.thanh.tung on 11/5/2015.
//

#include "ItemMatrix.hpp"


ItemMatrix::ItemMatrix() : vallue(0), collum(0), row(0) {
    matrix->collum = 0;
    matrix->row = 0;
    matrix->vallue = 0;
}

ItemMatrix::ItemMatrix(uint64_t collum, uint64_t row, uint64_t value) :
        vallue(value), collum(collum), row(row) {
    matrix->vallue = value;
    matrix->collum = collum;
    matrix->row = row;
};

void ItemMatrix::setCollum(uint64_t collum) {
    this->collum = collum;
    matrix->collum = this->collum;
}

void ItemMatrix::setRow(uint64_t row) {
    this->row = row;
    matrix->row = this->row;
}

void ItemMatrix::setValue(uint64_t value) {
    this->vallue = value;
    matrix->value = this->vallue;
}

uint64_t Matrix::getCollum() {
    return collum;
}

uint64_t Matrix::getRow() {
    return row;
}

uint64_t Matrix::getValue() {
    return vallue;
}