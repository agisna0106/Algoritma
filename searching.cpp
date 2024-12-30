#include <iostream>
using namespace std;

int main() {
	int a[10] = {32,65,34,74,1,57,85,12,0,5};
	int cari = 2;
	bool  ketemu = 0;
	
	for(int i=0; i<10; i++) {
		if(cari == a[i]) {
			cout << "Nilai ketemu di index ke-" << i;
			ketemu = 1;
			break;
		}
	}
	
	if(ketemu == 0) {
		cout << "Nilai tidak ketemu";
	}
	
	for(int i=0; i<10-1; i++) {
		for(int j=0;j<10-i-1; j++) {
			if(a[j] > a[j+1]) {
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	
	return 0;
}
