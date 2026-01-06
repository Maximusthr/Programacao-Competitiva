#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    set<int> pode;
    for (int i = 0; i < 10; i++){
        pode.insert(i);
    }

    for (int i = 0; i < k; i++){
        int x; cin >> x;
        pode.erase(x);
    }
    
    auto ok = [&](int dig) -> bool {
        while(dig > 0){
            int v = dig % 10;
            if (!pode.count(v)) return false;
            dig /= 10;
        }
        return true;
    };

    for (int i = n; ; i++){
        if (ok(i)) {
            cout << i << "\n";
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}