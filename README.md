# StructTensor: Compiling Structured Tensor Algebra

[![CI](https://github.com/edin-dal/structtensor/actions/workflows/compile_and_test.yml/badge.svg)](https://github.com/edin-dal/structtensor/actions/workflows/compile_and_test.yml)

StructTensor is the first framework that supports structured computation for tensor algebra on variable-sized tensors. It uses program reasoning and compiler techniques to generate a high-performance structure-aware code that can achieve **up to 6 orders of magnitude** performance boost over well-known dense tensor frameworks such as NumPy, PyTorch, and TensorFlow over structured computation in several applications such as machine learning (linear- and polynomial-regression) and computing convolution kernels. The  StructTensor compiler is written in Scala and will output a C++ code that can be later compiled through C++ compilers such as Clang or GCC.

To learn more about StructTensor, please read [our paper published in OOPSLA'23](https://dl.acm.org/doi/pdf/10.1145/3622804).

## Requirements

To run this framework, you need [Scala](https://www.scala-lang.org/download/all.html) 2 of minimum version 2.13.3 and [sbt](https://www.scala-sbt.org/download/) of minimum version 1.7.0. Note that sbt relies on JDK version 8. To compile the generated code, any C++ compiler, such as GCC or Clang can be used.

## Usage

To generate a code for the structured computation, first, the corresponding expression should be written in STUR. Each expression needs to provide the symbols (variables that are meant to be read from argv), dimension information of all used tensors (mandatory), unique set of all input tensors (optional, provides the structure of non-zero unique elements), and the redundancy map of all input tensors (optional, provides the mapping from redundant elements to the unique elements). Then, StructTensor will compile the file with the `.stur` extension and generate the code.

### Writing STUR

We describe the STUR files using examples. The expression corresponding to matrix-vector multiplication where the matrix is an $N \times N$ diagonal is as follows:

```
symbols: N
A(i) := B(i, j) * C(j)
B:D(i, j) := (0 <= i < N) * (0 <= j < N)
C:D(j) := (0 <= j < N)
B:U(i, j) := (i = j)
A:D(i) := (0 <= i < N)
```

Here, `N` is the symbol and will be provided through the command line to the generated code. The line after provides the computation expression. `A:D(i)`, `B:D(i, j)`, and `C:D(j)` indicate the dimensions of tensors `A`, `B`, and `C`, respectively. `B:U(i, j)` indicates the unique set of the non-zero and unique elements for matrix `B`. The following C++ code will be generated after being processed by StructTensor:

```c++
void fn(double * A, double ** B, double * C, int N) {
  for (int i = 0; i < N; ++i) {
    A[i] += (B[i][i] * C[i]);
  }
}
```

Instructions on how to generate C++ code from STUR files are provided in a [later section](#generating-c-code).

In this example, if matrix `B` is symmetric instead of diagonal, then the STUR expression would be as follows:

```
symbols: N
A(i) := B(i, j) * C(j)
B:D(i, j) := (0 <= i < N) * (0 <= j < N)
C:D(j) := (0 <= j < N)
B:U(i, j) := (i <= j)
B:R(i, j, ip, jp) := (i > j) * (ip = j) * (jp = i)
A:D(i) := (0 <= i < N)
```

Here, `B:R(i, j, ip, jp)` provides the mapping for redundant elements of matrix `B`.

Make sure that you are following the same convention when you write your own STUR file. Always use `T:D` for dimension information, `T:U` for unique set, and `T:R` for redundancy map of tensor `T`. Note that the second half of the iterator names in the redundancy map must always be similar to the first half but with an extra `p` at the end of their names.

#### Using Scalar Tensors and Numbers

Following is an example on how you can use scalar tensors and constant numbers in STUR.

```
symbols: N
A(i) := 3.14 * B() * C(i)
A:D(i) := (0 <= i < N)
C:D(i) := (0 <= i < N)
```

This computation will generate the following code:

```c++
for (int i = 0; i < N; ++i) {
  A[i] += (3.14 * B * C[i]);
}
```

As shown, the values of the array `C` are multiplied by `3.14` and the value of variable `B`.

#### Subtraction

Subtraction can be represented by multiplying the second operand of the addition by -1. Following is an example of using tensor subtraction with STUR syntax.

```
symbols: N
A(i) := B(i) + (-1) * C(i)
A:D(i) := (0 <= i < N)
B:D(i) := (0 <= i < N)
C:D(i) := (0 <= i < N)
```

#### Division

Division is represented by adding `^-1` to the name of the tensors or constants. Following is an example of using tensor divison with STUR syntax.

```
symbols: N
A(i) := B(i) * 3.14^-1 * C^-1()
A:D(i) := (0 <= i < N)
B:D(i) := (0 <= i < N)
```

This computation will generate the following code:

```c++
for (int i = 0; i < N; ++i) {
  A[i] += (1. / C * 1. / 3.14 * B[i]);
}
```

#### More Complex Structures

More complex structures can be represented through STUR as well. For example, assigning a matrix with skew-symmetric structure to another matrix can be represented as follows:

```
symbols: N
A(i, j) := B(i, j)
A:D(i, j) := (0 <= i < N) * (0 <= j < N)
B:D(i, j) := (0 <= i < N) * (0 <= j < N)
B:U(i, j) := (0 <= i <= j < N)
B:R(i, j, ip, jp) := -1 * (0 <= j < i < N) * (ip = j) * (jp = i) 
```

### Advanced Syntax

#### Preprocessing

If you wish to do some preprocessing on the tensors (e.g., provide data layout for structured tensors), the preprocessing code should be provided between `@preprocess_start` and `@preprocess_end` in the STUR file. For example, the STUR code for diagonal matrix-vector multiplication with a vector data layout for the diagonal matrix can be written as follows:

``` 
symbols: N
@preprocess_start
B2(i) := B(i, j) * (i = j)
B:D(i, j) := (0 <= i < N) * (0 <= j < N)
B:U(i, j) := (i = j)
B2:D(i) := (0 <= i < N)
@preprocess_end
A(i) := B2(i) * C(j) * (i = j)
B2:D(i) := (0 <= i < N)
C:D(j) := (0 <= j < N)
A:D(i) := (0 <= i < N)
```

This way, first, the diagonal of matrix `B` is compressed in a dense vector `B2`. Then, the computation uses the dense vector `B2` to perform the multiplication.

#### Selecting Outputs

If there are multiple lines of STUR code, but you only want to generate computation code for some of them, you can provide the list of comma separated `outputs` on top of the STUR file. For example:

```
symbols: N
outputs: B, C
A(i, j) := f(i) * f(j)
B(i, j) := A(j, i)
C(j) := B(i, j)
A:D(i, j) := (0 <= i < N) * (0 <= j < N)
B:D(j, i) := (0 <= j < N) * (0 <= i < N)
f:D(i) := (0 <= i < N)
C:D(j) := (0 <= j < N)
```

This will generate the computation code only for tensors `B` and `C` while leveraging the symmetric structure of `A` in their computations.

This will also activate *selective inlining* rather than aggressive inlining. This means that the code generated for `C` will use tensor `B` directly for projection rather than recomputing everything from the inlined version. The generated computation code will look like the following:

```c++
for (int i = 0; i < N; ++i) {
  for (int j = 0; j < min({(i) + 1, N}); ++j) {
    B[i][j] = (f[j] * f[i]);
  }
}
for (int j = 0; j < N; ++j) {
  for (int i = max({j, 0}); i < N; ++i) {
    C[j] = B[i][j];
  }
}
for (int j = 0; j < N; ++j) {
  for (int i = 0; i < min({j, N, (j) + 1}); ++i) {
    C[j] += B[j][i];
  }
}
```

#### Variable Ordering

You can provide arbitrary variable ordering and include extra non-symbol and unbound variables through a `;` separated mapping named `iters` by providing the mapping from the left-hand side tensor names to a comma separated list of variables. For example:

```
symbols: N, M, ITERS
iters: covar -> iter, i, j, k
covar(j, k) := X(i, j) * X(i, k) * (0 <= iter < ITERS)
covar:D(i, j) := (0 <= i < N) * (0 <= j < N)
X:D(i, j) := (0 <= i < M) * (0 <= j < N)
```

This will generate the following code:

```c++
for (int iter = 0; iter < ITERS; ++iter) {
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < min({(j) + 1, N}); ++k) {
        covar[j][k] += (X[i][k] * X[i][j]);
      }
    }
  }
}
```

### Generating C++ Code

To generate code for one of the existing `.stur` codes in the `examples/` directory, use the following command:

```
$ sbt
sbt:struct-tensor> clean
sbt:struct-tensor> compile
sbt:struct-tensor> run -i examples/<name>.stur -o <path/to/output.cpp>
```

This will read the file provided after `-i`, generate a C++ code for the kernel named `<name>.stur`, and write the output to the address provided after the `-o` flag. The code will be in a void function named `fn` and can be copied and used in an existing C++ code base.

To allocate and initiate the tensors and generate a runnable file, use the following command:

```
$ sbt 
sbt:struct-tensor> clean
sbt:struct-tensor> compile
sbt:struct-tensor> run -i examples/<name>.stur -o <path/to/output.cpp> --init-tensors
```

This way, a C++ code with a `main` function containing tensor allocation, random initiation, and the computation will be created. The generated code can be compiled using:

```
clang++ <path/to/output.cpp>  -std=c++17  -O3  -ffast-math  -march=native  -mtune=native  -ftree-vectorize  -o  <path/to/output>
```

### Command line options

All command line options can be obtained by using the command `sbt run --help`. The output can be seen as follows:

```
struct-tensor 0.1
Usage: sturct-tensor [options]

  --help              prints this usage text
  -l, --lang <lang>   select the target language for the generated code
  -i, --inf <path>    path to the stur input file
  -o, --outf <path>   where to stored the generated code
  --init-tensors      initialize the tensors randomly in the generated code
  --only-computation  generate only the computation code (no reconstruction code)
```

## Citing StructTensor

To cite StructTensor's paper, use the following BibTex:

```
@article{structtensor2023,
  author       = {Mahdi Ghorbani and
                  Mathieu Huot and
                  Shideh Hashemian and
                  Amir Shaikhha},
  title        = {Compiling Structured Tensor Algebra},
  journal      = {Proc. {ACM} Program. Lang.},
  volume       = {7},
  number       = {{OOPSLA2}},
  pages        = {204--233},
  year         = {2023},
  url          = {https://doi.org/10.1145/3622804},
  doi          = {10.1145/3622804},
  timestamp    = {Sun, 10 Dec 2023 17:01:16 +0100},
  biburl       = {https://dblp.org/rec/journals/pacmpl/GhorbaniHHS23.bib},
  bibsource    = {dblp computer science bibliography, https://dblp.org}
}
```
