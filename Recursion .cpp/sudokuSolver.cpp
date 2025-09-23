#include<iostream>
using namespace std;

void printSudoku(int sudoku[][9]){
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout<<sudoku[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

bool isSafe(int suduko[9][9], int row, int col,int digit){
    //for checking in vertical col 
    for (int i = 0; i <= 8; i++)
    {
        if (suduko[i][col] == digit)
        {
          return false;
        }
        
    }

    //for checking in horizontal row 
    for (int j = 0; j <= 8; j++)
    {
        if (suduko[row][j] == digit)
        {
          return false;
        }
        
    }

    //for 3X3 grid using starting row and starting col
    int startRow = (row/3)*3; // formula to find the staring roe and col of 3X3 matrix
    int startCol = (col/3)*3;

    for (int i = startRow; i < startRow + 2; i++) // by ading +2 we get the last element of 3X3 matrix
    {
        for (int j = startCol; j < startCol + 2; j++)
        {
            if(suduko[i][j] == digit){
                return false;
            }
        }
        
    }
    return true;
}

bool sudokuSolver(int sudoku[][9], int row, int col){
    //Base case
    if(row == 9){
        printSudoku(sudoku);
        return true;
    }

    int nextRow = row;
    int nextCol = col + 1;
    if(col + 1 == 9){
        nextRow = row + 1;
        nextCol = 0;
    }

    if(sudoku[row][col] != 0){
        return sudokuSolver(sudoku, nextRow, nextCol);
    }

    for(int digit = 1; digit<= 9; digit++){
        if(isSafe(sudoku, row, col, digit)){
            sudoku[row][col] = digit;
            if(sudokuSolver(sudoku, nextRow, nextCol)){
                return true;
            } 
            sudoku[row][col] = 0;
        }
    }
    return false;
}
int main(){ 
    int sudoku[9][9] = {{0,0,8,0,0,0,0,0,0},
                        {4,9,0,1,5,7,0,0,2},
                        {0,0,3,0,0,4,1,9,0},
                        {1,8,5,0,6,0,0,2,0},
                        {0,0,0,0,2,0,0,6,0},
                        {9,6,0,4,0,5,3,0,0},
                        {0,3,0,0,7,2,0,0,4},
                        {0,4,9,0,3,0,0,5,7},
                        {8,2,7,0,0,9,0,1,3}};

    sudokuSolver(sudoku,0 , 0);
    return 0; 
}