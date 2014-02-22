# include <iostream>
# define LL long long
using namespace std;

void multiplyMatrices(LL* a, LL* b) {
  LL c[4];
  
  for(int i=0; i<2; i++) {
    for(int j=0; j<2; j++) {
      c[i+2*j]=0;
      for(int k=0; k<2; k++) {
	c[i+2*j] = (c[i+2*j] + ((a[i+2*k] * b[k+2*j])%1000000007)%1000000007); // covering both possibilities of overflow
      }
    }
  }
  
  for(int i=0; i<4; i++) {
    a[i]=c[i];
  }
  
}

LL getFibonacci(int num) {
  LL fib_1 = 1;
  LL fib_2 = 2;

  if(num == 1) {
    return fib_1;
  } else if(num == 2) {
    return fib_2;
  } else {
    LL a[4] = {1,1,1,0};
    LL I[4] = {1,0,0,1};
    LL temp[4] = {1,0,0,1};
    
    for(LL i=(num-2); i>0; i = (i >> 1)) {
      if(i%2 == 1) {
	multiplyMatrices(temp, a);
      }
      multiplyMatrices(a, a);
      
    }
    return (((temp[0]*fib_2)%1000000007 + temp[1]*fib_1)%1000000007);

  }
}

LL numOfOnesInBinRep(int num) {
  LL count=0;
  for(int i = num; i>0; i = i>>1) {
    if(i%2)
      count++;
  }
  
  return count;
}

int main() {
  LL numOfTestCases;
  cin >> numOfTestCases;
  LL num, guess;
  for(int i=0; i<numOfTestCases; i++) {
    cin >> num; cin >> guess;
    LL numOfPossibilities = getFibonacci(num);
    LL numOfOnes = numOfOnesInBinRep(numOfPossibilities%1000000007);
    if(numOfOnes == guess) {
      cout << "CORRECT";
    } else {
      cout << "INCORRECT";
    }
    cout << endl;
    
  }
}



