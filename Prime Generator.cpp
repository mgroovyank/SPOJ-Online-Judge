//This code shows error time limit excedded
#include <iostream>
using namespace std;
int main() {
	int t;
	cin>>t;
	int i=0;
	while(i<t){
		int m,n;
		cin>>m;
		cin>>n;
		int j;
		for(j=m;j<n+1;j++){
			int isPrime=1;
			if(j==1){
				continue;
			}
			int k;
			for(k=2;k<j;k++){
				if(j%k==0){
					isPrime=0;
					break;
				}else{
					continue;
				}
			}
			if(isPrime==1){
				cout<<j;
        cout<<"\n";
			}
		}
		i++;
	}
	return 0;
}
