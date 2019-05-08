#include<iostream>
using namespace std;
int main(){
	int t;
    cin>>t;
    while(t--){
        long long int l,n;
        cin>>l;
        if(l%2==0){
        	n=l*(l+2)*(2*l+1)/8;
        }else{
        	n=(((l*(l+2)*(2*l+1))-1)/8);
        }
        cout<<n<<"\n";
    }
    return 0;
}
