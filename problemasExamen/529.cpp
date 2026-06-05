#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int n;
vector<int> ans;
bool found = false;

void dfs(int depth, int max_depth, vector<int>& path) {
    if (found) return;
    if (depth == max_depth) {
        if (path.back() == n) {
            ans = path;
            found = true;
        }
        return;
    }

    int last = path.back();
    for (int i = depth; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            int next_val = path[i] + path[j];
            if (next_val > last && next_val <= n) {
                int max_possible = next_val;
                for(int k = 0; k < max_depth - depth - 1; k++) {
                    max_possible *= 2;
                }
                if (max_possible < n) continue;

                path.push_back(next_val);
                dfs(depth + 1, max_depth, path);
                path.pop_back();
                if (found) return;
            }
        }
    }
}

int main() {
    vector<vector<int>> total_outputs;
    while (cin >> n && n != 0) {
        found = false;
        vector<int> path;
        path.push_back(1);
        if (n == 1) {
            total_outputs.push_back({1});
            continue;
        }
        int max_depth = 1;
        while (!found) {
            dfs(0, max_depth, path);
            max_depth++;
        }
        total_outputs.push_back(ans);
    }
    for (size_t i = 0; i < total_outputs.size(); i++) {
        for (size_t j = 0; j < total_outputs[i].size(); j++) {
            cout << total_outputs[i][j] << (j == total_outputs[i].size() - 1 ? "" : " ");
        }
        cout << endl;
    }
    system("pause");
    return 0;
}