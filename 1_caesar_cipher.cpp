#include<bits/stdc++.h>
using namespace std;
 
string encrypt(string text, int shift){
   string str="";
   for(auto s:text){
       if(islower(s)){
           char c = ((s -'a')+shift)%26+97;
           str+=c;
       }
        else{
        char c = ((s -'A')+shift)%26+65;
        str+=c;
        }
   }
   return str;
}
 
string decrypt(string text, int shift){
   string str="";
   for(auto s:text){
       if(islower(s)){
           char c = ((s -'a')-shift)%26+97;
           str+=c;
       }
       else{
           char c = ((s -'A')-shift)%26+65;
           str+=c;
       }
   }
   return str;
}
 
int main(){
   string text;
   cout << "Enter the text string : ";
   cin >> text;
 
   int shift;
   cout << "Enter the shift : ";
   cin >> shift;
 
   string a=encrypt(text, shift);
   string b=decrypt(a, shift);
 
  
   cout << "encrypted text : " << a << endl;
   cout << "decrypted text : " << b << endl;
}
