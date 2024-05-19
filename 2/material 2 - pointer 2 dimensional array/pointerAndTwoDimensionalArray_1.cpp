#include <iostream>

using namespace std;

int main(){
    int matrixA[2][2];
    int matrixB[2][2];

    //masukkan nilai matrix A
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << "Masukkan nilai dari matrix A = [" << i << "][" << j << "] : ";
            cin >> matrixA[i][j];
        }
    }

    //output matrix A
    cout << "Matrix A : " << endl;

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << matrixA[i][j] << " ";
        }
        cout << endl;
    }

    //masukkan nilai matrix B
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << "Masukkan nilai dari matrix B = [" << i << "][" << j << "] : ";
            cin >> matrixB[i][j];
        }
    }

    //output matrix B
    cout << "Matrix B : " << endl;

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << matrixB[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << endl;

    //penjumlahan matrix
    int matrixC[2][2];
    cout << "Matrix C = matrix A + matrix B = " << endl;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
            cout << matrixC[i][j] << " ";
        }
        cout << endl;
    }
}
