#include <iostream>

using namespace std;

struct node{
    int data;
    node* next;
};

int main(){
    //membuat simpul pertama
    node* head = new node();
    head->data = 1;
    head->next = NULL;

    //membuat simpul kedua
    node* second = new node();
    second->data = 2;
    second->next = NULL;

    //menyambungkan simpul pertama dan kedua
    head->next = second;

    //buat simpul ketiga
    node* third = new node();
    third->data = 3;
    third->next = NULL;

    //menyambungkan simpul kedua dan ketiga
    second->next = third;

    node* node = head; //mengarahkan ke simpul pertama untuk kemudian dilooping
    while(node != NULL){
        cout << node->data << " "; //output data pada simpul
        node = node->next; //mengarahkan ke simpul selanjutnya untuk dilooping
    }

    return 0;
}


