#include <iostream>

using namespace std;

int getCostOfString(char* cp) {
  int characters[52] = {0};
  int cost = 0;
  
  while(*cp != '\0') {
    if(islower(*cp)) {
      characters[*cp-'a'] +=1;
    } else {
      characters[*cp-'A'+26] +=1;
    }
    cp++;
  }
  
  for(int i=0; i<52; i++) {
    cost += characters[i]%2 + characters[i]/2;
  }
  
  return cost;
}
    

int main() {
  int numOfTestCases;
  int cin >> numOfTestCases;
  cin.get();
  
  int BUFSIZE = 400;
  
  for(int i=0; i< numOfTestCases; i++) {
    char* buf = new char(BUFSIZE);
    cin.getline(buf, BUFSIZE);
    int cost = getCostOfString(buf);
    cout << cost << endl;
  }
}