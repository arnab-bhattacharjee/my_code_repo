#include <iostream>

using namespace std;


int main() {
  
  int inputArray[] = {2,5,7,1,6,3,4,8};
  int length = 8;
  int mid = length/2;
  
  // Get me the # Inversions
  int Z = Sort_And_Count(inputArray, 0, ((length/2) -1));
  
  for (int i=0; i<length; i++)
    cout << inputArray[i];
}

// recursively sorts inputArray from index p to r
int Sort_And_Count(int inputArray, int p, int r) {
  
  int q = (p+r)/2;
  
  int X = Sort_And_Count(inputArray, p, q);
  int Y = Sort_And_Count(inputArray, q+1,r);
  int Z = Sort_And_CountSplitInversions(inputArray, p, r);
}