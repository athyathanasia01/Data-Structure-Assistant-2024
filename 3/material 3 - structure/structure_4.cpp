#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

struct alamatMahasiswa{
    string kota, kecamatan;
    int kodePos;
};

struct mahasiswa{
    string nama;
    string npm;
    float ipk;
    alamatMahasiswa alamat;
};

int main(){
    int jumlah;
    cout << "Masukkan jumlah mahasiswa   : ";
    cin  >> jumlah;

    mahasiswa mhs[jumlah];

    for(int i = 0; i < jumlah; i++){
        cout << "Masukkan data mahasiswa ke-" << i+1 << endl;
        cout << "Nama mahasiswa     : ";
        cin  >> mhs[i].nama;
        cout << "NPM mahasiswa      : ";
        cin  >> mhs[i].npm;
        cout << "Alamat mahasiswa   : " << endl;
        cout << "    Kota           : ";
        cin  >> mhs[i].alamat.kota;
        cout << "    Kecamatan      : ";
        cin  >> mhs[i].alamat.kecamatan;
        cout << "    Kode Pos       : ";
        cin  >> mhs[i].alamat.kodePos;
        cout << "IPK mahasiswa      : ";
        cin  >> mhs[i].ipk;

        system("cls");
    }

    cout << "Data Mahasiswa" << endl;
    cout << "=========================================================================" << endl;
    cout << "Nama       NPM         Kota          Kecamatan       Kode Pos        IPK " << endl;
    cout << "=========================================================================" << endl;
    for(int i = 0; i < jumlah; i++){
        cout << setiosflags(ios::left) << setw(11) << mhs[i].nama;
        cout << setiosflags(ios::left) << setw(12) << mhs[i].npm;
        cout << setiosflags(ios::left) << setw(14) << mhs[i].alamat.kota;
        cout << setiosflags(ios::left) << setw(16) << mhs[i].alamat.kecamatan;
        cout << setiosflags(ios::left) << setw(16) << mhs[i].alamat.kodePos;
        cout << setiosflags(ios::left) << setw(4) << mhs[i].ipk;
        cout << endl;
    }
}
