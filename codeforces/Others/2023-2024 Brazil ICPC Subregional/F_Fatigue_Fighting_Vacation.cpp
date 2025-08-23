#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, c, r; cin >> n >> c >> r;

    vector<int> cans(c);
    for (auto &i : cans) cin >> i;

    vector<int> rev(r);
    for (auto &i : rev) cin >> i;

    int ans = 0;

    for (int i = 0, j = 0; ;){
        if (i == c && j == r) break;
        if (j == r && n < cans[i]) break;
        if (i < c && n >= cans[i]){
            n -= cans[i];
            ans++;
            i++;
        }
        else if (j < r) {
            n += rev[j];
            ans++;
            j++;
        }
    }

    cout << ans << endl;
}