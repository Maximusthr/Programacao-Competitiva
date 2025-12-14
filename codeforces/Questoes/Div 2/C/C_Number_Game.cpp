#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    if (n == 1){
        cout << "FastestFinger" << "\n";
        return;
    }

    if (n % 2 || n == 2){
        cout << "Ashishgup" << "\n";
        return;
    }

    set<int> fatores;
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0){
            if (i % 2) fatores.insert(i);
            if (n/i % 2) fatores.insert(n/i);
        }
    }

    if (fatores.size() > 1){
        cout << "Ashishgup" << "\n";
    }
    else {
        if (fatores.size() == 1){
            int v = *fatores.begin();
            if (n/v != 2){
                cout << "Ashishgup" << "\n";
                return;
            }
        }
        cout << "FastestFinger" << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}