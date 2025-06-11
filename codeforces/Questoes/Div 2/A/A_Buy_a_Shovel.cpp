#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int x, r; cin >> x >> r;

    int ans = 1;
    int temp = x;
    while (x % 10 != 0 && x % 10 != r){
        x += temp;
        ans++;
    }

    cout << ans << "\n";
}
