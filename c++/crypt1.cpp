/*
ID: arnabbh1
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;

int *a;
int n;
ifstream fin("crypt1.in");
ofstream fout("crypt1.out");

bool check(int num,int digits) {
  int mod=1;
  for (int i=0 ; i<digits ; i++) mod*=10;
  if (num/mod == 0) {
    for (; num>0 ; num/=10) {
      int rem = num%10;
      bool isValid=false;
      for(int i=0 ; i<n ; i++) {
	if (rem == a[i]) isValid=true;;
      }
      if (!isValid) return false;
    }
  } else
    return false;
  return true;
}

int main() {
  long count=0;
  fin>>n;
  a = new int[n];
  for (int i=0 ; i<n ; i++)
    fin>>a[i];
  for (int i=0 ; i<n ; i++) {
    for (int j=0 ; j<n ; j++) {
      for (int k=0 ; k<n ; k++) {
	for (int l=0 ; l<n ; l++) {
	  for (int m=0 ; m<n ; m++) {
	    int num1=a[i]*100 + a[j]*10 + a[k];
	    int num2=a[l]*10 + a[m];
	    if (check(num1,3)
	      && check(num2,2)
	      && check(num1*a[l],3)
	      && check(num1*a[m],3)
	      && check(num1*num2,4)){ count++;}
	  }
	}
      }
    }
  }
  fout<<count<<endl;
}