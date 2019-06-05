#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int block;
int freq[1000001]={0};
int arr[3000001],n,q;
struct query{
  int l,r,idx;
};
query queries[200000];
bool comparator(query x,query y){
  if(x.l/block!=y.l/block){
    return x.l/block<y.l/block;
  }
  return x.r<y.r;
}
void distinct(){
  block=(int)sqrt(n);
  sort(queries,queries+q,comparator);
  int cl,cr,count;
  cl=queries[0].l;
  cr=cl;
  count=1;
  freq[arr[cl]]++;
  int ans[q],i;
  for(i=0;i<q;i++){
    while(cl<queries[i].l){
      freq[arr[cl]]--;
      if(freq[arr[cl]]==0){
        count--;
      }
      cl++;
    }
    while(cl>queries[i].l){
      cl--;
      freq[arr[cl]]++;
      if(freq[arr[cl]]==1){
        count++;
      }
    }
    while(cr<queries[i].r){
      cr++;
      freq[arr[cr]]++;
      if(freq[arr[cr]]==1){
        count++;
      }
    }
    while(cr>queries[i].r){
      freq[arr[cr]]--;
      if(freq[arr[cr]]==0){
        count--;
      }
      cr--;
    }
    ans[queries[i].idx]=count;
  }
  for(i=0;i<q;i++){
    cout<<ans[i]<<"\n";
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while(cin>>n){
    int i;
    for(i=0;i<n;i++){
      cin>>arr[i];
    }
    cin>>q;
    for(i=0;i<q;i++){
      queries[i].idx=i;
      cin>>queries[i].l>>queries[i].r;
      queries[i].l--;
      queries[i].r--;
    }
    distinct();
  }
  return 0;
}
