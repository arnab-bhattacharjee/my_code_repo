#include <cstdio>

#define REP(i,x) for(int i=0;i<x;i++)
#define SIZE 1000000
#define LL unsigned long long
int main() {
  LL k;
  scanf("%llu",&k);
  char* str=new char[SIZE+2];
  LL* cf=new LL[SIZE+2];
  scanf("%s",str+1);
  str[0]='0';
  LL i=0,numOfZeros=0,numOfSubStrings=0,count=0;
  if(k==0) {
    while(str[i+1]!=0) {
      if(str[i+1]=='0') {
	numOfZeros++;i++;
      } else {
	numOfSubStrings+=(numOfZeros*(numOfZeros+1))/2;i++;numOfZeros=0;
      }
    }
    printf("%llu",numOfSubStrings+=(numOfZeros*(numOfZeros+1))/2);return 0;
  }
    
  while(str[i]!=0) {
    if(str[i]=='0')cf[i]=count;
    else {count++;cf[i]=count;}
    i++;
  }
  i=0;LL j=1;LL numOfOnes,total=0;numOfZeros=0,numOfSubStrings=0;
  while(str[j]!=0) {
    while(str[i+1]!='1' && str[i+1]!=0){i++;numOfZeros++;}
    numOfOnes=cf[j]-cf[i];
    if(numOfOnes==k) { //str[i+1...j] is a substring containg k 1s
      numOfSubStrings=1;
      while(str[j+1]=='0'){j++;numOfSubStrings++;}
      total+=numOfSubStrings*(1+numOfZeros);
      i++;j++;numOfZeros=0;
    } else {j++;}
  }
  printf("%llu\n",total);
}