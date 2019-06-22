#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const int N=100005;
long long int lz[4*N];
long long int st[4*N];
void fillVal(int cn){
  int l=2*cn+1;
  int r=2*cn+2;
  st[cn]=st[l]+st[r];
}
void createST_util(int l,int r,int cn){
  if(l==r){
    st[cn]=0;
    return;
  }
  int mid=l+(r-l)/2;
  createST_util(l,mid,2*cn+1);
  createST_util(mid+1,r,2*cn+2);
  fillVal(cn);
}
void addNum(int l,int r,int p,int q,long long int v,int cn){
  if(lz[cn]!=0){
    st[cn]+=(r-l+1)*lz[cn];
    if(l!=r){
      lz[2*cn+1]+=lz[cn];
      lz[2*cn+2]+=lz[cn];
    }
    lz[cn]=0;
  }
  if(p>r || q<l){
    return;
  }
  if(l>=p && r<=q){
      st[cn]+=(r-l+1)*v;
      if(l!=r){
        lz[2*cn+1]+=v;
        lz[2*cn+2]+=v;
      }
      return;
  }
  int mid=l+(r-l)/2;
  addNum(l,mid,p,q,v,2*cn+1);
  addNum(mid+1,r,p,q,v,2*cn+2);
  st[cn]=st[2*cn+1]+st[2*cn+2];
}
long long int sum(int l,int r,int p,int q,int cn){
  if(lz[cn]!=0){
    st[cn]+=(r-l+1)*lz[cn];
    if(l!=r){
      lz[2*cn+1]+=lz[cn];
      lz[2*cn+2]+=lz[cn];
    }
    lz[cn]=0;
  }
  if(p>r ||q<l){
    return 0;
  }
  if(l>=p && r<=q){
    return st[cn];
  }
  int mid=l+(r-l)/2;
  return sum(l,mid,p,q,2*cn+1)+sum(mid+1,r,p,q,2*cn+2);
}
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,c;
    cin>>n>>c;
    int i;
    int u,p,q;
    memset(st,0,sizeof(st));
    memset(lz,0,sizeof(lz));
    createST_util(0,n-1,0);
    while(c--){
      cin>>u;
    if(u==0){
      int v;
      cin>>p>>q>>v;
      addNum(0,n-1,p-1,q-1,v,0);
    }else if(u==1){
      cin>>p>>q;
      cout<<sum(0,n-1,p-1,q-1,0)<<"\n";
    }
    }
  }
  return 0;
}
