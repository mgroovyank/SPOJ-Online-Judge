#include <iostream>
#include <string>
#include <map>
using namespace std;
struct trieNode{ 
    map<char,struct trieNode*> children;
    bool endOfWord; 
}; 
struct trieNode* createTrieNode(){
  struct trieNode *node = new trieNode;
  node->endOfWord=false;
  return node;
}
void insert(struct trieNode *root,string s){
  trieNode *current = root;
  for(int i=0;i<s.length();i++){
    map<char, struct trieNode*>::iterator itr= current->children.find(s[i]);
    if(itr==current->children.end()){
      struct trieNode *node=createTrieNode();
      current->children.insert(pair<char, struct trieNode*>(s[i],node));
      current=node;
    }else{
      current=itr->second;
    } 
  }
  current->endOfWord=true;
}
bool search(struct trieNode *root,string s){
  trieNode *current = root;
  for(int i=0;i<s.length();i++){
    map<char, struct trieNode*>::iterator itr= current->children.find(s[i]);
    if(itr==current->children.end()){
      return false;
    }
    current=itr->second;
    if(current->children.empty()){
      return false;
    }
  }
  return true;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    struct trieNode *root=createTrieNode();
    string s[n];
    for(int i=0;i<n;i++){
      cin>>s[i];
      insert(root,s[i]);
    }
    bool ans=true;
    for(int i=0;i<n;i++){
      if(search(root,s[i])){
        ans=false;
        break;
      } 
    }
    if(ans){
      cout<<"YES";
    }else{
      cout<<"NO";
    }
    cout<<"\n";

  }
}
