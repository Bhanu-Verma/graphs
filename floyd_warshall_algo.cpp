#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nV 4
#define INF 999

void floydWarshall(int graph[][nV]){
    for(int k=0; k<nV; k++){
        for(int i=0; i<nV; i++){
            for(int j=0; j<nV; j++){
                if(graph[i][k] + graph[k][j] < graph[i][j]){
                     graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}


int main() {
  int graph[nV][nV] = {{0, 3, INF, 5},
             {2, 0, INF, 4},
             {INF, 1, 0, INF},
             {INF, INF, 2, 0}};
  floydWarshall(graph);

        for(int i=0; i<nV; i++){
            for(int j=0; j<nV; j++){
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }
    return 0;
}