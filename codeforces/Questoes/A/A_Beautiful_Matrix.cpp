#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    pair<int, int> val;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            int a; cin >> a;

            if (a == 1){
                val = {i, j};
            }
        }
    }
    cout << abs(val.first - 2) + abs(val.second - 2) << "\n";
}
