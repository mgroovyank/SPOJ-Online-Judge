#include <iostream> 
#include <cstdlib>
using namespace std; 
long long int merge(int arr[],int temp[],int left,int mid,int right){
  int i, j, k;  
  long long int inv=0;  
  i=left; 
  j=mid; 
  k=left;
  while((i <= mid - 1) && (j <= right)){
    if (arr[i] <= arr[j]){
      temp[k++] = arr[i++];
      }else{
      temp[k++] = arr[j++];  
      inv=inv+(mid - i);  
      }  
  }  
  while(i <= mid - 1){
    temp[k++] = arr[i++];  
  }
  while(j <= right){
    temp[k++] = arr[j++];  
  }  
  for(i=left;i<=right;i++){
     arr[i]=temp[i];  
  }  
  return inv;  
}  
long long int _mergesort(int arr[],int temp[],int left,int right){  
  int mid;
  long long int inv=0;  
  if (right > left){
    mid = (right + left) / 2;  
        inv+=_mergesort(arr,temp,left,mid);  
        inv+=_mergesort(arr,temp,mid + 1,right);  
        inv+=merge(arr,temp,left,mid + 1,right);  
    }  
    return inv;  
}  
long long int mergesort(int arr[], int arr_size){  
    int* temp=(int*)malloc(sizeof(int)*arr_size);  
    return _mergesort(arr,temp,0,arr_size - 1);  
}
int main(){
  int t,n,i;
  long long int inv;
  cin>>t;
  cout<<"\n";
  while(t--){
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
      cin>>arr[i];
    }
    inv=mergesort(arr,n);
    cout<<inv<<"\n";
  }
  return 0;
} 
