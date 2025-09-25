// bottom-up

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, k; cin >> n >> k;

    vector<int> h(n);
    for (auto &i : h) cin >> i;

    vector<int> memo(n);

    memo[0] = 0;
    for (int i = 1; i < n; i++){
        memo[i] = INF;
        for (int j = max(0, i-k); j < i; j++){
            memo[i] = min(memo[i], memo[j] + abs(h[i]-h[j]));
        }
    }

    cout << memo[n-1] << "\n";
} 