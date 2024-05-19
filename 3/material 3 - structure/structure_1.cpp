#include <iostream>
using namespace std;

struct mahasiswa{
    string npm;
    string nama;
    string alamat;
    float ipk;
}mhs;

int main(){
    cout << "Input" << endl;
    cout << "Masukkan NPM \t\t : ";
    cin  >> mhs.npm;
    cout << "Masukkan nama \t\t : ";
    cin  >> mhs.nama;
    cout << "Masukkan alamat \t : ";
    cin  >> mhs.alamat;
    cout << "Masukkan nilai IPK \t : ";
    cin  >> mhs.ipk;

    cout << endl << "Output" << endl;
    cout << "NPM Mahasiswa \t\t : " << mhs.npm << endl;
    cout << "Nama Mahasiswa \t\t : " << mhs.nama << endl;
    cout << "Alamat Mahasiswa \t : " << mhs.alamat << endl;
    cout << "Nilai IPK \t \t : " << mhs.ipk << endl;

    return 0;
}

