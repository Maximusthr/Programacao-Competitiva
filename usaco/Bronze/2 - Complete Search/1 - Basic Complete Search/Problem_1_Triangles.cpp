#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

typedef struct{
    int x;
    int y;
} coord;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);

    int n; cin >> n;

    vector<coord> plano;
    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        plano.push_back({x, y});
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (j == i) continue;
            if (plano[j].x == plano[i].x){
                for (int k = 0; k < n; k++){
                    if (k == i || k == j) continue;
                    if (plano[k].y == plano[j].y || plano[k].y == plano[i].y){
                        int h = abs(plano[j].y - plano[i].y);
                        int b = 0;
                        if (plano[k].y == plano[j].y) b = abs(plano[k].x - plano[j].x);
                        else b = abs(plano[k].x - plano[i].x);
                        
                        ans = max(ans, b*h);
                    }
                }
            }
            else if (plano[j].y == plano[i].y){
                for (int k = 0; k < n; k++){
                    if (k == i || k == j) continue;
                    if (plano[k].x == plano[j].x || plano[k].x == plano[i].x){
                        int h = abs(plano[j].x - plano[i].x);
                        int b = 0;
                        if (plano[k].x == plano[j].x) b = abs(plano[k].y - plano[j].y);
                        else b = abs(plano[k].y - plano[i].y);

                        ans = max(ans, b*h);
                    }
                }
            }
        }
    }

    cout << ans << "\n";
}