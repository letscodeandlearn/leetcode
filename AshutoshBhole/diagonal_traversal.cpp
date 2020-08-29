/*
    URL: https://leetcode.com/problems/diagonal-traverse/
    Status: Accepted

*/

#include<iostream>
#include<vector>

using namespace std;


int maxRow, maxCol;

bool isCorrectCoOrdinate(int x, int y) {
    if (x < 0 || x >= maxRow){
        return false;
    }else if( y < 0 || y >= maxCol){
        return false;
    }
    return true;
}


vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    maxRow = matrix.size();
    if(maxRow > 0)
        maxCol = matrix[0].size();

    
    int totElements = maxCol * maxRow;
    int printElem =0;
    vector<int> op;
    
    int row=0, col = 0;
    while(printElem < totElements) {
        
        // Moving up
        for(;isCorrectCoOrdinate(row, col); row--, col++){
            op.push_back(matrix[row][col]);
            cout << matrix[row][col];
            printElem++;
        }
        
        //Correctons before moving down
        // Before diagonal
        if ((row < 0) && ((0 < col )  && (col < maxCol))) {
            row = 0;
            //col +=1;
        }
        // Diagonal
        else if((row < 0) && (col >= maxCol)) {
            row = 1;
            col = maxCol-1;
        }
        // After diagonal
        else if(((0 <= row) && ( row < maxRow )) && (col >=maxCol)) {
            row += 2;
            col =  maxCol-1;
        }
        
        // Moving down
            for(; isCorrectCoOrdinate(row, col); row++, col--){
            op.push_back(matrix[row][col]);
            cout << matrix[row][col];
            printElem++;
        }
        
        //Corrections before going up
        // Before diagoanl
        if(((0 < row) && (row < maxRow)) && ( 0 > col )) {
            //row = row+1;
            col = 0;
        }
        else if ((row >= maxRow) && (col < 0)){
            col = 1;
            row = maxRow-1;
        }
        else if((row >= maxRow) && ((0 <= col) && (col < maxCol))) {
            col +=2;
            row = maxRow-1;
        }
            
    }
    
    return op;
}

int main(){
    vector<int> row1, row2, row3,row4, row5, row6, row7, row8, row9, row10, op;
    row1.push_back(1);
    row2.push_back(2);
    row3.push_back(3);
    row4.push_back(4);

    row5.push_back(5);
    row6.push_back(6);

    row7.push_back(7);
    row8.push_back(8);
    row9.push_back(9);
    row10.push_back(10);

    vector<vector<int>> input;
    input.push_back(row1);
    input.push_back(row2);
    input.push_back(row3);
    input.push_back(row4);
    input.push_back(row5);
    input.push_back(row6);
    input.push_back(row7);
    input.push_back(row8);
    input.push_back(row9);
    input.push_back(row10);

    op = findDiagonalOrder(input);

    cout << "\n";
    for(int i = 0; i < op.size(); i++){
        cout<< op[i] << "\t";
    }
    return 0;
}