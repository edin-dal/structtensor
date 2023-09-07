cd ../outputs

structtensor_names=("TTM_DP" "TTM_J" "THP_DP" "THP_I" "THP_J" "MTTKRP_IJ" "MTTKRP_I" "MTTKRP_J")

for name in ${structtensor_names[@]}
do
  echo Compiling $name.cpp
  clang -lstdc++ $name.cpp -std=c++17 -O3 -ffast-math -march=native -ftree-vectorize -Rpass=loop-vectorize -o $name
  echo Compiling ${name}_Sparse.cpp
  clang -lstdc++ ${name}_Sparse.cpp -std=c++17 -O3 -ffast-math -march=native -ftree-vectorize -Rpass=loop-vectorize -o ${name}_Sparse
done

cd ../outputs_mlir
pipeline="builtin.module(canonicalize, cse, affine-expand-index-ops, lower-affine, finalize-memref-to-llvm, canonicalize, cse, loop-invariant-code-motion, convert-arith-to-llvm, convert-scf-to-cf, convert-func-to-llvm, convert-cf-to-llvm, reconcile-unrealized-casts)"
#pipeline="builtin.module(canonicalize,cse,func.func(affine-loop-invariant-code-motion,affine-parallelize,affine-simplify-structures,canonicalize,cse,affine-super-vectorize{virtual-vector-size=8 vectorize-reductions}),lower-affine,scf-parallel-loop-tiling,lower-affine,loop-invariant-code-motion,cse,canonicalize,convert-vector-to-llvm{reassociate-fp-reductions enable-x86vector},cse,canonicalize,finalize-memref-to-llvm,loop-invariant-code-motion,cse,canonicalize,convert-vector-to-scf{full-unroll},lower-affine,loop-invariant-code-motion,cse,canonicalize,convert-vector-to-llvm,finalize-memref-to-llvm,loop-invariant-code-motion,cse,canonicalize,convert-arith-to-llvm,cse,canonicalize,convert-scf-to-cf,canonicalize,cse,convert-func-to-llvm,convert-cf-to-llvm,cse,canonicalize)"
echo Using pipeline \"$pipeline\"
for name in ${structtensor_names[@]}
do
  echo Compiling $name.mlir
  mlir-opt $name.mlir -p="$pipeline" | mlir-translate --mlir-to-llvmir | clang -O3 utils.o -march=native -ftree-vectorize -x ir - -Rpass=loop-vectorize -ffast-math -o $name
  mlir-opt $name.mlir -p="$pipeline" | mlir-translate --mlir-to-llvmir | clang -O3 -mllvm -polly -mllvm -polly-vectorizer=stripmine utils.o -march=native -ftree-vectorize -x ir - -Rpass=loop-vectorize -ffast-math -o ${name}_polly
done
