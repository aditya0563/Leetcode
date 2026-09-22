class Solution {
public:
    struct Node {
        int total;
        int cnt[5];
        
        Node() {
            total = 1;
            cnt[0] = cnt[1] = cnt[2] = cnt[3] = cnt[4] = 0;
        }
    };

    int K;

    Node merge(const Node& l, const Node& r) {
        Node res;
        res.total = (l.total * r.total) % K;
        
        for (int i = 0; i < K; ++i) {
            res.cnt[i] = l.cnt[i];
        }
        
        for (int i = 0; i < K; ++i) {
            if (r.cnt[i] > 0) {
                res.cnt[(l.total * i) % K] += r.cnt[i];
            }
        }
        
        return res;
    }

    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        K = k;
        
        vector<Node> tree(2 * n);
        
        for (int i = 0; i < n; ++i) {
            int val = nums[i] % K;
            tree[n + i].total = val;
            tree[n + i].cnt[val] = 1;
        }
        
        for (int i = n - 1; i > 0; --i) {
            tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);
        }
        
        vector<int> result;
        result.reserve(queries.size());
        
        for (const auto& q : queries) {
            int idx = q[0];
            int val = q[1] % K;
            int start = q[2];
            int x = q[3];
            
            int p = n + idx;
            tree[p].total = val;
            for (int i = 0; i < K; ++i) tree[p].cnt[i] = 0;
            tree[p].cnt[val] = 1;
            
            for (p >>= 1; p > 0; p >>= 1) {
                tree[p] = merge(tree[p << 1], tree[p << 1 | 1]);
            }
            
            Node resL, resR;
            int l = n + start;
            int r = n + n;
            
            while (l < r) {
                if (l & 1) { 
                    resL = merge(resL, tree[l]); 
                    l++; 
                }
                if (r & 1) { 
                    r--; 
                    resR = merge(tree[r], resR); 
                }
                l >>= 1;
                r >>= 1;
            }
            
            Node final_res = merge(resL, resR);
            result.push_back(final_res.cnt[x]);
        }
        
        return result;
    }
};