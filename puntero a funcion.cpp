#include <iostream>

using namespace std;


float Addition(float a, float b) {
    return a + b;
}

float Subtraction(float a, float b) {
    return a - b;
}

float Multiplication(float a, float b) {
    return a * b;
}

float Division(float a, float b) {
    if (b != 0)
        return a / b;
    else {
        cout << "Error" << endl;
        return 0; 
    }
}

int main() {
    
    typedef float (*lpfnOperation)(float, float);

   
    lpfnOperation vpf[4] = { &Addition, &Subtraction, &Multiplication, &Division };

    float a, b, c;
    int opt;

    
    cout << "Ingreso de dos números";
    cin >> a >> b;

    
    cout << "Seleccionar operacion (0-Addition, 1-Subtraction, 2-Multiplication, 3-Division): ";
    cin >> opt;

    if (opt >= 0 && opt < 4) {
        
        c = (*vpf[opt])(a, b);
        cout << "Resultado: " << c << endl;
    } else {
        cout << "Operacion invalida" << endl;
    }

    return 0;
}
