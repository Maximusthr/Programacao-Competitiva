#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    int a1, b1, a2, b2; cin >> a1 >> b1 >> a2 >> b2;
    int e1, f1, e2, f2; cin >> e1 >> f1 >> e2 >> f2;
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

    int area1 = (a2-a1) * (b2-b1);

    int xInter = max(0, min(e2, x2) - max(e1, x1));
    int yInter = max(0, min(f2, y2) - max(f1, y1));
    area1 -= (xInter*yInter);

    int area2 = (e2-e1) * (f2-f1);
    xInter = max(0, min(a2, x2) - max(a1, x1));
    yInter = max(0, min(b2, y2) - max(b1, y1));
    area2 -= (xInter*yInter);

    cout << abs(area1 + area2) << "\n";
}