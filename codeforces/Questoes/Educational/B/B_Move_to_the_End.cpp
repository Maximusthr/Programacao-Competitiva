#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    ll sum = accumulate(arr.begin(), arr.end(), 0ll);

    vector<ll> todo;
    todo.push_back(sum);

    ll maior = arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i] >= maior){
            sum -= maior;
            maior = arr[i];
        }
        else sum -= arr[i];
        todo.push_back(sum);
    }

    reverse(todo.begin(), todo.end());

    for (auto &i : todo) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}