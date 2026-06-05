#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    int n, q, case_num = 1;
    vector<string> total_outputs;
    while (cin >> n >> q && (n != 0 || q != 0)) {
        vector<int> marbles(n);
        for (int i = 0; i < n; i++) cin >> marbles[i];
        
        sort(marbles.begin(), marbles.end());

        total_outputs.push_back("CASE# " + to_string(case_num++) + ":");
        for (int i = 0; i < q; i++) {
            int query;
            cin >> query;
            bool found = false;
            
            for (int j = 0; j < n; j++) {
                if (marbles[j] == query) {
                    total_outputs.push_back(to_string(query) + " found at " + to_string(j + 1));
                    found = true;
                    break;
                }
            }
            if (!found) {
                total_outputs.push_back(to_string(query) + " not found");
            }
        }
    }
    for (size_t i = 0; i < total_outputs.size(); i++) {
        cout << total_outputs[i] << endl;
    }
    system("pause");
    return 0;
}