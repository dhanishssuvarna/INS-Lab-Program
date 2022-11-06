#include "bits/stdc++.h"
using namespace std;

int main() {
	int pr=128, pu, p, k=99;

	cout<<"Select a number within the finite field : "; // point on the curve
	cin>>p;

	pu = p*pr;
	cout<<"the public key is: "<< pu << endl;

	string s;
	cout<<"Enter the message : ";
	cin>>s;

	int c1 = k*p;

	vector<int> c2;
	for(auto it:s) {
		c2.push_back(it+k*pu);
	}

	cout<<"Encrypted text C1 & C2" << endl;
	cout << "C1 : " << c1 << endl;
	cout << "C2 : ";
	for(auto it:c2)
		cout<<it<<" ";
	cout<<endl;

	string m="";
	for(auto it:c2){
		m+=it-pr*c1;
	}

	cout<<"Decrypted text : " << m << endl;
	return 0;
}
