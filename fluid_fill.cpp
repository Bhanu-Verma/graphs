#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*prob--Here we are given a 2d matrix containing some values. ex-
1 1 1 2
1 1 0 2
1 1 3 1
1 2 0 1

the edges that have same value and can be traversed by left,rihgt,up,down movement are considered
to be a same part. They can be visualized as a connected graph
NOTE--only left,right,up,down movements are allowed so one node can be connected to either 
to left or right or up or down

Task==change the coluor of graph to a given colour
*/


/*Logic--here we are going to use dfs on the matrix form of graph*/

void dfs(int i, int j, int initialColour, int finalColour, vector<vector<int>> &v){
    //node is connicted to up, down, left or right so we'll try to make 4 function calls-
    int n=v.size();
    int m=v[0].size();
    if(i<0 || j<0){
        return;
    }
    if(i>=n || j>=m){
        return;
    }

    //note if a block doesn't have same value as per its neighbours it's not a valid edge-
    if(v[i][j]!=initialColour) return;
    v[i][j]=finalColour;
    dfs(i-1,j,initialColour,finalColour,v);
    dfs(i+1,j,initialColour,finalColour,v);
    dfs(i,j+1,initialColour,finalColour,v);
    dfs(i,j-1,initialColour,finalColour,v);
}

int main(){
    int n,m;
    cout<<"give the number of rows and column in the matrix:";
    cin>>n>>m;
    vector< vector<int> > v(n, vector<int> (m));
    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++){
            cin>>v[i][j];
        }
    }
    
    int inclr, fclr;
    cout<<"give the valules of initial and final colurs:";
    cin>>inclr>>fclr;

    if(inclr!=fclr){
        dfs(0,0,inclr,fclr,v);
    }


    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

