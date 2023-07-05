#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
vector<int> graph[N];


int main(){
    //step1 -- take input of the graph
    int v,e;
    cin>>v>>e;
    for(int i=0; i<v;i++){
        graph[i].clear();
    }
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    //step2 -- make all the necessary ds and color vertex 0 with color 0 
    vector<int> color_of_vertex(v,-1);
    vector<bool> available(v,true);
    color_of_vertex[0] = 0;
    int chromatic_number = 0;


    //step3 -- color all the other vertices
    for(int i=1; i<v; i++){
        for(auto child:graph[i]){
            if(color_of_vertex[child]!=-1){
                available[color_of_vertex[child]] = false;
            }
        }
        int j;
        for(j=0; j<v; j++){
            if(available[j]==true){
                color_of_vertex[i] = j;
                break;
            }
        }

        chromatic_number = max(chromatic_number,j+1);

        for(int i=0; i<v; i++){
            available[i] = true;
        }
    }
    
    cout<<"minimum number of colors required to color the  graph:";
    cout<<chromatic_number<<endl;
    cout<<"color of the vertices is:\n";
    for(int i=0; i<v; i++){
        cout<<color_of_vertex[i]<<" "; 
    }

    return 0;
}