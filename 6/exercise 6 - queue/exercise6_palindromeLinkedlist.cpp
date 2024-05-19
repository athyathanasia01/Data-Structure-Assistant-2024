#include <iostream>

using namespace std;

// Node untuk linked list
struct Node {
    char data;
    Node* next;
};

// Class untuk stack yang diimplementasikan menggunakan linked list
class LinkedListStack {
private:
    Node* top;

public:
    LinkedListStack() : top(nullptr) {}

    // Fungsi untuk menambahkan elemen ke stack
    void push(char element) {
        Node* newNode = new Node;
        newNode->data = element;
        newNode->next = top;
        top = newNode;
    }

    // Fungsi untuk menghapus elemen dari stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack kosong, tidak dapat menghapus elemen." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // Fungsi untuk mendapatkan elemen teratas dari stack
    char peek() {
        if (isEmpty()) {
            cout << "Stack kosong." << endl;
            return '\0';
        }
        return top->data;
    }

    // Fungsi untuk memeriksa apakah stack kosong
    bool isEmpty() {
        return top == nullptr;
    }
};

// Fungsi untuk mengecek apakah string merupakan palindrom atau bukan
bool isPalindrome(LinkedListStack& stack, int length) {
    char ch;
    int i = 0;
    
    // Menerima karakter satu per satu dan menambahkannya ke dalam stack
    cout << "Masukkan karakter satu per satu: ";
    while (i < length) {
        cin >> ch;
        stack.push(ch);
        ++i;
    }

    // Membandingkan karakter input dengan karakter teratas stack
    i = 0;
    while (i < length) {
        cin >> ch;
        if (ch != stack.peek()) {
            return false;
        }
        stack.pop();
        ++i;
    }
    return true;
}

int main() {
    int length;
    cout << "Masukkan panjang string: ";
    cin >> length;

    LinkedListStack stack;
    if (isPalindrome(stack, length)) {
        cout << "String merupakan palindrom." << endl;
    } else {
        cout << "String bukan palindrom." << endl;
    }

    return 0;
}

