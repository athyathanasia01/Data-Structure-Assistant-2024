#include <iostream>
#include <conio.h>
#include <windows.h>

#define Nmaks 10
using namespace std;

typedef int matrik[Nmaks][Nmaks];

void gotoxy(short x, short y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main()
{
    int n,i,j;
    matrik A,B,C;

    cout<<"Program Perkalian Matrik A 2x2 dan B 2x2"<<endl;
    cout<<endl;

    n=2;
    cout<<"MAsukkan Nilai-Nilai Matrik A"<<endl;
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=n; j++)
        {
            cout<<"A["<<i<<","<<j<<"] = ";
            cin>>A[i][j];
        }
    }

    system("cls");
    cout<<"Masukkan Nilai-Nilai Matrik B"<<endl;
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=n; j++)
        {
            cout<<"B["<<i<<","<<j<<"] = ";
            cin>>B[i][j];
        }
    }

    system("cls");
    cout<<endl;

    for (j=1; j<=n; j++)
    {
        C[i][j] = (A[i][1]*B[1][j]) + (A[i][2]*B[2][j]);
    }


    system("cls");
    cout<<"Nilai-nilai matriks A, B, dan C"<<endl;
    cout<<endl;

    gotoxy(1,5);
    cout<<"A = ";
    for (i=1; i<=n; i++)
    {

        for (j=1; j<=n; j++)
        {
            gotoxy(2+4*j,2+2*i);
            cout<<A[i][j];
        }
    }

    gotoxy(1,10);
    cout<<"B = ";
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=n; j++)
        {
            gotoxy(2+4*j,7+2*i);
            cout<<B[i][j];
        }
    }

    gotoxy(1,15);
    cout<<"C = ";
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=n; j++)
        {
            gotoxy(2+4*j,12+2*i);
            cout<<A[i][j];
        }
    }

    gotoxy(12,15);
    cout<<" x ";
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=n; j++)
        {
            gotoxy(13+4*j,12+2*i);
            cout<<B[i][j];
        }
    }

    gotoxy(23,15);
    cout<<" = ";
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=n; j++)
        {
            gotoxy(24+4*j,12+2*i);
            cout<<C[i][j];
        }
    }
}
