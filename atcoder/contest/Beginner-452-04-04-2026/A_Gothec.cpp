#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    /*
    January 7
March 3
May 5
July 7
September 9
*/

    int n, m; cin >> n >> m;

    if (n == 1 && m == 7){
        cout << "Yes" << "\n";
        return;
    }
    if (n == 3 && m == 3){
        cout << "Yes" << "\n";
        return;
    }
    if (n == 5 && m == 5){
        cout << "Yes" << "\n";
        return;
    }
    if (n == 7 && m == 7){
        cout << "Yes" << "\n";
        return;
    }
    if (n == 9 && m == 9){
        cout << "Yes" << "\n";
        return;
    }

    cout << "No" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}