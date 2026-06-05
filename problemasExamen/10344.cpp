#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

bool evaluate(const vector<int>& a, int index, int current_val) {
    if (index == 5) return current_val == 23;
    
    if (evaluate(a, index + 1, current_val + a[index])) return true;
    if (evaluate(a, index + 1, current_val - a[index])) return true;
    if (evaluate(a, index + 1, current_val * a[index])) return true;
    
    return false;
}

int main() {
    vector<int> a(5);
    vector<string> total_outputs;
    while (cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4]) {
        if (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0 && a[4] == 0) break;
        
        sort(a.begin(), a.end());
        bool possible = false;
        
        do {
            if (evaluate(a, 1, a[0])) {
                possible = true;
                break;
            }
        } while (next_permutation(a.begin(), a.end()));

        if (possible) {
            total_outputs.push_back("Possible");
        } else {
            total_outputs.push_back("Impossible");
        }
    }
    for (size_t i = 0; i < total_outputs.size(); i++) {
        cout << total_outputs[i] << endl;
    }
    system("pause");
    return 0;
}