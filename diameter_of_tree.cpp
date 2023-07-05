#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3;
vector<int> adjlist[N]; 
vector<int> depth(N);

            /*prob--find diameter of a tree*/
/*diameter--max possible distance b/w any two nodes of the tree*/

/*logic--take any node as root node and find the max-distance node.
* whatever node you got it will definitly be an end of the diameter of tree
now when we apply dfs with that node as root we will get the max depth
*/


void dfs(int vertex, int parent){
    if(parent==-1){
        depth[vertex]=0;
    }
    for(auto i:adjlist[vertex]){
        if(parent!=i){
            depth[i]=depth[vertex]+1;
            dfs(i,vertex);

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
    int max_depth_vertex=1;
    for(int i=1; i<=n; i++){
        if(depth[i]>=depth[max_depth_vertex]){
            max_depth_vertex = i;
        }
    }

    cout<<max_depth_vertex<<endl;

    //now we will apply dfs on max_depth_vertex

    dfs(max_depth_vertex,-1);
    int ans = 0;
    for(int i=1; i<=n; i++){
        if(depth[i]>ans){
            ans=depth[i];
        }
    }
    cout<<ans;
    return 0;
}