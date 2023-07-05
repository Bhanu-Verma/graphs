#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
vector<int> graph[N];

void dfs(int &timer, int discovery[], int low[], int parent, int visited[], int src){
    //set the values for the source
    cout<<"source="<<src<<" "<<"parent="<<parent<<endl;
    discovery[src] = low[src] = timer++;
    visited[src] = 1;
    
    //traverse all the neighbours
    for(auto nbr:graph[src]){
        if(nbr==parent){
            //Here we needn't do anything
            continue;
        }
        if(!visited[nbr]){
            dfs(timer,discovery,low,src,visited,nbr);
            //update low value after calling the function as in the function call maybe 
            //value changed due to back edges
            low[src] = min(low[src],low[nbr]);

            if(low[nbr] > discovery[src]){
                //this means that we can go to the neighbour only by using source
                //so if we remove this edge this will disconnect the graph
                cout<<"bridge b/w "<<src<<" and "<<nbr<<endl;
 
            }
        }else{
            low[src] = min(low[src],discovery[nbr]);
        }
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

    for(int i=0; i<v; i++){
        discovery[i]=-1;
        low[i]=-1;
        visited[i]=0;
    }

    //call dfs with 0 as source
    dfs(timer,discovery,low,-1,visited,0);

    return 0;
}