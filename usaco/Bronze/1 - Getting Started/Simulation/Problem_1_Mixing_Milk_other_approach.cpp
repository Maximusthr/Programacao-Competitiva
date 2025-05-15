#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    vector<pair<int, int>> m;
    for (int i = 0; i < 3; i++){
        int c, q; cin >> c >> q;
        m.push_back({c, q});
    }   

    for (int i = 0; i < 100; i++){
        int b1 = i % 3;
        int b2 = (i+1) % 3;

        int amt = min(m[b1].second, m[b2].first - m[b2].second);

        m[b1].second -= amt;
        m[b2].second += amt;
    }
    
    for (int i = 0; i < 3; i++){
        cout << m[i].second << "\n";
    }
}
