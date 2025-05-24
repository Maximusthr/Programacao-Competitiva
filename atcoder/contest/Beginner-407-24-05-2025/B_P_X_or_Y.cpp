#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int x, y; cin >> x >> y;

    double sum = 0;
    for (int i = 1; i <= 6; i++){
        for (int j = 1; j <= 6; j++){
            if ((i+j >= x) || (abs(i-j) >= y)){
                sum++;
            }
        }
    }

    cout << fixed << setprecision(15);
    cout << sum/36 << "\n";
}
