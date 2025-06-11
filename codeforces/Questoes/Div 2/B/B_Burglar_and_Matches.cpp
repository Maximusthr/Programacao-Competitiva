#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n, m; cin >> n >> m;

    vector<pair<int, int>> matches;

    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        matches.push_back({b, a});
    }

    sort(matches.begin(), matches.end(), [&](pair<int, int> &x, pair<int, int> &y){
        if (x.first != y.first) return x.first > y.first;
        return x.second > y.second;
    });

    long long soma = 0;
    int pos = 0;
    while (n != 0 && pos < m){
        if (matches[pos].second <= n){
            soma += matches[pos].first * matches[pos].second;
            n -= matches[pos].second;
        }
        else {
            soma += matches[pos].first * n;
            n = 0;
        }
        pos++;
    }
    
    cout << soma << "\n";
}
