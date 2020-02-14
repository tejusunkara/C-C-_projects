#include "complex.h"

int main() {
    // test the functions of Complex class
    Complex a(1, 2);
    Complex b(3, 4);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;

    cout << "a + 1 = " << a + 1 << endl;
    cout << "a - 1 = " << a - 1 << endl;
    cout << "a * 2 = " << a * 2 << endl;
    cout << "a / 2 = " << a / 2 << endl;

    cout << "-3 + b = " << -3 + b << endl;
    cout << "3 - b = " << 3 - b << endl;
    cout << "3 * b = " << 3 * b << endl;
    cout << "3 / b = " << 3 / b << endl;

    return 0;
}



