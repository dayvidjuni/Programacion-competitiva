#include <iostream>
using namespace std;

int u[1000005];
int v[1000005];
int r[10000];

int main(){
    int n, m;
    int k, i, j, x, y;
    int z = 0;

    while(true){
        cin >>n >>m;
        
        if(n == 0){
            if(m == 0){
                break;
            }
        }

        for(i=0; i<n; i++){
            cin>> u[i];
        }
        for(i=0; i<m; i++){
            cin>> v[i];
        }

        k= 0;
        i= 0;
        j= 0;

        while(true){
            if(i == n){
                break;
            }
            if(j == m){
                break;
            }

            x= u[i];
            y= v[j];

            if(x == y){
                k++;
                i++;
                j++;
            }
            if(x < y){
                i++;
            }
            if(x > y){
                j++;
            }
        }

        r[z]= k;
        z++;
    }

    for(i=0; i<z; i++){
        if(i== z- 1){
            cout << r[i];
        }
        if(i!= z- 1){
            cout << r[i] << "\n";
        }
    }
    
    return 0;
}