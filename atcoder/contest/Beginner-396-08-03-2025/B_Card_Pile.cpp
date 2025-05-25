#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    stack<int> pilha;
    
    for (int i = 0; i < 100; i++){
        pilha.push(0);
    }
    
    int oper; cin >> oper;
    while (oper--){
        int x; cin >> x;
        if (x == 2) {
            cout << pilha.top() << "\n";
            pilha.pop();
        }
        else {
            int y; cin >> y;
            pilha.push(y);
        }   
    }

    cout << "\n";
}
