#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int a, b, c, d; cin >> a >> b >> c >> d;

        if (b > a && d > a && d <= c) cout << "Flower" << "\n";
        else if (b >= a && d > c && c < b) cout << "Flower" << "\n";
        else if (b < a && c < b && d > c) cout << "Flower" << "\n";
        else if (b > a && d > c && a < c) cout << "Flower" << "\n";
        else if (b > a && d > a && d >= c && b > c) cout << "Flower" << "\n";
        else cout << "Gellyfish" << "\n";
    }
}
