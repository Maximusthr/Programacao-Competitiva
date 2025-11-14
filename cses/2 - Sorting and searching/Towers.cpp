#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    
    int ans = 0;

    multiset<int> torres;
    for (int i = 0; i < n; i++){
        int x; cin >> x;

        auto it = torres.upper_bound(x);

        if (it == torres.end()){
            torres.insert(x);
            ans++;
            continue;
        }

        if (x >= *it){
            torres.insert(x);
            ans++;
        }
        else {
            torres.erase(it);
            torres.insert(x);
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}