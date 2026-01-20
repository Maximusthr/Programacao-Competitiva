#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<int> oper;

    while(m > n){
        oper.push_back(m);
        int v = m % 10;
        if (v == 1) m /= 10;
        else if (v & 1){
            cout << "NO" << "\n";
            return;
        }
        else m /= 2;
    }

    if (m != n){
        cout << "NO" << "\n";
    }
    else {
        oper.push_back(n);
        cout << "YES" << "\n";
        cout << oper.size() << "\n";
        reverse(oper.begin(), oper.end());
        for (auto &i : oper) cout << i << " ";
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}