#include<bits/stdc++.h>
using namespace std;
#define N 3

void getCofactor(int A[N][N], int temp[N][N], int p, int q, int n) {
    int i = 0, j = 0;
 
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = A[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinant(int A[N][N], int n) {
    int D = 0;

    if (n == 1)
        return A[0][0];
 
    int temp[N][N];
    int sign = 1;
 
    for (int f = 0; f < n; f++) {
        getCofactor(A, temp, 0, f, n);
        D += sign * A[0][f] * determinant(temp, n - 1);
 		sign = -sign;
    }
    return D;
}

void adjoint(int A[N][N], int adj[N][N]) {
    if (N == 1) {
        adj[0][0] = 1;
        return;
    }
 
    int sign = 1, temp[N][N];
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            getCofactor(A, temp, i, j, N);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = (sign) * (determinant(temp, N - 1));
        }
    }
}
 
bool inverse(int A[N][N], int adj[N][N], int inverse[N][N]) {
    int det = determinant(A, N);
    if (det == 0) {
        cout << "Singular matrix, can't find its inverse";
        return false;
    }
	det<0 ? (det=(det%26)+26) : det = det%26;
	cout << "Det : " << det << endl;

    adjoint(A, adj);

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			(adj[i][j] < 0) ? (adj[i][j] = (adj[i][j]%26) + 26) : (adj[i][j] = adj[i][j]%26);
		}
	}

	int k=0;
	for(k=1;k<26;k++) {
		if((k*det)%26==1)
			break;
	}
 
    for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			inverse[i][j] = (adj[i][j] * k) % 26;
		}
	}        
    return true;
}


string encrypt(int cipherMatrix[][1], int keyMatrix[][3], int messageVector[][1]) {
	string ans="";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 1; j++) {
			cipherMatrix[i][j] = 0;
			for (int k = 0; k < 3; k++) {
				cipherMatrix[i][j] += keyMatrix[i][k] * messageVector[k][j];
			}
			cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
		}
	}

	for (int i = 0; i < 3; i++)
		ans += cipherMatrix[i][0] + 65;

	return ans;
}


string decrypt(int cipherMatrix[][1], int invKeyMatrix[][3]) {
	string ans="";
	int messageVector[3][1];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 1; j++) {
			messageVector[i][j] = 0;
			for (int k = 0; k < 3; k++) {
				messageVector[i][j] += invKeyMatrix[i][k] * cipherMatrix[k][j];
			}
			messageVector[i][j] = messageVector[i][j] % 26;
		}
	}

	for (int i = 0; i < 3; i++)
		ans += messageVector[i][0] + 65;

	return ans;
}

int main() {
	string message;
	string key;
	string a, b;

	// cout << "Enter the Message : " << endl;
	// cout << "Enter the Key : " << endl;

	message = "ACT";
	key = "GYBNQKURP";

	int keyMatrix[3][3];
	int k = 0;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++) {
			keyMatrix[i][j] = (key[k]) % 65;
			k++;
		}
	}

	cout << "Key Matrix : " << endl;
	for (int i = 0; i <3; i++){
		for (int j = 0; j < 3; j++)
			cout << keyMatrix[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	int messageMatrix[3][1];
	for (int i = 0; i < 3; i++)
		messageMatrix[i][0] = (message[i]) % 65;

	int cipherMatrix[3][1];
	a = encrypt(cipherMatrix, keyMatrix, messageMatrix);

	int adj[3][3];
	int invKeyMatrix[3][3];

	if (!inverse(keyMatrix, adj, invKeyMatrix))
		exit(0);
		
	b = decrypt(cipherMatrix, invKeyMatrix);

	cout << endl << "Inverse Key Matrix : " << endl;
	for (int i = 0; i <3; i++){
		for (int j = 0; j < 3; j++)
			cout << invKeyMatrix[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	
	cout << "encrypted text : " << a << endl;
    cout << "decrypted text : " << b << endl;

	return 0;
}