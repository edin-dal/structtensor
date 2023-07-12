%0 = "arith.constant"() {"value" = 0 : index} : () -> index
%2 = "arith.constant"() {"value" = 2 : index} : () -> index
%5 = "arith.constant"() {"value" = 5 : index} : () -> index
%fif = "arith.constant"() {"value" = 5.0 : f64} : () -> f64
%A = memref.alloc(%5, %5) : memref<?x?xf64>

affine.store %fif, %A[%0, %2] : memref<?x?xf64>
affine.load %A[%0, %2] : memref<?x?xf64>

affine.for %i = %0 to %5 step 1 {

affine.for %j = %i to %5 step 1 {

}

}