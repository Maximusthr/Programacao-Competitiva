#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int L = 100;

void solve(){
    int n, m; cin >> n >> m;

    int start = 0;
    vector<int> limit(L);
    for (int i = 0; i < n; i++){
        int lenght, speed; cin >> lenght >> speed;

        for (int j = start; j < start + lenght; j++){
            limit[j] = speed;
        }
        start += lenght;
    }
    
    start = 0;
    vector<int> cow(L);
    for (int i = 0; i < n; i++){
        int lenght, speed; cin >> lenght >> speed;

        for (int j = start; j < start + lenght; j++){
            cow[j] = speed;
        }
        start += lenght;
    }

    int ans = 0;
    for (int i = 0; i < L; i++){
        ans = max(ans, cow[i]-limit[i]);
    }
    
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    solve();
}
