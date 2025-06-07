#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 3e5+5;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, l; cin >> n >> l;
    
    if (l%3 != 0) {
        cout << 0 << "\n";
        return 0;
    }

    vector<int> pontos(n+1);
    vector<ll> pos(MAX);

    pontos[0] = 0;
    pos[0]++;
    for (int i = 1; i < n; i++){
        int d; cin >> d;
        pontos[i] = (pontos[i-1] + d) % l;
        pos[pontos[i]]++;
    }

    ll ans = 0;
    for (int i = 0; i + 2 * l/3 < l; i++){
        ans += (pos[i] * pos[i + l/3] * pos[i + 2*l/3]);
    }

    cout << ans << "\n";
}
