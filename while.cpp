#include <iostream>
using namespace std;

int main(){
	int angka = -3;
	
//	while (angka > 0) {
//		cout << "Masukkan sebuah angka : ";
//		cin >> angka;
//	}
	
	cout << "\nDO\n";
	do{
		cout << "Masukkan sebuah angka : ";
		cin >> angka;
	} while (angka > 0);
	
	return 0;
}
