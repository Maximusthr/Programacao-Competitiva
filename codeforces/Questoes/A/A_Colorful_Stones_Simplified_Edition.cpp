#include <bits/stdc++.h>

using namespace std;

int main(){
    string a, b; cin >> a >> b;

    int ans = 1;
    for (int i = 0, j = 0; i < (int)b.size(); i++){
        if (b[i] == a[j]) {
            j++;
            ans++;
        }
    }

    cout << ans << "\n";
}
