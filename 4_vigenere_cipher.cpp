#include<bits/stdc++.h>
using namespace std;
 
string encrypt(string s, string k) {
    string ans="";
 
    for(int i=0; i<s.length();i++){
        int c = 65+(s[i]+k[i])%26;
        ans+=c;
    }
    return ans;
}
 
string decrypt(string s, string k) {
    string ans="";
 
    for(int i=0; i<s.length();i++){
        int c = 65+(s[i]-k[i]+26)%26;
        ans+=c;
    }
    return ans;
}
 
int main() {
    string key = "SECRET";
    string keyword="";
    int size = key.length();
 
    string text;
    cout << "Enter the text string : ";
    cin >> text;
 
    for(int i=0; i<text.length();i++){
        keyword+=key[i%size];
    }
    
    cout << "k : " << keyword << endl;

    string a = encrypt(text, keyword);
    string b = decrypt(a, keyword);
 
    cout << "encrypted text : " << a << endl;
    cout << "decrypted text : " << b << endl;
 
    return 0;
}
