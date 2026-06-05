#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int min_swaps = 1000000;
int map_count = 0;

bool is_sorted(const vector<int>& a) {
    for (size_t i = 0; i < a.size() - 1; i++) {
        if (a[i] > a[i+1]) return false;
    }
    return true;
}

void dfs(vector<int>& a, int swaps) {
    if (is_sorted(a)) {
        if (swaps == 0) return; 
        if (swaps < min_swaps) {
            min_swaps = swaps;
            map_count = 1;
        } else if (swaps == min_swaps) {
            map_count++;
        }
        return;
    }
    
    if (swaps >= min_swaps || swaps >= 10) return;

    for (size_t i = 0; i < a.size() - 1; i++) {
        if (a[i] > a[i+1]) { 
            int temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;
            
            dfs(a, swaps + 1);
            
            temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;
        }
    }
}

int main() {
    int n, case_num = 1;
    vector<pair<int, int>> total_outputs;
    while (cin >> n && n != 0) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        min_swaps = 1000000;
        map_count = 0;
        
        if (is_sorted(a)) {
            total_outputs.push_back({case_num++, 0});
            continue;
        }
        
        dfs(a, 0);
        total_outputs.push_back({case_num++, map_count});
    }
    for (size_t i = 0; i < total_outputs.size(); i++) {
        cout << "There are " << total_outputs[i].second << " swap maps for input data set " << total_outputs[i].first << "." << endl;
    }
    system("pause");
    return 0;
}