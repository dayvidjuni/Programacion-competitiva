#include <iostream>
#include <string>
using namespace std;

string m[1005];
int r, c;

void f(int x, int y){
    if(x<0){
        return;
    }
    if(x>=r){
        return;
    }
    if(y<0){
        return;
    }
    if(y>=c){
        return;
    }
    if(m[x][y]=='0'){
        return;
    }
    
    m[x][y] = '0';
    
    f(x + 1, y);
    f(x - 1, y);
    f(x, y + 1);
    f(x, y - 1);
}

int main(){
    int k= 0;
    
    cin>> r>> c;
    
    for(int i=0; i<r; i++){
        cin>> m[i];
    }
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(m[i][j] == '1'){
                k++;
                f(i, j);
            }
        }
    }
    
    cout<< k;
    
    return 0;
}