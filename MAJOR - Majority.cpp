#include <iostream>
#include <map>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    long long int n,num;
    int i,ans=0;
    cin>>n;
    map<long long int,int> data;
    map<long long int,int>::iterator itr;
    for(i=0;i<n;i++){
      cin>>num;
      itr=data.find(num);
      if(itr==data.end()){
        data.insert(pair<long long int,int>(num,1));
        ans=max(ans,1);
      }else{
        itr->second+=1;
        ans=max(ans,itr->second);
      }
    }
    if(ans>n/2){
      for(itr=data.begin();itr!=data.end();itr++){
        if(itr->second==ans){
          cout<<"YES "<<itr->first<<"\n";
          break;
        }
      }
    }else{
      cout<<"NO"<<"\n";
    }
  }
}
