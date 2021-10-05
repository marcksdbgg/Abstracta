#include <iostream>

int mod(int a, int b) {
    int r = a - b * (a / b);
    r = r + (r < 0) * b;
    return r;
}

int euclides_extendido(int a, int b) {
    int cont = 0;
    int aux_1 = a;
    int aux_2 = b;
    while (mod(a, b) != 0) {
        int aux = b;
        b = mod(a, b);
        a = aux;
        cont++;
    }
    cont = cont + 2;
    int arr[cont];
    arr[0] = aux_1;
    arr[1] = aux_2;

    int x[cont], y[cont], z[cont];
    y[0] = 1, y[1] = 0, z[0] = 0, z[1] = 1;
    for (int i = 1;; ++i) {
        x[i + 1] = arr[i - 1] / arr[i];
        arr[i + 1] = arr[i - 1] - (x[i + 1] * arr[i]);
        y[i + 1] = y[i - 1] - (x[i + 1] * y[i]);
        z[i + 1] = z[i - 1] - (x[i + 1] * z[i]);
        if (arr[i + 1] == 0) {
            return mod(y[i], arr[1]);
        }
    }
}

int main() {
    int a,b,c;
    std::cout << "Ingrese los dos numeros"<<std::endl;
    std::cout << "a: "; std::cin >> a;
    std::cout << "b: "; std::cin >> b;
    c = euclides_extendido(a, b);
    std::cout << "Resultado: "<<c;

}
