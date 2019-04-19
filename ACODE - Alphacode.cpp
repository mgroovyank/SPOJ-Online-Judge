
#include <iostream>
#include <string>
using namespace std;
int main(){
  string s;
  cin>>s;
  while(s[0]!='0'){
    int n=s.length();
    int b[n];
    int i;
    for(i=0;i<n;i+=1){
      b[i]=0;
    }
    b[0]=1;
    int j;
    for(i=1;i<n;i+=1){
        j=(s[i-1]-'0')*10+(s[i]-'0');
        if(s[i]-'0'){
            b[i]=b[i-1];
        }
        if(j>9 && j<27){
            if(i==1){
                b[i]=b[i]+1;
            }else{
                b[i]=b[i]+b[i-2];
            }
        }
    }
    cout<<b[n-1]<<"\n";
    cin>>s;
  }
  return 0;
}
