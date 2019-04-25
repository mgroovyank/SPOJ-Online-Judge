#include <iostream>
#include <stack>
#include <cstdio>
#include <vector>
using namespace std;
int ko;
int n,m;
vector<int>v[10001];   //adjaency list
int  dfs()
{
    int i,j,k;
    stack<int>s;
    bool visit[10010];
    for(i=1;i<=n;i++)
    {
        visit[i]=0;
    }
    s.push(1);
    ko=0;

    while(s.size()>0)
    {
        ko++;
        j=s.top();
        s.pop();
        if(visit[j]==true)
        {
     return 0;
        }
        visit[j]=true;
        for(i=0;i<v[j].size();i++)
        {
         s.push(v[j][i]);   
        }
    }
  
if(ko==n)
   return 1;
   else
   return 0;
}
int main() {
    int i,j,k,io,ko;
scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
     scanf("%d %d",&j,&k);
        v[j].push_back(k);
    }
k=    dfs();
    if(k==1&&(m+1==n))
    printf("YES\n");
    else
printf("NO\n");
    return 0;
}
