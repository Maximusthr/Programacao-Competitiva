#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    ll n; cin >> n;
    ll x, y; cin >> x >> y;

    ll black_x = n-x;
    ll black_y = n-y;

    ll white_x = x-1;
    ll white_y = y-1;

    ll white_mov = max(white_x, white_y);
    ll black_mov = max(black_x, black_y);

    if (white_mov <= black_mov) cout << "White" << "\n";
    else cout << "Black" << "\n";
}
