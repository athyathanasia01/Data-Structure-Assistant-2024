#include <iostream>
#define maks 20
using namespace std;

//mendeklarasi structure Queue
struct Queue{
	int front, rear; 
	char data[maks];
}Q;

//Mengecek apakah queue penuh
bool isFull() {
	return Q.rear == maks;
}

//mengecek apakah queue kosong
bool isEmpty() {
	return Q.rear == 0;
}

void enqueue(){
	if(isFull()){
		cout << "Queue sudah penuh" << endl;
	} else {
		char data;
		cout << "Masukkan data  : ";
		cin  >> data;
		Q.data[Q.rear] = data;
		
		//Iterasi rear
		Q.rear++;
		
		cout << "Data berhasil ditambahkan \n";
	}
}

bool isPalindrome() {
	int start = 0;
	int end = Q.rear - 1;
	
	while (start < end){
		if (Q.data[start] != Q.data[end]){
			return false;
		}
		++start;
		--end;
	}
	
	return true;
}

int main(){
	int maksData;
	cout << "Masukkan jumlah data : ";
	cin  >> maksData;
	
	for(int i = 0; i < maksData; i++){
		enqueue();
	}
	
	cout << endl;
	
	if(isPalindrome()){
		cout << "Merupakan palindrome" << endl;
	} else {
		cout << "Bukan merupakan palindrome" << endl;
	}
}
