#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 998244353;

struct mi {
	int v;
	explicit operator int() const { return v; }
	mi() { v = 0; }
	mi(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};
mi &operator+=(mi &a, mi b) {
	if ((a.v += b.v) >= MOD) a.v -= MOD;
	return a;
}
mi &operator-=(mi &a, mi b) {
	if ((a.v -= b.v) < 0) a.v += MOD;
	return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long)a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }
mi pow(mi a, long long p) {
	assert(p >= 0);
	return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) {
	assert(a.v != 0);
	return pow(a, MOD - 2);
}
mi operator/(mi a, mi b) { return a * inv(b); }

const int TODO = 1e6+5;

void solve(){
    int n; cin >> n;
    
    vector<int> total(TODO); // todos os itens
    map<int, int> qtd; // quantidade total de itens em uma chave
    map<pair<int, int>, int> local;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        for (int j = 0; j < x; j++){
            int v; cin >> v;
            local[{i, v}] += 1;
            qtd[i] += 1;
        }
    }
    
    for (auto [x, y] : local){
        total[x.second] += 1;
    }
    
    mi ans = 0;
    for (auto [x, y] : local){
        mi a = (mi)1/(mi)n; // probabilidade da criança ser escolhida
        mi b = (mi)y/(mi)qtd[x.first]; // probabilidade do item ser pego no local
        mi c = (mi)total[x.second]/(mi)n; // probabilidade de acertar a criança correta

        ans = ans + a * b * c;
    }

    cout << (int)(ans) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}