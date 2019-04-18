#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int cols;
	cin>>cols;
	while(cols){
    string s;
	  cin>>s;
		int i;
		string r;
		for(i=0;i<cols;i+=1){
			int j=i;
			while(j<s.size()){
				r.push_back(s[j]);
        if((int(ceil(j/cols))+1)%2==0){
          j=j+2*i+1;
        }else{
          j=j+2*cols-1-2*i;
        }
			}
		}
    cout<<r;
    cout<<"\n";
    cin>>cols;
	}
	return 0;
}
