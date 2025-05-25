#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    map<int, int> arr;

    for (int i = 0; i < 7; i++){
        int x; cin >> x;
        arr[x]++;
    }

    bool ok2 = false;
    bool ok3 = false;
    int c = 0;
    for (auto [x, y] : arr){
        if (y >= 3) {
            ok3 = true;
            c++;
            if (c == 2) ok2 = true;
        }
        else if (y == 2) ok2 = true;
        
    }

    if (ok2 && ok3) cout << "Yes" << "\n";
    else cout << "No" << "\n";
}
