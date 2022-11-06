#include<bits/stdc++.h>
using namespace std;
 
string encrypt(string s, char mtx[5][5]) {
    string ans = "";
    string temp = "";
    int n = s.length();
    int ind = 0;
    int x_1, y_1, x_2, y_2;
 
    while (ind < n) {
        temp = s[ind];
        if (ind == n - 1) {
            temp += 'X';
        }
        else {
            if (s[ind] == s[ind + 1])
                temp += 'X';
            else
                temp += s[++ind];
        }
        ++ind;
 
        x_1 = y_1 = x_2 = y_2 = -1;
 
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (x_1 != -1 && x_2 != -1)
                    break;
                else {
                    if (mtx[i][j] == temp[0]) {
                        x_1 = i;
                        y_1 = j;
                    }
                    if (mtx[i][j] == temp[1]) {
                        x_2 = i;
                        y_2 = j;
                    }
                }
            }
            if (x_1 != -1 && x_2 != -1)
                break;
        }
 
        // same row
        if (x_1 == x_2) {
            ans += mtx[x_1][((y_1 + 1) % 5)];
            ans += mtx[x_2][((y_2 + 1) % 5)];
        }
 
        // same col
        else if (y_1 == y_2) {
            ans += mtx[((x_1 + 1) % 5)][y_1];
            ans += mtx[((x_2 + 1) % 5)][y_2];
        }
 
        // Rectangle Swap
        else {
            ans += mtx[x_1][y_2];
            ans += mtx[x_2][y_1];
        }
    }
    return ans;
}
 
string decrypt(string s, char mtx[5][5]) {
    string ans = "";
    string temp = "";
    int n = s.length();
    int ind = 0;
    int x_1, y_1, x_2, y_2;
 
    while (ind < n) {
        temp = s[ind];
        if (ind == n - 1) {
            temp += 'X';
        }
        else {
            if (s[ind] == s[ind + 1])
                temp += 'X';
            else
                temp += s[++ind];
        }
        ++ind;
 
        x_1 = y_1 = x_2 = y_2 = -1;
 
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (x_1 != -1 && x_2 != -1)
                    break;
                else {
                    if (mtx[i][j] == temp[0]) {
                        x_1 = i;
                        y_1 = j;
                    }
                    if (mtx[i][j] == temp[1]) {
                        x_2 = i;
                        y_2 = j;
                    }
                }
            }
            if (x_1 != -1 && x_2 != -1)
                break;
        }
 
        // same row
        if (x_1 == x_2) {
            ans += mtx[x_1][(((y_1 - 1) % 5) < 0) ? 4 : ((y_1 - 1) % 5)];
            ans += mtx[x_2][(((y_2 - 1) % 5) < 0 ) ? 4 : ((y_2 - 1) % 5)];
        }
 
        // same col
        else if (y_1 == y_2) {
            ans += mtx[(((x_1 - 1) % 5) < 0) ? 4 : ((x_1 - 1) % 5)][y_1];
            ans += mtx[(((x_2 - 1) % 5) < 0) ? 4 : ((x_2 - 1) % 5)][y_2];
        }
 
        // Rectangle Swap
        else {
            ans += mtx[x_1][y_2];
            ans += mtx[x_2][y_1];
        }
    }
    return ans;
}
 
int main() {
    string key = "MONARCHY";
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int k_size = key.length();
    int a_size = 26;
    int k_ind = 0;
    int a_ind = 0;
 
    unordered_map<char, int> ump;
 
    for (int i = 0; i < k_size; i++) {
        ump[key[i]] = i;
    }
 
    char mtx[5][5];
 
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (k_ind < k_size) {
                mtx[i][j] = key[k_ind];
                k_ind++;
            }
            else {
                if (alpha[a_ind] == 'J') {
                    j--;
                    a_ind++;
                    continue;
                }
                auto it = ump.find(alpha[a_ind]);
                if (it == ump.end()) {
                    mtx[i][j] = alpha[a_ind];
                }
                else
                    j--;
                a_ind++;
            }
        }
    }
 
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << mtx[i][j] << " ";
        }
        cout << endl;
    }
 
    string text;
    cout << "Enter the text string : ";
    cin >> text;
 
    string a = encrypt(text, mtx);
    string b = decrypt(a, mtx);
 
    cout << "encrypted text : " << a << endl;
    cout << "decrypted text : " << b << endl;
 
    return 0;
}
