#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
  string s;
  cin>>s;
  int c=1;
  while(s[0]!='-'){
    int i,move=0;
    stack<char> o;
    for(i=0;i<s.length();i++){
      if(s[i]=='{'){
        o.push(s[i]);
      }else if(s[i]=='}'){
        if(!o.empty()){
          o.pop();
        }else{
          o.push('{');
          move++;
        }
      }
    }
    while(!o.empty()){
      o.pop();
      move++;
      o.pop();
    }
    cout<<c<<". "<<move<<"\n";
    cin>>s;
    c++;
  }
}
