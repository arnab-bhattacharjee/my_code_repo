#include <cstdio>
#include <string.h>
#include <inttypes.h>

int main() {
  int lcm=210;
  _int64 digits,c=1;
  scanf("%I64d",&digits);
  char* num=new char[digits+1];
  memset(num,'0',sizeof(char)*(digits+1));
  int a=1;
  while(true) {
    if(c>=digits) break;
    if(a<lcm){a*=10;c++;}
    if(a>=lcm){a=a%lcm;}
  }
  a=lcm-a;
  num[0]='1';int i=0;int rem;
  while(a>0){
    rem=a%10;
    num[digits-i-1]='0'+rem;i++;
    a/=10;    
  }
  if(digits==1||digits==2)printf("-1\n");
  else if(digits==3)printf("210\n");
  else {num[digits]=0;
  printf("%s",num);
  }
}