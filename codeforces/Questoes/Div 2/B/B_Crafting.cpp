#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].first;
    }
    for (int i = 0; i < n; i++){
        cin >> a[i].second;
    }

    bool used = false;
    int x = 0;
    int pos = -1;
    for (int i = 0; i < n; i++){
        a[i].first -= x;
        if (a[i].first < a[i].second){
            if (used){
                cout << "NO" << "\n";
                return;
            }
            x = a[i].second - a[i].first;
            used = true;
            pos = i;
        }
    }
    for (int i = 0; i < pos; i++){
        a[i].first -= x;
        if (a[i].first < a[i].second){
            cout << "NO" << "\n";
            return;
        }
    }
    
    cout << "YES" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}