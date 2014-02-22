#include <stdio.h>

#define Rep(i,x) for(int i=1;i<x;i++)

class BIT {
private:
  int* tree;
  int maxVal;
public:
  BIT(int n);
  void update(int idx);
  void cumFreq(int idx);
  void freq(int idx);
};

BIT::BIT(int n) {
  maxVal=n;
  tree=new int[maxVal+1];
  tree[0]=0;
}


void BIT::update(int idx) {
  while(idx<=maxVal) {
    tree[idx]++;
    idx+=(idx & -idx);
  }
}

void BIT::cumFreq(int idx) {
  int sum=0;

  while(idx>0) {
    sum+=tree[idx];
    idx-=(idx & -idx);
  }
  
  printf("%d\n",sum);
}

void BIT::freq(int idx) {
  int sum=tree[idx];
  int z=idx-(idx & -idx);
  idx--;
  while(idx!=z) {
    sum-=tree[idx];
    idx-=(idx & -idx);
  }
  
  printf("%d\n",sum);
}



int main() {
  int n;
  scanf("%d",&n);
  BIT* _bit=new BIT(n);
  Rep(i,n) {_bit->update(i);}
  Rep(i,n) {_bit->cumFreq(i);}
  Rep(i,n) {_bit->freq(i);}
  return 1;
}