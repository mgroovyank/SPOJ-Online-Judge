#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int q=-1,ans=0,p=5;
		while(q!=0){
			q=n/p;
			p=5*p;
			ans=ans+q;
		}
		cout<<ans;
		cout<<"\n";
	}
	return 0;
}
