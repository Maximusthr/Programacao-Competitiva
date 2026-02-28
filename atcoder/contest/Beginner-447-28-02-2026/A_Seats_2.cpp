#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<int> arr(n);

    int i = 0;
    while(i < n && m > 0){
        arr[i]++;
        m--;

        i += 2;
    }

    if (m > 0){
        cout << "No" << "\n";
    }
    else cout << "Yes" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}