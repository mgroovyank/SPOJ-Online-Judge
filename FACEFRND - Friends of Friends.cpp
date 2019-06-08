#include <iostream>
using namespace std;
int main(){
  int n;
  while(cin>>n){
    int visited[10000];
    for(int i=0;i<10000;i++){
      visited[i]=0;
    }
    int f1[n];
    int i,m,temp;
    for(i=0;i<n;i++){
      cin>>f1[i]>>m;
      visited[f1[i]]=-1;
      while(m--){
        cin>>temp;
        if(visited[temp]!=-1){
          visited[temp]=1;
        }
      }
    }
    int c=0;
    for(i=0;i<10000;i++){
      if(visited[i]==1){
        c++;
      }
    }
    cout<<c<<"\n";
  }
}
