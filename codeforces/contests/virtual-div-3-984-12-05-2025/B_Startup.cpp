#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n, k; cin >> n >> k;

        map<int, int> g; // garrafa

        for (int i = 0; i < k; i++){
            int x, y; cin >> x >> y;

            g[x] += y;
        }

        vector<pair<int, int>> val;
        for (auto [x, y] : g){
            val.push_back({x, y});
        }
        
        sort(val.begin(), val.end(), [&](pair<int, int> &x, pair<int, int> &y){
            return x.second > y.second;
        });

        int sum = 0;
        for (int i = 0; i < k; i++){
            while(n > 0 && i < (int)val.size()){
                sum += val[i].second;
                n--;
                break;
            }
        }

        cout << sum << "\n";
    }
}