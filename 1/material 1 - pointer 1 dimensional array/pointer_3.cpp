#include <iostream>
using namespace std;

int main(){
	int umur;
	int* pUmur;
	int** ppUmur;
	
	cout << "Masukkan umur kalian! ";
	cin >> umur;
	
	cout << "\n============================\n" << endl;
	
	pUmur = &umur;
	ppUmur = &pUmur;
	
	cout << "Nilai umur dari masukkan  : " << umur << endl;
	cout << "Nilai pUmur               : " << *pUmur << endl;
	cout << "Nilai ppUmur              : " << **ppUmur << endl;
}


