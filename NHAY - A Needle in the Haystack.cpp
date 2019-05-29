#include <iostream>
using namespace std;
int main(){
  int p;
  cin>>p;
  char pn[p];
  for(int i=0;i<p;i++){
    cin>>pn[i];
  }
  int temp[p];
  int i,j;
  j=0;
  i=1;
  temp[0]=0;
  while(i<p){
    if(pn[j]==pn[i]){
      temp[i]=j+1;
      j++;
      i++;
    }else{
      if(j!=0){
        j=temp[j-1];
      }else{
        temp[i]=0;
        i++;
      }
    }
  }
  char ch;
  j=0;
  int t=0;
  while(cin>>ch){
    if(ch==pn[j]){
      if(j==p-1){
        cout<<t-p+1<<"\n";
        j=temp[j];
      }else{
        j++;
      }
    }else{
        while(ch!=pn[j] && j!=0){
            j=temp[j-1];
     }
     if(ch==pn[j]){
       j++;
     }
    }
    t++;
  }
}
