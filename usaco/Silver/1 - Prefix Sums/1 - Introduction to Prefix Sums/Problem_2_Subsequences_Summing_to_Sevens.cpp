#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    int n; cin >> n;

    vector<ll> arr(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++){
        arr[i] = (arr[i] + arr[i-1]) % 7;
    }

    vector<int> left(n);
    vector<int> right(n);

    for (int i = 1; i <= n; i++){
        right[arr[i]] = i;
    }
    for (int i = n; i > 0; i--){
        left[arr[i]] = i;
    }

    int ans = 0;
    for (int i = 0; i < 7; i++){
        ans = max(right[i] - left[i], ans);
    }

    cout << ans << "\n";
}
