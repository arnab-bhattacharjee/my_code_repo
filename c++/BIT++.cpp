#include <cstdio>
#include <string.h>

#define REP(i,x) for(int i=0;i<x;i++)
#define LL long long
#define SIZE 1000001

int main() {
  char* a=new char[SIZE];
  char* b=new char[SIZE];
  memset(a,0,sizeof(char)*SIZE);
  memset(b,0,sizeof(char)*SIZE);
  scanf("%s",a);
  scanf("%s",b);
  LL count_a=0,length_a=0,length_b=0;
  REP(i,SIZE) {
    if(a[i]==0)break;
    else if(a[i]=='1') count_a++;
    length_a++;
  }
  
  LL count_b=0;
  REP(i,SIZE) {
    if(b[i]==0)break;
    else if(b[i]=='1') count_b++;
    length_b++;
  }
  
  if(count_a==0 && count_b!=0) printf("NO\n");
  else if(count_a!=0 && count_b==0) printf("NO\n");
  else if(length_a!=length_b) printf("NO\n");
  else printf("YES\n");
}