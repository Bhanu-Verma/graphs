#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3;
vector<pair<int,int>> adjlist[N]; 
vector<int> dist(N,INT_MAX);     //for storing distance of all the nodes from source node assuming that weight is 1

//prob -- in previous problem we saw that we can find shortest path using bfs if tree is unweighted
//mostly shortest path problems are solved using djkstras algo but if there are only two possible values of
//weight either 0 or 1 than 0-1 bfs may work

//logic -- in the queue while processing bfs at a time max two levels node may exist
//so if we get a zero weighted node we consider it in the previous level only not in the current one
//so to insert it at first node we use a deque because we are going to insert it at the end


//NOTE,NOTE,NOTE -- in 0,1 bfs we can't use visited array
// here we can process a node twice also at max so we don't use visited array

void bfs(int source){
    deque<int> dq;
    dq.push_back(source);
    dist[source] = 0;
    

    while(!dq.empty()){
        int curr_node = dq.front();
        dq.pop_front();
        cout<<curr_node<<" ";

        for(auto child:adjlist[curr_node]){
            if(dist[curr_node] + child.second < dist[child.first]){     //try to visualise it's obvious
                if(child.second==0){
                    dq.push_front(child.first);
                    dist[child.first] = dist[curr_node];
                }else{
                    dq.push_back(child.first);
                    dist[child.first] = dist[curr_node] + 1;
                }
                
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
        int u,v,w;
        cin>>u>>v>>w;
        adjlist[u].push_back({v,w});
        adjlist[v].push_back({u,w});
    }
    bfs(1);
    for(int i=1; i<=n; i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    return 0;
}