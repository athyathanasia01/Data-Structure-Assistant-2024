#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

struct dataKtp{
    char nama[50];
    char alamat[50];
    char golonganDarah[2];
    //membuat node next dan node previous
    dataKtp *nextNode, *prevNode;
};

/* menginisiasi node pertama = null
menginisiasi node terakhir = null
menginisiasi pembuatatan node helper
menginiasia pembuatan node baru
*/
dataKtp *first=NULL, *last=NULL, *loopHelper, *newNode;

void inputDataDepan(){
    newNode = new dataKtp;
    newNode->nextNode = NULL;
    newNode->prevNode = NULL;
    cout << "Nama           : ";
    cin  >> newNode->nama;
    cout << "Alamat         : ";
    cin  >> newNode->alamat;
    cout << "Golongan darah : ";
    cin  >> newNode->golonganDarah;
    if(first == NULL){
        first = last = newNode;
    } else {
        newNode->nextNode = first;
        first->prevNode = newNode;
        first = newNode;
    }

    system("cls");
}

void inputDataBelakang(){
    newNode = new dataKtp;
    newNode->nextNode = NULL;
    newNode->prevNode = NULL;
    cout << "Nama           : ";
    cin  >> newNode->nama;
    cout << "Alamat         : ";
    cin  >> newNode->alamat;
    cout << "Golongan darah : ";
    cin  >> newNode->golonganDarah;
    if(first == NULL){
        first = last = newNode;
    } else {
        last->nextNode = newNode;
        newNode->prevNode = last;
        last = newNode;
    }

    system("cls");
}

void outputData(){
    loopHelper = first;
    while(loopHelper != NULL){
        cout << "Nama           : " << loopHelper->nama << endl;
        cout << "Alamat         : " << loopHelper->alamat << endl;
        cout << "Golongan darah : " << loopHelper->golonganDarah << endl;
        cout << endl;
        loopHelper = loopHelper->nextNode;
    }
}

int main(){
    int choose;
    do{
        cout << "-----------DATA KTP MANUSIA-----------" << endl;
        cout << "Pilih menu : " << endl;
        cout << "1. Input data di depan " << endl;
        cout << "2. Input data di belakang " << endl;
        cout << "3. Output data " << endl;
        cout << "--------------------------------------" << endl << endl;
        cin  >> choose;

        switch(choose){
            case 1:
                inputDataDepan();
                break;
            case 2:
                inputDataBelakang();
                break;
            case 3:
                if(first == NULL){
                    cout << "Data masih kosong! " << endl;
                    getch();
                } else {
                    outputData();
                    getch();
                }
                system("cls");
                break;
            default :
                cout << "----------EXIT----------" << endl;
                break;
        }
    }while(choose <= 3);

    return 0;
}
