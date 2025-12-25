#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    map<int, int> freq;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        freq[x]++;
    }

    int last = -1;
    pair<int, int> ans = {-1, -1};
    for (auto [x, y] : freq){
        if (ans.first == -1 && ans.second == -1){
            if (y >= k){
                ans.first = x, ans.second = x;
                last = ans.first;
                continue;
            }
        }

        if (freq[x-1] < k){
            last = -1;
        }
        
        if (last != -1){
            if (y >= k){
                if (ans.second - ans.first < x - last){
                    ans.second = x;
                    ans.first = last;
                }
            }
        }
        else if (y >= k){
            last = x;
        }
    }

    if (ans.first == -1) cout << -1 << "\n";
    else cout << ans.first << " " << ans.second << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}