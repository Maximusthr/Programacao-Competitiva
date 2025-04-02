#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int x; cin >> x;

        string a, b; cin >> a >> b;

        int ones_up_odd = 0;
        int zeros_down_odd = 0;

        int ones_up_even = 0;
        int zeros_down_even = 0;

        // a
        for (int i = 0; i < x; i++){
            if (a[i] == '1' && i % 2 == 0) ones_up_even++;
            else if (a[i] == '1') ones_up_odd++;
        }

        // b
        for (int i = 0; i < x; i++){
            if (b[i] == '0' && i % 2 == 0) zeros_down_even++;
            else if (b[i] == '0') zeros_down_odd++;
        }

        if (zeros_down_even >= ones_up_odd && zeros_down_odd >= ones_up_even) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}
