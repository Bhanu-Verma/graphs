#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>

void solve(){
    int n,m;
    cin>>n>>m;
    map<int,int> mp;
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        mp[u]++;
        mp[v]++;
    }
    map<int,int> mp2;
    for(auto i:mp){
        mp2[i.second]++;
    }

    //printing map
    // for(auto i:mp2){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
    int x,y,prod;
    if(mp2.size()==2){
        for(auto i:mp2){
            if(i.first==1){
                prod = i.second;
            }else{
                y = i.first - 1;
            }
        }
        cout<<prod/y<<" "<<y<<endl;
    }else{
        for(auto i:mp2){
            if(i.second==1){
                x = i.first;
            }
            if(i.first==1){
                prod = i.second;
            }
        }
        cout<<x<<" "<<prod/x<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}