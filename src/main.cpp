#include <iostream>
#include <iomanip>
#include <mpi.h>
#include <omp.h>
#include "PiCalculator.h"

int main(int argc, char **argv) {
    int processes_count, process_number;
    double start_time, end_time;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &processes_count);
    MPI_Comm_rank(MPI_COMM_WORLD, &process_number);

    start_time = MPI_Wtime();

    int num_threads = 2; // Default number of threads
    int num_rectangles = 500000; // Default number of rectangles

    if (argc > 1) {
        num_threads = std::stoi(argv[1]);
    }

    omp_set_num_threads(num_threads);

    double local_integral = PiCalculator::calculate_pi_per_process(num_rectangles, processes_count, process_number);

    double global_integral;
    MPI_Reduce(&local_integral, &global_integral, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    end_time = MPI_Wtime();
    if (process_number == 0) {
        std::cout << "Approximation of PI: " << std::setprecision(10) << global_integral << std::endl;
        std::cout << "Computation time [s]: " << end_time - start_time << std::endl;
    }

    MPI_Finalize();
    return 0;
}
