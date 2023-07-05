#include "graph.cpp"
int parent[N];
int size[N];

void make(int x){
    if(x>=N){
        cout<<"Bhai na ho paga\n";
        return;
    }
    size[x] = 1;
    parent[x] = -1;
}

int find(int x){
    if(parent[x]==-1){
        return x;
    }
    return parent[x] = find(parent[x]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(size[a] < size[b]){
        swap(a,b);
    }
    parent[b] = a;
    size[a] += size[b];
}

int main(){
    vector<pair<int, pair<int,int>>> edges;
    
    int n;
    cout<<"give the number of elements in the graph:";
    cin>>n;
    for(int i=1; i<=n; i++){
        make(i);
    }

    int choice;
    cout<<"press 0 if graph is undirected and 1 if graph is directed:";
    cin>>choice;

    
    int m;
    cout<<"give the number of edges in the graph:";
    cin>>m;
    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({wt,{u,v}});
    }

    sort(edges.begin(),edges.end());
    int ans=0;
    for(auto edge:edges){
        int u = edge.second.first;
        int v = edge.second.second;
        int w = edge.first;

        if(find(u)==find(v)){
            continue;
        }else{
            Union(u,v);
            cout<<u<<" "<<v<<endl;
            ans += w;
        }
    }
    cout<<ans<<endl;
    return 0;
}
