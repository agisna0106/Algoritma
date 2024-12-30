#include <iostream>
using namespace std;

void show(int n, int *A);
void sorting(int n, int *A);

int main() {
	int n;
	cout << "Masukan jumlah angka yang akan diurutkan : "; cin >> n;
	int A[n];
	
	for(int i=0; i<n; i++) {
		cout << "Masukan Angka ke-" << i+1 <<" : "; cin >> A[i];
	}
	
	cout << "\nAngka sebelum disorting\n";
	show(n,A);
	sorting(n,A);
	cout << "\n\nAngka setelah disorting\n";
	show(n,A);
	
	return 0;
}



void show(int n, int *A) {
	for(int i=0; i<n; i++) {
		cout << A[i] << " ";
	}
}

void sorting(int n, int *A) {
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			if(A[i] < A[j]) {
				int tukar = A[i];
				A[i] = A[j];
				A[j] = tukar;
			}
		}
	}
}
