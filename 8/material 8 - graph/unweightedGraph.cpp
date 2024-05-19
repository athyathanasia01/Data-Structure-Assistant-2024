#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

#define MAX 999

int graph[MAX][MAX];
int n;
char simpul1 = 'A';
char simpul2 = 'A';

//function untuk menambahkan edge
void addEdge(int n){
	int i, j;
	cout << "Beri nilai 1 jika edge di kedua simpul yang terhubung dan 0 jika kedua simpul tidak terhubung" << endl << endl;
	for(i = 0; i < n; i++){
		cout << "Simpul " << simpul1++ << " terhubung dengan : " << endl;
		for (j = 0; j < n; j++){
			cout << "simpul " << simpul2++ << " : ";
			cin >> graph[i][j];
			cout << endl;
		}
		simpul2 = 'A';
		cout << endl;
	}
}

//function untuk mencetak graph
void printGraph(int n){
	cout << "Cetak Adjency Matriks" << endl << endl;
	int i, j;
	cout << "  ";
	simpul1 = 'A';
	simpul2 = 'A';
	for(i = 0; i < n; i++){
		cout << simpul1++ << "  ";
	}
	cout << endl;
	for(i = 0; i < n; i++){
		cout << simpul2++ << "  ";
		for(j = 0; j < n; j++){
			cout << graph[i][j] << "  ";
		}
		cout << endl;
	}
}

//function untuk mencari path terpendek
void searchPath(char x, char y){
	char source = x - 65;
	char destination = y - 65;
	int visited[MAX] = {0};
	int dist[MAX];
	int parent[MAX];
	for(int i = 0; i < n; i++){
		dist[i] = MAX;
		parent[i] = -1;
	}
	
	dist[source] = 0;
	visited[source] = 1;
	parent[source] = -1;
	
	int queue[MAX];
	int front = 0;
	int rear = 0;
	int z = 0;
	
	queue[rear++] = source;
	cout << rear << " " << front;
	while (front != rear) {
		int u = queue[front++];
		for(int v = 0; v < n; v++){
			if(graph[u][v]  && !visited[v]){
				visited[v] = 1;
				
				dist[v] = dist[u] + 1;
				parent[v] = u;
				queue[rear++] = v;
			}
		}
	}
	if(!visited[destination]){
		cout << "Tidak ada jalur dari " << x << " ke " << y << endl;
	} else {
		cout << "Jarak terpendek dari " << x << " ke " << y << " adalah " << dist[destination] << endl;
		
		cout << "Jalur terpendek adalah : ";
		int u = destination;
		while (u != -1){
			simpul1 = 'A';
			simpul1+=u;
			cout << " <-- " << simpul1;
			u = parent[u];
		}
		cout << endl;
	}
}

//function untuk menghapus edge
void deleteEdge(char x, char y){
	int i = x - 65;
	int j = y - 65;
	graph[i][j] = 0;
	graph[j][i] = 0;
	cout << "Garis antara simpul " << x << " dan " << " simpul " << y << " berhasil dihapus!" << endl;
}

//function untuk menghapus vertex
void deleteVertex(char z){
	int v = z - 65;
	if(v > n){
		cout << "Simpul tidak ada" << endl;
		return;
	}
	
	for(int i = v; i < n-1; i++){
		for(int j = 0; j < n; j++){
			graph[i][j] = graph[i+1][j];
		}
	}
	
	n--;
	
	cout << "Simpul " << z << " berhasil dihapus!" << endl;
}

int main(){
	first:
		system("cls");
		char name = 'A', x, y;
		int source, destination, j, i;
		int pil;
		
		cout << "========================================" << endl;
		cout << "             Adjency Matrix             " << endl;
		cout << "========================================" << endl;
		cout << "1. Tambah simpul dan sisi " << endl;
		cout << "2. Print graph " << endl;
		cout << "3. Cari jalur " << endl;
		cout << "4. Hapus simpul " << endl;
		cout << "5. Hapus sisi " << endl;
		cout << "\nMasukkan pilihan : "; cin >> pil;
		
		if(pil == 1){
			system("cls");
			cout << "Masukkan jumlah n : ";
			cin >> n;
			addEdge(n);
			
			cout << endl;
			cout << "Simpul berhasil dibuat." << endl;
			cout << "Tekan apa saja untuk melanjutkan!";
			getch();
			goto first;
		} else if(pil == 2){
			system("cls");
			printGraph(n);
			cout << "\nTekan apa saja untuk melanjutkan!";
			getch();
			goto first;
		} else if(pil == 3){
			system("cls");
			cout << "Mencari jalur terpendek " << endl;
			cout << "Masukkan node asal   : "; cin >> x;
			cout << "Masukkan node tujuan : "; cin >> y;
			searchPath(x, y);
			cout << endl;
			cout << "Tekan apa saja untuk melanjutkan!";
			getch();
			goto first;
		} else if(pil == 4){
			system("cls");
			printGraph(n);
			cout << "\nMenghapus simpul = "; cin >> x;
			deleteVertex(x);
			cout << endl;
			cout << "Tekan apa saja untuk melanjutkan!";
			getch();
			goto first;
		} else if(pil == 5){
			system("cls");
			printGraph(n);
			cout << "\nMenghapus garis antara simpul "; cin >> x;
			cout << " dengan simpul "; cin >> y;
			deleteEdge(x, y);
			cout << endl;
			cout << "Tekan apa saja untuk melanjutkan!";
			getch();
			goto first;
		} else {
			cout << "Input yang anda masukkan salah" << endl;
			char rep;
			cout << "Apakah anda ingin melanjutkan?"; cin >> rep;
			if (rep == 'y' || rep == 'Y'){
				cout << endl;
				cout << "Tekan apa saja untuk melanjutkan!";
				getch();
				goto first;
			} else {
				return 0;
			}
		}
}
