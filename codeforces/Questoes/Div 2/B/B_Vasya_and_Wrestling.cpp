#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    
    ll sum = 0;
    vector<int> a, b;

    bool last = false;

    for (int i = 0; i < n; i++){
        ll x; cin >> x;
        
        if (x < 0) b.push_back(abs(x));
        else a.push_back(x);

        sum += x;

        if (i == n-1){
            if (x < 0) last = true;
        }
    }

    if (sum > 0) cout << "first" << "\n";
    else if (sum < 0) cout << "second" << "\n";
    else {
        for (int i = 0; i < min(a.size(), b.size()); i++){
            if (a[i] > b[i]){
                cout << "first" << "\n";
                return;
            }
            if (a[i] < b[i]){
                cout << "second" << "\n";
                return;
            }
        }
        if (a == b){
            if (!last) cout << "first" << "\n";
            else cout << "second" << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}