#include <iostream>
using namespace std;
int main(){
	float c;
	cin>>c;
	while(c){
		float sum=0;
		int i=2;
		while(sum<=c){
			sum=sum+(1.00/i);
			i+=1;
		}
		cout<<i-2<<" card(s)";
		cout<<"\n";
		cin>>c;
	}
	return 0;
}
