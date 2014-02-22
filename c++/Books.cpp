#include <stdio.h>

#define LL long long
#define Rep(i,x) for(int i=0;i<x;i++)
int main() {
  int n;LL t;
  scanf("%d%lld",&n,&t);
  LL* a=new LL[2*n-1];
  Rep(i,n){scanf("%lld",&a[i]);}
  for(int i=0;i<n-1;i++){a[n+i]=a[i];}
  int i=0,j=0,count=0,maxCount=0;LL sum=0;
  for(;i<2*n-1;i++){
    printf("%lld\n",sum);
    for(;j<n+i && (sum+a[j])<=t;j++){printf("%lld\n",a[j]);sum+=a[j];count++;}
    if(j-i==n){printf("%d\n",n);return 0;}
    else{
      maxCount=(count>maxCount)?count:maxCount;
      sum-=a[i];count--;
    }
  }
  printf("%d\n",maxCount);
  return 0;
}
