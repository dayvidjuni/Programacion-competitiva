#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1, s2;
    char op;
    // El valor maximo de un int de 32 bits
    double limite = 2147483647.0;

    // Leemos el primer o , el operador y el segundo numero 
    while (cin >> s1 >> op >> s2) {
        // Imprimimos la lea original
        cout << s1 << " " << op << " " << s2 << endl;

        // stod maneja automaticamente numeros muy largos
        double n1 = stod(s1);
        double n2 = stod(s2);

        // Verificamos el primer numero
        if (n1 > limite) {
            cout << "first number too big" << endl;
        }

        // Verificamos el segundo numero
        if (n2 > limite) {
            cout << "second number too big" << endl;
        }

        // Calculamos el resultado segun el operador
        double resultado;
        if (op == '+') {
            resultado = n1 + n2;
        } else {
            resultado = n1 * n2;
        }

        // Verificamos el resultado
        if (resultado > limite) {
            cout << "result too big" << endl;
        }
    }

    system("pause");
    return 0;
    
}
