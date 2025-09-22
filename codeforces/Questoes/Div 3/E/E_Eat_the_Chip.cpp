#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct point {
    int x, y;
};

void solve(){
    int h, w; cin >> h >> w;

    point alice; cin >> alice.x >> alice.y;
    point bob; cin >> bob.x >> bob.y;

    if (alice.x >= bob.x){
        cout << "Draw" << "\n";
        return;
    }

    int x = abs(alice.x - bob.x);
    int media = (bob.x - alice.x + 1)/2;

    if (x % 2){
        if (alice.y == bob.y){
            cout << "Alice" << "\n";
        }
        else if (alice.y < bob.y){
            if ((alice.y + media >= w) || (alice.y + media >= bob.y + media - 1)){
                cout << "Alice" << "\n";
            }
            else cout << "Draw" << "\n";
        }
        else {
            if ((alice.y - media <= 1) || (alice.y - media <= bob.y - media + 1)){
                cout << "Alice" << "\n";
            }
            else cout << "Draw" << "\n";
        }
    }
    else {
        if (alice.y == bob.y){
            cout << "Bob" << "\n";
        }
        else if (alice.y < bob.y){
            if (bob.y - media <= 1){
                cout << "Bob" << "\n";
            }
            else cout << "Draw" << "\n";
        }
        else {
            if (bob.y + media >= w){
                cout << "Bob" << "\n";
            }
            else cout << "Draw" << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}