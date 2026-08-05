#include <iostream>
#include <string>
using namespace std;
int main(){
    string d;
    int a =0;
    int b =0;
    
    cin >>d;

    for(int i=0; i<d.length(); i=i+2){
        if(d[i] =='A'){
            if(d[i+1] =='1'){
                a++;
            }
            if(d[i+1] =='2'){
                a = a + 2;
            }
        }
        if(d[i] =='B'){
            if(d[i+1] =='1'){
                b++;
            }
            if(d[i+1] =='2'){
                b =b +2;
            }
        }
    }

    if(a >b){
        cout <<"A";
    }
    if(b >a){
        cout <<"B";
    }
    
    return 0;
}