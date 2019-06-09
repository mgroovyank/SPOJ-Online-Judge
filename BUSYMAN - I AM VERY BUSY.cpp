#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comparator(pair<int,int> x,pair<int,int> y){
  return x.second<y.second;
}
int main(){
  int t,n,i,j,k;
  cin>>t;
  while(t--){
    cin>>n;
    vector<pair<int,int> > s;
    for(i=0;i<n;i++){
      cin>>j>>k;
      s.push_back(make_pair(j,k));
    }
    sort(s.begin(),s.end(),comparator);
    int ans=1;
    int prev_time=s[0].second;
    for(i=1;i<n;i++){
      if(s[i].first>=prev_time){
        prev_time=s[i].second;
        ans++;
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}
