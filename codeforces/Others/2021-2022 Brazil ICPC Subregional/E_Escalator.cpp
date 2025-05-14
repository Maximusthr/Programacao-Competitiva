// Inspiração: https://github.com/jonh14lk/Competitive_Programming/blob/master/Problem%20Solving/Subregional%202021/e.cpp

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    int st = -1;
    int ans = 0;

    vector<int> p;
    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;

        if (x > ans){
            if (p.size()){
                st ^= 1;
                ans += 10;
                p.clear();
            }
            else st = y;
        }
        if (st == y) ans = x + 10;
        else p.push_back(x);
    }

    if (p.size()) ans += 10;

    cout << ans << "\n";
}
