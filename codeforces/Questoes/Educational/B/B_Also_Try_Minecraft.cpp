#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, q; cin >> n >> q;

    vector<ll> arr(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    vector<ll> sufix(n+2), prefix(n+1);

    for (int i = 1; i <= n; i++){
        prefix[i] += prefix[i-1];
        if (arr[i] < arr[i-1]){
            prefix[i] += arr[i-1] - arr[i];
        }
    }

    for (int i = n; i >= 1; i--){
        sufix[i] += sufix[i+1];
        // if (i > 1 && arr[i] > arr[i-1]){
        //     sufix[i] += arr[i] - arr[i-1];
        // }
        if (arr[i+1] > arr[i]){
            sufix[i] += arr[i+1] - arr[i];
        }
    }

    while(q--){
        int l, r; cin >> l >> r;

        if (l > r) cout << sufix[r] - sufix[l] << "\n";
        else cout << prefix[r] - prefix[l] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}