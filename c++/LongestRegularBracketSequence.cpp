#include <iostream>
#include <stack>
using namespace std;
#define Rep(i,x,y) for(int i=x;i<y;i++)
#define LL unsigned long long
#define INF std::numeric_limits<UL>::max()

int main(){
  string s;
  cin>>s;
  stack<int> S;
  int count=0,max_count=0,num=0;
  int i=0;
  while(s[i]){
    if(s[i]=='('){S.push(0);}
    else{
      if(!S.empty()){
	if(S.top()=='('){S.pop();S.push('1');}
	if(S.top()==max_count)num++;
	max_count=(S.top()>max_count)?S.top():max_count;
      }
    }
    i++;
  }
  cout<<max_count*2<<' '<<num+1<<endl;
}
