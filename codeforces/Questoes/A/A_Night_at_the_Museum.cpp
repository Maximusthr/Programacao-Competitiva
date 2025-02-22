#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    string x; cin >> x;

    int ans = 0;
    int temp = 97; // initial operation on a
    for (int i = 0; i < (int)x.size(); i++){
        int oper = abs(x[i]- temp);
        if (oper > 13)
            ans += 26-oper;
        else ans += oper;
        temp = x[i];
    }

    cout << ans << "\n";
}
