#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3;
vector<int> adjlist[N]; //Here we declare arrays globally so if we are doing a que with multiple test cases
                        //every time we'll have to reset the arrays
vector<int> visited(N,0);
vector<int> level(N,0);     //for storing level of all the nodes


void bfs(int source){
    queue<int> q;
    visited[source] = 1;
    q.push(source);
    
    while(!q.empty()){           
        int x=q.front();
        cout<<x<<" ";
        q.pop();
        for(auto i:adjlist[x]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
                level[i] = level[x]+1;
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
    level[1]=0;
    bfs(1);
    for(int i=1; i<=n; i++){
        cout<<level[i]<<" ";
    }cout<<endl;
    return 0;
}