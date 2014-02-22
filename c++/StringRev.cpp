#include <cstdio>

#define Rep(i,x) for(int i=0;i<x;i++)
#define swap(x,y) char temp=x;x=y;y=temp
void reverseWord(char* word, int length) {
  Rep(i,length/2){swap(word[i],word[length-1-i]);}
}

int main() {
  char* sentence=NULL;size_t n=100;
  ssize_t numOfChars=getline(&sentence,&n,stdin);
  printf("%s",sentence);
  int i=0,j=0;
  char* temp=sentence;//reverseWord(sentence,numOfChars-1);;
  while(j<numOfChars){while(sentence[j] != '\0' && sentence[j] != ' '){j++;} reverseWord(&sentence[i],j-i);j++;i=j;}
  
  printf("%s",sentence);
}