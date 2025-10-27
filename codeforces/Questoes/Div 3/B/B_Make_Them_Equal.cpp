#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    set<int> v;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        v.insert(x);
    }

    vector<int> v2 = {v.begin(), v.end()};

    int sum = (accumulate(v2.begin(), v2.end(), 0))/v2.size();

    int diff = abs(v2[0] - sum);
    bool ok = true;
    for (int i = 1; i < v2.size(); i++){
        if (v2[i] == sum) continue;
        if (abs(v2[i] - sum) != diff) {
            ok = false;
            break;
        }
    }

    int ans = INF;

    if (ok) ans = diff;

    if (v2.size() == 2) ans = min(abs(v2[0] - v2[1]), ans);

    if (ans == INF) cout << -1 << "\n";
    else cout << ans << "\n";

}
