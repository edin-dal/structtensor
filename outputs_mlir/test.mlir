[info] welcome to sbt 1.8.2 (Private Build Java 1.8.0_362)
[info] loading project definition from /home/mahdi/CS-PhD/Git/sparse-compiler/CodeGenerator/structtensor/project
[info] loading settings for project structtensor from build.sbt ...
[info] set current project to hello-world (in build file:/home/mahdi/CS-PhD/Git/sparse-compiler/CodeGenerator/structtensor/)
[info] running Main 
void compute() {


%i = "arith.addi"(%0, %I) : (index, index) -> index 
%cmpval2 = "arith.cmpi"(%i, %M) {predicate = 2 : i64} : (index, index) -> i1
"scf.if"(%cmpval2) ({

%j = "arith.addi"(%0, %J) : (index, index) -> index 
%cmpval3 = "arith.cmpi"(%j, %Q) {predicate = 2 : i64} : (index, index) -> i1
"scf.if"(%cmpval3) ({

%k_sum = "scf.for"(%0, %N, %1, %zerof) ({
^bb0(%k: index, %iter_sum_k: f64):

%l_sum = "scf.for"(%0, %P, %1, %zerof) ({
^bb0(%l: index, %iter_sum_l: f64):

%tmp0 = "memref.load"(%B, %i, %k, %l) : (memref<?x?x?xf64>, index, index, index) -> f64

%tmp1 = "memref.load"(%C, %k, %j) : (memref<?x?xf64>, index, index) -> f64

%tmp2 = "memref.load"(%D, %l, %j) : (memref<?x?xf64>, index, index) -> f64

%prod3 = "arith.mulf"(%tmp0, %tmp1) : (f64, f64) -> f64
%finalV4 = "arith.mulf"(%prod3, %tmp2) : (f64, f64) -> f64


%new_sum_l = "arith.addf"(%finalV4, %iter_sum_l) : (f64, f64) -> f64
"scf.yield"(%new_sum_l): (f64) -> ()
}) : (index, index, index, f64) -> f64
%new_sum_k = "arith.addf"(%l_sum, %iter_sum_k) : (f64, f64) -> f64
"scf.yield"(%new_sum_k): (f64) -> ()
}) : (index, index, index, f64) -> f64
%preVal6 = "memref.load"(%A, %i, %j) : (memref<?x?xf64>, index, index) -> f64
%peqVal5 = "arith.addf"(%k_sum, %preVal6) : (f64, f64) -> f64
"memref.store"(%peqVal5, %A, %i, %j) : (f64, memref<?x?xf64>, index, index) -> ()
"scf.yield"() : () -> ()
}, {"scf.yield"(): () -> ()}) : (i1) -> ()
"scf.yield"() : () -> ()
}, {"scf.yield"(): () -> ()}) : (i1) -> ()
}


void reconstruct() {
%tmp0 = "memref.load"(%B, %i, %k, %l) : (memref<?x?x?xf64>, index, index, index) -> f64

%tmp1 = "memref.load"(%C, %k, %j) : (memref<?x?xf64>, index, index) -> f64

%tmp2 = "memref.load"(%D, %l, %j) : (memref<?x?xf64>, index, index) -> f64

%prod3 = "arith.mulf"(%tmp0, %tmp1) : (f64, f64) -> f64
%tmpS0 = "arith.mulf"(%prod3, %tmp2) : (f64, f64) -> f64
%final_val0 = "arith.addf"(%tmpS0, %tmpS0) : (f64, f64) -> f64

"%r236 = memref.load"(%A, %i, %j) : (memref<?x?xf64>, index, index) -> f64
%r237 = arith.addf(%r236, %final_val0)
"memref.store"(%r237, %A, %i, %j) : (f64, memref<?x?xf64>, index, index) -> ()

}

[success] Total time: 1 s, completed 03-May-2023 18:06:01
