
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
    %Wi32 = "func.call"(%argv1) {callee = @atoi} : (!llvm.ptr<i8>) -> i32
    %W = arith.index_cast %Wi32 : i32 to index


%A = memref.alloc(%W) : memref<?xf64>

    "scf.for"(%const_val_0, %W, %const_val_1) ({
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



%B = memref.alloc(%W, %W) : memref<?x?xf64>

    "scf.for"(%const_val_0, %W, %const_val_1) ({
    ^bb0(%i: index):

    "scf.for"(%const_val_0, %W, %const_val_1) ({
    ^bb0(%j: index):

%orFlag7 = "arith.constant"() {value = 0 : i1} : () -> i1
%andFlag8 = "arith.constant"() {value = 1 : i1} : () -> i1


%consti11 = "arith.constant"() {value = 0 : index} : () -> index
%cmpFlag10 = "arith.cmpi"(%consti11, %i) {predicate = 3 : i64} : (index, index) -> i1
%andFlag9 = "arith.andi"(%andFlag8, %cmpFlag10) : (i1, i1) -> i1


%cmpFlag13 = "arith.cmpi"(%W, %i) {predicate = 4 : i64} : (index, index) -> i1
%andFlag12 = "arith.andi"(%andFlag9, %cmpFlag13) : (i1, i1) -> i1

%consti16 = "arith.constant"() {value = 0 : index} : () -> index
%cmpFlag15 = "arith.cmpi"(%consti16, %j) {predicate = 3 : i64} : (index, index) -> i1
%andFlag14 = "arith.andi"(%andFlag12, %cmpFlag15) : (i1, i1) -> i1


%cmpFlag18 = "arith.cmpi"(%W, %j) {predicate = 4 : i64} : (index, index) -> i1
%andFlag17 = "arith.andi"(%andFlag14, %cmpFlag18) : (i1, i1) -> i1

%consti21 = "arith.constant"() {value = 0 : index} : () -> index
%cmpFlag20 = "arith.cmpi"(%consti21, %i) {predicate = 3 : i64} : (index, index) -> i1
%andFlag19 = "arith.andi"(%andFlag17, %cmpFlag20) : (i1, i1) -> i1


%cmpFlag23 = "arith.cmpi"(%W, %i) {predicate = 4 : i64} : (index, index) -> i1
%andFlag22 = "arith.andi"(%andFlag19, %cmpFlag23) : (i1, i1) -> i1

%consti26 = "arith.constant"() {value = 0 : index} : () -> index
%consti27 = "arith.constant"() {value = 1 : index} : () -> index
%arith_var28 = "arith.addi"(%consti26, %consti27) : (index, index) -> index

%cmpFlag25 = "arith.cmpi"(%arith_var28, %i) {predicate = 4 : i64} : (index, index) -> i1
%andFlag24 = "arith.andi"(%andFlag22, %cmpFlag25) : (i1, i1) -> i1

%consti31 = "arith.constant"() {value = 0 : index} : () -> index
%cmpFlag30 = "arith.cmpi"(%consti31, %j) {predicate = 3 : i64} : (index, index) -> i1
%andFlag29 = "arith.andi"(%andFlag24, %cmpFlag30) : (i1, i1) -> i1


%cmpFlag33 = "arith.cmpi"(%W, %j) {predicate = 4 : i64} : (index, index) -> i1
%andFlag32 = "arith.andi"(%andFlag29, %cmpFlag33) : (i1, i1) -> i1

%orFlag34 = "arith.ori"(%orFlag7, %andFlag32) : (i1, i1) -> i1


%consti37 = "arith.constant"() {value = 0 : index} : () -> index
%cmpFlag36 = "arith.cmpi"(%consti37, %i) {predicate = 3 : i64} : (index, index) -> i1
%andFlag35 = "arith.andi"(%andFlag8, %cmpFlag36) : (i1, i1) -> i1


%cmpFlag39 = "arith.cmpi"(%W, %i) {predicate = 4 : i64} : (index, index) -> i1
%andFlag38 = "arith.andi"(%andFlag35, %cmpFlag39) : (i1, i1) -> i1

%consti42 = "arith.constant"() {value = 0 : index} : () -> index
%cmpFlag41 = "arith.cmpi"(%consti42, %j) {predicate = 3 : i64} : (index, index) -> i1
%andFlag40 = "arith.andi"(%andFlag38, %cmpFlag41) : (i1, i1) -> i1


%cmpFlag44 = "arith.cmpi"(%W, %j) {predicate = 4 : i64} : (index, index) -> i1
%andFlag43 = "arith.andi"(%andFlag40, %cmpFlag44) : (i1, i1) -> i1

%consti47 = "arith.constant"() {value = 1 : index} : () -> index
%cmpFlag46 = "arith.cmpi"(%consti47, %i) {predicate = 3 : i64} : (index, index) -> i1
%andFlag45 = "arith.andi"(%andFlag43, %cmpFlag46) : (i1, i1) -> i1


%cmpFlag49 = "arith.cmpi"(%W, %i) {predicate = 4 : i64} : (index, index) -> i1
%andFlag48 = "arith.andi"(%andFlag45, %cmpFlag49) : (i1, i1) -> i1


%consti52 = "arith.constant"() {value = 1 : index} : () -> index
%arith_var53 = "arith.subi"(%i, %consti52) : (index, index) -> index

%cmpFlag51 = "arith.cmpi"(%arith_var53, %j) {predicate = 0 : i64} : (index, index) -> i1
%andFlag50 = "arith.andi"(%andFlag48, %cmpFlag51) : (i1, i1) -> i1

%orFlag54 = "arith.ori"(%orFlag34, %andFlag50) : (i1, i1) -> i1


    "scf.if"(%orFlag54) ({
      %rval55 = "func.call"() {callee = @rand} : () -> i32
      %rval56 = "arith.remui"(%rval55, %1000000) : (i32, i32) -> i32
      %rval57 = "arith.sitofp"(%rval56) : (i32) -> f64
      %rval58 = "arith.divf"(%rval57, %f1000000) : (f64, f64) -> f64
      "memref.store"(%rval58, %B, %i, %j): (f64, memref<?x?xf64>, index, index) -> ()
      "scf.yield"() : () -> ()
    }, {
      "memref.store"(%zerof, %B, %i, %j): (f64, memref<?x?xf64>, index, index) -> ()
      "scf.yield"() : () -> ()
    }) : (i1) -> ()


    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()

    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()


%C = memref.alloc(%W) : memref<?xf64>

    "scf.for"(%const_val_0, %W, %const_val_1) ({
    ^bb0(%j: index):

%orFlag59 = "arith.constant"() {value = 0 : i1} : () -> i1
%andFlag60 = "arith.constant"() {value = 1 : i1} : () -> i1


%consti63 = "arith.constant"() {value = 0 : index} : () -> index
%cmpFlag62 = "arith.cmpi"(%consti63, %j) {predicate = 3 : i64} : (index, index) -> i1
%andFlag61 = "arith.andi"(%andFlag60, %cmpFlag62) : (i1, i1) -> i1


%cmpFlag65 = "arith.cmpi"(%W, %j) {predicate = 4 : i64} : (index, index) -> i1
%andFlag64 = "arith.andi"(%andFlag61, %cmpFlag65) : (i1, i1) -> i1

%orFlag66 = "arith.ori"(%orFlag59, %andFlag64) : (i1, i1) -> i1


    "scf.if"(%orFlag66) ({
      %rval67 = "func.call"() {callee = @rand} : () -> i32
      %rval68 = "arith.remui"(%rval67, %1000000) : (i32, i32) -> i32
      %rval69 = "arith.sitofp"(%rval68) : (i32) -> f64
      %rval70 = "arith.divf"(%rval69, %f1000000) : (f64, f64) -> f64
      "memref.store"(%rval70, %C, %j): (f64, memref<?xf64>, index) -> ()
      "scf.yield"() : () -> ()
    }, {
      "memref.store"(%zerof, %C, %j): (f64, memref<?xf64>, index) -> ()
      "scf.yield"() : () -> ()
    }) : (i1) -> ()


    "scf.yield"() : () -> ()
    }) : (index, index, index) -> ()


    %stime = "func.call"() {callee = @timer} : () -> i64

%0 = arith.constant 0 : index
"affine.for"(%W) ({
^0(%i : index):
  %1 = "affine.load"(%B, %i) {"map" = affine_map<(d0) -> (0, d0)>} : (memref<?x?xf64>, index) -> f64
  %2 = "affine.load"(%C, %i) {"map" = affine_map<(d0) -> (d0)>} : (memref<?xf64>, index) -> f64
  %3 = arith.mulf %1, %2 : f64
  "affine.store"(%3, %A) {"map" = affine_map<() -> (0)>} : (f64, memref<?xf64>) -> ()
  "affine.yield"() : () -> ()
}) {"lower_bound" = affine_map<() -> (0)>, "upper_bound" = affine_map<()[s0] -> (s0)>, "step" = 1 : index} : (index) -> ()
"affine.for"(%W) ({
^1(%i_1 : index):
  %4 = "affine.load"(%B, %i_1) {"map" = affine_map<(d0) -> ((d0 + 1), d0)>} : (memref<?x?xf64>, index) -> f64
  %5 = "affine.load"(%C, %i_1) {"map" = affine_map<(d0) -> (d0)>} : (memref<?xf64>, index) -> f64
  %6 = arith.mulf %4, %5 : f64
  "affine.store"(%6, %A, %i_1) {"map" = affine_map<(d0) -> ((d0 + 1))>} : (f64, memref<?xf64>, index) -> ()
  "affine.yield"() : () -> ()
}) {"lower_bound" = affine_map<() -> (0)>, "upper_bound" = affine_map<()[s0] -> ((s0 + -1))>, "step" = 1 : index} : (index) -> ()

%time = "func.call"(%stime) {callee = @timer_elapsed} : (i64) -> i64
"func.call"(%time) {callee = @print_i64} : (i64) -> ()

%last71 = "memref.load"(%A, %const_val_0) : (memref<?xf64>, index) -> f64
"func.call"(%last71) {callee = @print_f64_cerr} : (f64) -> ()


%last72 = "memref.load"(%B, %const_val_0, %const_val_0) : (memref<?x?xf64>, index, index) -> f64
"func.call"(%last72) {callee = @print_f64_cerr} : (f64) -> ()


%last73 = "memref.load"(%C, %const_val_0) : (memref<?xf64>, index) -> f64
"func.call"(%last73) {callee = @print_f64_cerr} : (f64) -> ()


%last74 = "memref.load"(%B, %const_val_0, %const_val_0) : (memref<?x?xf64>, index, index) -> f64
"func.call"(%last74) {callee = @print_f64_cerr} : (f64) -> ()




"func.return"() : () -> ()
    })  {function_type = (i32, !llvm.ptr<!llvm.ptr<i8>>) -> (), sym_name = "main", sym_visibility = "private"} : () -> ()
}) : () -> ()
