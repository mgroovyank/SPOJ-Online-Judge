#include <bits/stdc++.h>
using namespace std;
struct node{
  int sum,prefixsum;
  int suffixsum,maxsum;
};
int arr[50010];
node st[4*50010];
void build(int cn,int start,int end){
  if(start==end){
    st[cn].sum = arr[start];
    st[cn].prefixsum = arr[start];
    st[cn].suffixsum = arr[start];
    st[cn].maxsum = arr[start];
   }else{
     int mid = (start+end)/2;
     build(2*cn+1,start,mid);
     build(2*cn+2,mid+1,end);
     st[cn].sum=st[2*cn+1].sum + st[2*cn+2].sum;
     st[cn].prefixsum=max(st[2*cn+1].prefixsum,st[2*cn+1].sum + st[2*cn+2].prefixsum);
     st[cn].suffixsum=max(st[2*cn+2].suffixsum,st[2*cn+2].sum + st[2*cn+1].suffixsum);   
     st[cn].maxsum=max(st[cn].prefixsum,max(st[cn].suffixsum,max(st[2*cn+1].maxsum,max(st[2*cn+2].maxsum,st[2*cn+1].suffixsum+st[2*cn+2].prefixsum))));
   }
}

void update(int cn,int start,int end,int idx,int val){
   if(start == end){
      st[cn].sum = val;
      st[cn].prefixsum=val;
      st[cn].suffixsum=val;
      st[cn].maxsum=val;
   }else{
      int mid = (start + end) / 2;
      if(idx<=mid){
        update(2*cn+1,start,mid,idx,val);
      }else{
        update(2*cn+2,mid+1,end,idx,val);
      }
      st[cn].sum=st[2*cn+1].sum + st[2*cn+2].sum;
      st[cn].prefixsum=max(st[2*cn+1].prefixsum,st[2*cn+1].sum + st[2*cn+2].prefixsum);
      st[cn].suffixsum=max(st[2*cn+2].suffixsum,st[2*cn+2].sum + st[2*cn+1].suffixsum);   
      st[cn].maxsum=max(st[cn].prefixsum,max(st[cn].suffixsum,max(st[2*cn+1].maxsum,max(st[2*cn+2].maxsum,st[2*cn+1].suffixsum +st[2*cn+2].prefixsum))));
   }
}

node findMax(int cn,int start,int end,int l,int r){
   node result;
   result.sum=result.prefixsum=INT_MIN;
   result.suffixsum=result.maxsum=INT_MIN;
   
   if(r<start || end<l){
     return result;
   }
   if(l<=start && end<=r){
     return st[cn];
   }   
   int mid=(start+end)/2;
   if(l>mid){
     return findMax(2*cn+2,mid+1,end,l,r);
   }     
   if(r<=mid){
      return findMax(2*cn+1,start,mid,l,r);
   }
   node left=findMax(2*cn+1,start,mid,l,r);
   node right=findMax(2*cn+2,mid+1,end,l,r);
   
   result.sum = left.sum + right.sum;
   result.prefixsum=max(left.prefixsum, left.sum + right.prefixsum);
   result.suffixsum=max(right.suffixsum, right.sum + left.suffixsum);
   result.maxsum=max(result.prefixsum,max(result.suffixsum,max(left.maxsum,max(right.maxsum,left.suffixsum + right.prefixsum))));
   return result;            
}

int main(){
  int n,m,x,y,type;
  cin>>n;
  int i;
  for(i=0;i<n;i++){
    cin>>arr[i];
  }
  build(0,0,n-1);
  cin>>m;
  for(i=0;i<m;i++){
    cin>>type>>x>>y;
    if(type){
      cout<<findMax(0,0,n-1,x-1,y-1).maxsum<<"\n";
    }else{
      update(0,0,n-1,x-1,y);
    }
  }
}
