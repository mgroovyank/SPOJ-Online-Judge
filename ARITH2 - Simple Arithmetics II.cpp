#include <iostream>
using namespace std;
int main(){
  int t;
  cin>>t;
  int flag;
  long long num1,num2,ans,count;
  char op;
  while(t--){
    flag=1;
    count=0;
    while(flag){
      count++;
      if(count==1){
        cin>>num1;
      }else{
        num1=ans;
      } 
      op=' ';
      while(op == ' '){
        cin>>op;
      }
      if(op=='='){
        cout<<ans<<"\n";
        flag=0;
      }else{
        cin>>num2;
      }
      switch(op){
            case  '+' : ans=num1+num2;
                    break;
            case  '-' : ans=num1-num2;
                    break;
            case  '*' : ans=num1*num2;
                    break;
            case  '/' : ans=num1/num2;
                    break;
            default : break;
        }
      }
    }
        return 0;
        
}   
