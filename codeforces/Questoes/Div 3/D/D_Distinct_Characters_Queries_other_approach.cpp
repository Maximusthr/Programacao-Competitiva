#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;
    
    int n = s.size();

    vector<set<int>> arr(26);
    for (int i = 0; i < n; i++){
        int v = (s[i]-'a');

        arr[v].insert(i);
    }

    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        if (x == 1){
            int idx; cin >> idx;
            char v; cin >> v;

            idx--;

            arr[(s[idx] - 'a')].erase(idx);
            s[idx] = v;
            arr[(v-'a')].insert(idx);
        }
        else {
            int l, r; cin >> l >> r;
            l--, r--;

            int ans = 0;

            for (int i = 0; i < 26; i++){
                auto it = arr[i].lower_bound(l);
                if (it != arr[i].end() && *it <= r) ans++;
            }

            cout << ans << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}