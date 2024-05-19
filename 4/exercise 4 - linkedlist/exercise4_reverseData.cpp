#include <iostream>
#include <windows.h>

using namespace std;

struct dataNum{
    int number;
    dataNum *nextNode, *prevNode;
};

dataNum *first=NULL, *last=NULL, *helper, *newNode;

void inputData(int i){
    newNode = new dataNum;
    newNode->nextNode = NULL;
    newNode->prevNode = NULL;
    cout << "Data ke-" << i+1 << " : ";
    cin  >> newNode->number;
    if(first == NULL){
        first = last = newNode;
    } else {
        last->nextNode = newNode;
        newNode->prevNode = last;
        last = newNode;
    }

    system("cls");
}

void outputDataNonReverse(){
    helper = first;
    while(helper != NULL){
        cout << helper->number << " ";
        helper = helper->nextNode;
    }
}

void outputDataReverse(){
    helper = last;
    while(helper != NULL){
        cout << helper->number << " ";
        helper = helper->prevNode;
    }
}

int main(){
    int jumlah;
    cout << "Masukkan jumlah data : ";
    cin  >> jumlah;

    for(int i = 0; i < jumlah; i++){
        inputData(i);
    }

    system("cls");

    cout << "Output data " << endl;
    cout << "Normal     : ";
    outputDataNonReverse();
    cout << endl;
    cout << "Reverse    : ";
    outputDataReverse();
    cout << endl;

    return 0;
}
