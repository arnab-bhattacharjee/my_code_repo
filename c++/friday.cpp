/*
ID: arnabbh1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;
#define DAYS 7
#define MONTHS 12
#define STARTYEAR 1900
int main(){
    ifstream fin("friday.in");
    ofstream fout("friday.out");
    int dayCount[DAYS];
    memset(dayCount,0,sizeof(int)*DAYS);
    int daysInMonth[MONTHS];
    for(int i=0;i<MONTHS;i++) daysInMonth[i]=31;
    daysInMonth[1]=28;
    daysInMonth[3]--, daysInMonth[5]--, daysInMonth[8]--, daysInMonth[10]--;
    
    int N;
    fin>>N;
    int val=13%7;
    for(int i=0;i<N;i++){ // these many years
        if((STARTYEAR+i)%100==0) if((STARTYEAR+i)%400==0) daysInMonth[1]=29; else daysInMonth[1]=28;
        else if((STARTYEAR+i)%4==0) daysInMonth[1]=29; else daysInMonth[1]=28;
        for(int j=0;j<MONTHS;j++){
            dayCount[val]++;
            val+=daysInMonth[j];
            val%=7;
        }
    }
    
    for(int i=6;i<12;i++) fout<<dayCount[i%7]<<' ';
    fout<<dayCount[12%7]<<endl;
    return 0;
}
