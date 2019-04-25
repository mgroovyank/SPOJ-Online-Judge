#include <iostream>
using namespace std;
#include <string>
#include <cmath>
string s1,s2,s3,s4,s5;
int check(string s){//check if string is number
  int i,num=0;;
  for(i=0;i<s.length();i++){
    if(!isdigit(s[i])){
      return -1;
    }
    num=num*10+(s[i]-'0');
  }
  return num;
}
int main(){
  int t,v1,v2,v3;
  cin>>t;
  while(t--){
    cin>>s1>>s2>>s3>>s4>>s5;
    v1=check(s1);
    v2=check(s3);
    v3=check(s5);
    if(v1<0){
      v1=v3-v2;
    }else if(v2<0){
      v2=v3-v1;
    }else if(v3<0){
      v3=v1+v2;
    }
    cout<<v1<<" + "<<v2<<" = "<<v3<<"\n";
  }
  return 0;
}
