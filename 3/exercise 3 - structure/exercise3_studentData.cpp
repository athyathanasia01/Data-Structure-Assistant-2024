#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#define MAX 20

using namespace std;

struct nilai{
    float absen, tugas, uts, uas, nilaiAkhir;
    char indexHuruf;
};

struct mahasiswa{
    string npm, nama;
    nilai score;
};

char nilaiHuruf(float nilaiAkhir){
    if(nilaiAkhir > 80){
        return 'A';
    } else if(nilaiAkhir > 70){
        return 'B';
    } else if(nilaiAkhir > 60){
        return 'C';
    } else {
        return 'D';
    }
}

void inputMahasiswa(mahasiswa mhs[], int& jumlahMahasiswa){
    if(jumlahMahasiswa < MAX){
        cout << "Input Data Mahasiswa " << endl;
        cout << "NPM mahasiswa    : ";
        cin  >> mhs[jumlahMahasiswa].npm;
        cout << "Nama mahasiswa   : ";
        cin  >> mhs[jumlahMahasiswa].nama;
        cout << "Nilai mahasiswa  : " << endl;
        cout << "   Absen         : ";
        cin  >> mhs[jumlahMahasiswa].score.absen;
        cout << "   Tugas         : ";
        cin  >> mhs[jumlahMahasiswa].score.tugas;
        cout << "   UTS           : ";
        cin  >> mhs[jumlahMahasiswa].score.uts;
        cout << "   UAS           : ";
        cin  >> mhs[jumlahMahasiswa].score.uas;

        //hitung nilai akhir
        mhs[jumlahMahasiswa].score.nilaiAkhir =
            (0.1*mhs[jumlahMahasiswa].score.absen) +
            (0.2*mhs[jumlahMahasiswa].score.tugas) +
            (0.3*mhs[jumlahMahasiswa].score.uts) +
            (0.4*mhs[jumlahMahasiswa].score.uas);

        //define index huruf
        mhs[jumlahMahasiswa].score.indexHuruf =
            nilaiHuruf(mhs[jumlahMahasiswa].score.nilaiAkhir);

        jumlahMahasiswa++;
    }
}

void tampilMahasiswa(mahasiswa mhs[], int jumlahMahasiswa){
    cout << "Data Mahasiswa " << endl;
    cout << "===================================================" << endl;
    cout << "NPM       Nama       Nilai Akhir        Index Huruf" << endl;
    cout << "===================================================" << endl;

    for(int i = 0; i < jumlahMahasiswa; i++){
        cout << setiosflags(ios::left) << setw(10) << mhs[i].npm;
        cout << setiosflags(ios::left) << setw(11) << mhs[i].nama;
        cout << setiosflags(ios::left) << setw(19) << mhs[i].score.nilaiAkhir;
        cout << setiosflags(ios::left) << setw(11) << mhs[i].score.indexHuruf;
        cout << endl;
    }
}

void editMahasiswa(mahasiswa mhs[], int jumlahMahasiswa){
    cariLagi:
    string cariNpm;
    cout << "Masukkan NPM yang ingin diubah : ";
    cin  >> cariNpm;

    for(int i = 0; i < jumlahMahasiswa; i++){
        if(mhs[i].npm == cariNpm){
            cout << "Data mahasiswa berhasil ditemukan!" << endl;
            cout << "Ubah data" << endl;
            cout << "Nilai absen baru   : ";
            cin  >> mhs[i].score.absen;
            cout << "Nilai tugas baru   : ";
            cin  >> mhs[i].score.tugas;
            cout << "Nilai UTS baru     : ";
            cin  >> mhs[i].score.uts;
            cout << "Nilai UAS baru     : ";
            cin  >> mhs[i].score.uas;

            mhs[i].score.nilaiAkhir =
                (0.1*mhs[i].score.absen) +
                (0.2*mhs[i].score.tugas) +
                (0.3*mhs[i].score.uts) +
                (0.4*mhs[i].score.uas);

            mhs[i].score.indexHuruf = nilaiHuruf(mhs[i].score.nilaiAkhir);

            system("cls");
            cout << "Data berhasil diubah!" << endl;
            return;
        } else {
            cout << "Data tidak ditemukan!" << endl;
            char ans;
            cout << "Cari lagi?";
            cin  >> ans;
            if(ans == 'Y' || 'y'){
                goto cariLagi;
            } else{
                return;
            }
        }
    }
}

void hapusMahasiswa(mahasiswa mhs[], int& jumlahMahasiswa){
    string cariNpm;
    cout << "Masukkan NPM yang akan dihapus : ";
    cin  >> cariNpm;

    //mengalihkan posisi index ke i (npm yang dihapus) ke i+1
    for(int i = 0; i < jumlahMahasiswa; i++){
        if(mhs[i].npm == cariNpm){
            for(int j = i; j < jumlahMahasiswa - 1; j++){
                mhs[j] = mhs[j+1];
            }
        }
    }

    jumlahMahasiswa--;

    system("cls");

    cout << "Data mahasiswa berhasil dihapus" << endl;
    return;
}

int main(){
    mahasiswa dataMahasiswa[MAX];
    int jumlahMahasiswa = 0;
    int menu;

    do{
        start:
        cout << "Menu -->  1. Input data mahasiswa     " << endl;
        cout << "          2. Tampilkan data mahasiswa " << endl;
        cout << "          3. Edit data mahasiswa      " << endl;
        cout << "          4. Hapus data mahasiswa     " << endl;
        cout << "          5. Keluar                   " << endl;
        cout << "Pilih menu?";
        cin  >> menu;

        switch (menu){
            case 1 :
                inputMahasiswa(dataMahasiswa, jumlahMahasiswa);
                system("cls");
                goto start;
                break;
            case 2 :
                tampilMahasiswa(dataMahasiswa, jumlahMahasiswa);
                getch();
                system("cls");
                goto start;
                break;
            case 3 :
                editMahasiswa(dataMahasiswa, jumlahMahasiswa);
                getch();
                system("cls");
                goto start;
                break;
            case 4 :
                hapusMahasiswa(dataMahasiswa, jumlahMahasiswa);
                getch();
                system("cls");
                goto start;
                break;
            case 5 :
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                goto start;
        }
    }while(menu > 5);

    return 0;
}
