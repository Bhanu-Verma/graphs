#include<bits/stdc++.h>
using namespace std;
#define ll long long
        /*given an undirected graph find the number of components*/
const int N=1e3;        //assuming that limit of input is 10^3
//int graph[N][N];
vector<pair<int,int>> adjlist[N];     //this is an array of type vector<int>
vector<int> visited(N+1);   //to keep track of visited elements

        /*to store all the connected components*/
vector<vector<int>> cc;
vector<int> current_cc;  

void dfs(int source){
    visited[source]=1;
    current_cc.push_back(source);
    for(auto i:adjlist[source]){
        if(!visited[i.first]){
            dfs(i.first);
        }
    }
}

int main(){
    int n;
    cout<<"give the number of elements in the graph:";
    cin>>n;
    int choice;
    cout<<"press 0 if graph is undirected and 1 if graph is directed:";
    cin>>choice;
    int m;
    cout<<"give the number of edges in the graph:";
    cin>>m;

    //if you don't want to declare graph globally --
    //int arr[n+1][n+1]     assuming that nodes start from 1

    if(choice==0){
        for(int i=0; i<m; i++){
            int u,v,w;        //there is an edge b/w u and v
            cin>>u>>v>>w;
           // graph[u][v]=graph[v][u]=w;
            adjlist[u].push_back({v,w});        
            adjlist[v].push_back({u,w});  
              
        }
    }else{
        for(int i=0; i<m; i++){
            int u,v,w;
            cin>>u>>v>>w;   //there is an edge b/w u and v having weight w
          //  graph[u][v]=w;
            adjlist[u].push_back({v,w});
        }
    }
    
    //Logic -- apply dfs in dfs we get all the complete connected segment in one call so we'll
    //increment counter on the every call that we make from main
    int count=0;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            count++;
            current_cc.clear();  //for every component sending an empty vector
            dfs(i);
            cc.push_back(current_cc);
        }
    }
    cout<<"number of connected components="<<count<<endl;
    for(auto i:cc){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}