#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<string> arr(n);
    for (auto &i : arr) cin >> i;

    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--, y2--;

    auto isValid = [&](int x, int y) -> bool {
        return (x >= 0 && x < n && y >= 0 && y < m);
    };

    int dx[4] = {0, -1, 1, 0};
    int dy[4] = {1, 0, 0, -1};
    

    queue<pair<int, int>> q;
    q.push({x1, y1});
    while(!q.empty()){
        int u = q.front().first;
        int v = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++){
            int cx = dx[i] + u;
            int cy = dy[i] + v;

            if (isValid(cx, cy)){
                if (cx == x2 && cy == y2 && arr[cx][cy] == 'X'){
                    cout << "YES" << "\n";
                    return;
                }

                if (arr[cx][cy] == 'X') continue;
                arr[cx][cy] = 'X';
                q.push({cx, cy});
            }
        }
    }
    cout << "NO" << "\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}