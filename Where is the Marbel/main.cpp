#include <iostream>

using namespace std;

int main() {
    int n, q;
    int caso= 1;
    
    while (cin >>n >>q &&(n !=0 ||q !=0)) {
        int canicas[10005];
        
        for (int i =0; i <n; i++) {
            cin >> canicas[i];
        }
        
        for (int i =0; i <n -1; i++) {
            for (int j =0; j <n -i -1; j++) {
                if (canicas[j] >canicas[j + 1]) {
                    int temp =canicas[j];
                    canicas[j] =canicas[j + 1];
                    canicas[j + 1] = temp;
                }
            }
        }
        
        cout << "CASE# "<< caso++<< ":\n";
        
        for (int i =0; i <q; i++) {
            int consulta;
            cin >>consulta;
            
            bool encontrado =false;
            
            for (int j =0; j <n; j++) {
                if (canicas[j] ==consulta) {
                    cout <<consulta <<" found at " << j + 1 << "\n";
                    encontrado =true;
                    break;
                }
            }
            
            if (!encontrado) {
                cout <<consulta <<" not found\n";
            }
        }
    }
    
    system("pause");
    return 0;
}