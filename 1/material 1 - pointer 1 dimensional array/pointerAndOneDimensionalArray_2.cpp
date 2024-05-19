#include <iostream>
#define clear 14

using namespace std;

int main(){
    char word[] = "Struktur Data sangat menyenangkan!";
    char* pWord = word;

    cout << "Sebelum 14 karakter dilewatkan!" << endl;
    cout << "word  : " << word << endl;
    cout << "pWord : " << pWord << endl;
    cout << endl;

    //melewatkan 14 karakter pertama dari word[]
    pWord += clear;

    cout << "Setelah 14 karakter dilewatkan!" << endl;
    cout << "word  : " << word << endl;
    cout << "pWord : " << pWord << endl;
}
