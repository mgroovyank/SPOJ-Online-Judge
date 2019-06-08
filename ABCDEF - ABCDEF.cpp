#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  int n;
  while(cin>>n){
    int i;
  int arr[n];
  for(i=0;i<n;i++){
    cin>>arr[i];
  }
  int j,k;
  vector<long long int> lhs,rhs;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      for(k=0;k<n;k++){
        lhs.push_back((arr[i]*arr[j])+arr[k]);
        if(arr[i]!=0){
          rhs.push_back((arr[i]*(arr[j]+arr[k])));
        }
      }
    }
  }
  sort(rhs.begin(),rhs.end());
  vector<long long int>::iterator itr;
  pair<vector<long long int>::iterator,std::vector<long long int>::iterator> ip;
  int count=0;
  for(itr=lhs.begin();itr!=lhs.end();itr++){
    ip=equal_range(rhs.begin(),rhs.end(),*itr);
    count+=ip.second-ip.first;
  }
  cout<<count<<"\n";
  }
}
