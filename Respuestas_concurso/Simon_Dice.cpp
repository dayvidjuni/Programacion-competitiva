#include <iostream>
#include <string>
using namespace std;
int main(){
    int a;
    int k = 0;
    string d, g;
    string r[1000];
    
    cin >> a;
    getline(cin, d);

    for(int i=0; i<a; i++){
        getline(cin, d);
        if(d.length() >= 11){
            g = "";
            for(int j=0; j<11; j++){
                g =g +d[j];
            }
            if(g == "Simon says "){
                for(int j=11; j<d.length(); j++){
                    r[k]= r[k]+d[j];
                }
                k++;
            }
        }
    }

    for(int i=0; i<k; i++){
        cout << r[i] << "\n";
    }
    
}