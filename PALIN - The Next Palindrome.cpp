#include <iostream>
#include <cstring>
using namespace std;
int allNine(string str){
	int i;
	for(i=0;i<str.length();i=i+1){
		if(str[i]!='9'){
			return 0;
		}
	}
	return 1;
}

int main(){
	int t;
	cin>>t;
    string str;
    int i,j,k,m;
	while(t--){
		cin>>str;
		int len=str.length();
		char ans[str.length()+3];
		if(allNine(str)){
			ans[0]='1';
			for(i=1;i<len;i++){
				ans[i]='0';
			}
			ans[len]=1;
			ans[len+1]='\0';
			cout<<ans<<endl;
		}else{
      i=len/2;
      j=i;
			if(len%2==0){
				i=i-1;
			}
			while(i>=0 && str[i]==str[j]){
				i=i-1;
				j=j+1;
			}
			if(i<0 || str[i]<str[j]){
        i=len/2;
        j=i;
        if(len%2==0){
          i=i-1;
        }
				k=1;
				while(i>=0){
					m=((str[i]-'0')+k);
					k=m/10;
				    str[i]=(m%10)+'0';
				    str[j]=str[i];
				    i=i-1;
				    j=j+1;
				}
			}else{
				while(i>=0){
					str[j]=str[i];
					i=i-1;
					j=j+1;
				}
			}
			cout<<str<<endl;
		}
	}
	return 0;
}

