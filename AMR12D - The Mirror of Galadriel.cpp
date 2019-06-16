#include <iostream>
#include <string>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;
    int i,j,l;
    l=s.length();
    i=0;
    j=l-1;
    bool palindrome = true;
    while(i<=j){
      if(s[i]!=s[j]){
        palindrome=false;
        break;
      }
      i++;
      j--;
    }
    cout<<(palindrome?"YES":"NO");
    cout<<"\n";
  }
}
