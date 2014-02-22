#include <stdio.h>

class KMP {
private:
  char* pattern;
  int m;
  char* text;
  int n;
  int* F;
  void buildFailureFunction();
public:
  KMP(char* text, int textLength, char* pattern, int patternLength);
};

void KMP::buildFailureFunction() {
  printf("here\n");
  F[0]=0;F[1]=0;
  for(int i=2;i<=m;i++) {
    int j=F[i-1];
    while(true) {
      printf("here\n");
      if(pattern[i-1]==pattern[j]) {
	F[i]=j+1;break;
      } else {
	if(j==0){F[i]=0;break;}
	j=F[j];
      }
    }
  }
  
  for(int i=0;i<=m;i++) {
    printf("%d\n",F[i]);
  }
}

KMP::KMP(char* text, int textLength, char* pattern, int patternLength) {
  this->text=text;
  n=textLength;
  this->pattern=pattern;
  m=patternLength;
  F=new int[m+1];
  buildFailureFunction();
}



int main() {
  KMP(" ",1,"ABABAC",6);
  return 1;
}