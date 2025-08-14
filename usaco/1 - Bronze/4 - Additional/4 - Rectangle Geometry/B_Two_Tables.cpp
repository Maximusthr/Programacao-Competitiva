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

ll intersect(Rect p, Rect q){
    ll xOverlap = max(0LL, min(p.x2, q.x2) - max(p.x1, q.x1));
    ll yOverlap = max(0LL, min(p.y2, q.y2) - max(p.y1, q.y1));

    return (xOverlap * yOverlap);
}

void solve(){
    cout << fixed << setprecision(9);

    Rect a;
    cin >> a.x2 >> a.y2;
    
    Rect b;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    
    Rect c;
    c.x1 = 0;
    c.y1 = 0;
    cin >> c.x2 >> c.y2;
    
    Rect c2;
    c2.x1 = a.x2 - c.x2;
    c2.y1 = a.y2 - c.y2;
    c2.x2 = a.x2;
    c2.y2 = a.y2;

    double ans = 0;
    ll dist_bc, dist_cb, dist_dir, dist_esq;
    
    // baixo -> cima
    ll area = intersect(b, c);
    if (area > 0){
        dist_bc = c.y2 - b.y1;
        if (b.y2 + dist_bc > a.y2) dist_bc = INF;
    }
    else {
        cout << ans << "\n";
        return;
    }
    
    // esquerda -> direita
    area = intersect(b, c);
    if (area > 0){
        dist_esq = c.x2 - b.x1;
        if (b.x2 + dist_esq > a.x2) dist_esq = INF;
    }
    else {
        cout << ans << "\n";
        return;
    }

    // cima -> baixo
    area = intersect(b, c2);
    if (area > 0){
        dist_cb = b.y2 - c2.y1;
        if (b.y1 - dist_cb < 0) dist_cb = INF;
    }
    else {
        cout << ans << "\n";
        return;
    }

    // direita -> esquerda
    area = intersect(b, c2);
    if (area > 0){
        dist_dir = b.x2 - c2.x1;
        if (b.x1 - dist_dir < 0) dist_dir = INF;
    }
    else {
        cout << ans << "\n";
        return;
    }


    // todos infinitos
    if (dist_esq == INF && dist_dir == INF && dist_bc == INF && dist_cb == INF){
        cout << -1 << "\n";
        return;
    }

    cout << (double) min({dist_bc, dist_cb, dist_dir, dist_esq}) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        solve();
    }
}
