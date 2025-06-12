//upsolve

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, d; cin >> n >> d;

    vector<pair<int, int>> dupla(n);
    for (auto &[x, y] : dupla) cin >> x >> y;

    sort(dupla.begin(), dupla.end());

    vector<int> best_sum(n);
    best_sum[0] = dupla[0].second;
    
    int j = 0, sum = dupla[0].second;
    int ans = 0;

    for (int i = 0; i < n; i++){
        while(j+1 < n && dupla[j+1].first - dupla[i].first <= d){
            sum += dupla[++j].second;
            best_sum[j] = max(best_sum[j-1], sum);
        }

        ans = max(ans, sum + (i > 0 ? best_sum[i-1] : 0));
        sum -= dupla[i].second;
    }

    cout << ans << "\n";
}