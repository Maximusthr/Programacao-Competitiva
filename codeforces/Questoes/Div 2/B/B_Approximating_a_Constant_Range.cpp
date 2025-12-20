#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;
    
    multiset<int> v;
    v.insert(arr[0]);
    int ans = 1;
    
    int l = 0, r = 0;
    while (r < n){
        r++;

        if (r == n) break;

        v.insert(arr[r]);

        int menor = *v.begin();
        int maior = *prev(v.end());

        if (abs(menor - maior) <= 1) ans = max(ans, r - l + 1);
        else {
            while (l < r && abs(menor - maior) > 1){
                v.erase(v.find(arr[l]));
                l++;
                menor = *v.begin();
                maior = *prev(v.end());
            }
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}