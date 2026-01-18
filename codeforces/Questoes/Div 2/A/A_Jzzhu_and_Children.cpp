#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    queue<pair<int, int>> arr;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        arr.push({x, i});
    }

    while(!arr.empty()){
        if (arr.size() == 1){
            cout << arr.front().second + 1 << "\n";
            return;
        }
        auto x = arr.front();
        arr.pop();

        x.first -= m;
        if (x.first > 0) arr.push({x});
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}