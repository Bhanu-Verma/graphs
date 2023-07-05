#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
vector<int> graph[N];

void dfs(int &timer, int discovery[],int low[], int parent, int visited[], int src, set<int> &ap){
    discovery[src] = low[src] = timer++;
    visited[src] = 1;
    int child = 0;
    for(auto nbr:graph[src]){
        if(nbr==parent){
            continue;
        }
        if(!visited[nbr]){
            dfs(timer,discovery,low,src,visited,nbr,ap);
            low[src] = min(low[src],low[nbr]);
            if(low[nbr] >= discovery[src] && parent!=-1){
                ap.insert(src);
            }
            child++;
        }else{
            low[src] = min(low[src],discovery[nbr]);
        }
    }
    if(parent==-1 && child>1){
        ap.insert(src);
    }
}


int main(){
    //step1 -- take input of the graph
    int v,e;
    cin>>v>>e;
    for(int i=0; i<v;i++){
        graph[i].clear();
    }
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    //step2:make all the required data structures
    int timer = 0;
    int discovery[v];
    int low[v];
    int visited[v];
    set<int> ap;

    for(int i=0; i<v; i++){
        discovery[i]=-1;
        low[i]=-1;
        visited[i]=0;
    }

    //call dfs with 0 as source
    for(int i=0; i<v; i++){
        if(!visited[i])
            dfs(timer,discovery,low,-1,visited,i,ap);
    }
    cout<<"the following are the articulation points for the given graph:\n";
    while(!ap.empty()){
        int x = *ap.begin();
        cout<<x<<" ";
        ap.erase(x);
    }
    return 0;
}