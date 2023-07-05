#include<bits/stdc++.h>
using namespace std;
#define ll long long

//make a 2d matrix to store adjaceny list--
const int N=1e3;        //assuming that limit of input is 10^3
int graph[N][N];
vector<pair<int,int>> adjlist[N];     //this is an array of type vector<int>


int main(){
    //ADJACENCY MATRIX
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
            graph[u][v]=graph[v][u]=w;
            adjlist[u].push_back({v,w});        
            adjlist[v].push_back({u,w});  
              
        }
    }else{
        for(int i=0; i<m; i++){
            int u,v,w;
            cin>>u>>v>>w;   //there is an edge b/w u and v having weight w
            graph[u][v]=w;
            adjlist[u].push_back({v,w});
        }
    }
    cout<<"Adjacency matrix is :\n";
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=1; i<n+1; i++){
        cout<<i<<" ";
        for(auto j:adjlist[i]){
            cout<<"["<<j.first<<" "<<j.second<<"]";
        }
        cout<<endl;
    }
    return 0;
}