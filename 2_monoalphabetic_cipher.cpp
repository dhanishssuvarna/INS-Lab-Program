#include<bits/stdc++.h>
using namespace std;
 
string encrypt(string text, unordered_map<char, char> &ump){
   string s="";
   for(int i=0; i<text.size(); i++){
       auto it = ump.find(text[i]);
 
       if(it != ump.end()){
           s+=it->second;
       }
   }
   return s;
}
 
string decrypt(string text, unordered_map<char, char> &ump){
   string s="";
   for(int i=0; i<text.size(); i++){
      
       for(auto it:ump){
           if(it.second == text[i]){
               s+=it.first;
               break;
           }
       }
   }
   return s;
}
 
int main(){
   string key="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQKSTUVWXYZ";
   string value="qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
 
   unordered_map<char, char> ump;
 
   for(int i=0; i<52; i++){
       ump.insert({key[i], value[i]});
   }
 
   string text;
   cout << "Enter the text string : ";
   cin >> text;
 
   string a=encrypt(text, ump);
   string b=decrypt(a, ump);
 
   cout << "encrypted text : " << a << endl;
   cout << "decrypted text : " << b << endl;
 
   return 0;
}
