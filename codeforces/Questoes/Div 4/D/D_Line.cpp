#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    string s; cin >> s;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++){
        if (s[i] == 'L') arr[i] = i;
        else if (s[i] == 'R') arr[i] = n-i-1;
    }
    
    ll sum = accumulate(arr.begin(), arr.end(), 0LL);
    
    // mudando at most k people 
    vector<pair<ll, int>> mudei;
    for (int i = 0; i < n; i++){
        ll temp = sum;
        if (s[i] == 'L') {
            ll aux = n-i-1;
            if (aux > arr[i]) mudei.push_back({aux, i});
        }
        else if (s[i] == 'R'){
            ll aux = i;
            if (aux > arr[i]) mudei.push_back({aux, i});
        }
    }

    sort(mudei.begin(), mudei.end(), [&](pair<ll, int> &a, pair<ll, int> &b){
        return a.first > b.first;
    });

    for (int i = 0; i < mudei.size(); i++){
        sum = sum - arr[mudei[i].second] + mudei[i].first;
        cout << sum << " ";
    }
    n -= mudei.size();
    for (int i = 0; i < n; i++){
        cout << sum << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        solve();
    }
}