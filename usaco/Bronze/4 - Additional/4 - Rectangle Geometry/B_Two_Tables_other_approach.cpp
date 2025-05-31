#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

typedef struct{    
    ll x1, y1, x2, y2;
    ll area (){
        return (x2-x1) * (y2-y1);
    }
} Rect;

void solve(){
    cout << fixed << setprecision(9);

    Rect a;
    cin >> a.x2 >> a.y2;
    
    Rect b;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    
    Rect c;
    cin >> c.x2 >> c.y2;
    
    ll ans = INF;
    if (b.x2 - b.x1 + c.x2 <= a.x2){
        ans = min(ans, max(0LL, c.x2 - b.x1));
        ans = min(ans, max(0LL, b.x2 - (a.x2 - c.x2)));
    }
    if (b.y2 - b.y1 + c.y2 <= a.y2){
        ans = min(ans, max(0LL, c.y2 - b.y1));
        ans = min(ans, max(0LL, b.y2 - (a.y2 - c.y2)));
    }

    if (ans == INF) cout << -1 << "\n";
    else cout << (double) ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        solve();
    }
}
