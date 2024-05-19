#include <iostream>

using namespace std;

void compressedCharacter(char input[], int length){
    if(length == 0){
            return;
    }

    char currentChar = input[0];
    int count = 1;

    for(int i = 1; i < length; i++){
        if(input[i] == currentChar){
            count++;
        } else {
            cout << "'" << currentChar << "', '" << count << "', ";
            currentChar = input[i];
            count = 1;
        }
    }

    cout << "'" << currentChar << "', '" << count << "'";
}

int main(){
    int arr_length;
    cout << "Masukkan jumlah array yang diinginkan! ";
    cin >> arr_length;

    char input[arr_length];

    for(int i = 0; i < arr_length; i++){
        cout << "Masukkan nilai array ke-" << i+1;
        cin >> input[i];
        cout << endl;
    }

    cout << "[";
    compressedCharacter(input, arr_length);
    cout << "]" << endl;

    return 0;
}
