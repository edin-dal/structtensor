
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
    %const_val_0 = "arith.constant"() {"value" = 0 : index} : () -> index
    %zi32 = "arith.constant"() {"value" = 0 : i32} : () -> i32
    %zerof = "arith.constant"() {"value" = 0.0 : f64} : () -> f64
    %const_val_1 = "arith.constant"() {"value" = 1 : index} : () -> index
    %oi1 = "arith.constant"() {"value" = 1 : i1} : () -> i1
    %oi0 = "arith.constant"() {"value" = 0 : i1} : () -> i1
    "func.call"(%zi32) {callee = @srand} : (i32) -> ()
    %1000000 = "arith.constant"() {"value" = 1000000 : i32} : () -> i32
    %f1000000 = "arith.constant"() {"value" = 1000000.0 : f64} : () -> f64


    %argvv1 = llvm.getelementptr %argv[1] : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<!llvm.ptr<i8>>
    %argv1 = "llvm.load"(%argvv1) : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<i8>
    %Ni32 = "func.call"(%argv1) {callee = @atoi} : (!llvm.ptr<i8>) -> i32
    %N = arith.index_cast %Ni32 : i32 to index

    %argvv2 = llvm.getelementptr %argv[2] : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<!llvm.ptr<i8>>
    %argv2 = "llvm.load"(%argvv2) : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<i8>
    %Ji32 = "func.call"(%argv2) {callee = @atoi} : (!llvm.ptr<i8>) -> i32
    %J = arith.index_cast %Ji32 : i32 to index

    %argvv3 = llvm.getelementptr %argv[3] : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<!llvm.ptr<i8>>
    %argv3 = "llvm.load"(%argvv3) : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<i8>
    %Mi32 = "func.call"(%argv3) {callee = @atoi} : (!llvm.ptr<i8>) -> i32
    %M = arith.index_cast %Mi32 : i32 to index

    %argvv4 = llvm.getelementptr %argv[4] : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<!llvm.ptr<i8>>
    %argv4 = "llvm.load"(%argvv4) : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<i8>
    %Pi32 = "func.call"(%argv4) {callee = @atoi} : (!llvm.ptr<i8>) -> i32
    %P = arith.index_cast %Pi32 : i32 to index




%A = memref.alloc(%M, %N, %P) : memref<?x?x?xf64>

    "scf.for"(%const_val_0, %M, %const_val_1) ({
    ^bb0(%i: index):

    "scf.for"(%const_val_0, %N, %const_val_1) ({
    ^bb0(%j: index):

    "scf.for"(%const_val_0, %P, %const_val_1) ({
    ^bb0(%k: index):

%orFlag1 = "arith.constant"() {value = 0 : i1} : () -> i1
%andFlag2 = "arith.constant"() {value = 1 : i1} : () -> i1


    "scf.if"(%orFlag1) ({
      %rval3 = "func.call"() {callee = @rand} : () -> i32
      %rval4 = "arith.remui"(%rval3, %1000000) : (i32, i32) -> i32
      %rval5 = "arith.sitofp"(%rval4) : (i32) -> f64
      %rval6 = "arith.divf"(%rval5, %f1000000) : (f64, f64) -> f64
      "memref.store"(%rval6, %A, %i, %j, %k): (f64, memref<?x?x?xf64>, index, index, index) -> ()
      "scf.yield"() : () -> ()
    }, {
      "memref.store"(%zerof, %A, %i, %j, %k): (f64, memref<?x?x?xf64>, index, index, index) -> ()
      "scf.yield"() : () -> ()
    }) : (i1) -> ()


    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()




%B = memref.alloc(%M, %N, %P) : memref<?x?x?xf64>

    "scf.for"(%const_val_0, %M, %const_val_1) ({
    ^bb0(%i: index):

    "scf.for"(%const_val_0, %N, %const_val_1) ({
    ^bb0(%j: index):

    "scf.for"(%const_val_0, %P, %const_val_1) ({
    ^bb0(%k: index):

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

%consti21 = "arith.constant"() {value = 0 : index} : () -> index
%cmpFlag20 = "arith.cmpi"(%consti21, %k) {predicate = 3 : i64} : (index, index) -> i1
%andFlag19 = "arith.andi"(%andFlag17, %cmpFlag20) : (i1, i1) -> i1


%cmpFlag23 = "arith.cmpi"(%P, %k) {predicate = 4 : i64} : (index, index) -> i1
%andFlag22 = "arith.andi"(%andFlag19, %cmpFlag23) : (i1, i1) -> i1


%cmpFlag25 = "arith.cmpi"(%j, %J) {predicate = 0 : i64} : (index, index) -> i1
%andFlag24 = "arith.andi"(%andFlag22, %cmpFlag25) : (i1, i1) -> i1

%orFlag26 = "arith.ori"(%orFlag7, %andFlag24) : (i1, i1) -> i1


    "scf.if"(%orFlag26) ({
      %rval27 = "func.call"() {callee = @rand} : () -> i32
      %rval28 = "arith.remui"(%rval27, %1000000) : (i32, i32) -> i32
      %rval29 = "arith.sitofp"(%rval28) : (i32) -> f64
      %rval30 = "arith.divf"(%rval29, %f1000000) : (f64, f64) -> f64
      "memref.store"(%rval30, %B, %i, %j, %k): (f64, memref<?x?x?xf64>, index, index, index) -> ()
      "scf.yield"() : () -> ()
    }, {
      "memref.store"(%zerof, %B, %i, %j, %k): (f64, memref<?x?x?xf64>, index, index, index) -> ()
      "scf.yield"() : () -> ()
    }) : (i1) -> ()


    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()




%C = memref.alloc(%M, %N, %P) : memref<?x?x?xf64>

    "scf.for"(%const_val_0, %M, %const_val_1) ({
    ^bb0(%i: index):

    "scf.for"(%const_val_0, %N, %const_val_1) ({
    ^bb0(%j: index):

    "scf.for"(%const_val_0, %P, %const_val_1) ({
    ^bb0(%k: index):

%orFlag31 = "arith.constant"() {value = 0 : i1} : () -> i1
%andFlag32 = "arith.constant"() {value = 1 : i1} : () -> i1


%consti35 = "arith.constant"() {value = 0 : index} : () -> index
%cmpFlag34 = "arith.cmpi"(%consti35, %i) {predicate = 3 : i64} : (index, index) -> i1
%andFlag33 = "arith.andi"(%andFlag32, %cmpFlag34) : (i1, i1) -> i1


%cmpFlag37 = "arith.cmpi"(%M, %i) {predicate = 4 : i64} : (index, index) -> i1
%andFlag36 = "arith.andi"(%andFlag33, %cmpFlag37) : (i1, i1) -> i1

%consti40 = "arith.constant"() {value = 0 : index} : () -> index
%cmpFlag39 = "arith.cmpi"(%consti40, %j) {predicate = 3 : i64} : (index, index) -> i1
%andFlag38 = "arith.andi"(%andFlag36, %cmpFlag39) : (i1, i1) -> i1


%cmpFlag42 = "arith.cmpi"(%N, %j) {predicate = 4 : i64} : (index, index) -> i1
%andFlag41 = "arith.andi"(%andFlag38, %cmpFlag42) : (i1, i1) -> i1

%consti45 = "arith.constant"() {value = 0 : index} : () -> index
%cmpFlag44 = "arith.cmpi"(%consti45, %k) {predicate = 3 : i64} : (index, index) -> i1
%andFlag43 = "arith.andi"(%andFlag41, %cmpFlag44) : (i1, i1) -> i1


%cmpFlag47 = "arith.cmpi"(%P, %k) {predicate = 4 : i64} : (index, index) -> i1
%andFlag46 = "arith.andi"(%andFlag43, %cmpFlag47) : (i1, i1) -> i1

%orFlag48 = "arith.ori"(%orFlag31, %andFlag46) : (i1, i1) -> i1


    "scf.if"(%orFlag48) ({
      %rval49 = "func.call"() {callee = @rand} : () -> i32
      %rval50 = "arith.remui"(%rval49, %1000000) : (i32, i32) -> i32
      %rval51 = "arith.sitofp"(%rval50) : (i32) -> f64
      %rval52 = "arith.divf"(%rval51, %f1000000) : (f64, f64) -> f64
      "memref.store"(%rval52, %C, %i, %j, %k): (f64, memref<?x?x?xf64>, index, index, index) -> ()
      "scf.yield"() : () -> ()
    }, {
      "memref.store"(%zerof, %C, %i, %j, %k): (f64, memref<?x?x?xf64>, index, index, index) -> ()
      "scf.yield"() : () -> ()
    }) : (i1) -> ()


    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()


    %stime = "func.call"() {callee = @timer} : () -> i64

%0 = arith.constant 0 : index
"affine.for"(%M) ({
^0(%i : index):
  "affine.for"(%N) ({
  ^1(%j : index):
    "affine.for"(%P) ({
    ^2(%k : index):
      %1 = "affine.load"(%B, %k, %j, %i) {"map" = affine_map<(d0, d1, d2) -> (d2, d1, d0)>} : (memref<?x?x?xf64>, index, index, index) -> f64
      %2 = "affine.load"(%C, %k, %j, %i) {"map" = affine_map<(d0, d1, d2) -> (d2, d1, d0)>} : (memref<?x?x?xf64>, index, index, index) -> f64
      %3 = arith.mulf %1, %2 : f64
      "affine.store"(%3, %A, %k, %j, %i) {"map" = affine_map<(d0, d1, d2) -> (d2, d1, d0)>} : (f64, memref<?x?x?xf64>, index, index, index) -> ()
      "affine.yield"() : () -> ()
    }) {"lower_bound" = affine_map<() -> (0)>, "upper_bound" = affine_map<()[s0] -> (s0)>, "step" = 1 : index} : (index) -> ()
    "affine.yield"() : () -> ()
  }) {"lower_bound" = affine_map<() -> (0)>, "upper_bound" = affine_map<()[s0] -> (s0)>, "step" = 1 : index} : (index) -> ()
  "affine.yield"() : () -> ()
}) {"lower_bound" = affine_map<() -> (0)>, "upper_bound" = affine_map<()[s0] -> (s0)>, "step" = 1 : index} : (index) -> ()

%time = "func.call"(%stime) {callee = @timer_elapsed} : (i64) -> i64
"func.call"(%time) {callee = @print_i64} : (i64) -> ()

%last53 = "memref.load"(%A, %const_val_0, %const_val_0, %const_val_0) : (memref<?x?x?xf64>, index, index, index) -> f64
"func.call"(%last53) {callee = @print_f64_cerr} : (f64) -> ()


%last54 = "memref.load"(%B, %const_val_0, %const_val_0, %const_val_0) : (memref<?x?x?xf64>, index, index, index) -> f64
"func.call"(%last54) {callee = @print_f64_cerr} : (f64) -> ()


%last55 = "memref.load"(%C, %const_val_0, %const_val_0, %const_val_0) : (memref<?x?x?xf64>, index, index, index) -> f64
"func.call"(%last55) {callee = @print_f64_cerr} : (f64) -> ()


%last56 = "memref.load"(%B, %const_val_0, %const_val_0, %const_val_0) : (memref<?x?x?xf64>, index, index, index) -> f64
"func.call"(%last56) {callee = @print_f64_cerr} : (f64) -> ()




"func.return"() : () -> ()
    })  {function_type = (i32, !llvm.ptr<!llvm.ptr<i8>>) -> (), sym_name = "main", sym_visibility = "private"} : () -> ()
}) : () -> ()
