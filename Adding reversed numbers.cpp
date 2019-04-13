#include <iostream>
using namespace std;
unsigned long long int rev(unsigned long long int n){
	unsigned long long int r=0;
	while(n%10==0){
		n=n/10;
	}
	while(n!=0){
		r=r*10+n%10;
		n=n/10;
	}
	return r;
}

int main() {
	unsigned long long int t;
	cin>>t;
	unsigned long long int sum;
	while(t--){
		unsigned long long int m,n;
		cin>>m>>n;
		sum=0;
		sum=rev(m)+rev(n);
		sum=rev(sum);
		cout<<sum;
		cout<<"\n";
	}
	return 0;
}
