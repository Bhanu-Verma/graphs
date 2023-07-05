#include "graph.cpp"
vector<int> dist(N,INT_MAX);
set<pair<int,int>> st;   

//prob--given a graph with weights find the shortest distance from a given node

//logic -- here we use a set of pair--first is distance of the node and second is node itself
// we take weight at first because we want to take out minimum distance every time
//i)    initially all distances are infinity.
//ii)   put the source node in a list
//iii)  make distance of source = 0
//iv)   now we will go to all the children of a node if we can minimize the distance then we'll
//minimize it and push it to our priority queue
//v)    again until priority queue is empty we'll follow the same procedure
//vi)   every time we take the minimum distance node outside
//vii)  also keep track of the visited nodes when something comes out of the queue it has been processed completely so we mark its visited as true.

void dijkstra(int source){
    dist[1] = 0;
    st.insert({0,1});

    while(st.size()>0){
        auto dist_node = *st.begin();
        int node = dist_node.second;
        int node_dist = dist_node.first;
        st.erase(*st.begin());
        visited[node] = 1;
        for(auto child:adjlist[node]){
            int child_node = child.first;
            int child_weight = child.second;
            if(!visited[child_node]){
            if(child_weight + node_dist < dist[child_node]){
                dist[child_node] = child_weight + node_dist;
                st.insert({dist[child_node],child_node});
            }
            }  
        }
    }
}


int main(){
    int n=input_graph();
    int source = 1;
    
    dijkstra(source);

    for(int i=1; i<=n; i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    return 0;
}