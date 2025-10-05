#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<ll> arr(n);
    vector<ll> prefix(n+1);

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        prefix[i+1] = prefix[i] + arr[i];
    }

    string s; cin >> s;

    vector<int> L, R;

    for (int i = 0; i < n; i++){
        if (s[i] == 'L') L.push_back(i);
        else R.push_back(i);
    }

    if (L.size() == 0 || R.size() == 0){
        cout << 0 << "\n";
        return;
    }

    int t_L = L.size(), t_R = R.size();
    for (int i = t_L-1; i >= 0; i--){
        if (L[i] > R.back()) L.pop_back();
        else break;
    }
    
    ll ans = 0; 
    int i = 0, j = R.size()-1;
    while(i < t_L && j >= 0 && L[i] < R[j]){
        ans += prefix[R[j]+1] - prefix[L[i]];
        i++, j--;
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}