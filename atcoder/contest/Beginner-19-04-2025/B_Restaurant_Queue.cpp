#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    queue<pair<int,int >> fila;

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (x == 1) {
            int y; cin >> y;
            fila.push({x, y});
        }
        else if (x == 2){
            cout << fila.front().second << "\n";
            fila.pop();
        }
    }
}
