#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    
    set<int> num;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        num.insert(x);
    }

    if (*num.begin() == 1) {
        bool ok = false;
        vector<int> copy = {num.begin(), num.end()};
        int s = 0;
        for (int i = 0; i < copy.size(); i++){
            if (copy[i] - s == 1){
                s++;
            }
            else {
                cout << (s % 2 ? "Bob" : "Alice") << "\n";
                return;
            }
        }
        cout << (s % 2 ? "Alice" : "Bob") << "\n";
    }
    else cout << "Alice" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}