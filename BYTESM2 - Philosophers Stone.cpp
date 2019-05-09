#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int h,w;
    cin>>h>>w;
    int i,j,arr[h][w];
    for(i=0;i<h;i++){
      for(j=0;j<w;j++){
        cin>>arr[i][j];
      }
    }
    int res[h][w];
    for(j=0;j<w;j++){
      res[0][j]=arr[0][j];
    }
    int l,s,r;
    for(i=1;i<h;i++){
      for(j=0;j<w;j++){
        s=arr[i][j]+res[i-1][j];
        l=arr[i][j]+res[i-1][j-1];
        r=arr[i][j]+res[i-1][j+1];
        if(j==0){
          res[i][j]=max(s,r);
        }else if(j==w-1){
          res[i][j]=max(s,l);
        }else{
          res[i][j]=max(s,max(r,l));        
        }
      }
    }
    int ans=0;
    for(j=0;j<w;j++){
      ans=max(ans,res[h-1][j]);
    }
    cout<<ans<<"\n";
  }
  return 0;
}
