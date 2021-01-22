#include <iostream>
#include <complex>

using namespace std;

void subtractionOfNumbers(float a, float b) {
    cout << "\nфункция для вычитания вещественных чисел:\n";
    cout << a << " + " << b << " = " << (a - b);
}
void subtractionOfNumbers(float xi, float xc, float yi, float yc) {
    cout << "\nфункция для вычитания комплексных чисел:\n";
    cout << xi << "+" << "i*" << xc << " - " << yi << "+" << "i*" << yc;
    yi = -yi;
    yc = -yc;
    cout << " = " << xi + yi << "+i*" << xc + yc;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    subtractionOfNumbers(3.45, 1.05);
    subtractionOfNumbers(3.0, 4.0, 1.0, 1.5);
}

