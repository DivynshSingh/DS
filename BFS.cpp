#include<iostream>
#include<list>
#include<queue>
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

void BFS(int startVertex) {
  bool* visited = new bool[n];
  for (int i = 0; i < n; i++) {
      visited[i] = false;
  }
  queue<int> q;
  visited[startVertex] = true;
  q.push(startVertex);
  while (!q.empty()) {
      int vertex = q.front();
      cout << vertex << " ";
      q.pop();
      for (auto it = adjlist[vertex].begin(); it != adjlist[vertex].end(); ++it) {
          if (!visited[*it]) {
              visited[*it] = true;
              q.push(*it);
          }
      }
     }
  delete[] visited;
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

    cout << "BFS starts from vertex 4:";
    g.BFS(4);
}