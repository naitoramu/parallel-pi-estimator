#include <cmath>
#include "../includes/PiCalculator.h"

double PiCalculator::calculate_pi_per_process(int rectangles_count, int processes_count, int process_number) {
    int rectangles_per_process = rectangles_count / processes_count;
    const double a = 0.0; // Lower bound
    const double b = 1.0; // Upper bound

    return calculate_pi_in_parallel(
        a + process_number * (b - a) / processes_count,
        a + (process_number + 1) * (b - a) / processes_count,
        rectangles_per_process
    );
}

double PiCalculator::calculate_pi_in_parallel(double a, double b, int rectangles_count) {
    double sum = 0.0;
    double dx = (b - a) / rectangles_count;

    #pragma omp parallel for reduction(+:sum) schedule(static)
    for (int i = 0; i < rectangles_count; ++i) {
        sum += rectangle_area(a, dx, i);
    }

    return 4.0 * sum;
}

double PiCalculator::rectangle_area(double a, double dx, int i) {
    double x_left = a + i * dx;
    double x_right = x_left + dx;
    double x_mid = (x_left + x_right) / 2;
    double y_mid = sqrt(1 - x_mid * x_mid);
    return y_mid * dx;
}