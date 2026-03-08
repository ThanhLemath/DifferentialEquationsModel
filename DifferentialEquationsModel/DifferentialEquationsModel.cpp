#include <iostream>
#include <Python.h>
#include "matplotlibcpp.h"
// 356 and 354 have been commented out 
#include <vector>

namespace plt = matplotlibcpp;

int main()
{
    Py_Initialize();
    int const n = 100;
    double initial_value_y = 36;
    double initial_value_x = 10;
    const double step_size = 0.01;
    double arr[n];
    arr[0] = initial_value_y;
    for (int i = 0; i < n - 1; i++) {
        arr[i + 1] = arr[i] + step_size * 3 * (initial_value_x + i * step_size) * (1 - arr[i]);
    }

    // --- Copy to std::vector for plotting ---
    std::vector<double> y(arr, arr + n);

    // Create x-axis vector
    std::vector<double> x(n);
    for (int i = 0; i < n; i++) {
        x[i] = initial_value_x + i * step_size;
    }

    // --- Plot with matplotlibcpp ---
    plt::plot(x, y);
    plt::title("Array Plot Example");
    plt::xlabel("x");
    plt::ylabel("y");
    plt::grid(true);
    plt::show();

    Py_Finalize();  // Shutdown Python

    return 0;
}
