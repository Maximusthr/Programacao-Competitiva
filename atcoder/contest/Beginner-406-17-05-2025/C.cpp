// WA

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

typedef struct{
    int x;
    bool pequeno;
    bool val;
} num;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    deque<num> m;

    int count_val = 0;

    bool is_peq = false;
    for (int i = 0; i < n-1; i++){
        if (arr[i] < arr[i+1]){
            m.push_back({arr[i], true, false});
            is_peq = true;
        }
        else if (arr[i] > arr[i+1]){
            m.push_back({arr[i], false, false});
            is_peq = false;
        }
        if (i > 0 && i <= n-1){
            if ((arr[i] > arr[i+1] && arr[i] > arr[i-1]) || (arr[i] < arr[i+1] && arr[i] < arr[i-1])){
                m[i] = {arr[i], is_peq, true};
                count_val++;
            }
        }
    }

    // push no ultimo;
    m.push_back({arr[n-1], false, false});

    int ans = 0;
    for (int i = 0, j = 0; i < n; i++){
        if ((int)m.size() >= 4){
            if (m[j].pequeno) {
                if ((m[j].val && count_val > 1) || (count_val > 0)) {
                    ans++;
                    //count_val--;
                }
                //if(m[j].val) count_val--;
            }
            //if (!m[j].pequeno && m[j].val) count_val--;
            if (m[j].val) count_val--;
        }
        m.pop_front();
    }

    cout << ans << "\n";
}