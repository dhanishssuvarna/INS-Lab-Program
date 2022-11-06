#include<bits/stdc++.h>
using namespace std;

int powermod(int a, int b, int n) {
	int res = 1;
	for(int i=0; i<b; i++){
		res = (res*a) % n;
	}
	return res;
}

int proot(int q){
	int flag=0;
	for(int i=1;i<q;i++){
		unordered_set<int> s;

		for(int j=1;j<q;j++){
			int t = powermod(i,j,q);

			if(s.insert(t).second==0){
				flag=1;
				break;
			}
		}
		if(flag==1){
			flag=0;
			continue;
		}else{
			return i;
		}
	}
	return -1;
}

int main() {
    int q, a, Pa, Pb, x, y, b, ka, kb;

	cout << "Enter a prime number : ";
	cin >> q;

	a = proot(q);

	if(a<0){
		cout << "Primitive Root does not exist" << endl;
		exit(0);
	}

	cout << "Primitive Root is : " << a << endl;

	cout << "Enter Private Key of Alice : ";
	cin >> Pa;

	cout << "Enter Private Key of Bob : ";
	cin >> Pb;

    x = powermod(a, Pa, q);
    y = powermod(a, Pb, q);

    ka = powermod(y, Pa, q);
    kb = powermod(x, Pb, q);

    cout << "Secret key for the Alice is : " << ka << endl;
    cout << "Secret key for the Alice is : " << kb << endl;

    return 0;
}
