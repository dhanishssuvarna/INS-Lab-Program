#include "bits/stdc++.h"
using namespace std;

int randInRange(int low, int high) {
	return rand()%(high-(low+1)) + (low+1);
}

int gcd(int a, int b) {
	return b==0 ? a : gcd(b, a%b);
}

int toint(char c) {
	return (c < 'a') ? (c-'A'+26) : (c-'a');
}

char tochar(int n) {
	return (n >= 26) ? (n+'A'-26) : (n+'a');
}

int powermod(int a, int b, int n) {
	int res = 1;
	for(int i=0; i<b; i++){
		res = (res*a) % n;
	}
	return res;
}

// PU = {e, n}
int encrypt(int M, int PU[2]) {
	return powermod(M, PU[0], PU[1]);
}

int decrypt(int C, int PR[2]) {
	return powermod(C, PR[0], PR[1]);
}


int main() {
	int p, q, e, d, n, phi, pu[2], pr[2];
	vector<int> v;

	cout << "Enter two large prime numbers : ";
	cin>>p>>q;

	n = p*q;
	phi = (p-1)*(q-1);

	do {
		e = randInRange(1,phi);
	}while(gcd(e,phi)!=1);

	for(d=1;d<phi;d++) {
		if((d*e)%phi==1)
			break;
	}

	cout<<"\n";
	cout<<"public key is: {e,n} = "<<"{"<<e<<","<<n<<"}\n";
	cout<<"private key is: {d,n} = "<<"{"<<d<<","<<n<<"}\n";
	cout<<"\n";

	pu[0]=e;pu[1]=n;pr[0]=d;pr[1]=n;
	string msg;

	cout<<"Enter the message to encrypt : ";
	cin>>msg;

	cout<<"Encrypted text :";
	for(int i=0;i<msg.size();i++) {
		int M = toint(msg[i]);
		int C = encrypt(M,pu);
		cout<<C;
		v.push_back(C);
	}
	cout<<"\n";


	msg="";
	for(auto it:v){
		int M = decrypt(it,pr);
		msg += tochar(M);
	}

	cout << "Decrypted message : " << msg << endl;

	return 0;
}
