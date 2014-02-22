/*
ID: arnabbh1
PROG: calfflac
LANG: C++
*/
#include <iostream>
#include <fstream>	

using namespace std;

ifstream fin("calfflac.in");
ofstream fout("calfflac.out");
long pos[1<<16];
long p[1<<16];

void getLongestPalindromesForEveryIndex(string s) {
  long c = 0;
  long r = 0;
  for (long i = 1; i < s.length()-1; i++) {
    //cout<<s.length()<<endl;
    //cout << i << '\t' << c << '\t' << r << '\n';
    long iref = 2*c - i;
    //fout<<i<<'\t'<<iref<<endl;
    p[i] =(r>i)?min(p[iref],r-i):0;
    // no need to check if we are failing out of array because of the added sentinels
    while(s[i+p[i]+1] == s[i-p[i]-1]) p[i]++;
    if (i+p[i]>r) {
      c = i;
      r = p[i] + i;
    }
  }
}

string modify(string s) {
  // adding a sentinel as well at end and begining to avoid falling out of bound
  string t="^#";
  for (int i=0; s[i]; i++) {t+=s[i]; t+='#';}
  t+='$';
  return t;
}

string preprocess(string s) {
  string t;
  for(long i=0,j=0 ; s[i] ; i++) {
    if (s[i]>='a' && s[i]<='z') {
      t+=s[i];
      pos[j++]=i;
    } else if (s[i]>='A' && s[i]<='Z') {
      t+=s[i]-'A'+'a';
      pos[j++]=i;
    }
  }
  return t;
}

int main() {

  string s,buf;
  while (getline(fin,buf)) {
    s+=buf; s+='\n';
  }
  //fout<<s<<endl;
  string t=preprocess(s);
  //for(int i=0;t[i];i++) fout<<i<<'\t'<<pos[i]<<endl;

  //fout<<t<<endl;
  t=modify(t);
  getLongestPalindromesForEveryIndex(t);
  //for(long i=0;t[i];i++) fout<<i<<'\t'<<pos[i]<<endl;
  long maxp=0,poscentre=0;
  for(long i=0;t[i];i++)
    if (maxp<p[i]){maxp=p[i]; poscentre=i;}
  fout<<maxp<<endl;
  poscentre-=1;
  poscentre=poscentre>>1;
  //cout<<"centre :"<<poscentre<<endl;
  long half=maxp>>1;
  long l=poscentre-half;
  //cout<<l<<'\t'<<l+maxp-1<<endl;
  //fout<<pos[l]<<'\t'<<pos[l+maxp-1]<<endl;
  fout<<s.substr(pos[l],pos[l+maxp-1]-pos[l]+1);
  fout<<endl;  //for(long i=0;t[i];i++) fout<<i<<'\t'<<p[i]<<endl;

}