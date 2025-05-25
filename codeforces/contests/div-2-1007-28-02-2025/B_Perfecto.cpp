#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;

    while(t--){
        int aux; cin >> aux;

        vector<long long> odd;
        vector<long long> even;
        for (int i = 1; i <= aux; i++){
            if (i % 2 == 1) odd.push_back(i);
            else even.push_back(i);
        }

        if (even.size() % 2 == 1) sort(odd.rbegin(), odd.rend());

        bool ok = false;
        long long sum = 0;
        for (int i = 0; i < even.size(); i++){
            sum += even[i];
            int square = sqrt(sum);
            if (square * square == sum) {
                ok = true;
                break;
            }
        }

        for (int i = 0; i < odd.size(); i++){
            sum += odd[i];
            int square = sqrt(sum);
            if (square * square == sum){
                ok = true;
                break;
            }
        }

        if (ok) cout << -1;
        else {
            for (int i = 0; i < even.size(); i++){
                cout << even[i] << " ";
            }
            for (int i = 0; i < odd.size(); i++){
                cout << odd[i] << " ";
            }
        }

        cout << "\n";
    }
}
