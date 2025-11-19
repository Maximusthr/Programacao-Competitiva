#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    stack<pair<int, int>> pos;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        while(!pos.empty()){
            int v = pos.top().first;
            if (v < x){
                cout << pos.top().second << " ";
                pos.push({x, i+1});
                break;
            }
            else pos.pop();
        }
        if (pos.empty()){
            cout << 0 << " ";
            pos.push({x, i+1});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}