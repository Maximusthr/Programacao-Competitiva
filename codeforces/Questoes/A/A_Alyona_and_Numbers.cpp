#include <bits/stdc++.h>

using namespace std;

//must be O(n);

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int x, y; cin >> x >> y;

    long long ans = 0;

    map<int, int> m;
    for (int i = 1; i <= y; i++)
        m[i%5]++;

    for (int i = 1; i <= x; i++){
        if (i % 5 == 1) ans += m[4];
        else if (i % 5 == 2) ans += m[3];
        else if (i % 5 == 3) ans += m[2];
        else if (i % 5 == 4) ans += m[1];
        else ans += m[0];
    }
    
    cout << ans << "\n";
}
