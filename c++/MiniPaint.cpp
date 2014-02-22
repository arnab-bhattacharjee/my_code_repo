#include <stdio.h>

using namespace std;

int min(int i,int j,int k) {
  int min=i;
  if(min>j){min=j;}
  if(min>k){min=k;}
  return min;
}

int main() {
  int maxSizeOfPicture=10;
  int noOfWaysToPaintSpace=3; // 0-no paint, 1-WHITE, 2-BLACK
  char* picture=new char[maxSizeOfPicture+1];
  
  scanf("%s",picture);
  
  int maxStrokes;
  scanf("%d",&maxStrokes);
  
  int*** DP=new int**[maxSizeOfPicture];
  
  for(int i=0;i<maxSizeOfPicture;i++) {
    DP[i]=new int*[maxStrokes+1];
    for(int j=0;j<maxStrokes+1;j++) {
      DP[i][j]=new int[noOfWaysToPaintSpace+1];
    }
  }
  
  for(int i=0;i<maxSizeOfPicture;i++) {
    for(int k=0;k<noOfWaysToPaintSpace;k++){DP[i][0][k]=i+1;}
  }
  
  for(int j=1;j<=maxStrokes;j++)
    for(int k=0;k<noOfWaysToPaintSpace;k++) {
      if(k==0){DP[0][j][k]=1;}
      else if(k==1){DP[0][j][k]=(picture[0]=='W')?0:1;}
      else{DP[0][j][k]=(picture[0]=='B')?0:1;}
    }
  
  for(int i=1;i<maxSizeOfPicture;i++) {
    for(int j=1;j<=maxStrokes;j++) {
      for(int k=0;k<noOfWaysToPaintSpace;k++) {
	if(k==0){DP[i][j][k]=min(DP[i-1][j][0]+1,DP[i-1][j][1]+1,DP[i-1][j][2]+1);}
	
	else if(k==1){DP[i][j][k]=min(DP[i-1][j-1][0]+((picture[i]=='W')?0:1),
				       DP[i-1][j][1]+((picture[i]=='W')?0:1),
				       DP[i-1][j-1][2]+((picture[i]=='W')?0:1));}
	
	else{DP[i][j][k]=min(DP[i-1][j-1][0]+((picture[i]=='B')?0:1),
			      DP[i-1][j-1][1]+((picture[i]=='B')?0:1),
			      DP[i-1][j][2]+((picture[i]=='B')?0:1));}
      }
    }
  }
  
  printf("\n%d\n",min(DP[maxSizeOfPicture-1][maxStrokes][0],DP[maxSizeOfPicture-1][maxStrokes][1],DP[maxSizeOfPicture-1][maxStrokes][2]));
}