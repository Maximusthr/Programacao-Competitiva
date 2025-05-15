#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    vector<pair<int, int>> m;
    for (int i = 0; i < 3; i++){
        int c, q; cin >> c >> q;
        m.push_back({c, q});
    }   

    int i, j = 0;
    while (i < 100){
        if (j == 2){
            m[j-2].second += m[j].second;
            m[j].second -= m[j].second;
            if (m[j-2].second > m[j-2].first) {
                m[j].second += m[j-2].second - m[j-2].first;
                m[j-2].second = m[j-2].first;
            }
        }
        m[j+1].second += m[j].second;
        m[j].second -= m[j].second;
        if (m[j+1].second > m[j+1].first) {
            m[j].second += m[j+1].second - m[j+1].first;
            m[j+1].second = m[j+1].first;
        }
        if (j < 2) j++;
        else j = 0;
        i++;
    }

    for (int i = 0; i < 3; i++){
        cout << m[i].second << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    solve();
}
