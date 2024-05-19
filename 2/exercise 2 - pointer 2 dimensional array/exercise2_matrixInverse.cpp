#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    int n;
    cout << "Masukkan jumlah n matrix : ";
    cin >> n;

    int M[n][n];
    system("cls");

    cout << "Masukkan nilai pada matrix! " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << "M[" << i << "][" << j << "] = ";
            cin >> M[i][j];
            cout << endl;
        }
    }

    system("cls");

    cout << "Tampilan matrix sesungguhnya" << endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "Tampilan matrix inverse" << endl;

    for(int j = 0; j < n; j++){
        for(int i = n-1; i >= 0; i--){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }

}
