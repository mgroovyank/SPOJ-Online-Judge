#include <iostream>
#include <string>
#define SIZE 122
using namespace std;
int ans;
struct trieNode{
  struct trieNode* children[SIZE];
  bool endOfWord;
};
struct trieNode* getNode(){
  struct trieNode* newNode = new trieNode;
  newNode->endOfWord=false;
  for(int i=0;i<SIZE;i++){
    newNode->children[i]=NULL;
  }
  return newNode;
}
void insert(struct trieNode* temp,string s){
  for(int i=0;i<s.length();i++){
    int idx=s[i];
    if(!temp->children[idx]){
      temp->children[idx]=getNode();
      ans++;
    }
    temp=temp->children[idx];
  }
  temp->endOfWord=true;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    ans=0;
    string s;
    cin>>s;
    struct trieNode *root= getNode();
    int l=s.length()-1;
    for(int i=l;i>=0;i--){
      insert(root,s.substr(i,s.length()-i));
    }
    cout<<ans<<"\n";
  }
  return 0;
}
