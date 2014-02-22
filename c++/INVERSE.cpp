#include <iostream>
#include <cassert>
#define LL long long
using namespace std;

LL getLargestMultipleNotExceeding(int smaller_num, int larger_num) {
  assert(smaller_num < larger_num);
  
  int i;
  for(i=1; i*smaller_num <= larger_num; i++)
    ;
  
  return (i-1);
}

/* return r such that ar=1(mod p)
 */
LL getInverse(LL a, LL p) {
  LL work_matrix[6]={1,0,a,0,1,p};
  int j=0;
  LL largest_multiple;
  while(work_matrix[2] != 0 || work_matrix[5] != 0) {
    if(work_matrix[2] < work_matrix[5]) {
      largest_multiple = getLargestMultipleNotExceeding(work_matrix[2], work_matrix[5]);
      j=1;
    } else {
      largest_multiple = getLargestMultipleNotExceeding(work_matrix[5], work_matrix[2]);
      j=0;
    }
    
    for(int i=0; i<3; i++) {
      work_matrix[i+j*3] -= largest_multiple*work_matrix[i+((j+1)%2)*3];
    }
  }
  return (work_matrix[2]+work_matrix[5]);
}

int main() {
  LL a,p;
  cin >> a >> p;
  
  LL gcd = getInverse(a, p);
  cout << gcd;
}