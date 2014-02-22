#include <iostream>
#include <cmath>
#define long long LL
using namespace std;

int main() {
  const LL MAX_NUM;
  LL strt_intvl, end_intvl;
  
  LL possiblePrimeFactors[] = generatePrimes(sqrt(MAX_NUM));
  
  LL primes[] = new LL[](end_intvl-strt_intvl);
  
  for (int i=1; i<lastPrime; i++) {
    residue = strt_intvl%primes[i];
    sieveUsingPrime(primes, (i-residue)%residue);
  }
}

LL [] generatePrimes(LL num) {
  LL possiblePrimeFactors[] = new LL[](num);
  
  // store numbers 1 to num in seq.
  for (LL i=1; i<num; i++) {
    possiblePrimeFactors[i]=i;
  }
  
  sieveUsingPrime(possiblePrimeFactors, );