#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);

    int n; cin >> n;
    vector<pair<int, int>> t;

    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        t.push_back({x, y});
    }

    sort(t.begin(), t.end());

    int start = 0;
    for (int i = 0; i < n; i++){
        if (t[i].first <= start){
            start += t[i].second;
        }
        else start = t[i].first + t[i].second;
    }

    cout << start << "\n";
}