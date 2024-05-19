#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

int main(){
    int jml, tgl;
    cout << "Masukkan jumlah data yang diinput : ";
    cin >> jml;

    cout << "Masukkan tanggal terakhir         : ";
    cin >> tgl;

    system("cls");

    string nm_brg[jml];
    cout << "Masukkan nama barang" << endl;
    for(int i = 0; i < jml; i++){
        cout << "Barang ke-" << i+1 << " : ";
        cin >> nm_brg[i];
        cout << endl;
    }

    system("cls");

    int arr_brg[tgl][jml];
    for(int i = 0; i < tgl; i++){
        for(int j = 0; j < jml; j++){
            cout << "Jumlah barang " << nm_brg[j] << " tanggal " << i+1 << " : ";
            cin >> arr_brg[i][j];
            cout << endl;
        }
    }

    system("cls");

    cout << "Detail barang " << endl;
    char ans;
    do{
        int angka, nama;
        cout << "Masukkan tanggal     : ";
        cin >> angka;
        cout << endl;
        cout << "Masukkan kode barang : ";
        cin >> nama;

        cout << "=====================================\n";

        cout << "Data tanggal   : " << angka << endl;
        cout << "Nama Barang    : " << nm_brg[nama] << endl;
        cout << "Alamat barang  : " << &arr_brg[angka-1][nama] << endl;

        cout << endl;
        cout << "=====================================\n";

        cout << "Apakah ingin mencari data barang lagi?";
        cin >> ans;
    }while(ans == 'y' || ans == 'Y');
}
