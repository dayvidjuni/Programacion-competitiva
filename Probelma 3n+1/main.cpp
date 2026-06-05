#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int i,j;
    int max_len= 0;
    while(cin>> i>> j){
        for (int n= min(i,j); n<= max(i,j); n++) {
            int cycle_length= 1;
            int temp= n;
            while (temp!= 1) {
                if (temp% 2== 0) {
                    temp/= 2;
                } else {
                    temp=3* temp+ 1;
                }
                cycle_length++;
            }
            max_len =max(max_len, cycle_length);
        }
        cout << i<<" "<< j<<" "<< max_len<< endl;
        max_len= 0;
    }
    
    system("pause");
    return 0;
}