#!/bin/bash

PROCESSES_COUNTS=(1 2)
THREADS_COUNTS=(1 2 3 4 5 6)

for processes_count in ${PROCESSES_COUNTS[@]}; do
  for threads_count in ${THREADS_COUNTS[@]}; do
    result=$(mpiexec -n ${processes_count} ./PI_Calculator ${threads_count})
    echo "p${processes_count} t${threads_count} ${result}"
  done
done