
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
    %Ii32 = "func.call"(%argv4) {callee = @atoi} : (!llvm.ptr<i8>) -> i32
    %I = arith.index_cast %Ii32 : i32 to index

    %argvv5 = llvm.getelementptr %argv[5] : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<!llvm.ptr<i8>>
    %argv5 = "llvm.load"(%argvv5) : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<i8>
    %Qi32 = "func.call"(%argv5) {callee = @atoi} : (!llvm.ptr<i8>) -> i32
    %Q = arith.index_cast %Qi32 : i32 to index

    %argvv6 = llvm.getelementptr %argv[6] : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<!llvm.ptr<i8>>
    %argv6 = "llvm.load"(%argvv6) : (!llvm.ptr<!llvm.ptr<i8>>) -> !llvm.ptr<i8>
    %Pi32 = "func.call"(%argv6) {callee = @atoi} : (!llvm.ptr<i8>) -> i32
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


%cmpFlag26 = "arith.cmpi"(%i, %I) {predicate = 0 : i64} : (index, index) -> i1
%andFlag25 = "arith.andi"(%andFlag23, %cmpFlag26) : (i1, i1) -> i1

%orFlag27 = "arith.ori"(%orFlag8, %andFlag25) : (i1, i1) -> i1


    "scf.if"(%orFlag27) ({
      %rval28 = "func.call"() {callee = @rand} : () -> i32
      %rval29 = "arith.remui"(%rval28, %1000000) : (i32, i32) -> i32
      %rval30 = "arith.sitofp"(%rval29) : (i32) -> f64
      %rval31 = "arith.divf"(%rval30, %f1000000) : (f64, f64) -> f64
      "memref.store"(%rval31, %B, %i, %k, %l): (f64, memref<?x?x?xf64>, index, index, index) -> ()
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

%orFlag32 = "arith.constant"() {value = 0 : i1} : () -> i1
%andFlag33 = "arith.constant"() {value = 1 : i1} : () -> i1


%consti36 = "arith.constant"() {value = 0 : index} : () -> index
%cmpFlag35 = "arith.cmpi"(%consti36, %k) {predicate = 3 : i64} : (index, index) -> i1
%andFlag34 = "arith.andi"(%andFlag33, %cmpFlag35) : (i1, i1) -> i1


%cmpFlag38 = "arith.cmpi"(%N, %k) {predicate = 4 : i64} : (index, index) -> i1
%andFlag37 = "arith.andi"(%andFlag34, %cmpFlag38) : (i1, i1) -> i1

%consti41 = "arith.constant"() {value = 0 : index} : () -> index
%cmpFlag40 = "arith.cmpi"(%consti41, %j) {predicate = 3 : i64} : (index, index) -> i1
%andFlag39 = "arith.andi"(%andFlag37, %cmpFlag40) : (i1, i1) -> i1


%cmpFlag43 = "arith.cmpi"(%Q, %j) {predicate = 4 : i64} : (index, index) -> i1
%andFlag42 = "arith.andi"(%andFlag39, %cmpFlag43) : (i1, i1) -> i1

%orFlag44 = "arith.ori"(%orFlag32, %andFlag42) : (i1, i1) -> i1


    "scf.if"(%orFlag44) ({
      %rval45 = "func.call"() {callee = @rand} : () -> i32
      %rval46 = "arith.remui"(%rval45, %1000000) : (i32, i32) -> i32
      %rval47 = "arith.sitofp"(%rval46) : (i32) -> f64
      %rval48 = "arith.divf"(%rval47, %f1000000) : (f64, f64) -> f64
      "memref.store"(%rval48, %C, %k, %j): (f64, memref<?x?xf64>, index, index) -> ()
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

%orFlag49 = "arith.constant"() {value = 0 : i1} : () -> i1
%andFlag50 = "arith.constant"() {value = 1 : i1} : () -> i1


%consti53 = "arith.constant"() {value = 0 : index} : () -> index
%cmpFlag52 = "arith.cmpi"(%consti53, %l) {predicate = 3 : i64} : (index, index) -> i1
%andFlag51 = "arith.andi"(%andFlag50, %cmpFlag52) : (i1, i1) -> i1


%cmpFlag55 = "arith.cmpi"(%P, %l) {predicate = 4 : i64} : (index, index) -> i1
%andFlag54 = "arith.andi"(%andFlag51, %cmpFlag55) : (i1, i1) -> i1

%consti58 = "arith.constant"() {value = 0 : index} : () -> index
%cmpFlag57 = "arith.cmpi"(%consti58, %j) {predicate = 3 : i64} : (index, index) -> i1
%andFlag56 = "arith.andi"(%andFlag54, %cmpFlag57) : (i1, i1) -> i1


%cmpFlag60 = "arith.cmpi"(%Q, %j) {predicate = 4 : i64} : (index, index) -> i1
%andFlag59 = "arith.andi"(%andFlag56, %cmpFlag60) : (i1, i1) -> i1


%cmpFlag62 = "arith.cmpi"(%j, %J) {predicate = 0 : i64} : (index, index) -> i1
%andFlag61 = "arith.andi"(%andFlag59, %cmpFlag62) : (i1, i1) -> i1

%orFlag63 = "arith.ori"(%orFlag49, %andFlag61) : (i1, i1) -> i1


    "scf.if"(%orFlag63) ({
      %rval64 = "func.call"() {callee = @rand} : () -> i32
      %rval65 = "arith.remui"(%rval64, %1000000) : (i32, i32) -> i32
      %rval66 = "arith.sitofp"(%rval65) : (i32) -> f64
      %rval67 = "arith.divf"(%rval66, %f1000000) : (f64, f64) -> f64
      "memref.store"(%rval67, %D, %l, %j): (f64, memref<?x?xf64>, index, index) -> ()
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

%last68 = "memref.load"(%A, %const_val_0, %const_val_0) : (memref<?x?xf64>, index, index) -> f64
"func.call"(%last68) {callee = @print_f64_cerr} : (f64) -> ()


%last69 = "memref.load"(%B, %const_val_0, %const_val_0, %const_val_0) : (memref<?x?x?xf64>, index, index, index) -> f64
"func.call"(%last69) {callee = @print_f64_cerr} : (f64) -> ()


%last70 = "memref.load"(%C, %const_val_0, %const_val_0) : (memref<?x?xf64>, index, index) -> f64
"func.call"(%last70) {callee = @print_f64_cerr} : (f64) -> ()


%last71 = "memref.load"(%D, %const_val_0, %const_val_0) : (memref<?x?xf64>, index, index) -> f64
"func.call"(%last71) {callee = @print_f64_cerr} : (f64) -> ()


%last72 = "memref.load"(%B, %const_val_0, %const_val_0, %const_val_0) : (memref<?x?x?xf64>, index, index, index) -> f64
"func.call"(%last72) {callee = @print_f64_cerr} : (f64) -> ()


%last73 = "memref.load"(%D, %const_val_0, %const_val_0) : (memref<?x?xf64>, index, index) -> f64
"func.call"(%last73) {callee = @print_f64_cerr} : (f64) -> ()





"func.return"() : () -> ()
    })  {function_type = (i32, !llvm.ptr<!llvm.ptr<i8>>) -> (), sym_name = "main", sym_visibility = "private"} : () -> ()
}) : () -> ()
