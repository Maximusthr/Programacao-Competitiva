#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9 + 7;

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

vector<mi> fat;

mi Comb(mi a, mi b){
    return fat[(int)a] / (fat[(int)b] * fat[(int)(a-b)]);
}

void solve(){
    ll n, m; cin >> n >> m;

    cout << (int) Comb(n + 2*m - 1, n-1) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    fat.resize(1e5 + 5);
    fat[0] = 1;
    for (int i = 1; i < 1e5 + 5; i++){
        fat[i] = fat[i-1] * i;
    }

    solve();
}