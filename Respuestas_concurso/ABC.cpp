#include <iostream>
using namespace std;
int main(){
    int a,b,c,g;
    char d[3];
    int f[3];
    
    cin >> a>>b>>c;
    f[0]=a;
    f[1]=b;
    f[2]=c;

    for(int i=0; i<3;i++){
        cin >>d[i];
    }

    for(int i=0; i<3; i++ ){
        for(int j=i+1; j<3; j++){
            if(f[i] > f[j]){
                g=f[i];
                f[i]=f[j];
                f[j]=g;
            }
        }
    }

    for(int i=0; i<2; i++){
        if(d[i] == 'A'){
            cout <<f[0] << " ";
        }
        if(d[i] == 'B'){
            cout <<f[1] << " ";
        }
        if(d[i] == 'C'){
            cout <<f[2] << " ";
        }
    }
    if(d[2] == 'A'){
            cout <<f[0];
        }
        if(d[2] == 'B'){
            cout <<f[1];
        }
        if(d[2] == 'C'){
            cout <<f[2];
        }
    
    return 0;
}