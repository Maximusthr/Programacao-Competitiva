#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;

    while(t--){
        int x; cin >> x;

        vector<int> arr(x);
        for (auto &i : arr) cin >> i;

        bool zero = false;
        for (int i = 0; i < x; i++){
            if (arr[i] == 0) {
                zero = true;
                break;
            }
        }

        if (!zero) {
            cout << 1 << "\n";
            cout << 1 << " " << x << "\n";
        }
        else {
            bool first = false;
            for (int i = 0; i < x/2; i++){
                if (arr[i] == 0) {
                    first = true;
                    break;
                }
            }

            bool second = false;
            for (int i = x/2; i < x; i++){
                if (arr[i] == 0){
                    second = true;
                    break;
                }
            }

            if (first && second){
                cout << 3 << "\n";
                cout << 1 << " " << x/2 << "\n";
                if (x % 2 == 0) cout << 2 << " " << x/2+1 << "\n";
                else cout << 2 << " " << x/2+2 << "\n";
                cout << 1 << " " << 2 << "\n";
            }
            else if (first){
                cout << 2 << "\n";
                cout << 1 << " " << x/2 << "\n";
                if (x % 2 == 0) cout << 1 << " " << x/2+1 << "\n";
                else cout << 1 << " " << x/2+2 << "\n";
            }
            else if (second){
                cout << 2 << "\n";
                cout << x/2+1 << " " << x << "\n";
                cout << 1 << " " << x/2+1 << "\n";
            }
        }
    }
}
