#include <iostream>
#include <stack>
using namespace std;

void postfix(const char* c) {
  stack<int> S;
  int i=0;
  int temp=0;
  cout << (int)'9';
  while (c[i] != '\0') {
    cout << "c[i]:" << c[i] << (int)c[i];
    if ('0' <= c[i] && c[i] <= (int)'9') {cout<< "here"; temp = temp*10 + c[i]-'0'; cout << temp;}
    switch(c[i]) {
      case '+':
      {
	int a,b;
	a = S.top();
	cout << a;
	S.pop();
	b = S.top();
	cout << b;
	S.pop();
	S.push(a+b);
	cout << S.top();
	break;
      }
      case ' ':
      {
	S.push(temp);
	cout << "temp :" << temp << endl;
	temp=0;
      }
    }
    i++;
  }
  cout << S.top();
}

int main() {
  
  char c[] = "1 2 3 + +";
  postfix(c);
  return 1;
}