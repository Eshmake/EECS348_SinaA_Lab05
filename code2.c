
/* 
Name: Sina Asheghalishahi
KUID: 3127403
LAB Session: Wednesday 9 a.m.
LAB Assignment: 05
Description: Program contains functions for basic matrix operations.
Collaborators: None
*/

#include <stdio.h>

#define SIZE 5

#define COLS1 SIZE
#define COLS2 SIZE

//Matrix Addition Func.
int* addMatrices(int m1[][COLS1], int m2[][COLS2], int rows1, int cols1, int rows2, int cols2){
    int sumMatrix[rows1][cols1];
    if(rows1 != rows2 || cols1 != cols2){
        printf("Invalid dimensions for addition.\n");
        return NULL;
    }
    else{
        for(int i = 0; i < rows1; i++){
            for(int j = 0; j < cols1; j++){
                sumMatrix[i][j] = m1[i][j] + m2[i][j];
            }
        }
    }
    return sumMatrix;
}

//Matrix Multiplication Func.
int* multipyMatrices(int m1[][COLS1], int m2[][COLS2], int rows1, int cols1, int rows2, int cols2){
    int prodMatrix[rows1][cols2];
    
    if(cols1 != rows2){
        printf("Invalid dimensions for multiplication.\n");
    }
    else{
        for(int i = 0; i < rows1; i++){
            for(int j = 0; j < cols2; j++){
                prodMatrix[i][j] = 0;
                for(int c = 0; c < rows2; c++){
                    prodMatrix[i][j] += m1[i][c] * m2[c][j];
                }
            }
        }
    }
    return prodMatrix;
}

//Matrix Transposition Func.
int* transposeMatrix(int m[][COLS1], int rows, int cols){
    int transMatrix[cols][rows];

    for(int j = 0; j < cols; j++){
        for(int i = 0; i < rows; i++){
            transMatrix[j][i] = m[i][j];
        }
    }
    return transMatrix;
}

//Matrix Printing Func.
void printMatrix(int m[][COLS1], int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%-2d ", m[i][j]);
        }
        printf("\n");
    }
}


int main() {
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };


    printf("1st Matrix: \n");
    printMatrix(m1, SIZE, SIZE);

    printf("\n2nd Matrix: \n");
    printMatrix(m2, SIZE, SIZE);

    printf("\nSum of Matrices: \n");
    printMatrix(addMatrices(m1, m2, SIZE, SIZE, SIZE, SIZE), SIZE, SIZE);

    printf("\nProduct of Matrices: \n");
    printMatrix(multipyMatrices(m1, m2, SIZE, SIZE, SIZE, SIZE), SIZE, SIZE);

    printf("\nTranspose of 1st Matrix: \n");
    printMatrix(transposeMatrix(m1, SIZE, SIZE), SIZE, SIZE);

    printf("\nTranspose of 2nd Matrix: \n");
    printMatrix(transposeMatrix(m2, SIZE, SIZE), SIZE, SIZE);

    return 0;
}