#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    string x; cin >> x;

    int ans = 0;

    if ((int)x.size() % 2 == 0){
        ans = (int)x.size()/2;
    }
    else {
        ans = (int)x.size()/2 + 1;

        bool ok = true;
        for (int i = 1; i < (int)x.size(); i++){
            if (x[i] == '1') {
                ok = false;
                break;
            }
        }
        if (ok) ans--;
    }

    cout << ans << "\n";
}
