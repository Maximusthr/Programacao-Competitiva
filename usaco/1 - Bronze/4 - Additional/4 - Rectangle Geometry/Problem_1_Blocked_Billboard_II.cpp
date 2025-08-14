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

ll intersect (Rect p, Rect q){
    ll xOverlap = max(0LL, min(p.x2, q.x2) - max(p.x1, q.x1));
    ll yOverlap = max(0LL, min(p.y2, q.y2) - max(p.y1, q.y1));

    return xOverlap * yOverlap;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    Rect a, b;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;

    ll area = a.area();

    Rect i;
    i.x2 = min(a.x2, b.x2);
    i.x1 = max(a.x1, b.x1);

    i.y2 = min(a.y2, b.y2);
    i.y1 = max(a.y1, b.y1);

    if ((i.x2 == a.x2 && i.x1 == a.x1 && i.y1 == a.y1) || (i.x2 == a.x2 && i.x1 == a.x1 && i.y2 == a.y2) 
    || (i.y2 == a.y2 && i.y1 == a.y1 && i.x1 == a.x1) || (i.x2 == a.x2 && i.x1 == a.x1 && i.y2 == a.y2)) area -= intersect(a, b);

    cout << (area >= 0 ? area : 0) << "\n";
}
