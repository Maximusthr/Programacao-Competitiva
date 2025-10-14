#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int a, b;
int x, y;
int n;
string s;

void coord(ll &x, ll &y, ll v){
    for (int i = 0; i < v; i++){
        if (s[i] == 'U') y++;
        if (s[i] == 'D') y--;
        if (s[i] == 'R') x++;
        if (s[i] == 'L') x--;
    }
}

bool ok(ll mid){
    ll a1 = a, b1 = b;
    ll xf = x, yf = y;
    ll xx = 0, yy = 0;

    if (n >= mid){
        coord(xx, yy, mid);

        a1 += xx;
        b1 += yy;

        xf -= a1;
        yf -= b1;

        xf = abs(xf);
        yf = abs(yf);

        return (xf + yf <= mid);
    }
    else {
        coord(xx, yy, n);

        ll aux = mid;

        ll resto = aux % n;
        aux /= n;

        xx *= aux, yy *= aux;
        coord(xx, yy, resto);

        a1 += xx;
        b1 += yy;

        xf -= a1;
        yf -= b1;

        xf = abs(xf);
        yf = abs(yf);

        return (xf + yf <= mid);        
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    cin >> a >> b;
    cin >> x >> y;

    cin >> n;
    cin >> s;

    ll l = 0, r = 2e18;
    while(l < r){
        ll mid = l + (r-l)/2;

        if (ok(mid)){
            r = mid;
        }
        else l = mid + 1;
    }

    if (l == 2e18) cout << -1 << "\n";
    else cout << l << "\n";
}