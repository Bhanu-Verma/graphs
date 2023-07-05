#include <bits/stdc++.h>
using namespace std;
const int N = 1e2;
int parent[N];
int size[N];
        /*  DISJOINT SET UNION */
//THERE ARE THREE FINCTIONS IN THEM
//1) MAKE -- ADDS A NEW INDEPENDENT NODE
//2) FIND -- GIVES PARENT OF THE GROUP
//3) UNION -- TAKE UNION OF TWO GROUOPS
   
//path compression -- in this algo we are finding ultimate parent so we directly add the child to ultimate parent

   
    /*make a new component for v*/
void make(int v){
    parent[v] = v;
    size[v] = 1;
    //because if something is parent of itself it is an independent component

} 
   
    /*find parent of component haveing v*/
int find(int v){
    if(v==parent[v]) return v;

    return parent[v] = find(parent[v]);

}
   
    /*take union of components having a and b*/
void Union(int a, int b){
    //first find the roots
    a = find(a);
    b = find(b);
    //for optimizing we add smaller tree to the biger one
    if(a!=b){
        if(size[a] < size[b]){
            swap(a,b);
        }
        parent[b] = a;
        size[a] += size[b];    //because they have been merged
    }else{
        //do nothing because both are already in same component

    }
}

