#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3;

int parent[N];
int size[N];
        //Kruksal's algorithm
//arrange the edges in sorted order 
//start inserting them in the graph if there 
// is no loop then insert it in the tree otherwise not

//Most crucial part of the algorithm is to find that if we insert an edge then there will be a looop or not
//for this we can use disjoint set
//if we are putting an edge between two nodes and they are part of same component then we can't put a node between them

//make function--
void make(int v){
    parent[v] = v;
    size[v] = 1;
}

int find(int v){
    if(v==parent[v]) return v;
    return parent[v] = find(parent[v]);
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
    int total_cost = 0;
    for(auto &edge:edges){
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if(find(u)==find(v)){
            continue;
        }else{
            total_cost += wt;
            Union(u,v);
            cout<<u<<" "<<v<<endl;
        }
    }
    cout<<total_cost<<endl;
    return 0;
}