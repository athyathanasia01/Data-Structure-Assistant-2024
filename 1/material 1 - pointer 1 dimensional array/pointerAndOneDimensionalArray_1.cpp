#include <iostream>
using namespace std;

int main(){
	int qty_item[10];
	int* pQty;
	//pQty = qty_item; 
	pQty = &qty_item[0];
	
	for(int i = 0; i < 10; i++){
		cout << "Masukkan jumlah barang ke-" << i+1 << " : ";
		cin >> qty_item[i];
		
		cout << endl;
	}
	
	cout << "\n==============================================\n" << endl;
	
	for(int i = 0; i < 10; i++){
		cout << "Jumlah barang ke-" << i+1 << " : " << *pQty << endl;
		cout << "Alamat barang yang tersimpan   : " << pQty << endl;
		pQty++;
		cout << endl;
	}
}


