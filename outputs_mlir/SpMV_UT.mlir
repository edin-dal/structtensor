
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


%A = memref.alloc(%M) : memref<?xf64>

    "scf.for"(%0, %M, %1) ({
    ^bb0(%i: index):

%orFlag1 = "arith.constant"() {value = 0 : i1} : () -> i1
%andFlag2 = "arith.constant"() {value = 1 : i1} : () -> i1


    "scf.if"(%orFlag1) ({
      %rval3 = "func.call"() {callee = @rand} : () -> i32
      %rval4 = "arith.remui"(%rval3, %1000000) : (i32, i32) -> i32
      %rval5 = "arith.sitofp"(%rval4) : (i32) -> f64
      %rval6 = "arith.divf"(%rval5, %f1000000) : (f64, f64) -> f64
      "memref.store"(%rval6, %A, %i): (f64, memref<?xf64>, index) -> ()
      "scf.yield"() : () -> ()
    }, {
      "memref.store"(%zerof, %A, %i): (f64, memref<?xf64>, index) -> ()
      "scf.yield"() : () -> ()
    }) : (i1) -> ()


    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()



%B = memref.alloc(%M, %N) : memref<?x?xf64>

    "scf.for"(%0, %M, %1) ({
    ^bb0(%i: index):

    "scf.for"(%0, %N, %1) ({
    ^bb0(%j: index):

%orFlag7 = "arith.constant"() {value = 0 : i1} : () -> i1
%andFlag8 = "arith.constant"() {value = 1 : i1} : () -> i1


%consti11 = "arith.constant"() {value = 0 : index} : () -> index
%cmpFlag10 = "arith.cmpi"(%consti11, %i) {predicate = 3 : i64} : (index, index) -> i1
%andFlag9 = "arith.andi"(%andFlag8, %cmpFlag10) : (i1, i1) -> i1


%cmpFlag13 = "arith.cmpi"(%M, %i) {predicate = 4 : i64} : (index, index) -> i1
%andFlag12 = "arith.andi"(%andFlag9, %cmpFlag13) : (i1, i1) -> i1

%consti16 = "arith.constant"() {value = 0 : index} : () -> index
%cmpFlag15 = "arith.cmpi"(%consti16, %j) {predicate = 3 : i64} : (index, index) -> i1
%andFlag14 = "arith.andi"(%andFlag12, %cmpFlag15) : (i1, i1) -> i1


%cmpFlag18 = "arith.cmpi"(%N, %j) {predicate = 4 : i64} : (index, index) -> i1
%andFlag17 = "arith.andi"(%andFlag14, %cmpFlag18) : (i1, i1) -> i1


%cmpFlag20 = "arith.cmpi"(%i, %j) {predicate = 3 : i64} : (index, index) -> i1
%andFlag19 = "arith.andi"(%andFlag17, %cmpFlag20) : (i1, i1) -> i1

%orFlag21 = "arith.ori"(%orFlag7, %andFlag19) : (i1, i1) -> i1


    "scf.if"(%orFlag21) ({
      %rval22 = "func.call"() {callee = @rand} : () -> i32
      %rval23 = "arith.remui"(%rval22, %1000000) : (i32, i32) -> i32
      %rval24 = "arith.sitofp"(%rval23) : (i32) -> f64
      %rval25 = "arith.divf"(%rval24, %f1000000) : (f64, f64) -> f64
      "memref.store"(%rval25, %B, %i, %j): (f64, memref<?x?xf64>, index, index) -> ()
      "scf.yield"() : () -> ()
    }, {
      "memref.store"(%zerof, %B, %i, %j): (f64, memref<?x?xf64>, index, index) -> ()
      "scf.yield"() : () -> ()
    }) : (i1) -> ()


    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()


%C = memref.alloc(%N) : memref<?xf64>

    "scf.for"(%0, %N, %1) ({
    ^bb0(%j: index):

%orFlag26 = "arith.constant"() {value = 0 : i1} : () -> i1
%andFlag27 = "arith.constant"() {value = 1 : i1} : () -> i1


%consti30 = "arith.constant"() {value = 0 : index} : () -> index
%cmpFlag29 = "arith.cmpi"(%consti30, %j) {predicate = 3 : i64} : (index, index) -> i1
%andFlag28 = "arith.andi"(%andFlag27, %cmpFlag29) : (i1, i1) -> i1


%cmpFlag32 = "arith.cmpi"(%N, %j) {predicate = 4 : i64} : (index, index) -> i1
%andFlag31 = "arith.andi"(%andFlag28, %cmpFlag32) : (i1, i1) -> i1

%orFlag33 = "arith.ori"(%orFlag26, %andFlag31) : (i1, i1) -> i1


    "scf.if"(%orFlag33) ({
      %rval34 = "func.call"() {callee = @rand} : () -> i32
      %rval35 = "arith.remui"(%rval34, %1000000) : (i32, i32) -> i32
      %rval36 = "arith.sitofp"(%rval35) : (i32) -> f64
      %rval37 = "arith.divf"(%rval36, %f1000000) : (f64, f64) -> f64
      "memref.store"(%rval37, %C, %j): (f64, memref<?xf64>, index) -> ()
      "scf.yield"() : () -> ()
    }, {
      "memref.store"(%zerof, %C, %j): (f64, memref<?xf64>, index) -> ()
      "scf.yield"() : () -> ()
    }) : (i1) -> ()


    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()


affine.for %i = affine_map<()[] -> (0)> () [] to affine_map<()[M, N] -> (min(M, N))> () [%M, %N] step 1 {
  affine.for %j = affine_map<(i)[] -> (i)> (%i) [] to affine_map<()[N] -> (N)> () [%N] step 1 {
    %A_0 = affine.load %B[%i, %j] : memref<?x?xf64>
    %A_1 = affine.load %C[%j] : memref<?xf64>
    %A_2 = arith.mulf %A_0, %A_1 : f64
    affine.store %A_2, %A[%i] : memref<?xf64>
  }
}



  %last = "memref.load"(%A, %0) : (memref<?xf64>, index) -> f64
  "func.call"(%last) {callee = @print_f64_cerr} : (f64) -> ()
  

  %last = "memref.load"(%B, %0, %0) : (memref<?x?xf64>, index, index) -> f64
  "func.call"(%last) {callee = @print_f64_cerr} : (f64) -> ()
  

  %last = "memref.load"(%C, %0) : (memref<?xf64>, index) -> f64
  "func.call"(%last) {callee = @print_f64_cerr} : (f64) -> ()
  

  %last = "memref.load"(%B, %0, %0) : (memref<?x?xf64>, index, index) -> f64
  "func.call"(%last) {callee = @print_f64_cerr} : (f64) -> ()
  



"func.return"() : () -> ()
    })  {function_type = (i32, !llvm.ptr<!llvm.ptr<i8>>) -> (), sym_name = "main", sym_visibility = "private"} : () -> ()
}) : () -> ()
