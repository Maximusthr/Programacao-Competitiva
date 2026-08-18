struct Seg {
    vector<vector<int>> seg;

    Seg(int n) : seg(4*n) {}

    vector<int> merge(vector<int> &a, vector<int> &b){
        int n = a.size();
        int m = b.size();

        vector<int> ans;

        ans.reserve(n+m);

        int i = 0, j = 0;
        while(i < n && j < m){
            if (a[i] <= b[j]){
                ans.push_back(a[i]);
                i++;
            }
            else {
                ans.push_back(b[j]);
                j++;
            }
        }

        while (i < n){
            ans.push_back(a[i]);
            i++;
        }

        while(j < m){
            ans.push_back(b[j]);
            j++;
        }

        return ans;
    }

    vector<int> &build(vector<int> &arr, int p, int l, int r){
        if (l == r) {
            seg[p].push_back(arr[l]);
            return seg[p];
        }
        int mid = (l+r)/2;
        return seg[p] = merge(build(arr, 2*p, l, mid), build(arr, 2*p+1, mid+1, r));
    }

    int query(int a, int b, int p, int l, int r, int k){
        if (l > b || r < a) return 0;
        if (l >= a && r <= b){
            // operacao
        }   
        int mid = (l+r)/2;
        return query(a, b, 2*p, l, mid, k) + query(a, b, 2*p+1, mid+1, r, k);
    }
};
