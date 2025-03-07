#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    long long n, k; cin >> n >> k;

    vector<long long> arr(n);
    for (auto &i : arr) cin >> i;

    vector<long long> q(k);
    for (auto &i : q) cin >> i;

    for (long long i = 0; i < (long long)q.size(); i++){
        long long aux = q[i];

        auto it = lower_bound(arr.begin(), arr.end(), aux);
        if (*it == aux) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}
