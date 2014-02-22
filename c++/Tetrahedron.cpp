#include <cstdio>
#include <string.h>

int main() {
  unsigned long steps;
  scanf("%lu",&steps);
  unsigned long *T=new unsigned long[10000000];
  memset(T,0,sizeof(T));
  T[2]=3;
  for(unsigned long i=3;i<=steps;i++){
    T[i]=((T[i-1]*2)%1000000007)+((T[i-2]*3)%1000000007);
    if(T[i]>=1000000007)T[i]-=1000000007;
  }
  
  printf("%lu\n",T[steps]);
}
    