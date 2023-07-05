#include "graph.cpp"
vector<int> key(N+1,INT_MAX);
vector<int> parent(N+1,-1);
vector<int> mst(N+1,0);

int get_min(int n){
    int min_key = INT_MAX, min_node = -1;
    for(int i=1; i<=n; i++){
        if(mst[i]==false && key[i]<min_key){
            min_key = key[i];
            min_node = i;
        }
    }

    return min_node;
}

int main(){
    int n = input_graph();
    display_graph(n);
    key[1] = 0;
    parent[1] = -1;
    
    for(int i=1; i<=n-1; i++){
        int min_node = get_min(n);
        mst[min_node] = 1;
        for(auto j:adjlist[min_node]){
            if(mst[j.first]==0 && key[j.first]>j.second){
                key[j.first] = j.second;
                parent[j.first] = min_node;
            }
        }
    }

    for(int i=1; i<=n; i++){
        cout<<i<<" "<<parent[i]<<endl;
    }
    return 0;
}