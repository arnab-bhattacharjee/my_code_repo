#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define SIZE 1000000
#define REP(i,x) for(int i=0;i<x;i++)

int main() {
  int a=103993;
  int b=33102;
 
  char aftDec[SIZE+1];
  
  int befDec=a/b;
  int rem=(a%b)*10;
  

  REP(i,SIZE) {
  while(rem<b) {rem*=10;aftDec[i++]='0';}
  aftDec[i]='0'+(rem/b);
  rem=rem%b;rem*=10;
  }
  aftDec[SIZE]='\0';
  
  int t;int num;
  scanf("%d",&t);
  while(t--) {
    scanf("%d",&num);
    if(num==0) printf("3\n");
    else printf("3.%.*s\n",num,aftDec);
  }
}