
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
    %Qi32 = "func.call"(%argv4) {callee = @atoi} : (!llvm.ptr<i8>) -> i32
    %Q = arith.index_cast %Qi32 : i32 to index

    %argvv5 = llvm.getelementptr %argv[5] : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<!llvm.ptr<i8>>
    %argv5 = "llvm.load"(%argvv5) : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<i8>
    %Pi32 = "func.call"(%argv5) {callee = @atoi} : (!llvm.ptr<i8>) -> i32
    %P = arith.index_cast %Pi32 : i32 to index



%A = memref.alloc(%M, %Q) : memref<?x?xf64>

    "scf.for"(%const_val_0, %M, %const_val_1) ({
    ^bb0(%i: index):

    "scf.for"(%const_val_0, %Q, %const_val_1) ({
    ^bb0(%j: index):

%orFlag2 = "arith.constant"() {value = 0 : i1} : () -> i1
%andFlag3 = "arith.constant"() {value = 1 : i1} : () -> i1


    "scf.if"(%orFlag2) ({
      %rval4 = "func.call"() {callee = @rand} : () -> i32
      %rval5 = "arith.remui"(%rval4, %1000000) : (i32, i32) -> i32
      %rval6 = "arith.sitofp"(%rval5) : (i32) -> f64
      %rval7 = "arith.divf"(%rval6, %f1000000) : (f64, f64) -> f64
      "memref.store"(%rval7, %A, %i, %j): (f64, memref<?x?xf64>, index, index) -> ()
      "scf.yield"() : () -> ()
    }, {
      "memref.store"(%zerof, %A, %i, %j): (f64, memref<?x?xf64>, index, index) -> ()
      "scf.yield"() : () -> ()
    }) : (i1) -> ()


    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()




%B = memref.alloc(%M, %N, %P) : memref<?x?x?xf64>

    "scf.for"(%const_val_0, %M, %const_val_1) ({
    ^bb0(%i: index):

    "scf.for"(%const_val_0, %N, %const_val_1) ({
    ^bb0(%k: index):

    "scf.for"(%const_val_0, %P, %const_val_1) ({
    ^bb0(%l: index):

%orFlag8 = "arith.constant"() {value = 0 : i1} : () -> i1
%andFlag9 = "arith.constant"() {value = 1 : i1} : () -> i1


%consti12 = "arith.constant"() {value = 0 : index} : () -> index
%cmpFlag11 = "arith.cmpi"(%consti12, %i) {predicate = 3 : i64} : (index, index) -> i1
%andFlag10 = "arith.andi"(%andFlag9, %cmpFlag11) : (i1, i1) -> i1


%cmpFlag14 = "arith.cmpi"(%M, %i) {predicate = 4 : i64} : (index, index) -> i1
%andFlag13 = "arith.andi"(%andFlag10, %cmpFlag14) : (i1, i1) -> i1

%consti17 = "arith.constant"() {value = 0 : index} : () -> index
%cmpFlag16 = "arith.cmpi"(%consti17, %k) {predicate = 3 : i64} : (index, index) -> i1
%andFlag15 = "arith.andi"(%andFlag13, %cmpFlag16) : (i1, i1) -> i1


%cmpFlag19 = "arith.cmpi"(%N, %k) {predicate = 4 : i64} : (index, index) -> i1
%andFlag18 = "arith.andi"(%andFlag15, %cmpFlag19) : (i1, i1) -> i1

%consti22 = "arith.constant"() {value = 0 : index} : () -> index
%cmpFlag21 = "arith.cmpi"(%consti22, %l) {predicate = 3 : i64} : (index, index) -> i1
%andFlag20 = "arith.andi"(%andFlag18, %cmpFlag21) : (i1, i1) -> i1


%cmpFlag24 = "arith.cmpi"(%P, %l) {predicate = 4 : i64} : (index, index) -> i1
%andFlag23 = "arith.andi"(%andFlag20, %cmpFlag24) : (i1, i1) -> i1

%orFlag25 = "arith.ori"(%orFlag8, %andFlag23) : (i1, i1) -> i1


    "scf.if"(%orFlag25) ({
      %rval26 = "func.call"() {callee = @rand} : () -> i32
      %rval27 = "arith.remui"(%rval26, %1000000) : (i32, i32) -> i32
      %rval28 = "arith.sitofp"(%rval27) : (i32) -> f64
      %rval29 = "arith.divf"(%rval28, %f1000000) : (f64, f64) -> f64
      "memref.store"(%rval29, %B, %i, %k, %l): (f64, memref<?x?x?xf64>, index, index, index) -> ()
      "scf.yield"() : () -> ()
    }, {
      "memref.store"(%zerof, %B, %i, %k, %l): (f64, memref<?x?x?xf64>, index, index, index) -> ()
      "scf.yield"() : () -> ()
    }) : (i1) -> ()


    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()



%C = memref.alloc(%N, %Q) : memref<?x?xf64>

    "scf.for"(%const_val_0, %N, %const_val_1) ({
    ^bb0(%k: index):

    "scf.for"(%const_val_0, %Q, %const_val_1) ({
    ^bb0(%j: index):

%orFlag30 = "arith.constant"() {value = 0 : i1} : () -> i1
%andFlag31 = "arith.constant"() {value = 1 : i1} : () -> i1


%consti34 = "arith.constant"() {value = 0 : index} : () -> index
%cmpFlag33 = "arith.cmpi"(%consti34, %k) {predicate = 3 : i64} : (index, index) -> i1
%andFlag32 = "arith.andi"(%andFlag31, %cmpFlag33) : (i1, i1) -> i1


%cmpFlag36 = "arith.cmpi"(%N, %k) {predicate = 4 : i64} : (index, index) -> i1
%andFlag35 = "arith.andi"(%andFlag32, %cmpFlag36) : (i1, i1) -> i1

%consti39 = "arith.constant"() {value = 0 : index} : () -> index
%cmpFlag38 = "arith.cmpi"(%consti39, %j) {predicate = 3 : i64} : (index, index) -> i1
%andFlag37 = "arith.andi"(%andFlag35, %cmpFlag38) : (i1, i1) -> i1


%cmpFlag41 = "arith.cmpi"(%Q, %j) {predicate = 4 : i64} : (index, index) -> i1
%andFlag40 = "arith.andi"(%andFlag37, %cmpFlag41) : (i1, i1) -> i1

%orFlag42 = "arith.ori"(%orFlag30, %andFlag40) : (i1, i1) -> i1


    "scf.if"(%orFlag42) ({
      %rval43 = "func.call"() {callee = @rand} : () -> i32
      %rval44 = "arith.remui"(%rval43, %1000000) : (i32, i32) -> i32
      %rval45 = "arith.sitofp"(%rval44) : (i32) -> f64
      %rval46 = "arith.divf"(%rval45, %f1000000) : (f64, f64) -> f64
      "memref.store"(%rval46, %C, %k, %j): (f64, memref<?x?xf64>, index, index) -> ()
      "scf.yield"() : () -> ()
    }, {
      "memref.store"(%zerof, %C, %k, %j): (f64, memref<?x?xf64>, index, index) -> ()
      "scf.yield"() : () -> ()
    }) : (i1) -> ()


    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()



%D = memref.alloc(%P, %Q) : memref<?x?xf64>

    "scf.for"(%const_val_0, %P, %const_val_1) ({
    ^bb0(%l: index):

    "scf.for"(%const_val_0, %Q, %const_val_1) ({
    ^bb0(%j: index):

%orFlag47 = "arith.constant"() {value = 0 : i1} : () -> i1
%andFlag48 = "arith.constant"() {value = 1 : i1} : () -> i1


%consti51 = "arith.constant"() {value = 0 : index} : () -> index
%cmpFlag50 = "arith.cmpi"(%consti51, %l) {predicate = 3 : i64} : (index, index) -> i1
%andFlag49 = "arith.andi"(%andFlag48, %cmpFlag50) : (i1, i1) -> i1


%cmpFlag53 = "arith.cmpi"(%P, %l) {predicate = 4 : i64} : (index, index) -> i1
%andFlag52 = "arith.andi"(%andFlag49, %cmpFlag53) : (i1, i1) -> i1

%consti56 = "arith.constant"() {value = 0 : index} : () -> index
%cmpFlag55 = "arith.cmpi"(%consti56, %j) {predicate = 3 : i64} : (index, index) -> i1
%andFlag54 = "arith.andi"(%andFlag52, %cmpFlag55) : (i1, i1) -> i1


%cmpFlag58 = "arith.cmpi"(%Q, %j) {predicate = 4 : i64} : (index, index) -> i1
%andFlag57 = "arith.andi"(%andFlag54, %cmpFlag58) : (i1, i1) -> i1


%cmpFlag60 = "arith.cmpi"(%j, %J) {predicate = 0 : i64} : (index, index) -> i1
%andFlag59 = "arith.andi"(%andFlag57, %cmpFlag60) : (i1, i1) -> i1

%orFlag61 = "arith.ori"(%orFlag47, %andFlag59) : (i1, i1) -> i1


    "scf.if"(%orFlag61) ({
      %rval62 = "func.call"() {callee = @rand} : () -> i32
      %rval63 = "arith.remui"(%rval62, %1000000) : (i32, i32) -> i32
      %rval64 = "arith.sitofp"(%rval63) : (i32) -> f64
      %rval65 = "arith.divf"(%rval64, %f1000000) : (f64, f64) -> f64
      "memref.store"(%rval65, %D, %l, %j): (f64, memref<?x?xf64>, index, index) -> ()
      "scf.yield"() : () -> ()
    }, {
      "memref.store"(%zerof, %D, %l, %j): (f64, memref<?x?xf64>, index, index) -> ()
      "scf.yield"() : () -> ()
    }) : (i1) -> ()


    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()


    %stime = "func.call"() {callee = @timer} : () -> i64

%0 = arith.constant 0 : index
"affine.for"(%M) ({
^0(%i : index):
  "affine.for"(%Q) ({
  ^1(%j : index):
    "affine.for"(%N) ({
    ^2(%k : index):
      "affine.for"(%P) ({
      ^3(%l : index):
        %1 = "affine.load"(%C, %j, %k) {"map" = affine_map<(d0, d1) -> (d1, d0)>} : (memref<?x?xf64>, index, index) -> f64
        %2 = "affine.load"(%B, %l, %k, %i) {"map" = affine_map<(d0, d1, d2) -> (d2, d1, d0)>} : (memref<?x?x?xf64>, index, index, index) -> f64
        %3 = "affine.load"(%D, %j, %l) {"map" = affine_map<(d0, d1) -> (d1, d0)>} : (memref<?x?xf64>, index, index) -> f64
        %4 = arith.mulf %1, %2 : f64
        %5 = arith.mulf %4, %3 : f64
        "affine.store"(%5, %A, %j, %i) {"map" = affine_map<(d0, d1) -> (d1, d0)>} : (f64, memref<?x?xf64>, index, index) -> ()
        "affine.yield"() : () -> ()
      }) {"lower_bound" = affine_map<() -> (0)>, "upper_bound" = affine_map<()[s0] -> (s0)>, "step" = 1 : index} : (index) -> ()
      "affine.yield"() : () -> ()
    }) {"lower_bound" = affine_map<() -> (0)>, "upper_bound" = affine_map<()[s0] -> (s0)>, "step" = 1 : index} : (index) -> ()
    "affine.yield"() : () -> ()
  }) {"lower_bound" = affine_map<() -> (0)>, "upper_bound" = affine_map<()[s0] -> (s0)>, "step" = 1 : index} : (index) -> ()
  "affine.yield"() : () -> ()
}) {"lower_bound" = affine_map<() -> (0)>, "upper_bound" = affine_map<()[s0] -> (s0)>, "step" = 1 : index} : (index) -> ()

%time = "func.call"(%stime) {callee = @timer_elapsed} : (i64) -> i64
"func.call"(%time) {callee = @print_i64} : (i64) -> ()

%last66 = "memref.load"(%A, %const_val_0, %const_val_0) : (memref<?x?xf64>, index, index) -> f64
"func.call"(%last66) {callee = @print_f64_cerr} : (f64) -> ()


%last67 = "memref.load"(%B, %const_val_0, %const_val_0, %const_val_0) : (memref<?x?x?xf64>, index, index, index) -> f64
"func.call"(%last67) {callee = @print_f64_cerr} : (f64) -> ()


%last68 = "memref.load"(%C, %const_val_0, %const_val_0) : (memref<?x?xf64>, index, index) -> f64
"func.call"(%last68) {callee = @print_f64_cerr} : (f64) -> ()


%last69 = "memref.load"(%D, %const_val_0, %const_val_0) : (memref<?x?xf64>, index, index) -> f64
"func.call"(%last69) {callee = @print_f64_cerr} : (f64) -> ()


%last70 = "memref.load"(%D, %const_val_0, %const_val_0) : (memref<?x?xf64>, index, index) -> f64
"func.call"(%last70) {callee = @print_f64_cerr} : (f64) -> ()





"func.return"() : () -> ()
    })  {function_type = (i32, !llvm.ptr<!llvm.ptr<i8>>) -> (), sym_name = "main", sym_visibility = "private"} : () -> ()
}) : () -> ()
