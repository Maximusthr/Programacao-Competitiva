#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    vector<pair<int ,int>> arr;

    bool change = false;
    for (int i = 0; i < t; i++){
        int x, y; cin >> x >> y;

        if (x > y || x < y)
            change = true;
        
        arr.push_back({x, y});
    }

    if (change) cout << "rated" << "\n";
    else {
        bool ok = false;
        for (int i = 0; i < t; i++){
            if (i == t-1) break;
            if (i == 0) {
                if (arr[i].first < arr[i+1].first)
                    ok = true;
            }
            else if (arr[i].first < arr[i+1].first || arr[i].first > arr[i-1].first){
                ok = true;
            }

            if (ok) {
                cout << "unrated" << "\n";
                return 0;
            }
        }

        cout << "maybe" << "\n";
    }
}
