#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n; cin >> n;

    vector<long long> arr(n);
    for (auto &i : arr) cin >> i;

    long long ans = arr[0];
    long long aux = arr[0];
    for (int i = 1; i < n; i++){
        aux = max(arr[i], aux + arr[i]);
        ans = max(ans, aux);
    }

    cout << ans << "\n";
}
