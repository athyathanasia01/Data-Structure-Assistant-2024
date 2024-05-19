#include <iostream>
using namespace std;

int main(){
    int x, y;
    int* px;

    x = 77;
    y = x;
    px = &x;

    cout << "Nilai x  : " << x << endl;
    cout << "Nilai y  : " << y << endl;
    cout << "Alamat x : " << &x << endl;
    cout << "Alamt x yang disimpan pada px : " << px << endl;
    cout << "Nilai px : " << *px << endl;
}
