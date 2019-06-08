#include <iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main() {
    int n;
    int half=0,one4=0,three4=0;
    scanf("%d",&n);
    int x,y;
    char op;
    while(n--)
    {
     cin>>x>>op>>y;
     if(x==1 && y==4) one4++;
     if(x==1 && y==2) half++;
     if(x==3 && y==4) three4++;
    }
    int sum=three4;
    three4-=one4;
    if(three4<0)
      {
          double k=(-three4 * 1.0/4.0);
          sum=sum+(int)k; 
          k=k-(int)k;
          k=1-k;
          if(k>=0.5 && half>0)
            half--;
          sum++;
      }
    sum=sum+(ceil(half*0.5));
    sum=sum+1;
    printf("%d\n",sum);
    return 0;
}
