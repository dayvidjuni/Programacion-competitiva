#include <iostream>
#include <string>
using namespace std;
int main(){
    int a;
    char b;
    string c;
    int p[200];
    int s[200];
    int k =0;
    int t =0;

    for(int i=0; i<200; i++){
        p[i] =0;
        s[i] =0;
    }

    while(true){
        cin >> a;
        if(a == -1){
            break;
        }
        cin >>b;
        cin >>c;
        
        if(s[b] == 0){
            if(c == "right"){
                s[b] =1;
                k++;
                t = t+ a+ (p[b]* 20);
            }
            if(c == "wrong"){
                p[b]++;
            }
        }

    }

    cout <<k << " " <<t;
    
    return 0;
}