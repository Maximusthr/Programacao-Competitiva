#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

typedef struct{
    ll x1, y1, x2, y2;
    ll area() {
        return (x2 - x1) * (y2- y1);
    }
} Rect;

ll intersect(Rect p, Rect q){
    ll xOverlap = max(0LL, min(p.x2, q.x2) - max(p.x1, q.x1));
    ll yOverlap = max(0LL, min(p.y2, q.y2) - max(p.y1, q.y1));
    
    return xOverlap * yOverlap;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    Rect a, j, k;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> j.x1 >> j.y1 >> j.x2 >> j.y2;
    cin >> k.x1 >> k.y1 >> k.x2 >> k.y2;

    ll area_b = a.area();

    ll interJ = intersect(a, j);
    ll interK = intersect(a, k);

    area_b -= (interJ+interK);

    if (intersect(j, k) > 0){
        Rect l;
        l.x2 = min(j.x2, k.x2);
        l.x1 = max(j.x1, k.x1);
        l.y2 = min(j.y2, k.y2);
        l.y1 = max(j.y1, k.y1);

        area_b += intersect(a, l);
    }

    if (area_b > 0) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}
