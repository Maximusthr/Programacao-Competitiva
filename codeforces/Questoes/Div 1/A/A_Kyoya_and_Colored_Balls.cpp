#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

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

mi Comb (mi a, mi b){
    return fat[(int)a] / (fat[(int)b] * fat[(int)(a-b)]);
}

void solve(){
    int n; cin >> n;
    vector<ll> colors(n);
    for (auto &i : colors) cin >> i;    

    mi ans = 1;
    mi sum = (mi) colors[0];
    for (int i = 1; i < n; i++){
        ans = ans * Comb(sum + (mi) colors[i] - 1, (mi) colors[i] - 1);
        sum = sum + (mi)colors[i];
    }

    cout << (int) ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    fat.resize(MAX);
    fat[0] = 1;
    for (int i = 1; i < MAX; i++){
        fat[i] = fat[i-1] * (mi)i;
    }

    solve();
}