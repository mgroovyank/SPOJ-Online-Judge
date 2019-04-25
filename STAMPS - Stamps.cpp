#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int t,r;
	cin>>t;
	r=t;
	while(t--){
		int s,f;
		cin>>s>>f;
		int i;
		int arr[f];
		for(i=0;i<f;i++){
			cin>>arr[i];
		}
		sort(arr,arr+f);
		int sum=0;
		for(i=f-1;i>=0;i--){
			sum=sum+arr[i];
			if(sum>=s){
				break;
			}
		}
		cout<<"Scenario #"<<r-t<<":"<<"\n";
    if(sum<s){
      cout<<"impossible"<<"\n";
    }else{
      cout<<f-i<<"\n";
    }
	}
	return 0;
}
