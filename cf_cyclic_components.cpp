#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>

void dfs(int src, vector<int> adj[], int visited[], stack<int> &st){
    visited[src] = 1;
    st.push(src);
    for(auto nbr : adj[src]){
        if(!visited[nbr]){
            dfs(nbr,adj,visited,st);

        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    int visited[n+1] = {0};
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            stack<int> st;
            dfs(i,adj, visited, st);
            bool flag = true;
            while (!st.empty())
            {
                int x = st.top();
                st.pop();
                if(adj[x].size()!=2){
                    flag =false;
                    break;
                }
            }
            if(flag == false){
                continue;
            }else{
                ans++;
            }
        }
        
        
    }

    cout<<ans<<endl;
    return 0;
}