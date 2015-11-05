//
// Created by duong.thanh.tung on 11/5/2015.
//
#include <stdint.h>

typedef struct {
    uint64_t collum;
    uint64_t row;
    uint64_t value;
} Matrix;

class ItemMatrix {
private:
    Matrix *matrix;
    uint64_t collum;
    uint64_t row;
    uint64_t vallue;
public:
    ItemMatrix();

    ItemMatrix(uint64_t collum, uint64_t row, uint64_t value);

    void setCollum(uint64_t collum);
    void setRow(uint64_t row);
    void setValue(uint64_t value);

    uint64_t getCollum();
    uint64_t getRow();
    uint64_t getValue();
};