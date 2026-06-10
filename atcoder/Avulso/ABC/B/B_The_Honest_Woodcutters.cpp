#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> a(n), b(n);
    for (auto &i : a) {
        cin >> i;
        i--;
    }
    for (auto &i : b) {
        cin >> i;
        i--;
    }

    for (int i = 0; i < n; i++){
        if (b[a[i]] != i) {
            cout << "No" << "\n";
            return;
        }
    }

    cout << "Yes" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}