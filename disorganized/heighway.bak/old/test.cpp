#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

vector<bool> h;
vector<bool>::iterator i,j;
// size = (int) h.size()

void dlp(){ for(j=h.begin(); j<h.end(); j++){ cout << *j; }; cout << endl; }

void lp(){
	dlp(); h.push_back(1); dlp();
	cout << "~:" << endl;
	i=h.end();
	cout << *i << endl;
	while(i!=h.begin()){
		cout << *i << "~" << (int) (i<h.begin()) << (int) (i==h.begin()) << (int) (i>h.begin()) << endl;
	}
	cout << ":~" << endl;
	dlp();
}

int main(){
	h.push_back(0);
	lp(); dlp();
	lp(); dlp();
	lp(); dlp();

	return 0;
}
