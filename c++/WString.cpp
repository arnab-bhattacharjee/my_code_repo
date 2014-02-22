#include <iostream>
#include <string.h>

using namespace std;
#define Rep(i,x,y) for(int i=x;i<y;i++)
#define NUM_OF_ALPHABETS 26

int main(){
    string s;
    cin>>s;
    
    int noOfHashes=0;
    
    for(int i=0;s[i];i++){
        if(s[i]=='#'){
            noOfHashes++;
        }
    }

    int* maxOccurences=new int[noOfHashes+1];
    int alphabetCount[NUM_OF_ALPHABETS];
    
    memset(alphabetCount,0,sizeof(alphabetCount));
    
    for(int i=0,j=0;;i++){
        if(s[i]=='#' || !s[i]){
            int max=0;
            Rep(k,0,NUM_OF_ALPHABETS){
                max=(max<alphabetCount[k])?alphabetCount[k]:max;
            }
            maxOccurences[j]=max;
            j++;
            memset(alphabetCount,0,sizeof(alphabetCount));
            if(!s[i])break;
        } else{
            alphabetCount[s[i]-'a']++;
        }
    }
    //Rep(i,0,noOfHashes+1)cout<<maxOccurences[i]<<endl;
    
    // 0 - prefix, 1 - suffix
    int* DP[2];
    Rep(i,0,2){
        DP[i]=new int[noOfHashes+1];
    }
    
    int j=0;
    for(int i=0;s[i];i++){
        if(s[i]=='#'){
            int max=0;
            Rep(k,0,NUM_OF_ALPHABETS){
                max=(max<alphabetCount[k])?alphabetCount[k]:max;
            }
            DP[0][j]=max;
            j++;
            if(j==(noOfHashes-2))break;
        } else{
            alphabetCount[s[i]-'a']++;
        }
    }
    Rep(i,0,noOfHashes+1)cout<<DP[0][i]<<'\t';
    cout<<endl;
    
    memset(alphabetCount,0,sizeof(alphabetCount));
    
    j=noOfHashes;
    for(string::reverse_iterator it=s.rbegin();it!=s.rend();it++){
        if(*it=='#'){
            int max=0;
            Rep(k,0,NUM_OF_ALPHABETS){
                max=(max<alphabetCount[k])?alphabetCount[k]:max;
            }
            DP[1][j]=max;
            j--;
            if(j==(2))break;
        } else{
            alphabetCount[*it-'a']++;
        }
    }
    Rep(i,0,noOfHashes+1)cout<<DP[1][i]<<'\t';
}