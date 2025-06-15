#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int x; cin >> x;

    vector<int> races(102);
    for (int i = 0; i < n; i++){
        races[arr[i]]++;
    }

    int ans = 0;
    for (int i = 1; i <= 101; i++){
        if (x <= i) {
            ans += races[i];
        }
    }

    cout << ans << "\n";
}