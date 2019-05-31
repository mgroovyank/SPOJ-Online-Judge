//This solution is not passing on spoj due to Time Limit exceeded but works for the test cases of spoj toolkit.
#include <iostream>
#include <cmath>
using namespace std;
struct node{
  int sum,maxSum,left,right;
};

void fillVal(node *st,int cn){
  int l=cn*2+1;
  int r=cn*2+2;
  st[cn].sum=st[l].sum+st[r].sum;
  st[cn].left=max(st[l].left,st[l].sum+st[r].left);
  st[cn].right=max(st[r].right,st[r].sum+st[l].right);
  st[cn].maxSum=max(max(st[l].maxSum,st[r].maxSum),st[r].left+st[l].right);
}

void createST_util(int arr[],int l,int r,node *st,int cn){
  if(l==r){
    st[cn].sum=st[cn].maxSum=st[cn].left=st[cn].right=arr[l];//left=prefix sum and right=suffix sum
    return;
  }
  int mid=l+(r-l)/2;
  createST_util(arr,l,mid,st,2*cn+1);
  createST_util(arr,mid+1,r,st,2*cn+2);
  fillVal(st,cn);
}

node* createST(int arr[],int n){
  int h=(int)ceil(log2(n));
  long long int nodes=2*(int)pow(2,h)-1;
  node *st=new node[nodes];
  createST_util(arr,0,n-1,st,0);
  return st;
}

node emptyNode(){
    node ret;
    ret.left = ret.right = ret.sum = ret.maxSum = 0;
    return ret;
}

node Combination(node a, node b){
    node ret;
    ret.sum = a.sum + b.sum;
    ret.left = max(a.left, a.sum + b.left);
    ret.right = max(b.right, b.sum + a.right);
    ret.maxSum = max(max(a.maxSum, b.maxSum), b.left + a.right); 
    return ret;
}

node findMaxSum(node *st,int l,int r,int x,int y,int cn){
  if(r<x || l>y){
    return emptyNode();
  }
  if(l>=x && r<=y){
    return st[cn];
  }
  int mid=l+(r-l)/2;
  if(y<=mid){
    return findMaxSum(st,l,mid,x,y,cn*2+1);
  }
  if(x>mid){
    return findMaxSum(st,mid+1,r,x,y,cn*2+2);
  }
  node LChild=findMaxSum(st,l,mid,x,y,cn*2+1);
  node RChild=findMaxSum(st,mid+1,r,x,y,cn*2+2);
  return Combination(LChild, RChild);
}
 
int main(){
  int n;
  while(cin>>n){
    int i,arr[n];
  for(i=0;i<n;i++){
    cin>>arr[i];
  }
  int m;
  cin>>m;
  while(m--){
    int x,y;
    cin>>x>>y;
    node *st=createST(arr,n);
    cout<<findMaxSum(st,0,n-1,x-1,y-1,0).maxSum<<"\n";
  }
  }
  return 0;
}
