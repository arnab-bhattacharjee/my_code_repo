#include <iostream>
#include <sys/types.h>
#include <unistd.h>
using namespace std;

int main(){
	pid_t child_pid;
	child_pid=fork();
	if(child_pid){ cout<<"Initiating wait protocol!"; int a; cin>>a; while(true){if(a==-1) break;cin>>a;}}
	else cout<<"Hello WOrld!";
	return 0;
}
