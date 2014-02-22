#include <stdio.h>

using namespace std;

class KMP {
private:
  int m; // pattern length
  int n; // text length
  const char* pattern;
  const char* text;
  int* F;
  void buildFailureFunction();
public:
  KMP(int m,int n,const char* pattern,const char* text);
  bool isPatternExisting();
};

KMP::KMP(int m, int n, const char* pattern, const char* text) {
  this->m=m;
  this->n=n;
  this->pattern=pattern;
  this->text=text;
  F=new int[m+1];
}

bool KMP::isPatternExisting() {
  int i=0,j=0;
  
  buildFailureFunction();
  
  while(true) {
    if(i==n) return false;
    if(pattern[j]==text[i]){i++;j++;if(j==(m-1))return true;}
    else if(j>0){j=F[j];}
    else i++;
  }

}

void KMP::buildFailureFunction() {
  F[0]=0;
  F[1]=0;
  
  for(int i=2;i<=m;i++) {
    int j=F[i-1];
    while(true) {
      if(pattern[j]==pattern[i-1]){F[i]=j+1;break;}
      else {
	if(j==0){F[i]=0;break;}
	else {j=F[j];}
      }
    }
  }
  
  for(int i=0;i<=m;i++){printf("%d\t",F[i]);}
  printf("\n");
}


int main() {
  int t=24;
  char* A=new char[11];
  char* B=new char[6];
  while(t--) {
    scanf("%s %s",A,B);
    KMP* _kmp=new KMP(5,10,B,A);
    int result=(_kmp->isPatternExisting()==true)?1:0;
    printf("%d\n",result);
    delete _kmp;
  }
}