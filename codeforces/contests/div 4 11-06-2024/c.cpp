#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    vector<int> x;

    int ans = 0, aux = 0, count = 0;

    while(t--){
        int n; cin >> n;

        while (n--){
            int i = 0;
            cin >> x[i];
            i++;
        }

        for (int j = 0; j < (int)x.size(); j++){
            for (int k = 0; k < (int)x.size(); k++){
                aux += x[k];
                if (x[j] == aux) {
                    count++;
                }
                k++;
            }
        }

        count = ans;

        cout << ans << "\n";
    }
}
