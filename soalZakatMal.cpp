#include <iostream>
using namespace std;

void Pertanian1(int hasil);
void Pertanian2(int hasil);
void Emas(int emas);
void Uang(int uang);

int main() {
	cout<<"=====Program Penghitung Zakat=====\n";
	int pilih, i, hasilTani, emas, uang;
	string yo, pilihan;
	
	awal :
	cout<<"Menu Zakat Mal <1-3> : \n";
	cout<<"1. Pertanian\n";
	cout<<"2. Emas\n";
	cout<<"3. Uang/Penghasilan\n";
	cout<<"Masukan pilihan -> "; cin>>pilih;
	
	switch (pilih) {
		case 1:
			pilihan:
			cout<<"Apakah pertanian anda menggunakan pengairan sendiri? <y/n>";
			cin>>yo;
			if(yo == "y") {
				cout<<"Masukan Penghasilan pertanian : "; cin>>hasilTani;
				Pertanian1(hasilTani);
			}else if(yo == "n") {
				cout<<"Masukan Penghasilan pertanian : "; cin>>hasilTani;
				Pertanian2(hasilTani);
			}else {
				goto pilihan;
			}
			
			break;
		case 2:
			nominalEmas:
				cout<<"Berapa nominal emas anda jika dirupiahkan : "; 
			cin>>emas;
			if(emas >= 46750000){
				Emas(emas);
			}else if(emas < 46750000) {
				cout<<"Anda tidak perlu zakat\n";
			}else {
				goto nominalEmas;
			}
			
			break;
		
		case 3:
			nominalUang:
				cout<<"Berapa nominal uang/penghasilan anda : ";
			cin>>uang;
			Uang(uang);
			break;
		
		default :
			goto awal;
			
	}
	
	cout<<"Apakah anda ingin kembali ke halaman Utama <y/n>";
	cin>>pilihan;
	if(pilihan == "y") {
		goto awal;
	}
	
	return 0;
}

void Pertanian1(int hasil) {
	int zakat = hasil*(2.5/100);
	cout <<"Penghasilan anda : "<<hasil<<endl 
		 <<"Zakat Anda   	 : "<<zakat<<endl
		 <<"Sisa Penghasilan : "<<hasil-zakat<<endl;
}

void Pertanian2(int hasil) {
	int zakat = hasil*0.1;
	cout <<"Penghasilan anda : "<<hasil<<endl 
		 <<"Zakat Anda   	 : "<<zakat<<endl
		 <<"Sisa Penghasilan : "<<hasil-zakat<<endl;
}

void Emas(int emas) {
	int zakat = emas*0.25;
	cout <<"Harta anda : "<<emas<<endl 
		 <<"Zakat Anda : "<<zakat<<endl
		 <<"Sisa Harta : "<<emas-zakat<<endl;
}

void Uang(int uang) {
	int zakat = uang*0.25;
	cout <<"Uang anda  : "<<uang<<endl 
		 <<"Zakat Anda : "<<zakat<<endl
		 <<"Sisa Uang  : "<<uang-zakat<<endl;
}


