#include <iostream>
#include <windows.h>

using namespace std;

struct mahasiswa{
    string npm;
    string nama;
    struct alamatMahasiswa{
        string kota, kecamatan;
        int kodePos;
    }alamat;
    float ipk;
}mhs;

/*
struct alamatMahasiswa{
    string kota, kecamatan;
    int kodePos;
};

struct mahasiswa{
    alamatMahasiswa alamat;
    string npm;
    string nama;
    float ipk;
}mhs;
*/

int main(){
    cout << "Input" << endl;
    cout << "Nama mahasiswa     : ";
    cin  >> mhs.nama;
    cout << "NPM mahasiswa      : ";
    cin  >> mhs.npm;
    cout << "Alamat mahasiswa   : " << endl;
    cout << "    Kota           : ";
    cin  >> mhs.alamat.kota;
    cout << "    Kecamatan      : ";
    cin  >> mhs.alamat.kecamatan;
    cout << "    Kode Pos       : ";
    cin  >> mhs.alamat.kodePos;
    cout << "IPK mahasiswa      : ";
    cin  >> mhs.ipk;

    system("cls");

    cout << endl << "Output" << endl;
    cout << "Nama mahasiswa     : " << mhs.nama << endl;
    cout << "NPM mahasiswa      : " << mhs.npm << endl;
    cout << "Alamat mahasiswa   : " << endl;
    cout << "    Kota           : " << mhs.alamat.kota << endl;
    cout << "    Kecamatan      : " << mhs.alamat.kecamatan << endl;
    cout << "    Kode Pos       : " << mhs.alamat.kodePos << endl;
    cout << "IPK mahasiswa      : " << mhs.ipk << endl;

    return 0;
}
