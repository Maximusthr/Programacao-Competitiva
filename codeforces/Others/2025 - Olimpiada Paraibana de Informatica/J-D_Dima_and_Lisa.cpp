#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef long long ll;

bool is_prime(int x) {
    if (x <= 1) return false;

    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);
    
    int n;
    cin >> n;

    if (is_prime(n)) {
        cout << 1 << endl << n << endl;
    } else {
        cout << 3 << endl;

        if (n % 3 == 0 && is_prime(n / 3)) {
            cout << n/3 << ' ' << n/3 << ' ' << n/3 << endl; 
        } else {
            for (int i = n / 2; i >= 3; i--) {
                if (is_prime(i) && is_prime(n - 2 * i)) {
                    cout << i << ' ' << i << ' ' << n - 2 * i << endl;
                    break;
                }
            }
        }
    }

    return 0;
}
