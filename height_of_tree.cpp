#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3;
/*prob--given a tree write a code to calculate depth and height of all the nodes of the tree*/
vector<int> adjlist[N]; 
int depth[N];   //we are making two arrays to store answer for all the nodes
int height[N];

void dfs(int vertex, int parent){
    if(parent==-1){
        depth[vertex]=0;
    }
    for(auto i:adjlist[vertex]){
        if(i!=parent){
            depth[i]=depth[vertex]+1;
            dfs(i,vertex);
            height[vertex] = max(height[vertex],height[i]+1);
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
    dfs(1,-1);
    for(int i=1; i<=n; i++){
        cout<<depth[i]<<" ";
        //cout<<height[i]<<" ";
    }
    cout<<endl;
    for(int i=1; i<=n; i++){
       // cout<<depth[i]<<" ";
        cout<<height[i]<<" ";
    }
    return 0;
}