#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    
    vector<int> a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    for (int i = 0; i < n; i++){
        a[i] -= b[i];
    }

    vector<int> pos, neg;
    for (int i = 0; i < n; i++){
        if (a[i] > 0) pos.push_back(a[i]);
        else neg.push_back(abs(a[i]));
    }

    sort(neg.begin(), neg.end());

    ll ans = 0;
    for (int i = 0; i < pos.size(); i++){
        int l = -1, r = neg.size()-1;
        while(l < r){
            int mid = l + (r-l+1)/2;

            if (pos[i] > neg[mid]) l = mid;
            else r = mid - 1;
        }
        if (l == -1) continue;
        ans += l+1;
    }

    ans += 1ll * pos.size() * (pos.size() - 1)/2;
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}