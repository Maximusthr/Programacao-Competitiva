#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<pair<ll, ll>> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr.begin(), arr.end());

    if (n == 1 && arr[0].first == 0){
        cout << 1 << "\n";
        return;
    }
    else if (n == 1 && arr[0].first != 0){
        cout << -1 << "\n";
        return;
    }

    vector<pair<ll, ll>> a(n);
    for (int i = 0; i < n; i++){
        a[i].second = arr[i].second;
    }

    int eq = 1;
    ll last = 0;
    ll last_v = 0;
    for (int i = 1; i < n; i++){
        if (arr[i].first == arr[i-1].first){
            eq++;
        }
        else {
            ll v = (arr[i].first - last) / eq;

            if (v < last_v){
                cout << -1 << "\n";
                return;
            }

            last_v = v;
            last += eq * v;

            int j = i-1;
            while(j >= 0 && a[j].first == 0){
                a[j].first = v;
                j--;
            }
            eq = 1;
        }
    }

    ll maior = 0;
    for (int i = 0; i < n; i++){
        maior = max(maior, a[i].first);
    }

    for (int i = n-1; i >= 0; i--){
        if (a[i].first == 0) a[i].first = maior + 1;
        else break;
    }

    vector<ll> prefix(n+1), equal(n+1);
    for (int i = 1; i <= n; i++){
        prefix[i] += prefix[i-1] + a[i-1].first;

        if (i > 1){
            if (a[i-1].first == a[i-2].first){
                equal[i] = equal[i-1];
            }
            else {
                equal[i] = prefix[i-1];
            }
        }
    }

    for (int i = 0; i < n; i++){
        if (arr[i].first != equal[i+1]){
            cout << -1 << "\n";
            return;
        }
    }

    vector<ll> ans(n);
    for (int i = 0; i < n; i++){
        ans[a[i].second] = a[i].first;
    }
    for (auto &i : ans) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}