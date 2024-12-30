#include <iostream>
using namespace std;

int main() {
	int a[10] = {32,65,34,74,1,57,85,12,0,5};
	int temp;
	
	cout << "Sebelum diurut\n";
	for(int i=0; i<10; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	
	for(int i=0; i<10-1; i++) {
		for(int j=0;j<10-i-1; j++) {
			cout << a[j] << " " << a[j+1] << endl;
			if(a[j] > a[j+1]) {
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	
	
	
	cout << "\nSetelah diurut\n";
	for(int i=0; i<10; i++) {
		cout << a[i] << " ";
	}
	
	return 0;
}
