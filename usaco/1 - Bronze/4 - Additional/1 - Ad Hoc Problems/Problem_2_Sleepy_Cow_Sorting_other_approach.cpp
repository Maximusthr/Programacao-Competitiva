#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;
    
    int ans = n-1;
    for (int i = n-2; i >= 0; i--){
        if (arr[i] < arr[i+1]){
            ans = i;
        }
        else break;
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);

    solve();
}