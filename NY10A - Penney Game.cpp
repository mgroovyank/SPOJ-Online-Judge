#include <iostream>
#include <string>
using namespace std;
int main(){
  int p;
  cin>>p;
  while(p--){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int i,a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0;
    for(i=0;i<s.length()-2;i++){
      if(s[i]=='T' && s[i+1]=='T' && s[i+2]=='T'){
        a++;
      }else if(s[i]=='T' && s[i+1]=='T' && s[i+2]=='H'){
        b++;
      }else if(s[i]=='T' && s[i+1]=='H' && s[i+2]=='T'){
        c++;
      }else if(s[i]=='T' && s[i+1]=='H' && s[i+2]=='H'){
        d++;
      }else if(s[i]=='H' && s[i+1]=='T' && s[i+2]=='T'){
        e++;
      }else if(s[i]=='H' && s[i+1]=='T' && s[i+2]=='H'){
        f++;
      }else if(s[i]=='H' && s[i+1]=='H' && s[i+2]=='T'){
        g++;
      }else if(s[i]=='H' && s[i+1]=='H' && s[i+2]=='H'){
        h++;
      }
    } 
    cout<<n<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<" "<<g<<" "<<h;
  }
}
