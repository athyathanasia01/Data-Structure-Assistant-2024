#include <iostream>
using namespace std;

int maks = 3;
int topA = 3;
int topB = 0;
int topC = 0;
int A[3] = {30, 20, 10};
int B[3] = {0};
int C[3] = {0};
int poppedValue;

void push(char hanoi){
	switch (hanoi){
		case 'A' :
			if (topA >= maks){
				cout << "Data in Hanoi A is full" << endl;
			} else {
				A[topA] = poppedValue;
				topA++;
			}
			break;
		case 'B' :
			if (topB >= maks){
				cout << "Data in Hanoi B is full" << endl;
			} else {
				B[topB] = poppedValue;
				topB++;
			}
			break;
		case 'C' :
			if (topC >= maks){
				cout << "Data in Hanoi C is full" << endl;
			} else {
				C[topC] = poppedValue;
				topC++;
			}
			break;
		default  :
			cout << "You have the wrong entry hanoi tower name!" << endl;
	}
}

bool isEmptyA(){
	if(topA == 0){
		return true;
	} else {
		return false;
	}
}

bool isEmptyB(){
	if(topB == 0){
		return true;
	} else {
		return false;
	}
}

bool isEmptyC(){
	if(topC == 0){
		return true;
	} else {
		return false;
	}
}

void pop(char hanoi){
	switch (hanoi){
		case 'A' :
			if(isEmptyA()){
				cout << "There's no data in tower Hanoi A" << endl;
			} else {
				poppedValue = A[topA-1];
				A[topA-1] = 0;
			}
			break;
		case 'B' : 
			if(isEmptyB()){
				cout << "There's no data in tower Hanoi A" << endl;
			} else {
				poppedValue = B[topB-1];
				B[topB-1] = 0;
			}
			break;
		case 'C' :
			if(isEmptyC()){
				cout << "There's no data in tower Hanoi A" << endl;
			} else {
				poppedValue = C[topC-1];
				C[topC-1] = 0;
			}
			break;
		default  : 
			cout << "You have the wrong entry tower hanoi name!" << endl;
	}
}

void DisplayHanoi(){
	cout << "This is stack of hanoi tower!" << endl;
	cout << "=============================" << endl;
	cout << "Tower A : ";
	for(int i = 0; i < maks; i++){
		if(A[i] != 0){
			cout << A[i] << " -> ";
		}
	}
	cout << endl;
	cout << "Tower B : ";
	for(int i = 0; i < maks; i++){
		if(B[i] != 0){
			cout << B[i] << " -> ";
		}
	}
	cout << endl;
	cout << "Tower C : ";
	for(int i = 0; i < maks; i++){
		if(C[i] != 0){
			cout << C[i] << " -> ";
		}
	}
	cout << endl;
}

int main(){
	DisplayHanoi();
	cout << endl;
	cout << "Memindahkan nilai A ke B" << endl;
	pop('A');
	push('B');
	DisplayHanoi();
	cout << endl;
	cout << "Memindahkan nilai B ke C" << endl;
	pop('B');
	push('C');
	DisplayHanoi();
}
