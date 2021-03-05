#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class liczby_polpierwsze {
	ifstream plik;
	
public:
	liczby_pierwsze();
	~liczby_pierwsze();
	void wczyt();
	bool sprawdzenie(int);
	
};
liczby_pierwsze::liczby_pierwsze() {
plik.open("ciagi.txt");
}

void liczby_pierwsze::wczyt() {
	
	vector <int> pierwsze;
	string ciag;
	int dec;
	if(plik.good()) {
		
	while(!plik.eof()) {
		
		plik>>ciag;
		bitset<32> bin(ciag);
		dec = bin.to_ulong();
		if(this->sprawdzenie(dec)) {
			pierwsze.push_back(dec);
		}
		
	}	
		
}
	
cout<<pierwsze.size()<<"\n";
cout<<"min: "<< *min_element(pierwsze.begin(), pierwsze.end())<<"\n"; 
cout<<"max: "<< *max_element(pierwsze.begin(), pierwsze.end()); 
}

bool liczby_pierwsze::sprawdzenie(int ciag) {
vector <int> dzielniki;
for(int i=2; i<=ciag/2; i++) {
	int c=ciag;
	while(c%i==0){
		c=c/i;
		dzielniki.push_back(c);
	}
}
	
	if(dzielniki.size()==2) {
	return true;
	}
	else {
	return false;
	}
}

liczby_pierwsze::~liczby_pierwsze() {
	plik.close();
}



int main(int argc, char** argv) {
liczby_pierwsze c;
c.wczyt();
return 0;
}
