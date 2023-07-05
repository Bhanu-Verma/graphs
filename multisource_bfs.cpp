#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3;
vector<int> adjlist[N]; 
vector<int> visited(N,0);
vector<int> dist(N,0);     //for storing distance of all the nodes from source node assuming that weight is 1

/*Prob -- in normal bfs we have a source node and a destination but in multisource bfs we have two or more source nodes and we need to go to a given destination in minimum distance*/

/*logic--we know that in queue there can be at max two levels at a time 
* we put all the source nodes to the queue at starting only (because staritng means that distance = 0 and we can start from any of the nodes => for all of them distance is 0 only)
* then we apply logic of bfs and correspodingly we will reach the given node from all the sources
* but here we can't go to a node more than one time because we are applying bfs with all the source node 
* so we'll reach the destination with guarantedly shortest path

*/

void bfs(vector<int> sources)
{   
    queue<int> q;
    for(int i=0; i<sources.size(); i++){
        q.push(sources[i]);
        dist[sources[i]]=0;
        visited[sources[i]]=1;
    }
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto i:adjlist[x]){
            if(!visited[i]){
                q.push(i);
                dist[i] = dist[x] + 1;
                visited[i] = 1;
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
    vector<int> sources;
    cout<<"give the three source nodes:";
    for(int i=0; i<3; i++){
        int x;
        cin>>x;
        sources.push_back(x);
    }
    bfs(sources);
    for(int i=1; i<=n; i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    return 0;
}
