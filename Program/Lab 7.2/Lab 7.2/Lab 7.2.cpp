#include <iostream>
#include <stdio.h>
using namespace std;

int min(int n, ...) {
    int* ptr = &n, result = 0;
    result = *(++ptr);
    while (n != 0) {
        if (result > (*ptr)) {
            result = (*ptr);
        }
        ptr++;
        n--;
    }
    return result;

}

int main()
{
    cout << min(5, 1, 2, 3, 0, 5);
    cout << "\n";
    cout << min(10, 1, 2, 3, 0, 5, 1, 2, 3, -1, 5);
    cout << "\n";
    cout << min(12, 1, 2, 3, 0, 5, -22, 2, 3, -1, 5);
}
