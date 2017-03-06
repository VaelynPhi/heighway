#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

vector<bool> h(0);
vector<bool>::iterator i,j;
// size = (int) h.size()

void dlp(){
// for(j=h.begin(); j<h.end(); j++){ cout << *j; };
 cout << '~' << h.size() << endl;
}

void lp(){
 h.push_back(1);
 i=h.end()-2;
 while(i>=h.begin()){ h.push_back(!*i--); }
}

int main(){
	h.push_back(0);
	dlp();
	lp(); dlp();
	return 0;
}
