#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    
    string a, b; cin >> a >> b;

    int ans = 0;
    for (int i = 0; i < n; i++){
        if (a[i] != b[i]){
            int j = i + 1;
            while (j < n && a[j] == b[j]) j++;
            if (j == n){
                ans++;
                break;
            }

            if (a[i] == a[j]) {
                ans++;
                i = j-1;
            }
            else {
                int dist = j - i;
                if (dist >= 2) {
                    ans++;
                    i = j-1;
                }
                else {
                    ans += dist;
                    i = j;
                }
            }
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}