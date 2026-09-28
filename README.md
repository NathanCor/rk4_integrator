# rk4_integrator

A universal, header-only C++11 (and later) library for numerical integration using the 4th-order Runge-Kutta (RK4) method.

## Features
- **Header-only**: Just drop `include/rk4.hpp` into your project or use CMake.
- **Universal**: Works with any state type that supports addition `+` and scalar multiplication `*` (e.g., `double`, `std::valarray`, `Eigen::VectorXd`).
- **Zero overhead**: Highly optimized via C++ templates.

## Usage

```cpp
#include "rk4.hpp"
#include <iostream>

int main() {
    // dy/dt = -0.5 * y
    auto deriv = [](double t, double y) { return -0.5 * y; };

    double y = 100.0;
    double dt = 0.1;
    
    // One RK4 step
    y = nummeth::rk4_step(deriv, 0.0, y, dt);
    
    std::cout << "Next state: " << y << "\n";
    return 0;
}
