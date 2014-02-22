#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
    int N;
    cin>>N;
    vector<pair<int,int> > cordinate(N);
    for(int i=0;i<N;i++){
        cin>>cordinate[i].first>>cordinate[i].second;
    }
    
    int count=0;
    
    for(int i=0;i<N-2;i++){
        for(int j=i+1;j<N-1;j++){
            for(int k=j+1;k<N;k++){
                //got 3 points
                int a1=cordinate[i].first;
                int b1=cordinate[i].second;
                int a2=cordinate[j].first;
                int b2=cordinate[j].second;
                int a3=cordinate[k].first;
                int b3=cordinate[k].second;
                float m1=(float)(b2-b1)/(float)(a2-a1);
                float m2=(float)(b3-b2)/(float)(a3-a2);
                int c1=pow(b1,2)+pow(a1,2)-pow(b2,2)-pow(a2,2);
                int c2=pow(b2,2)+pow(a2,2)-pow(b3,2)-pow(a3,2);
                if(m1==m2)continue;
                int L1[3]={2*(a1-a2),2*(b1-b2),c1};
                int L2[3]={2*(a2-a3),2*(b2-b3),c2};
                double centre1,centre2;
                centre1=(double)(L1[2]*L2[1]-L2[2]*L1[1])/(double)(L1[0]*L2[1]-L2[0]*L1[1]);
                centre2=(double)(L1[2]*L2[0]-L2[2]*L1[0])/(double)(L1[1]*L2[0]-L2[1]*L1[0]);
                double radius_squared= pow((centre1-a1),2)+pow((centre2-b1),2);
                for(int l=0;l<N;l++){
                    if(l!=i && l!=j && l!=k){
                        double dist_squared=pow((centre1-cordinate[l].first),2)+pow((centre2-cordinate[l].second),2);
                        if(dist_squared<=radius_squared){
                            //cout<<L1[0]<<'\t'<<L1[1]<<'\t'<<L1[2]<<endl;
                            //cout<<centre1<<'\t'<<centre2<<endl;
                            //cout<<dist_squared<<'\t'<<radius_squared<<endl;
                            count++;
                            //cout<<cordinate[i].first<<'\t'<<cordinate[i].second<<endl;
                            //cout<<cordinate[j].first<<'\t'<<cordinate[j].second<<endl;
                            //cout<<cordinate[k].first<<'\t'<<cordinate[k].second<<endl;
                            //cout<<cordinate[l].first<<'\t'<<cordinate[l].second<<endl<<endl<<endl;
                        }
                    }
                }
            }
        }
    }
    
    //cout<<count<<endl;
    int total=((N*(N-1)*(N-2))/6)*(N-3);
    //cout<<total<<endl;
    cout<<(double)count/(double)total<<endl;
    }
}
