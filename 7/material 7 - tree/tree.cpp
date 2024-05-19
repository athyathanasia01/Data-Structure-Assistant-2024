#include <iostream>

using namespace std;

struct Node{
	char label;
	Node *right, *left, *parent;
};

Node *root, *newNode, *cur, *temp;
bool emptyTree(){
	if(root == NULL){
		return true;
	} else {
		return false;
	}
}

void createTree (char label){
	if(root){
		cout << "Tree sudah dibuat" << endl;
	} else {
		root = new Node();
		root -> label  = label;
		root -> left   = NULL;
		root -> right  = NULL;
		root -> parent = NULL;
		cout << label << "Berhasil menjadi root" << endl;
	}
}

Node *insert(char label, Node *node, string child){
	if(emptyTree()){
		cout << "Tree masih kosong, Tolong dibuat dulu!" << endl;
	} else {
		if(child == "left"){
			if (node -> left){
				cout << "Anak bagian kiri dari node " << node -> label << " sudah ada isinya!" << endl;
			} else {
				newNode = new Node();
				newNode -> label  = label;
				newNode -> left   = NULL;
				newNode -> right  = NULL;
				newNode -> parent = node;
				node    -> left   = newNode;
				cout << "Label " << label << " berasil dibuat di anak kiri dari node " << node -> label << endl;
			}
		} if(child == "right"){
			if(node -> right){
				cout << "Anak bagian kanan dari node " << node -> label << " suda ada isinya!" << endl; 
			} else {
				newNode = new Node();
				newNode -> label  = label;
				newNode -> left   = NULL;
				newNode -> right  = NULL;
				newNode -> parent = node;
				node    -> right  = newNode;
				cout << "Label " << label << " berhasil dibuat di anak kanan dari node " << node -> label << endl;
			}
		}
		return newNode;
	}
}

void updateLabel (char label, Node *node){
	if (emptyTree()){
		cout << "Buat tree terlebi dahulu!" << endl;
	} else {
		if (!node){
			cout << "Tidak ada node ini atau masih kosong!" << endl;
		} else {
			cout << "Label sebelumnya = " << node -> label << endl;
			node -> label = label;
			cout << "Label setelahnya = " << node -> label << endl;
		}
	}
}

void retriveLabel (Node *node){
	if(!node){
		cout << "Tidak ada Node ini atau masih kosong" << endl;
	} else {
		cout << "Label dari node ini adalah " << node -> label << endl;
	}
}

void search (Node *node, char label){
	bool find;
	if(!node){
		return;
	} 
	cout << node -> label << " ";
		if (label == node -> label){
			cout << "\nData ditemukan!!\n";
			find = true;
			return;
		} else {
			if (find){
				return;
			} else {
				search (node -> left, label);
			}
			
			if (find){
				return;
			} else {
				search (node -> right, label);
			}
		}
}

void deleteSub (Node *node){
	if (node != NULL){
		if (node != root && node == node -> parent -> left){
			node -> parent -> left = NULL;
		}
		deleteSub (node -> left);
		if (node != root && node == node -> parent -> right){
			node -> parent -> right = NULL;
		}
		deleteSub (node -> right);
		if (node == root){
			root = NULL;
			delete root;
		} else {
			delete node;
		}
	}
}

void clearTree (Node *node){
	if (node != NULL){
		if (node != root && node == node -> parent -> left){
			node -> parent -> left = NULL;
		}
		clearTree (node -> left);
		if (node != root && node == node -> parent -> right){
			node -> parent -> right = NULL;
		}
		clearTree (node -> right);
		if (node == root){
			root = NULL;
			delete root;
		} else {
			delete node;
		}
	}
}

void preOrder (Node *node){
	if (!node){
		return;
	} else {
		cout << node -> label << " ";
		preOrder (node -> left);
		preOrder (node -> right);
 	}
}

void postOrder (Node *node){
	if (!node){
		return;
	} else {
		postOrder (node -> left);
		postOrder (node -> right);
		cout << node -> label << " ";
	}
}

void inOrder (Node *node){
	if (!node){
		return;
	} else {
		inOrder (node -> left);
		cout << node -> label << " ";
		inOrder (node -> right);
	}
}

int main () {
	Node *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeZ;
	
	cout << "Membuat Tree" << endl;
	
	createTree('A');
	
	nodeB = insert('B', root, "left");
	nodeC = insert('C', root, "right");
	nodeZ = insert('Z', root, "left");
	nodeD = insert('D', nodeB, "left");
	nodeE = insert('E', nodeB, "right");
	nodeF = insert('F', nodeC, "right");
	nodeG = insert('G', nodeC, "left");
	
	cout << "\nMembaca secara post order" << endl;
	postOrder(root);
	
	cout << "\nMembaca secara In order" << endl;
	inOrder(root);
	
	cout << "\nMembaca secara Pre Order" << endl;
	preOrder(root);
	
	cout << "\nCari E = "; search(root, 'E');
	
	cout << endl;
	updateLabel('Z', nodeB);
	
	retriveLabel(nodeG);
	
	deleteSub(nodeG);
	
	preOrder(root);
	
	deleteSub(root);
	
	preOrder(root);
	
	if(emptyTree()){
		cout << "\nTree kosong" << endl;
	} else {
		cout << "Tree tidak kosong" << endl;
	}
}
