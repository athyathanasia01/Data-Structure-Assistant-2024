#include <iostream>

using namespace std;

int maks = 5, top = 0;
string book[5];

void PushBook(string data){
	if(top >= maks){
		cout << "Data is full" << endl;
	} else {
		book[top] = data;
		top++;
	}
}

void DisplayBook(){
	cout << "Book Stack Data" << endl;
	cout << "===============" << endl;
	for(int i = maks-1; i >= 0; i--){
		if(book[i] != ""){
			cout << "Stack no. " << i+1 << " = " << book[i] << endl;
		}
	}
}

int main(){
	PushBook("Sherlock");
	PushBook("Hujan");
	DisplayBook();
	cout << endl;
	
	PushBook("Negeri 5 Menara");
	PushBook("Senja");
	PushBook("Sejarah Dunia");
	DisplayBook();
	cout << endl;
	
	PushBook("Kata");
	DisplayBook();
	
	return 0;
}
