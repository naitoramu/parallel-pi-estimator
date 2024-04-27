//
// Created by kuba on 4/26/24.
//

#ifndef PI_CALCULATOR_PICALCULATOR_H
#define PI_CALCULATOR_PICALCULATOR_H


class PiCalculator {

public:
    static double calculate_pi_per_process(int, int, int);
    static double calculate_pi_in_parallel(double, double, int);

private:
    static double rectangle_area(double, double, int i);
};


#endif //PI_CALCULATOR_PICALCULATOR_H
