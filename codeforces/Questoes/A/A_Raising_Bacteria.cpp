#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int x; cin >> x;

    if (x == 1) {
        cout << 1 << "\n";
        return 0;
    }
    
    // transforming into binary form

    vector<int> arr;

    while (x > 0){
        arr.push_back(x%2);
        x /= 2;
    }

    int ans = 0;
    for (int i = 0 ; i < (int)arr.size(); i++){
        if (arr[i] == 1) ans++;
    }

    cout << ans << "\n";
}
