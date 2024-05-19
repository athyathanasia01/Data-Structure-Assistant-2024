#include <iostream>
#include <windows.h>

using namespace std;

struct Node {
	int data;
	Node* next;
};

struct Stack {
	Node* top;
	Stack(){
		top = NULL;
	}
	
	void push(int value){
		Node* newNode = new Node;
		newNode->data = value;
		newNode->next = top;
		top = newNode;
		cout << "Nilai " << value << " sudah diinput ke dalam stack.\n";
		system("cls");
	}
	
	void pop(){
		if(top == NULL){
			cout << "Stack sudah kosong.\n";
			return;
		}
		Node* temp = top;
		int poppedValue = top->data;
		top = top->next;
		//delete temp;
		cout << "Nilai " << poppedValue << " sudah dihapus dalam stack.\n";
		system("cls");
	}
	
	void display(){
		if(top == NULL){
			cout << "Stack masih kosong.\n";
			return;
		}
		Node* currentNode = top;
		cout << "Stack: ";
		while (currentNode != NULL){
			cout << currentNode->data << "->";
			currentNode = currentNode->next;
		}
		cout << "NULL" << endl;
	}
};

int main(){
	Stack s;
	int menu, nilai;
	while (true){
		cout << "Menu :\n";
		cout << "1. Push \n";
		cout << "2. Pop \n";
		cout << "3. Tampilkan stack \n";
		cout << "4. Keluar \n";
		cout << "Pilihan : ";
		cin  >> menu;
		
		switch (menu) {
			case 1 :
				cout << "Masukkan nilai yang ingin dipush : ";
				cin  >> nilai;
				s.push(nilai);
				break;
			case 2 : 
				s.pop();
				break;
			case 3 : 
				s.display();
				break;
			case 4 : 
				return 0;
			default : 
				cout << "Pilihan tidak valid. \n";
				break;
		}
	}
}
