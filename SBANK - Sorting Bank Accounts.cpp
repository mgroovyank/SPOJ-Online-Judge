#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
  map<string,int> acc;
  int t;
  cin>>t;
  while(t--){
    acc.clear();//to clear the map
    int n;
    cin>>n;
    cin.ignore();//to clear input buffer to take string input 
    int i;
    string s,emptystring;
    for(i=0;i<n;i++){
      getline(cin,s);
      if(acc.find(s)==acc.end()){
        acc[s]=1;
      }else{
        acc[s]=acc[s]+1;
      }
    }
    getline(cin,emptystring);//to get empty string as input
    map<string,int>::const_iterator it;
    for(it=acc.begin();it!=acc.end();it++){
      cout<<it->first<<" "<<it->second<<"\n";
    }
    cout<<endl;//to clear output buffer
  }
}
