#include <iostream>
using namespace std;

int v[200005];

int main(){
    int n;
    long long c = 0;
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(v[i] > v[j]){
                c++;
            }
        }
    }
    
    cout << c;
    
    return 0;
}