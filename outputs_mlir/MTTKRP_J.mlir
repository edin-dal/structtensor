
"builtin.module"() ({
  "func.func"() ({}) {function_type = (!llvm.ptr<i8>) -> i32, sym_name = "puts", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = (!llvm.ptr<i8>) -> i32, sym_name = "atoi", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = (i32) -> (), sym_name = "srand", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = () -> (i32), sym_name = "rand", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = (i32) -> (), sym_name = "print_i32", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = (i64) -> (), sym_name = "print_i64", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = (f64) -> (), sym_name = "print_f64_cerr", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = () -> (i64), sym_name = "timer", sym_visibility = "private"} : () -> ()
  "func.func"() ({}) {function_type = (i64) -> (i64), sym_name = "timer_elapsed", sym_visibility = "private"} : () -> ()

  "func.func"() ({
    ^bb0(%argc : i32, %argv : !llvm.ptr<!llvm.ptr<i8>>):
    %0 = "arith.constant"() {"value" = 0 : index} : () -> index
    %zi32 = "arith.constant"() {"value" = 0 : i32} : () -> i32
    %zerof = "arith.constant"() {"value" = 0.0 : f64} : () -> f64
    %1 = "arith.constant"() {"value" = 1 : index} : () -> index
    %oi1 = "arith.constant"() {"value" = 1 : i1} : () -> i1
    %oi0 = "arith.constant"() {"value" = 0 : i1} : () -> i1
    "func.call"(%zi32) {callee = @srand} : (i32) -> ()
    %1000000 = "arith.constant"() {"value" = 1000000 : i32} : () -> i32
    %f1000000 = "arith.constant"() {"value" = 1000000.0 : f64} : () -> f64


    %argvv1 = llvm.getelementptr %argv[1] : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<!llvm.ptr<i8>>
    %argv1 = "llvm.load"(%argvv1) : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<i8>
    %Mi32 = "func.call"(%argv1) {callee = @atoi} : (!llvm.ptr<i8>) -> i32
    %M = arith.index_cast %Mi32 : i32 to index

    %argvv2 = llvm.getelementptr %argv[2] : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<!llvm.ptr<i8>>
    %argv2 = "llvm.load"(%argvv2) : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<i8>
    %Ni32 = "func.call"(%argv2) {callee = @atoi} : (!llvm.ptr<i8>) -> i32
    %N = arith.index_cast %Ni32 : i32 to index

    %argvv3 = llvm.getelementptr %argv[3] : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<!llvm.ptr<i8>>
    %argv3 = "llvm.load"(%argvv3) : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<i8>
    %Pi32 = "func.call"(%argv3) {callee = @atoi} : (!llvm.ptr<i8>) -> i32
    %P = arith.index_cast %Pi32 : i32 to index

    %argvv4 = llvm.getelementptr %argv[4] : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<!llvm.ptr<i8>>
    %argv4 = "llvm.load"(%argvv4) : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<i8>
    %Qi32 = "func.call"(%argv4) {callee = @atoi} : (!llvm.ptr<i8>) -> i32
    %Q = arith.index_cast %Qi32 : i32 to index

    %argvv5 = llvm.getelementptr %argv[5] : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<!llvm.ptr<i8>>
    %argv5 = "llvm.load"(%argvv5) : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<i8>
    %Ji32 = "func.call"(%argv5) {callee = @atoi} : (!llvm.ptr<i8>) -> i32
    %J = arith.index_cast %Ji32 : i32 to index


    %A = memref.alloc(%M, %Q) : memref<?x?xf64>
    %B = memref.alloc(%M, %N, %P) : memref<?x?x?xf64>
    %C = memref.alloc(%N, %Q) : memref<?x?xf64>
    %D = memref.alloc(%P, %Q) : memref<?x?xf64>


    "scf.for"(%0, %M, %1) ({
    ^bb0(%i1: index):

    "scf.for"(%0, %N, %1) ({
    ^bb0(%i2: index):

    "scf.for"(%0, %P, %1) ({
    ^bb0(%i3: index):

    "scf.if"(%oi1) ({
      %rval4 = "func.call"() {callee = @rand} : () -> i32
      %rval5 = "arith.remui"(%rval4, %1000000) : (i32, i32) -> i32
      %rval6 = "arith.sitofp"(%rval5) : (i32) -> f64
      %rval7 = "arith.divf"(%rval6, %f1000000) : (f64, f64) -> f64
      "memref.store"(%rval7, %B, %i1, %i2, %i3): (f64, memref<?x?x?xf64>, index, index, index) -> ()
      "scf.yield"() : () -> ()
    }, {
      "memref.store"(%zerof, %B, %i1, %i2, %i3): (f64, memref<?x?x?xf64>, index, index, index) -> ()
      "scf.yield"() : () -> ()
    }) : (i1) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()


    "scf.for"(%0, %N, %1) ({
    ^bb0(%i8: index):

    "scf.for"(%0, %Q, %1) ({
    ^bb0(%i9: index):

    "scf.if"(%oi1) ({
      %rval10 = "func.call"() {callee = @rand} : () -> i32
      %rval11 = "arith.remui"(%rval10, %1000000) : (i32, i32) -> i32
      %rval12 = "arith.sitofp"(%rval11) : (i32) -> f64
      %rval13 = "arith.divf"(%rval12, %f1000000) : (f64, f64) -> f64
      "memref.store"(%rval13, %C, %i8, %i9): (f64, memref<?x?xf64>, index, index) -> ()
      "scf.yield"() : () -> ()
    }, {
      "memref.store"(%zerof, %C, %i8, %i9): (f64, memref<?x?xf64>, index, index) -> ()
      "scf.yield"() : () -> ()
    }) : (i1) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()


    "scf.for"(%0, %P, %1) ({
    ^bb0(%i15: index):

    "scf.for"(%0, %Q, %1) ({
    ^bb0(%i16: index):

    %gen_cond14 = "arith.cmpi"(%i16, %J) {predicate = 0 : i64} : (index, index) -> i1   

    "scf.if"(%gen_cond14) ({
      %rval17 = "func.call"() {callee = @rand} : () -> i32
      %rval18 = "arith.remui"(%rval17, %1000000) : (i32, i32) -> i32
      %rval19 = "arith.sitofp"(%rval18) : (i32) -> f64
      %rval20 = "arith.divf"(%rval19, %f1000000) : (f64, f64) -> f64
      "memref.store"(%rval20, %D, %i15, %i16): (f64, memref<?x?xf64>, index, index) -> ()
      "scf.yield"() : () -> ()
    }, {
      "memref.store"(%zerof, %D, %i15, %i16): (f64, memref<?x?xf64>, index, index) -> ()
      "scf.yield"() : () -> ()
    }) : (i1) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()


    "scf.for"(%0, %M, %1) ({
    ^bb0(%i21: index):

    "scf.for"(%0, %Q, %1) ({
    ^bb0(%i22: index):

    "scf.if"(%oi0) ({
      %rval23 = "func.call"() {callee = @rand} : () -> i32
      %rval24 = "arith.remui"(%rval23, %1000000) : (i32, i32) -> i32
      %rval25 = "arith.sitofp"(%rval24) : (i32) -> f64
      %rval26 = "arith.divf"(%rval25, %f1000000) : (f64, f64) -> f64
      "memref.store"(%rval26, %A, %i21, %i22): (f64, memref<?x?xf64>, index, index) -> ()
      "scf.yield"() : () -> ()
    }, {
      "memref.store"(%zerof, %A, %i21, %i22): (f64, memref<?x?xf64>, index, index) -> ()
      "scf.yield"() : () -> ()
    }) : (i1) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()


    %stime = "func.call"() {callee = @timer} : () -> i64

affine.if affine_set<()[Q, J] : (Q >= J + 1)> () [%Q, %J] {
  affine.for %i = affine_map<()[] -> (0)> () [] to affine_map<()[M] -> (M)> () [%M] step 1 {
    affine.for %j = affine_map<()[] -> (0)> () [] to affine_map<()[N] -> (N)> () [%N] step 1 {
      affine.for %k = affine_map<()[] -> (0)> () [] to affine_map<()[P] -> (P)> () [%P] step 1 {
        %A_0 = affine.load %C[%j, symbol(%J)] : memref<?x?xf64>
        %A_1 = affine.load %B[%i, %j, %k] : memref<?x?x?xf64>
        %A_2 = affine.load %D[%k, symbol(%J)] : memref<?x?xf64>
        %A_3 = arith.mulf %A_0, %A_1 : f64
        %A_4 = arith.mulf %A_3, %A_2 : f64
        affine.store %A_4, %A[%i, symbol(%J)] : memref<?x?xf64>
      }
    }
  }
}


    %time = "func.call"(%stime) {callee = @timer_elapsed} : (i64) -> i64
    
    %last = "memref.load"(%A, %0, %0) : (memref<?x?xf64>, index, index) -> f64

    "func.call"(%last) {callee = @print_f64_cerr} : (f64) -> ()
    "func.call"(%time) {callee = @print_i64} : (i64) -> ()
    
    "func.return"() : () -> ()
    })  {function_type = (i32, !llvm.ptr<!llvm.ptr<i8>>) -> (), sym_name = "main", sym_visibility = "private"} : () -> ()
}) : () -> ()
