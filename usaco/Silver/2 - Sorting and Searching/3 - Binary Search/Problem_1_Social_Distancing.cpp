#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m; 
vector<pair<ll, ll>> dist;

bool ok(ll mid){
    int k = 1;
    ll d = dist[0].first;

    for (int i = 0; i < m;){
        d += mid;

        // se d > dist[i].second, aloco para o proximo -> d = dist[i+1].first
        // se não, mantenho no que estiver
        // se o i estourar: paciencia (acabo o loop)
        
        // eu preciso alocar enquanto o valor nao estourar
        if (d >= dist[i].second){
            // vai pro proximo com uma ressalva, a distancia precisa se manter
            int j = i;
            while (j < m && d > dist[j].second){
                j++;
            }
            if (j == m) break;
            if (d < dist[j].first) d = dist[j].first;
            i = j;
        }
        k++;

        if (k == n) return true;

    }

    return (k >= n);
}

void solve(){
    cin >> n >> m;

    for (int i = 0; i < m; i++){
        ll x, y; cin >> x >> y;
        dist.push_back({x, y});
    }

    sort(dist.begin(), dist.end());

    ll l = 0, r = 1e18+5;
    while(l < r){
        ll mid = l + (r-l+1)/2;

        if (ok(mid)){
            l = mid;
        }
        else r = mid - 1;
    }

    cout << l << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    solve();
}