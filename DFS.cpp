#include<iostream>
#include<vector>
#include<list>
using namespace std;
class graph{
public:
   list<int> *adjlist;
   int n;
   graph(int v){
   adjlist=new list<int> [v];
   n=v;
   }
 void addedge(int u,int v,bool bi){
   adjlist[u].push_back(v);
   if(bi){
       adjlist[v].push_back(u);
    }
   }
 void print(){
   for(int i=0;i<n;i++){
       cout<<i<<"--->";
       for(auto it:adjlist[i]){
           cout<<it<<" ";
       }
       cout<<endl;
   }
   cout<<endl;
 }

void DFS(int start) {
    vector<bool>visited(n, false);
    DFSUtil(start, visited);
}

void DFSUtil(int vertex, vector<bool> &visited) {
    visited[vertex] = true;
    cout << vertex << " ";
    for (int neighbor : adjlist[vertex]) {
        if (!visited[neighbor]) {
            DFSUtil(neighbor, visited);
        }
    }
}
};

int main() {
    graph g(5);
    g.addedge(1,2,true);
    g.addedge(4,2,true);
    g.addedge(1,3,true);
    g.addedge(4,3,true);
    g.addedge(1,4,true);

    g.print();

    cout << "DFS starts at vertx 1: ";
    g.DFS(1);
}