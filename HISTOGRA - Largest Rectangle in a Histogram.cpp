#include <iostream>
#include <stack>
using namespace std;
int main(){
  long long int n;
  cin>>n;
  while(n){
    long long int i;
    long long int h[n];
    for(i=0;i<n;i++){
      cin>>h[i];
    }
    i=0;
    stack<long long int> st;
    long long int tp;
    long long int max_area=0;
    long long int temp_area=0;
    while(i<n){
      if(st.empty() || h[i]>=h[st.top()]){
        st.push(i++);
      }else{
        tp=st.top();
        st.pop();
        temp_area=h[tp]*(st.empty()?i:i-st.top()-1);
        if(max_area<temp_area){
          max_area=temp_area;
        }
      }
    }
    while(st.empty()==false){
      tp=st.top();
      st.pop();
      temp_area=h[tp]*(st.empty()?i:i-st.top()-1);
      if(max_area<temp_area){
        max_area=temp_area;
      }
    }
    cout<<max_area<<"\n";
    cin>>n;
  }
  return 0;
}
