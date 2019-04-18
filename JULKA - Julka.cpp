#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void add(string a,string b){
  string c="";
  int i;
  int la=a.length();
  int lb=b.length();
  if(lb<la){
    swap(a,b);
  }
  int carry=0,sum=0;
  for(i=0;i<la;i++){
    sum=(a[i]-'0')+(b[i]-'0')+carry;
    c.push_back((sum%10)+'0');
    carry=sum/10;
  }
  for(i=la;i<lb;i++){
    sum=(b[i]-'0')+carry;
    c.push_back(sum%10+'0');
    carry=sum/10;
  }
  if(carry){
    c.push_back(carry+'0');
  }
  reverse(c.begin(),c.end());
  cout<<c;
}
void sub(string a,string b){
  string c="";
  int i;
  int la=a.length();
  int lb=b.length();
  if(lb>la){
    swap(a,b);
  }
  if(lb==la){
    for(i=0;i<la;i++){
      if(a[i]<b[i]){
        swap(a,b);
        break;
      }
    }
  }
  int carry=0,sub=0;
  for(i=lb-1;i>=0;i-=1){
    sub=(a[i+la-lb]-'0')-(b[i]-'0')-carry;
    if(sub<0){
      sub=sub+10;
      carry=1;
    }else{
      carry=0;
    }
    c.push_back(sub+'0');
  }
  for(int i=la-lb-1;i>=0;i--){ 
    if (a[i]=='0' && carry){
      c.push_back('9'); 
      continue; 
    } 
    int sub = ((a[i]-'0')-carry); 
    if (i>0 || sub>0){
      c.push_back(sub+'0'); 
      carry=0;
    } 
  }
  cout<<c; 
}
void div(string a,int b){
  reverse(a.begin(),a.end());
  string c;
  int idx=0; 
  int temp=a[idx]-'0'; 
  while(temp<b){
    temp=temp*10+(a[++idx]-'0');
  }  
  while(a.size()>idx){ 
    c+=(temp/b)+'0'; 
      temp=(temp%b)*10+a[++idx]-'0'; 
    } 
    cout<<c;
}
int main() {
	int t=1;
	while(t--){
    string a,b;
    cin>>a;
    cin>>b;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
	}
	return 0;
}
