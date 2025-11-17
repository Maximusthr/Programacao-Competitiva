#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e6 + 5;

void solve(){
    int n, m, k; cin >> n >> m >> k;

    vector<bool> holes(MAX);
    for (int i = 0; i < m; i++){
        int x; cin >> x;
        holes[x] = true;
    }

    int x = 1;
    bool fim = false;

    if (holes[x]) fim = true;
    
    for (int i = 0; i < k; i++){
        int y1, y2; cin >> y1 >> y2;

        if (!fim && x == y1){
            x = y2;
            if (holes[x]){
                fim = true;
            }
        }
        else if (!fim && x == y2){
            x = y1;
            if (holes[x]){
                fim = true;\
            }
        }
    }

    cout << x << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}