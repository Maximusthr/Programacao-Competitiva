#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;

    map<int, int> home;
    map<int, int> guest;

    while(t--){
        int a, b; cin >> a >> b;
        home[a]++;
        guest[b]++;
    }
    int ans = 0;
    for (auto [x, y] : home){
        if (guest[x] > 0)
            ans += y * guest[x];
    }

    cout << ans << "\n";
}
