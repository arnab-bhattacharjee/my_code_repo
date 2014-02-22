/*
ID: arnabbh1
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
#define SIZE 300

string convertFromDecimalToBaseB(int n,int b){
    string tmp="";
    while(n/b!=0){
        int rem=n%b;
	if(rem<10) tmp+=(rem+'0');
	else{tmp+=(rem-10)+'A';}
        n=n/b;
    }
    if(n%b<10)tmp+=(n%b)+'0';
    else {tmp+=(n%b-10)+'A';}
    return tmp;
}

bool isPalindrome(string s){
    int l=s.length();
    for(int i=0;i<(l>>1);i++)
        if(s[i]!=s[l-1-i])
            return false;
    return true;
}

int main(){
    ifstream fin("palsquare.in");
    ofstream fout("palsquare.out");
    int a[SIZE];
    for(int i=0;i<SIZE;i++) a[i]=(i+1)*(i+1);
    
    int b[SIZE];
    for(int i=0;i<SIZE;i++) b[i]=i+1;
    
    int n;
    fin>>n;
    string s[SIZE];
    for(int i=0;i<SIZE;i++){
        string tmp=convertFromDecimalToBaseB(a[i],n);
        string c="";
        c=convertFromDecimalToBaseB(b[i],n);
        //cout<<c.length()<<endl;
        if(isPalindrome(tmp)){
            for(int j=c.length()-1;j>=0;j--) fout<<c[j];
            fout<<' '<<tmp<<endl;  
        } 
        //cout<<tmp<<endl;
    }
}