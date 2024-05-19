#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int main(){
    int jumlah_siswa;

    cout << "Masukkan jumlah siswa : ";
    cin >> jumlah_siswa;

    string nama_siswa[jumlah_siswa];

    for(int i = 0; i < jumlah_siswa; i++){
        cout << "Masukkan data nama siswa ke-" << i+1;
        cin >> nama_siswa[i];
        cout << endl;
    }

    system("cls");
    cout << "Nama Siswa        Alamat pada komputer  " << endl;
    cout << "====================================================" << endl;
    for(int i = 0; i < jumlah_siswa; i++){
        cout << setiosflags(ios::left) << setw(18) << nama_siswa[i];
        cout << &nama_siswa[i] << endl;
    }

    cout << endl << "Program ini dibuat oleh : Annisa Intan Nuraini" << endl;

    return 0;
}
