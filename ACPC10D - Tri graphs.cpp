#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	int cas=1;
	while(n){
		int i,j;
		int arr[n][3];
		int temp;
		for(i=0;i<n;i++){
			for(j=0;j<3;j++){
				cin>>arr[i][j];
			}
		}
		for(i=0;i<n;i++){
			if(i==0){
				arr[i][2]+=arr[i][1];
			}else if(i==1){
				arr[i][0]+=arr[i-1][1];
				arr[i][1]+=min(arr[i-1][1],min(arr[i][0],arr[i-1][2]));
				arr[i][2]+=min(arr[i-1][1],min(arr[i-1][2],arr[i][1]));
			}else{
				arr[i][0]+=min(arr[i-1][0],arr[i-1][1]);
				arr[i][1]+=min(min( min(arr[i-1][0],arr[i-1][1]),arr[i-1][2]),arr[i][0]);
				arr[i][2]+=min(arr[i-1][1],min(arr[i-1][2],arr[i][1]));
			}
		}
		cout<<cas<<". "<<arr[n-1][1]<<"\n";
    cas++;
		cin>>n;
	}
}
