# Reliability-PCA-BDDs-and-CUDD-implementation
BDD for reliability and PCA

1. input file F1: A boolean expression representation of a top event (system problem) as a sum of products, or logical disjunction of conjunctions.
(csv or txt file with one term per line).

2. input file F2: list of variables (single events) with associated probabilities and durations. 
(csv or txt file with 2 columns, variable and associated probability of outage and duration.)

3. function 1: convert F1 to CUDD BDD through Cudd_bddAnd and Cudd_bddOr.

4. functions 2: Render the BDD and the min. cutsets to output file F3.

5. function 3 and output F4: Calculate the top event probability and duration from F3.



