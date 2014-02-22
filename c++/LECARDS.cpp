# include <iostream>

#define LL long long

LL getNumOfCombinations(int n, int r) {
  for(int i=1; i<=r; i++) {
    numOfCombinations *= (n-r+1)/i;
}
  

int main() {
  int num;
  cin << num;
  
  for(int i = 0, j = 1; i < (num-1); i++, j = j<<1) {
      possibilitiesOfWinsAndDraws = j;
  }
  
  if(num%2 == 1) {
    possibilitiesOfWins = possibilitiesOfWinsAndDraws;
  } else {
    numOfCombinations = getNumOfCombinations(num, num/2);
    possibilitiesOfWins = possibilitiesOfWinsAndDraws - numOfCombinations;
  }
} 