#include<bits/stdc++.h>
using namespace std;
int arr[200];
int i,len,carry,num,pos;

int main()
{
    string s;
    while(getline(cin,s))
    {
        len=i=carry=num=pos=0;
        memset(arr,0,sizeof(arr));
        len=s.length();
        pos=0;
        for(i=len-1;i>=0;i--,pos++)     
            arr[pos]=s[i]-'0';

        carry=0;
        for(i=0;i<len;i++)                   
        {
            num=(arr[i]*2) + carry;
            arr[i]=num%10;
            carry=num/10;
        }
        while(carry)
        {
            arr[i]=carry%10;
            carry/=10;
            if(carry)
                i++;
        }
        pos=i;                   
        i=0;
        if(arr[i]>=2)
            arr[i]-=2;
        else
        {
            arr[i]+=8;
            i++;
            arr[i]--;
        }

        while(1)
        {
            if(arr[i]>=0 || i==pos)
                break;
            else
            {
                arr[i]=9;
                i++;
                arr[i]--;
            }
        }
        while(arr[pos]==0)
            pos--;
        if(pos<0)
            cout<<1;
        for(i=pos;i>=0;i--)
            cout<<arr[i];
        cout<<endl;
    }
    return 0;

}
