#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string inputArray[] = { "b", "a", "b", "b", "a", "c", "c" };
    int inputSize = sizeof(inputArray) / sizeof(inputArray[0]);

    string outputArray[inputSize * 2]; // Maksimum ukuran adalah dua kali inputSize
    int outputSize = 0;
    int count = 1;

    for (int i = 1; i < inputSize; i++) {
        if (inputArray[i] == inputArray[i - 1]) {
            count++;
        } else {
            outputArray[outputSize++] = inputArray[i - 1];
            stringstream ct;
            ct << count;
            outputArray[outputSize++] = ct.str();
            count = 1;
        }
    }

    // Menangani elemen terakhir
    outputArray[outputSize++] = inputArray[inputSize - 1];
    stringstream ct;
    ct << count;
    outputArray[outputSize++] = ct.str();

    // Menampilkan output
    cout << "[ ";
    for (int i = 0; i < outputSize; i++) {
        cout << "'" << outputArray[i] << "', ";
    }
    cout << "]" << endl;

    // Menampilkan panjang array sebelum dan sesudah
    cout << "Panjang array sebelum = " << inputSize << ", ";
    cout << "Panjang array sesudah = " << outputSize << endl;

    return 0;
}
