#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n, t, k, d; cin >> n >> t >> k >> d;

    int time1 = 0, cake1 = 0;
    while (cake1 < n){
        time1 += t;
        cake1 += k;
    }

    // optimal time

    int time2 = 0, cake2 = 0, count_new = 0, time_new = d;
    bool ok = false;
    while (cake2 < n){
        if (d <= time2){
            cake2 += k;
            time_new += t;
            ok = true;
        }
        cake2 += k;
        time2 += t;

        if (cake2 >= n && ok){
            time2 -= t;
            int aux = abs(time_new-time2);
            time2 += aux;
            break;
        }
    }

    if (time1 <= time2) cout << "NO";
    else cout << "YES";
    cout << "\n";
}
