#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, q; cin >> n >> q;

    vector<ll> arr(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    vector<int> dif(n+2);
    for (int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        dif[l]++;
        dif[r+1]--;
    }

    for (int i = 1; i <= n; i++){
        dif[i] += dif[i-1];
    }

    sort(dif.begin()+1, dif.end(), greater<int>());
    sort(arr.begin()+1, arr.end(), greater<int>());
    
    ll sum = 0;
    for (int i = 1; i <= n; i++){
        sum += arr[i] * dif[i];
    }

    cout << sum << "\n";
}