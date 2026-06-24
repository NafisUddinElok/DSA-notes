#include <bits/stdc++.h>
using namespace std;

int main(){
    deque<int> dq;

    dq = {1, 2, 3, 4, 5};
    dq.push_front(100);
    dq.push_front(200);
    dq.push_back(500);
    dq.push_back(550);
    for(int i : dq){
        cout << i << " ";
    }
    cout << endl;
}