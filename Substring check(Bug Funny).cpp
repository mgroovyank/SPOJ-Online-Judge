//SBSTR1 - Substring Check (Bug Funny)
//@author mgroovyank

#include <iostream>
using namespace std;
int main(){
  int arr1[10]={1,1,1,0,1,1,1,0,1,1};//string
  int arr2[5]={1,0,0,1,1};//substring
  int i,j=0,k;
  for(i=0;i<5;i=i+1){
    k=0;
    for(j=i;j<i+5;j=j+1){
      if(arr1[j]==arr2[k]){
        k=k+1;
        if(k==5){
          cout<<"1";//print 1 if arr2 is a substring of the arr1 string
        }
      }else{
        cout<<"0";//print 0 if arr2 is not a substring of the arr1 string
        i=5;
        break;
      }
    }
  }
}
