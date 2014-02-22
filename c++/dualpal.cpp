/*
ID: arnabbh1
PROG: dualpal
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
    ifstream fin("dualpal.in");
    ofstream fout("dualpal.out");
    int N,S;
    fin>>N>>S;
    
    int total=0;
   
    for(int i=S+1;;i++){
        string tmp[11];
        int count=0;
        for(int j=2;j<11;j++){
            tmp[j]=convertFromDecimalToBaseB(i,j);
            if(isPalindrome(tmp[j])) count++;
            if(count==2){ fout<<i<<endl, total++; break;}
        }
        if(total==N) return 0;
    }
}