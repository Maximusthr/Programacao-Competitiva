#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int x; cin >> x;
    int a; cin >> a;

    int op = 7 - a;

    for (int i = 0; i < x; i++){
        int c, d; cin >> c >> d;
        if (a == c || a == d || op == c || op == d) {
            cout << "NO" << "\n";
            return 0;
        }
    }
    cout << "YES" << "\n";
}
