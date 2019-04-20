#include <iostream>
#include <stack>
using namespace std;
int main(){
  int n;
  cin>>n;
  while(n){
    int a[n],b[n];
    int i,j=0;
    stack<int> s;
    for(i=0;i<n;i++){
      cin>>a[i];
    }
    for(i=0;i<n;i++){
      while(!s.empty() && j+1==s.top()){
        b[j]=s.top();
        s.pop();
        j++;
      }
      if(j+1==a[i]){
        b[j]=a[i];
        j++;
      }else{
        s.push(a[i]);
      }
    }

    int k=1;
    for(i=0;i<n-1;i++){
      if(b[i]<b[i+1]){
        continue;
      }
      k=0;
      break;
    }
    if(k==1){
      cout<<"yes";
    }else{
      cout<<"no";
    }
    cout<<"\n";
    cin>>n; 
  }
  return 0;
}
