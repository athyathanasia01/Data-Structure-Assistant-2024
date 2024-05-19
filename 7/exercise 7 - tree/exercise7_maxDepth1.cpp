#include <iostream>
using namespace std;

// Definisikan struktur Node untuk pohon biner
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(NULL), right(NULL) {}
};

// Fungsi untuk menambahkan node baru ke pohon biner
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return new Node(data);
    } else {
        Node* temp;
        int level = 1;
        Node* queue[100]; // Ukuran antrian node yang cukup besar
        int front = -1, rear = -1;
        queue[++rear] = root;
        
        while (front != rear) {
            temp = queue[++front];
            if (temp->left != NULL) {
                queue[++rear] = temp->left;
            } else {
                temp->left = new Node(data);
                return root;
            }

            if (temp->right != NULL) {
                queue[++rear] = temp->right;
            } else {
                temp->right = new Node(data);
                return root;
            }
        }
    }
    return root;
}

// Fungsi rekursif untuk mencari kedalaman pohon
int maxDepth(Node* root) {
    if (root == NULL) return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return max(leftDepth, rightDepth) + 1;
}

int main() {
    Node* root = NULL;
    int n, data;
    cout << "Masukkan jumlah node: ";
    cin >> n;
    cout << "Masukkan nilai node:\n";
    for (int i = 0; i < n; ++i) {
        cin >> data;
        root = insertNode(root, data);
    }
    int depth = maxDepth(root);
    cout << "Kedalaman pohon: " << depth << endl;
    return 0;
}

