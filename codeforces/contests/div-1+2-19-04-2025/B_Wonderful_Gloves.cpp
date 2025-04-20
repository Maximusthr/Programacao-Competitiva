#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n, m; cin >> n >> m;

        vector<int> l(n);
        for (auto &i : l) cin >> i;
        
        vector<int> r(n);
        for (auto &i : r) cin >> i;

        vector<pair<int, int>> todo;
        for (int i = 0; i < n; i++){
            todo.push_back({l[i], r[i]});
        }

        ll ans = 0;
        
        for (int i = 0; i < n; i++){
            ans += max(todo[i].first, todo[i].second);
            if (todo[i].first == max(todo[i].first, todo[i].second)) todo[i].first = 0;
            else todo[i].second = 0;
        }
        
        sort(todo.begin(), todo.end());

        vector<int> sobra;
        for (int i = 0; i < n; i++) sobra.push_back(max(todo[i].first, todo[i].second));

        sort(sobra.begin(), sobra.end(), greater<int>());

        int par = 0;
        for (int i = 0; par < m-1; i++){
            ans += sobra[i];
            par++;
        }
        cout << ans + 1 << "\n";
    }
}
