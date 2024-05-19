#include <iostream>
using namespace std;

int main(){
	int x = 5;
	int* y;
	y = &x;

	cout << "Nilai variabel x    : " << x << endl;
	cout << "Alamat variabel x   : " << &x << endl;
	cout << "Isi dari variabel y : " << y << endl;
	cout << "Alamat variabel y   : " << &y << endl;
	cout << "Nilai yang terkandung dalam variabel y : " << *y << endl;
}


