#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

typedef struct{
    int x1, y1, x2, y2;
} Rect;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);

    Rect a, b;

    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;

    int max_X = max(a.x2, b.x2) - min(a.x1, b.x1);
    int max_Y = max(a.y2, b.y2) - min(a.y1, b.y1);

    cout << max(max_X, max_Y) * max(max_X, max_Y) << "\n";
}
