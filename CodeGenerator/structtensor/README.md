# How to run experiments

## Micro Benchmarks

Run sbt by specifying the experiment name to generate the code [use `sbt "run [name]"`]:

`LRC`       = Linear Regression - Creation

`PR2C`      = Polynomial Regression Degree 2 - Creation

`PR3C`      = Polynomial Regression Degree 3 - Creation

`LRA`       = Linear Regression - Addition

`PR2A`      = Polynomial Regression Degree 2 - Addition

`PR3A`      = Polynomial Regression Degree 3 - Addition

`TTM_DP`    = TTM: Diagonal (Plane)

`TTM_J`     = TTM: Fixed j

`TTM_UT`    = TTM: Upper Triangular (Half-cube)

`THP_DP`    = THP: Diagonal (Plane)

`THP_I`     = THP: Fixed i

`THP_J`     = THP: Fixed j

`MTTKRP_IJ` = MTTKRP: Fixed i & j

`MTTKRP_I`  = MTTKRP: Fixed i

`MTTKRP_J`  = MTTKRP: Fixed j

For example: `sbt "run THP_I"` to get the code for THP: Fixed i case. 
Then compile the file `[name].cpp` using the flags mentioned in the example.
Run the code by passing the required arguments to the compiled code.

### Example

```
sbt "run THP_I"
c++ THP_I.cpp -g -std=c++17 -O3 -pthread -mtune=native -Wno-narrowing -mavx2 -ffast-math -ftree-vectorize -o THP_I
./THP_I 100 100 100 10
```

## E2E

Run sbt by specifying the experiment name to generate the code [use `sbt "run [name]"`]:

`E2E_LR`    = E2E - Linear Regression

`E2E_PR2`   = E2E - Polynomial Regression Degree 2

### Example

```
sbt "run E2E_LR"
python new_dataset_creator.py
c++ main.cpp -g -std=c++17 -O3 -pthread -mtune=native -Wno-narrowing -mavx2 -ffast-math -ftree-vectorize -o main
./main
```

For different cases of Favorita and Retailer, you need to change the name of the dataset in line 209 of `main.cpp` to the corresponding name.
Two different sizes of dataset are suhffled and generated using the Python code.
