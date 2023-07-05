#include "graph.cpp"

    
int main(){
    vector<pair<int, pair<int,int>>> edges;
    
    int n;
    cout<<"give the number of elements in the graph:";
    cin>>n;
    
    int choice;
    cout<<"press 0 if graph is undirected and 1 if graph is directed:";
    cin>>choice;

    
    int m;
    cout<<"give the number of edges in the graph:";
    cin>>m;
    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        if(choice == 0){
            edges.push_back({wt,{u,v}});
            edges.push_back({wt,{v,u}});
        }else{
            edges.push_back({wt,{u,v}});
        }
    }

    vector<int> dist(n+1,INT_MAX);
    dist[0] = 0;
    dist[1] = 0;

    for(int i=1; i<=n-1; i++){
        for(auto j:edges){
            int u = j.second.first;
            int v = j.second.second;
            int w = j.first;
            if(dist[u]!=INT_MAX && dist[u]+w <dist[v]){
                dist[v] = dist[u]+w;
            }
        }
    }

    for(auto j:edges){
            int u = j.second.first;
            int v = j.second.second;
            int w = j.first;
            if(dist[u]!=INT_MAX && dist[u]+w <dist[v]){
                cout<<"Negative cycle detected\n";
            }
        }


    for(auto j:dist){
        cout<<j<<" ";
    }
    return 0;
}