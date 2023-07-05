#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3;
vector<int> adjlist[N]; 
vector<int> visited(N,0);
vector<int> dist(N,0);     //for storing distance of all the nodes from source node assuming that weight is 1


//prob -- given a graph in which all the edges have same weight 
//find shortest path in the tree..

//logic - think that in bfs we are traversing levelwise so from source node we'll get all the nodes on least distance


void bfs(int source){
    queue<int> q;
    q.push(source);
    visited[source] = 1;
    dist[source] = 0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout<<x<<" ";
        for(auto child:adjlist[x]){
            if(!visited[child]){
                q.push(child);
                visited[child] = 1; 
                dist[child] = dist[x]+1;
            }
        }
    }
}


int main(){
    int n;
    cout<<"Enter the number of nodes in tree:";
    cin>>n;
    int m;
    cout<<"Enter the number of edges in the graph:";
    cin>>m;
    cout<<"give the information about the edges:";
    while(m--){
        int u,v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    bfs(1);
    for(int i=1; i<=n; i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    return 0;
}