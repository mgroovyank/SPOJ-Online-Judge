#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
struct AdjListNode { 
	int dest; 
	int weight; 
	struct AdjListNode* next; 
}; 
struct AdjList { 
	struct AdjListNode *head;
};
struct Graph{ 
	int V; 
	struct AdjList* arr; 
}; 
struct AdjListNode* newAdjListNode(int dest, int weight) { 
	struct AdjListNode* newNode=(struct AdjListNode*) malloc(sizeof(struct AdjListNode)); 
	newNode->dest = dest; 
	newNode->weight = weight; 
	newNode->next = NULL; 
	return newNode; 
} 
struct Graph* createGraph(int V){ 
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph)); 
	graph->V = V; 
	graph->arr=(struct AdjList*)malloc(V * sizeof(struct AdjList)); 
	for (int i = 0; i < V; ++i){
    graph->arr[i].head=NULL; 
  } 
	return graph; 
} 
void addEdge(struct Graph* graph, int src, int dest, int weight){ 
	struct AdjListNode* newNode = newAdjListNode(dest, weight); 
	newNode->next = graph->arr[src].head;
	graph->arr[src].head = newNode;
	newNode = newAdjListNode(src, weight); 
	newNode->next = graph->arr[dest].head; 
	graph->arr[dest].head = newNode; 
} 
struct MinHeapNode{ 
	int v; 
	int dist; 
}; 
struct MinHeap{ 
	int size;
	int capacity;
	int *pos;	
	struct MinHeapNode **arr;
};
struct MinHeapNode* newMinHeapNode(int v, int dist){ 
	struct MinHeapNode* minHeapNode=(struct MinHeapNode*) malloc(sizeof(struct MinHeapNode)); 
	minHeapNode->v = v; 
	minHeapNode->dist = dist; 
	return minHeapNode; 
} 
struct MinHeap* createMinHeap(int capacity){ 
	struct MinHeap* minHeap=(struct MinHeap*) malloc(sizeof(struct MinHeap)); 
	minHeap->pos = (int *)malloc(capacity * sizeof(int)); 
	minHeap->size = 0; 
	minHeap->capacity = capacity; 
	minHeap->arr=(struct MinHeapNode**) malloc(capacity * sizeof(struct MinHeapNode*)); 
	return minHeap; 
} 
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) { 
	struct MinHeapNode* t = *a; 
	*a = *b; 
	*b = t; 
}
void minHeapify(struct MinHeap* minHeap, int idx){ 
	int smallest, left, right; 
	smallest = idx; 
	left = 2 * idx + 1; 
	right = 2 * idx + 2; 
	if (left < minHeap->size && 
		minHeap->arr[left]->dist < minHeap->arr[smallest]->dist ) 
	smallest = left; 

	if (right < minHeap->size && 
		minHeap->arr[right]->dist < minHeap->arr[smallest]->dist ) 
	smallest = right; 

	if (smallest != idx){
		MinHeapNode *smallestNode = minHeap->arr[smallest]; 
		MinHeapNode *idxNode = minHeap->arr[idx]; 

		minHeap->pos[smallestNode->v] = idx; 
		minHeap->pos[idxNode->v] = smallest; 
		swapMinHeapNode(&minHeap->arr[smallest], &minHeap->arr[idx]); 
		minHeapify(minHeap, smallest); 
	} 
} 
int isEmpty(struct MinHeap* minHeap){ 
	return minHeap->size == 0; 
} 
struct MinHeapNode* extractMin(struct MinHeap* minHeap) { 
	if (isEmpty(minHeap)) 
		return NULL; 
	struct MinHeapNode* root = minHeap->arr[0]; 
	struct MinHeapNode* lastNode = minHeap->arr[minHeap->size - 1]; 
	minHeap->arr[0] = lastNode; 
	minHeap->pos[root->v] = minHeap->size-1; 
	minHeap->pos[lastNode->v] = 0; 
	--minHeap->size; 
	minHeapify(minHeap, 0); 
	return root; 
}
void decreaseKey(struct MinHeap* minHeap, int v, int dist) 
{
	int i = minHeap->pos[v]; 
	minHeap->arr[i]->dist = dist; 
	while (i && minHeap->arr[i]->dist < minHeap->arr[(i - 1) / 2]->dist){ 
		minHeap->pos[minHeap->arr[i]->v] = (i-1)/2; 
		minHeap->pos[minHeap->arr[(i-1)/2]->v] = i; 
		swapMinHeapNode(&minHeap->arr[i], &minHeap->arr[(i - 1) / 2]); 
		i = (i - 1) / 2; 
	} 
}
bool isInMinHeap(struct MinHeap *minHeap, int v){ 
if (minHeap->pos[v] < minHeap->size) 
	return true; 
return false; 
}
void dijkstra(struct Graph* graph, int src, int temp){ 
	int V = graph->V;
	int dist[V];	 
	struct MinHeap* minHeap = createMinHeap(V);  
	for (int v = 0; v < V; ++v){ 
		dist[v] = INT_MAX; 
		minHeap->arr[v] = newMinHeapNode(v, dist[v]); 
		minHeap->pos[v] = v; 
	}
	minHeap->arr[src]=newMinHeapNode(src, dist[src]); 
	minHeap->pos[src]=src; 
	dist[src]=0; 
	decreaseKey(minHeap,src,dist[src]);
	minHeap->size=V; 
	while (!isEmpty(minHeap)){
		struct MinHeapNode* minHeapNode = extractMin(minHeap); 
		int u = minHeapNode->v;  
    if(u==temp){
      break;
    }
		struct AdjListNode* pCrawl=graph->arr[u].head; 
		while (pCrawl != NULL){ 
			int v = pCrawl->dest; 
			if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX && pCrawl->weight + dist[u] < dist[v]){ 
				dist[v]=dist[u] + pCrawl->weight;
				decreaseKey(minHeap, v, dist[v]); 
			}
			pCrawl = pCrawl->next; 
		} 
	} 
	cout<<dist[temp]; 
}
int main(){
  int s;
  cin>>s;
  while(s--){
    int n;
    cin>>n;
    struct Graph* graph = createGraph(n);
    map<string, int> cities;
    for(int i=0;i<n;i++){
      string sx;
      cin>>sx;
      cities[sx]=i;
      int p;
      cin>>p;
      while(p--){
        int nr,cost;
        cin>>nr>>cost;
        addEdge(graph,i,nr-1,cost);
      }
    }  
    int r;
    cin>>r;
    pair<int,int> arr[r];
    for(int i=0;i<r;i++){
      string a,b;
      cin>>a>>b;
      arr[i]=make_pair(cities.find(a)->second,cities.find(b)->second);
    }
    for(int i=0;i<r;i++){
      dijkstra(graph,arr[i].first,arr[i].second);
      cout<<"\n";
    }
  } 
	return 0; 
} 
