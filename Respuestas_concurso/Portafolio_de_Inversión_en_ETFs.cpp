#include <iostream>
using namespace std;
int main(){
    int c, n, k, t;
    int p[25];
    int r =0;
    int m =1;

    cin >>c >>n;

    for(int i=0; i<n; i++){
        cin>> p[i];
    }

    for(int i=0; i<n; i++){
        m =m * 2;
    }

    for(int i=0; i<m; i++){
        k = 0;
        t = i;
        for(int j=0; j<n; j++){
            if(t % 2 == 1){
                k= k+ p[j];
            }
            t = t/ 2;
        }
        if(k == c){
            r++;
        }
    }

    cout <<r;
    
    return 0;
}