#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int verif(char x){
    if (x == 'A') return 0;
    if (x == 'C') return 1;
    if (x == 'G') return 2;
    if (x == 'T') return 3;
}

int n, m; 
vector<vector<int>> spotty(n, vector<int> (m));
vector<vector<int>> plain(n, vector<int> (m));

bool test_pos(int p1, int p2, int p3){
    vector<int> ID(64);

    // spotty cows
    for (int i = 0; i < n; i++){
        int valor = 16 * spotty[i][p1] + 4 * spotty[i][p2] + spotty[i][p3];
        ID[valor] = 1;
    }

    bool ok = true;
    // plain cows
    for (int i = 0; i < n; i++){
        int valor = 16 * plain[i][p1] + 4 * plain[i][p2] + plain[i][p3];
        if (ID[valor]) ok = false; 
    }

    ID.assign(64, 0);

    return ok;
}

void solve(){
    cin >> n >> m;

    spotty.assign(n, vector<int> (m));
    plain.assign(n, vector<int> (m));

    // A = 0
    // C = 1
    // G = 2
    // T = 3
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            char x; cin >> x;
            spotty[i][j] = verif(x);
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            char x; cin >> x;
            plain[i][j] = verif(x);
        }
    }   

    int ans = 0;
    for (int p1 = 0; p1 < m; p1++){
        for (int p2 = p1 + 1; p2 < m; p2++){
            for (int p3 = p2 + 1; p3 < m; p3++){
                if (test_pos(p1, p2, p3)) ans++;
            }
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    solve();
}