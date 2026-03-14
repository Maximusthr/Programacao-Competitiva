#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k, p, energy; cin >> n >> k >> p >> energy;

    queue<pair<int, int>> arr;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        arr.push({x, i+1});
    }

    int ans = 0;

    int aux = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    while(energy > 0){
        // boto na mesa quais posso jogar

        while(arr.size() > 0 && aux < k){
            aux++;
            pq.push(arr.front());
            arr.pop();
        }

        vector<pair<int, int>> v;
        while(!pq.empty()){
            v.push_back({pq.top()});
            pq.pop();
        }

        bool ok = true;
        bool achou = false;
        for (int i = 0; i < v.size(); i++){
            if (v[i].second == p){
                if (energy - v[i].first >= 0){
                    ans++;
                    energy -= v[i].first;
                    arr.push(v[i]);
                    achou = true;
                    aux--;
                }
                else {
                    ok = false;
                    break;
                }
            }
            else {
                pq.push(v[i]);
            }
        }
        
        if (!ok) break;
        if (!achou){
            energy -= pq.top().first;
            arr.push(pq.top());
            pq.pop();
            aux--;
        }
    }

    cout << ans << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}