#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Rect{
    ll x1, y1, x2, y2;
};

ll Intersect(Rect p, Rect q){
    ll xOverlap = max(0LL, min(p.x2, q.x2) - max(p.x1, q.x1));
    ll yOverlap = max(0LL, min(p.y2, q.y2) - max(p.y1, q.y1));

    return (xOverlap * yOverlap);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;
    
    while(t--){
        Rect a, b;
        cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
        cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
        
        if (Intersect(a, b) > 0){
            ll x1 = max(a.x1, b.x1);
            ll y1 = max(a.y1, b.y1);
            ll x2 = min(a.x2, b.x2);
            ll y2 = min(a.y2, b.y2);
            
            cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
        }
        else cout << "No Overlap" << "\n";

        if (t > 0) cout << "\n";
    }
}