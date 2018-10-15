//
// Created by jallport on 10/9/2017.
//
#include <algorithm>
#include "matrix.h"


using namespace std;



matrix::matrix(int rows, int cols){
    m_rows=rows;
    m_cols=cols;
    setArray0(m_rows,m_cols);

    setArray(m_rows,m_cols);

}




int matrix::getRandom(){
    int min=3;
    int max=9;

    return (min +(rand()%(int)(max-min)));
}

// Creates a matrix of 0s
void matrix::setArray0(int rows,int cols) {
    char matrix[rows][cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = '0';
            cout << " ";
            cout << matrix[i][j];
        }
        cout << endl;
    }
    cout<<endl;
}
// Creates matrix of 0s with 5 random xs
void matrix::setArray(int rows, int cols){
    int count=0;
    char matrix[rows][cols];

    // sets the position of the Xs
    for (int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(count<5 ){
                int arow= rand() % (rows);
                int acol= rand() % (cols);

                if (matrix[arow][acol]!='X'){
                    matrix[arow][acol] = 'X';
                    count++;
                }//if


            }//if
            //sets the 0s in the matrix
            if(matrix[i][j]!='X') {
                matrix[i][j] = '0';
            }//if
        }//for
    }//for

    // prints hte matrix.
    for(int L=0;L<rows;L++){
        for(int M=0;M<cols;M++){
            cout<<" ";
            cout<<matrix[L][M];
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

