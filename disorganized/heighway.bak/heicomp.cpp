#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

vector<bool> h(0);
vector<bool>::iterator i,j;

void dlp(){ for(j=h.begin(); j<h.end(); j++){ cout << *j; }; cout/* << '~' << h.size()*/ << endl; }

//void lp(){ h.push_back(1); i=h.end()-2; while(i>=h.begin()){ h.push_back(!*i--); } }

int main(){
	int k=6;

	h.push_back(0);
	while(--k>0){
		h.push_back(1);
		i=h.end()-2;
		while(i>=h.begin()){ h.push_back(!*i--); }
	}
	dlp();
	return 0;
}
