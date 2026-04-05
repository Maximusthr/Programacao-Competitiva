#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    deque<pair<int, int>> deq;
    for (int i = 0; i < n; i++){
        deq.push_back({i+1, 0});
    }

    while(m--){
        int x; cin >> x;
        if (x == 1){
            char c; cin >> c;

            deq.pop_back();

            pair<int, int> info = deq.front();
            if (c == 'U'){
                deq.push_front({info.first, info.second+1});
            }
            else if (c == 'D'){
                deq.push_front({info.first, info.second-1});
            }
            else if (c == 'L'){
                deq.push_front({info.first-1, info.second});
            }
            else {
                deq.push_front({info.first+1, info.second});
            }
        }
        else {
            int y; cin >> y;
            y--;
            cout << deq[y].first << " " << deq[y].second << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}