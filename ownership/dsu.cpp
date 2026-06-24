#include <bits/stdc++.h>
using namespace std;


// dsu implementation
vector<int> parent, rankv;

int findset(int a){
    if(parent[a] == a){
        return a;
    }
    else {
        parent[a] = findset(parent[a]); // for path compression
        return parent[a];
    }
}

void unionSet(int a, int b){

    // connecting the set containing a and the set containing b
    a = findset(a);
    b = findset(b);

    if(a == b) return; // same set
    
    if(rankv[a] > rankv[b]){
        parent[b] = a;
    }
    else if(rankv[a] < rankv[b]){
        parent[a] = b;
    }
    else if(rankv[a] == rankv[b]){
        parent[a] = b;
        rankv[b]++;
    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int n; cin >> n;
    int n = 5;
    // vector<int> a(n);

    parent.resize(n);
    rankv.resize(n);
    
    cout << "program started"<< endl;

    // parent[i] = i for all i
    for(int i= 0; i < n; i++){
        parent[i] = i;
    }

    // rankv[i] = 0 for all i
    for(int i= 0; i <n ; i++){
        rankv[i] = 0;
    }

    unionSet(0, 1);
    unionSet(1, 2);

    if(findset(0) == findset(2)){
        cout << "0 and 2 are in the same set\n";
    }
    else {
        cout << "0 and 2 are in different sets\n";
    }

    return 0;
}