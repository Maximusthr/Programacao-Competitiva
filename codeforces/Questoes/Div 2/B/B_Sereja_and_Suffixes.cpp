#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int dist = 0;
    map<int, queue<int>> mapa;
    for (int i = 0; i < n; i++){
        mapa[arr[i]].push(i);
        if (mapa[arr[i]].size() == 1) dist++;
    }

    vector<int> total(n+1);
    total[0] = dist;

    for (int i = 0; i < n; i++){
        mapa[arr[i]].pop();
        if (mapa[arr[i]].size() == 0) dist--;
        total[i+1] = dist;
    }

    while(m--){
        int x; cin >> x;
        x--;

        cout << total[x] << "\n";
    }
}