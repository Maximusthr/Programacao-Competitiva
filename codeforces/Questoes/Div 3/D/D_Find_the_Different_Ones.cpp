#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<ll> arr(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    vector<ll> prefix(n+1);
    for (int i = 1; i <= n; i++){
        prefix[i] = prefix[i-1] + arr[i];
    }

    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;

        bool foi = false;
        int lll = l, rr = r;
        while (lll < rr){
            int mid = lll + (rr-lll)/2; 
            
            ll bb_left = (prefix[mid] - prefix[lll-1] + mid-lll)/(mid-lll+1);
            
            if (arr[mid] != arr[l]){
                cout << l << " " << mid << "\n";
                foi = true;
                break;
            }

            if (bb_left != arr[l]){
                if (arr[mid] != arr[l]){
                    cout << l << " " << mid << "\n";
                    foi = true;
                    break;
                }
                else {
                    rr = mid;
                }
            }
            else {
                lll = mid + 1;
            }
        }

        int l3 = l, r3 = r;
        if (!foi){
            while (l3 < r3){
                int mid = l3 + (r3-l3)/2; 
                
                ll bb_left = (prefix[mid] - prefix[l3-1] + mid-l3)/(mid-l3+1);
                
                if (arr[mid] != arr[l]){
                    cout << l << " " << mid << "\n";
                    foi = true;
                    break;
                }
    
                if (bb_left != arr[l]){
                    if (arr[mid] != arr[l]){
                        cout << l << " " << mid << "\n";
                        foi = true;
                        break;
                    }
                    else {
                        l3 = mid;
                    }
                }
                else {
                    r3 = mid - 1;
                }
            }
        }

        int l2 = l, r2 = r;
        if (!foi){
            while (l2 < r2){
                int mid = l2 + (r2-l2)/2; 
                
                ll bb_right = (prefix[mid] - prefix[l2-1])/(mid-l2+1);
    
                
                if (arr[mid] != arr[l]){
                    cout << l << " " << mid << "\n";
                    foi = true;
                    break;
                }
                
                if (bb_right != arr[l]){
                    if (arr[mid] != arr[l]){
                        cout << l << " " << mid << "\n";
                        foi = true;
                        break;
                    }
                    else {
                        l2 = mid;
                    }
                }
                else {
                    r2 = mid-1;
                }
            }
        }

        int l4 = l, r4 = r;
        if (!foi){
            while (l4 < r4){
                int mid = l4 + (r4-l4)/2; 
                
                ll bb_right = (prefix[mid] - prefix[l4-1])/(mid-l4+1);
    
                
                if (arr[mid] != arr[l]){
                    cout << l << " " << mid << "\n";
                    foi = true;
                    break;
                }
                
                if (bb_right != arr[l]){
                    if (arr[mid] != arr[l]){
                        cout << l << " " << mid << "\n";
                        foi = true;
                        break;
                    }
                    else {
                        r4 = mid;
                    }
                }
                else {
                    l4 = mid+1;
                }
            }
        }

        if (!foi){
            if (arr[l2] != arr[l]){
                cout << l << " " << l2 << "\n";
            }
            else if (arr[lll] != arr[l]){
                cout << l << " " << lll << "\n";
            }
            else if (arr[l3] != arr[l]){
                cout << l << " " << l3 << "\n";
            }
            else if (arr[l4] != arr[l]){
                cout << l << " " << l4 << "\n";
            }
            else cout << -1 << " " << -1 << "\n";
        }
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}