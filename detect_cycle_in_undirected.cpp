#include<bits/stdc++.h>
using namespace std;
#define ll long long

            /*detect cycle in aundirected graph*/


const int N=1e3;        
vector<pair<int,int>> adjlist[N];     
vector<int> visited(N+1);   


//Here we are going to store parent node also
bool detect_loop(int source, int parent){

    visited[source]=1;      
    bool isloop = false;
    for(auto j:adjlist[source]){
        
        if(visited[j.first]==1 && j.first!=parent){
            cout<<"loop is present \n";
            return true;
        }
        if(visited[j.first]!=1){
            
            visited[j.first]=1;

            isloop |= detect_loop(j.first, source);
           
            
        }
        
    }

    return isloop;
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
    
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            detect_loop(i,-1);
        }
    }

    return 0;
}