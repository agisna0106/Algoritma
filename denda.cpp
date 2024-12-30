#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

int main(){
	int n;
	
	cout<<"Masukan jumlah data yang akan diinputkan : "; cin>>n;
	cout<<endl;
	
	string data[n][3];
	int hari, denda=0;
	bool ket;
	
	for(int i=0; i<n; i++){
		cout<<"Nama Anggota\t\t: "; cin>>data[i][0];
		cout<<"Lama Hari Peminjaman\t: "; cin>>data[i][1];
		
		stringstream s;
		s << data[i][1];
		s >> hari;
		
		int count=hari, jml; 
		
		for(int j=0; j<hari; j++){
			if(count%7==0){
				jml+=1;
				count-=7;
			}
			count--;
		}
		denda=jml*5000;
		
		stringstream stream;
		stream << denda;
		stream >> data[i][2];
	}
	
	cout<<endl;
	
	cout<<"|"<<setw(2)<<left<<"No"
		<<"|"<<setw(20)<<left<<"Nama Anggota"
		<<"|"<<setw(25)<<left<<"Lama Hari Peminjaman"
		<<"|"<<setw(15)<<left<<"Denda (Rp.)"
		<<"|"<<endl;
	for(int i=0; i<n; i++){
		cout<<"|"<<setw(2)<<left<<i+1
			<<"|"<<setw(20)<<left<<data[i][0]
			<<"|"<<setw(25)<<left<<data[i][1]
			<<"|"<<setw(15)<<left<<data[i][2]
			<<"|"<<endl;
	}
	
	return 0;
}





//int n=22, hasil=0;
//	int denda=n;
//	for(int i=1; i<n; i++) {
//		if(denda%7==0){
//			hasil+=1;
//			denda-=7;
//		}
//		denda--;
//		
//	}
//	
//	cout<<hasil*5000;
