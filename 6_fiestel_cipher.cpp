#include<bits/stdc++.h>
using namespace std;
 
string randKey(int n){
    string key="";
    for (int i = 0; i < n; i++){
        int r = rand()%2;
        key+=(r+48);
    }
    return key;
}
 
string DecimalToBinary(int num, int n) {
    string s="";
    while(num){
        if(num & 1)
            s+='1';
        else
            s+='0';
        num = num >> 1;
    }
 
    int size=s.length();
    for (int i=size; i<n; i++)
        s+='0';
 
    reverse(s.begin(), s.end());
 
    return s;
}
 
int main(){
    string text;
    cout << "Enter the text string : ";
    cin >> text;
 
    int size=text.length();
    int ascii[size];
 
    // Generate Ascii value for each character in text
    for(int i=0; i<size; i++){
        if(islower(text[i]))
            ascii[i]=text[i]-'a'+97;
        else
            ascii[i]=text[i]-'A'+65;
    }
 
    string binary="";
    // Decimal To Binary conversion
    for(int i : ascii){
        // binary += bitset<8>(i).to_string();
        binary += DecimalToBinary(i, 8);
    }
 
    int n=binary.length()/2;
    string l1 = binary.substr(0, n);
    string r1 = binary.substr(n, n);
 
    // Generate random Key
    string k1 = randKey(n);
    string k2 = randKey(n);
 
    string encrypt="";
    string decrypt="";
    string s, s1, s2;
    int K1, K2, L1, R1, L2, R2, L3, R3, L4, R4, L5, R5, L6, R6, f1, f2, f3, f4;
 
    // ---------------- Encrypt Start------------------------
 
    L1 = stoi(l1, 0, 2);
    R1 = stoi(r1, 0, 2);
    K1 = stoi(k1, 0, 2);
    K2 = stoi(k2, 0, 2);
   
    // First round
    f1 = R1^K1;
    R2 = f1^L1;
    L2 = R1;
 
    // Second round
    f2 = R2^K2;
    R3 = f2^L2;
    L3 = R2;
 
    s1 = DecimalToBinary(L3, n);
    s2 = DecimalToBinary(R3, n);
 
    s=s1+s2;
 
    for(int i=0; i<s.length(); i=i+8){
        string s_temp = s.substr(i, 8);
        int n_temp = stoi(s_temp, 0, 2);
        encrypt += n_temp;
    }
 
    // ---------------- Encrypt End------------------------
 
    // ---------------- Decrypt start------------------------
 
    // assign
    L4 = L3;
    R4 = R3;
   
    // First round
    f3 = L4^K2;
    L5 = R4^f3;
    R5 = L4;
   
    // Second round
    f4 = L5^K1;
    L6 = R5^f4;
    R6 = L5;
 
    s1 = DecimalToBinary(L6, n);
    s2 = DecimalToBinary(R6, n);
 
    s=s1+s2;
 
    for(int i=0; i<s.length(); i=i+8){
        string s_temp = s.substr(i, 8);
        int n_temp = stoi(s_temp, 0, 2);
        decrypt += n_temp;
    }
    // ---------------- Decrypt End- -----------------------
 
    cout << "encrypted text : " << encrypt << endl;
    cout << "decrypted text : " << decrypt << endl;
 
    return 0;
}
