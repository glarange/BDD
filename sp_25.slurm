#! /usr/bin/env bash

#SBATCH --job-name=sump_25
#SBATCH --output=sp25b.log
#SBATCH --ntasks-per-node=1
#SBATCH  -p debug-28core
#SBATCH --nodes=1
#SBATCH --time=1:00:00
#SBATCH --mail-type=BEGIN,END
#SBATCH --mail-user=guilherme.larangeira@stonybrook.edu

module load gcc-stack
module load cudd/3.0.0
module load sylvan/1.5.0
source activate bdd

gcc -lm sum_prod_25.c /gpfs/software/dd/cudd-3.0.0/cudd/.libs/libcudd.a -o sp25
./sp25
