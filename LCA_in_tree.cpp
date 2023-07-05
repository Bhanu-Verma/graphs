#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3;
vector<int> adjlist[N]; 

/*prob--lca in a tree*/
/*logic--store the path of both the nodes from the root node
* last common element in both the arrays in lca
* now problem is to find the path that we can do using dfs--
* for this purpose we'll make a parent array that will store parent of all the nodes 
* using this array we'll find path of both the nodes
*/


vector<int> path(int node, vector<int> parents){
    vector<int> ans;
    ans.push_back(node);
    while(parents[node]!=-1){
        ans.push_back(node);
        node = parents[node];
    }
    ans.push_back(node);
    reverse(ans.begin(),ans.end());
    return ans;
}

void dfs(int vertex, int parent, vector<int> &parents){
    cout<<"entered\n";
    parents[vertex] = parent;
    for(auto i:adjlist[vertex]){
        if(i!=parent){
            //depth[i]=depth[vertex]+1;
            dfs(i,vertex,parents);
            //height[vertex] = max(height[vertex],height[i]+1);
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
   
    vector<int> parents(n+1,-1);
    dfs(1,-1, parents);
    for(int i=1; i<=n; i++){
        cout<<parents[i]<<" ";
    }
    cout<<endl;
    int node1, node2;
    cout<<"give the nodes that you want to use to find LCA:";
    cin>>node1>>node2;
    vector<int> path1 = path(node1, parents);
    vector<int> path2 = path(node2, parents);
    int lca = -1;
    int mn_size = min(path1.size(),path2.size());
    for(int i=0; i<mn_size; i++){
        if(path1[i]!=path2[i]){
            break;
        }else{
            lca = path1[i];
        }
    }
    cout<<"lowest common ancestor is:"<<lca<<endl;
    return 0;
}