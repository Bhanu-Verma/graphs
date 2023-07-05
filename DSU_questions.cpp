#include "disjoint_set.cpp"

//prob -- there were initially n independent cities
// but there  arose k fights as a result of which
// j merged into i
// find after all the k fights how many independent kihdoms are remaining



int main(){
    int n;  //total initial elements
    cin>>n;
    for(int i=1; i<=n; i++){
        make(i);
    }

    int k;     //k takeovers happened
    cin>>k;
    while(k--){
        int i,j;    //j merged into i
        cin>>i>>j;
        Union(i,j);
    }

    int count=0;
    for(int i=1; i<=n; i++){
        // if i is parent of its corresponding component then we willl increase the count
        if(find(i)==i){
            count++;
        }
    }

    cout<<count<<endl;
    return 0;
}