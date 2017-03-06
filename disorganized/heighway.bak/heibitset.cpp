#include <iostream>
#include <stdio.h>
#include <bitset>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
using namespace std;

// use enum for left/right "enum turn {right, left}"
int i,k,e;

timespec ini, fin;

int main(int argc, char **argv){
	const int t=6;
	const int s=(1<<t)-1;
	cout << t << ':' << s << endl;
	bitset<s> h;

//	cout << (float)(1/1000000) << endl;
//	double fl=1.0f;
//	for(i=0; i<7; i++){ printf("%f\n",(double)(1/(pow(10,i)))); }

	clock_gettime(CLOCK_REALTIME, &ini);

	h[0]=0; e=0;
	k=t;
	while(--k>0){
		i=e;
		h[++e]=1;
		while(i>-1){
			h[++e]=!h[i--];
		}
	}

	clock_gettime(CLOCK_REALTIME, &fin);

for(int j=0; j<=e; j++){ cout << h[j]; };
cout << endl ;
//<< "Size: " << h.size() << "; Contents: " << h.to_string() << endl;

	cout << "Time: " << (fin.tv_sec-ini.tv_sec) << ":" << (fin.tv_nsec-ini.tv_nsec) << endl;
	return 0;
}
