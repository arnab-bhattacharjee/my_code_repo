#include <cstdio>

using namespace std;
#define REP(i,x) for(int i=0;i<x;i++)
#define rep(i,x,y) for(int i=x;i<y;i++)

int binarySearch(int num, int A[], int length){
  int left=0,right=length,mid=(right+left)/2;
  while(!(A[mid]>num && A[mid-1]<num)){
    if(mid==0)break;
    printf("%d\t%d\t%d\n",left,mid,right);
    if(A[mid]<num){left=mid+1;}
    else{right=mid-1;}
    mid=(right+left)/2;
  }
  
  return mid;
}

int main(){
  int n;
  scanf("%d",&n);
  int* a=new int[n];
  REP(i,n)scanf("%d",&a[i]);
  
  int* A=new int[n];
  int* P=new int[n];
  
  A[0]=0;
  P[0]=-1;
  int length=0;
  rep(i,1,n){
    if(a[A[length]]<a[i]){
      length++;
      A[length]=i;
      P[i]=A[length-1];
    } else{
      int pos=binarySearch(a[i],A,length);
      A[pos]=i;
      P[i]=(pos>0)?A[pos-1]:-1;
    }
  }
}