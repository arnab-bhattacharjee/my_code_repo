/*
ID: arnabbh1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

int main(){
    ifstream fin("beads.in");
    ofstream fout("beads.out");
    int N;
    fin>>N;
    string str;
    fin>>str;
    int i;
    str+=str;
    //fout<<str<<endl;
    char prev='$',curr,next;int prev_i,next_i;

    int max=0;
    i=0;
    while(str[i]=='w')i++;
    for(;str[i];i++){
        if(str[i]=='r' || str[i]=='b') continue;
        if(str[i]=='w') prev=str[i-1], prev_i=i-1;
        while(str[i]=='w') i++;
        next=str[i], next_i=i;
        if(prev==next) for(int j=prev_i+1;j<next_i;j++) str[j]=prev;
        prev_i=next_i;
        prev=next;
    }
    //fout<<str<<endl;
    
    int mid_i;
    bool flag=false;
    int first;
    i=0;
    while(str[i]){
        if(!flag){
            prev_i=i;
            while(str[i]=='w') {i++;}
	    while(str[i]==str[i+1]) i++;
            i++;
	    mid_i=i;
            while(str[i]=='w') {i++;}
            flag=true;
	    first=i-1;
	    //if(!str[i]) {fout<<str.length()<<endl;return 0;}	
        }
        while(str[i]==str[i+1]) i++;
        i++;
        next_i=i;
        while(str[i]=='w') {i++;}
        if(max<(i-prev_i)){max=i-prev_i;/*fout<<i<<'\t'<<prev_i<<endl;*/}
        prev_i=mid_i;
        mid_i=next_i;
        //fout<<"here"<<endl;
    }
    //cout<<max<<endl;
    if(max>(str.length()>>1)) max=(str.length()>>1);
    
    fout<<max<<endl;
}
