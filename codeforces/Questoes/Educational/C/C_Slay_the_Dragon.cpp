#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct p {ll x; ll y;};

void solve(){
    int n; cin >> n;

    vector<ll> arr(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    sort(arr.begin()+1, arr.end());

    int m; cin >> m;
    
    vector<p> dragons(m);
    for (auto &i : dragons) cin >> i.x >> i.y;
    
    vector<ll> prefix(n+2);
    for (int i = 1; i <= n; i++){
        prefix[i] += prefix[i-1] + arr[i];
    }

    for (int i = 0; i < m; i++){
        int idx = lower_bound(arr.begin()+1, arr.end(), dragons[i].x) - arr.begin();

        if (idx == n+1) idx--;

        ll valor = arr[idx];

        ll sobra1 = max(0ll, dragons[i].x - arr[idx]);
        ll pref1 = prefix[n] - prefix[idx] + prefix[idx-1];
        pref1 = max(0ll, dragons[i].y - pref1);

        ll sobra2 = LINF;
        ll pref2 = LINF;
        if (idx >= 2){
            sobra2 = max(0ll, dragons[i].x - arr[idx-1]);
            pref2 = prefix[n] - prefix[idx-1] + prefix[idx-2];
            pref2 = max(0ll, dragons[i].y - pref2);
        }

        cout << min(sobra1 + pref1, sobra2 + pref2) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}