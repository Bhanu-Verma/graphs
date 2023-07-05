#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3;
vector<int> adjlist[N]; 
/*given Q quires -
 for each quirie given a node V
 print subtree sum of V and count of even numbers in subtree of V
*/

//here we have to precompute the sum of subtrees

int subtree_sum[N]; //to store sum of subtree
int even_count[N];

void dfs(int vertex, int parent){
    if(vertex%2==0) even_count[vertex]++;
    subtree_sum[vertex]+=vertex;
    for(auto child : adjlist[vertex]){
        if(child!=parent){
            dfs(child,vertex);
            subtree_sum[vertex]+=subtree_sum[child];
            even_count[vertex]+=even_count[child];
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
        cout<<subtree_sum[i]<<" ";
    }
    cout<<endl;
    for(int i=1; i<=n; i++){
        cout<<even_count[i]<<" ";
    }
    cout<<endl;
    return 0;
}
