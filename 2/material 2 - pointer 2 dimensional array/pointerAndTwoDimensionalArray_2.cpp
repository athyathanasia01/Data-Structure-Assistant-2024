#include <iostream>
#include <windows.h> //mengaktifkan perintah gotoxy

#define MAX 10
typedef int matrix[MAX][MAX];

using namespace std;

void gotoxy(short x, short y){
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main(){
    int dimensi = 2;
    matrix A, B, C;

    cout << "Masukkan nilai matrix A" << endl;
    for(int i = 0; i < dimensi; i++){
        for(int j = 0; j < dimensi; j++){
            cout << "Nilai A[" << i << "][" << j << "] : ";
            cin >> A[i][j];
        }
    }

    system("cls");

    cout << "Masukkan nilai matrix B" << endl;
    for(int i = 0; i < dimensi; i++){
        for(int j = 0; j < dimensi; j++){
            cout << "Nilai B[" << i << "][" << j << "] : ";
            cin >> B[i][j];
        }
    }

    system("cls");

    cout << endl;

    for(int i = 0; i < dimensi; i++){
        for(int j = 0; j < dimensi; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    gotoxy(0, 3);
    cout << "Nilai matrix A ";

    gotoxy(0, 5);
    cout << "A = ";
    for(int i = 1; i <= dimensi; i++){
        for(int j = 1; j <= dimensi; j++){
            gotoxy(1+(3*j), 2+(2*i));
            cout << A[i-1][j-1];
        }
    }

    gotoxy(0, 7);
    cout << "Nilai matrix B ";

    gotoxy(0, 9);
    cout << "B = ";
    for(int i = 1; i <= dimensi; i++){
        for(int j = 1; j <= dimensi; j++){
            gotoxy(1+(3*j), 6+(2*i));
            cout << B[i-1][j-1];
        }
    }

    gotoxy(0, 12);
    cout << "Nilai matrix C " << endl;
    gotoxy(0, 14);
    cout << "C = ";
    for(int i = 1; i <= dimensi; i++){
        for(int j = 1; j <= dimensi; j++){
            gotoxy(1+(3*j), 11+(2*i));
            cout << A[i-1][j-1];
        }
    }

    gotoxy(9, 14);
    cout << "+";

    for(int i = 1; i <= dimensi; i++){
        for(int j = 1; j <= dimensi; j++){
            gotoxy(8+(3*j), 11+(2*i));
            cout << B[i-1][j-1];
        }
    }

    gotoxy(3, 17);
    cout << "=";

    for(int i = 1; i <= dimensi; i++){
        for(int j = 1; j <= dimensi; j++){
            gotoxy(1+(3*j), 14+(2*i));
            cout << C[i-1][j-1];
        }
    }

    return 0;
}
