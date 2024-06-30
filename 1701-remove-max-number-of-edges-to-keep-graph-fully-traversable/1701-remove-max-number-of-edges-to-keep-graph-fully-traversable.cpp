class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    int components;

    DSU(int n) { // constructor
        parent.resize(n);
        rank.resize(n);
        components = n;
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int x_p = find(x);
        int y_p = find(y);

        if (x_p == y_p)
            return;

        if (rank[x_p] > rank[y_p]) {
            parent[y_p] = x_p;
        } else if (rank[x_p] < rank[y_p]) {
            parent[x_p] = y_p;
        } else {
            parent[x_p] = y_p;
            rank[y_p]++;
        }
        components--; // added for this problem
    }

    bool is1component() {
        return components == 1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU Alice(n);
        DSU Bob(n);

        auto alpha = [](vector<int>& v1, vector<int>& v2) {
            return v1[0] > v2[0];
        };

        sort(edges.begin(), edges.end(), alpha);

        int edgeCnt = 0;

        for (auto &vec : edges) {
            int type = vec[0];
            int u = vec[1] - 1; // Convert to 0-indexed
            int v = vec[2] - 1; // Convert to 0-indexed

            if (type == 3) {
                bool edgeAdded = false;
                // for Alice
                if (Alice.find(u) != Alice.find(v)) {
                    Alice.Union(u, v);
                    edgeAdded = true;
                }

                // for Bob
                if (Bob.find(u) != Bob.find(v)) {
                    Bob.Union(u, v);
                    edgeAdded = true;
                }

                if (edgeAdded) {
                    edgeCnt++;
                }
            } else if (type == 2) {
                if (Bob.find(u) != Bob.find(v)) {
                    Bob.Union(u, v);
                    edgeCnt++;
                }
            } else { // type == 1
                if (Alice.find(u) != Alice.find(v)) {
                    Alice.Union(u, v);
                    edgeCnt++;
                }
            }
        }

        if (Alice.is1component() && Bob.is1component()) {
            return edges.size() - edgeCnt;
        }

        return -1;
    }
};