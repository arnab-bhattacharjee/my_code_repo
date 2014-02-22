#include <cstdio>
#include <iostream>
#define REP(i,x) for(int i=0;i<x;i++)

using namespace std;

int main() {
  char alphabet[27];
  char givenSentence[101];int t;
  scanf("%d ",&t);
  scanf("%s",alphabet);
  
  while(t--) {  
    char translatedSentence[101];
    scanf("%s",givenSentence);
    int i;
    for(i=0;givenSentence[i]!=0;i++) {
      if(islower(givenSentence[i])) translatedSentence[i]=alphabet[givenSentence[i]-'a'];
      else if(isupper(givenSentence[i])) translatedSentence[i]=alphabet[givenSentence[i]-'A']+'A'-'a';
      else if(givenSentence[i]=='_') translatedSentence[i]=' ';
      else translatedSentence[i]=givenSentence[i];
    }
    translatedSentence[i]=0;
    
    printf("%s\n",translatedSentence);
  }
}
  
  
  