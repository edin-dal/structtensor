# Overview

# Change List

- Discuss GCC auto-vectorization activation (Reviewer A).
- Further Clarification of limitations and future work (Reviewer A).
- Clarify that color encoding is for visual purposes in Figure 3 (Reviewer A).
- Make all the notations consistent (Reviewer A).
- Restructure and add missing references to the related work (Reviewer A).
- Clarify the code generation algorithm, add an example for it, and explain the required information for it (Reviewer A & B).
- Redefine scientific questions and restructure the experiment section (Reviewer A).
- Clarify how we mix the real and set domains further with an example (Reviewer B).
- Add "put it all together" section to wrap all the steps of StructTensor through the motivating example (Reviewer B).
- Clarify the free variables addition rule (Reviewer B).
- Emphasize the soundness of inference rules rather than completeness (Reviewer B).
- Further elaborate on the comparison with LGen and Sympiler (Reviewer C).
- Explain the reason why StructTensor performs better than TACO on only sparse kernels (Reviewer C).

# Individual Responses

## Reviewer A

> Topical work in an insufficiently explored area.
> While the paper does not sound as ground-breaking as TACO in its time, just like TACO it is important to realize that much of the state of the art lacked such a unifying picture and high level of automation. Sure, all code generation ideas and optimizations have been evaluated before, just like TACO reused pioneering work by Bik and much practice accumulated from numerical libraries and compilers for sparse representations. For these reasons, I would definitely not call this paper incremental, it is quite an achievement.

Thank you for your kind comment.

> From an HPC perspective, the paper has one major flow however: the absence of absolute performance results (GFLOPS or time, roofline model) on a clearly identified hardware platform, and the lack of automatic vectorization in the code generator itself (relying on GCC's autovectorization instead). For the latter, a discussion of a posteriori investigation of assembly code would be sufficient, if it can be confirmed that vectorization does takes place. For the former, it is clearly missing and the paper would not be acceptable as is in an HPC venue.
> 
> The fact the word "block" never happens in the paper is troubling. First of all, the authors should be more explicit that they are not considering "unstructured" "block-structured" representation (not in a general form at least); this is fine but slightly reduces the scope (e.g., it essentially makes it unusable in deep learning applications, but other ML techniques are supported, as illustrated in the paper). Second, the authors acknowledge the lack of tiling/blocking; this is understandable for dynamic sparsity tools like TACO, but more problematic in representations where large chunks of data are actually dense. Yet the work remains a valuable contribution despite these limitations.


As for the auto-vectorization, we have tested whether it will be activated on tensor operation kernels (Figure 13) using the `-fopt-info-vec` flag. The output log shows that vectorization is happening on the innermost loop. Therefore the computation is actually vectorized. We will add a discussion about auto-vectorization to our experimental section.

We agree that our work has limitations. As you mentioned, it will not be a good fit for an HPC conference. Also, we do not support unstructured block structure, which is crucial for deep learning. Nevertheless, StructTensor is beneficial for a variety of applications. We will clarify these points in the revision.

> Finally, the paper would also be slightly stronger with more emphasis on reproducibility (e.g. an open source implementation).

We will submit the code for the artifact evaluation. Also, we plan to make the code open source in the future for wider adoption after properly documenting it.

> Is there a rationale for the colors in Figure 3?

Colors serve the same purpose as numbers on matrix elements. Matrix elements are color encoded for better visualisation purposes. 

For example, elements in (row, col) = (1, 7), (1, 13), (3, 5), (5, 3), (13, 1), (7, 1) are all pink (and they all have number 12 on them), because they have the exact same value.

We will clarify this in the paper.

> Inconsistency between the notations in Figure 7 and the earlier notations. In particular, matrix multiplication was denoted initially as \times, before becoming \cdot.

Thank you for your comment. Matrix multiplication uses \times notation only in Figure 2 and is \cdot for the rest of the paper. We will make all notations consistent throughout the whole paper.

> Also, avoid * as a multiplication symbol (introduced in Figure 5) if possible, which should be possible if using \times for matrix multiplication.

Multiplication in our language has a different semantic than matrix multiplication (even though it can express matrix multiplication). It is closest to the definition of tensor outer product and can capture generalised einsum expressions. Selection of * as this multiplication is similar to the TACO's frontend. We believe that this notation is appropriate for our semantic. However, we are open to suggestions.

> Earlier, the || and // syntaxes could also be spaced (internal kerning) more homogenously.

We will decrease the space between // to make it homogenous to ||.

> Related work:
> -   The selection of polyhedral framework is somewhat inconsistent. isl is a polyhedral library with advanced scheduling and code generation capabilities, CLooG is a code generator, and the former is used in Tensor Comprehensions and also in the more recent MLIR-based PolyBlocks from Bondhugula et al. It is probably better to present it in this way, with underlying frameworks separate from the dervied tensor compilers.
> -   JAX has sparse tensor support, leveraging MLIR code generation mirroring TACO's representation and algorithms; although it is arguably preliminary.

Thank you for your suggestions. We are going to restructure the related works as you suggested and add the missing references.

> The paper is not very clear about the need for manual, offline specification of the structure, and how it is expressed. Section 5.6 should be extended to make that clearer. In particular, it should be explained somewhere what information is strictly necessary and which expressions can rely on the inference mechanism of Section 6. Can you sketch how you would make this better?


We use STUR as the frontend language. A tensor computation should be written in STUR. To generate the code for the expression the following information should be provided for each tensor:

-  Dimension information (required): The size of each dimension of the tensor must be provided through STUR. Without dimension information, code generation is impossible.
- Unique set (optional): Bounds over all unique non-zero elements of the tensor should be provided in the unique set. If the unique set is not provided, we assume that the tensor is fully dense.
- Redundancy map (optional): The mapping from repetitive non-zero values to their unique corresponding values should be provided in the redundancy map. If the redundancy map is not provided, we assume that there is no redundancy structure.

All intermediate and output tensors' structures can be inferred following our program reasoning rules using the mentioned input information. We will clarify this better in section 5.6.

> p15 I'm confused by the partial injective relation discussion. First of all, an injection is not injective in general. And then the next property is the exact definition of a morphism (homo-morphism in fact), and I don't see how this could yield a characterization of injective relations. Please correct me and propose an alternative argument/wording.

**Waiting for Matheiu**

> The benchmark selection in the evaluation appears somewhat chaotic. At least I am missing some of the rationale for evaluating one type of scientific question on one given set of benchmarks. Did I miss something?

We aimed to show that our framework is beneficial for a variety of applications, therefore we tested it on a variety of benchmarks. However, due to lack of space, we were selective and only presented the experiments that can precisely answer the questions. 

We will make this section less chaotic by restructuring the scientific questions and experimental section to have the following order:

- *How advantageous is symbolic sparsity over dynamic sparsity for tensors and matrices?* 
The experiments in section 7.3 in addition to 3 SpMV kernels (including the population growth using Leslie matrix in section 7.4)  will be answering this scientific question. In all of these kernels, the symbolic sparsity is being propagated throughout the computation.
- *Does StructTensor perform better than the state-of-the-art tensor processing frameworks for real-world structured computations after leveraging the redundancy structure?* 
The experiments in section 7.2 in addition to computation of 1D convolution from section 7.4 will be answering this question. In regression examples, input has no structure but StructTensor can infer a structure for output. For 1D convolution computation using Toeplitz matrix, the input has both redundancy and sparsity patterns and this structure is being propagated throughout the computation. Also, we will add other regression experiments that contain sparsity in their input vector to further exploit the potential of StructTensor in enhancing the computation using both types of strucutre.
- *How do the optimizations benefit StructTensor?*
An extended version of section 7.5 will answer this question. Due to lack of space, we only used a subset of our experiments to show the impact of optimisation techniques we have employed. We will use some of the extra pages given to us for revision to include more kernels and discuss the optimisation impacts further.
- *Is it worthwhile to perform the computation over a compressed tensor and then decompress the result in real-world applications?*
We will answer to this question using our end-to-end experiments (section 7.6).


## Reviewer B

> Perhaps this reflects some poor understanding on my part, but I would have appreciated more text or proofs of the rules in Figs. 9 and 10, which did not seem obvious or straightforward to me, even given the first paragraph of Sec. 5.1.

We do agree that they are non-intuitive. Therefore, we tried to give further intuition and understanding through examples. Moreover, proving the soundness of structure inference is a challenging part that is shown in section 6.

> This is perhaps a very subjective reaction on my part, but I found it rather confusing for the unique sets and redundancy maps to have used the same notation as the tensor definitions themselves; I assumed that they were also somehow numerical definitions until I saw the line about how  +  and  ∗  should be understood to be union and intersection, respectively, for those cases. Maybe using  ∧  and  ∨  (or  ∪  and  ∩) would make the intent clearer. Perhaps clarifying the notation early and prominently in the paper might be helpful for readers (e.g., I also had trouble with the summing over free variables).

Our design decision was to use the same notation for both real and set domains in order to unify their representation and for optimisation and reasoning purposes.
As an example, consider the chess pattern unique set provided in line 336 of the paper. The set representation of that unique set is:
$\{ (i, j) | (0 \leq i' < (m/2)) \wedge (0 \leq j' < (n/2)) \wedge (i = i'∗ 2) ∧ (j = j'∗ 2 + 1) \} \cup  
\{ (i, j) | (0 \leq i' < (m/2)) \wedge (0 \leq j' < (n/2)) ∧ (i = i'∗ 2+1) \wedge (j = j'∗ 2) \}$
In STUR, the $\wedge$ and $\cup$ signs are translated to $*$ and $+$, respectively. $\cap$ and $\lor$ have the same translation as $\wedge$ and $\cup$, respectively. Therefore the described unique set will be translated to 
$T_U (i, j) := (0 \leq i' < (m/2)) ∗ (0 \leq j' < (n/2)) ∗ (i = i'∗ 2) ∗(j = j'∗ 2 + 1) + (0 \leq i' < (m/2))∗  (0 \leq j' < (n/2)) ∗ (i = i'∗ 2+1) ∗ (j = j'∗ 2)$
In this example, $i'$ and $j'$ are free variables that appear on the right hand side but do not appear on the left hand side. For this assignment to have meaning, we need to factor out $i'$ and $j'$  by summing over them. After that, the assignment will take place. 

We will improve the presentation by adding the mentioned example and showing the correspondence between set operations and numerical operations. We will also clarify what we mean by summing over free variables using the example.

> In Sec. 3, I think it would have been helpful for the motivating example to have included some ballpark numbers for the impact of the optimizations demonstrated.

The exact number of elements in the optimized covariance matrix for $n$ features is $\frac{n^4 + 10 n^3 + 35 n^2 + 26 n}{24}$ compared to $n^4 + 2 n^3 + n^2$ elements for the naive version for the polynomial regression degree 2. We will add the comparison to the paper.

> In Fig. 16, I think the caption should explicitly say that the reconstruction time is so negligible that it's not visible in the graph (I assume that's the intent). Perhaps the caption could give the numerical measurement if it's that small. Not saying so explicitly might lead the reader to conclude that there was a mistake in the graph.

We will clarify in the caption that the reconstruction time is so negligible. 

>Typo: Line 1097: "none of these work support redundancy-aware computation" -> "none of these works supports redundancy-aware computation"
>
> Typo: Lines 1097-1098: "Moreover, sparity is handled in run-time that leads to irregular memory access..." -> "Moreover, sparsity is handled at run time, leading to irregular memory access..."
> 
> Typo: Line 1103: "Performing common-subexpression" -> "Performing common-subexpression elimination"

Thanks. We will fix these typos.

> Would it be possible to outline code generation in more detail? For example, going with the motivating example in Sec. 3, could you explain how the definitions for M1, M2, and M3 result in the C++ code given at the end of the section? 
> 
> I would have appreciated more detail on code generation, as I did not think Algorithm 2 provided enough information to figure out how to generate code using the uniqueness sets and redundancy maps.
> 
> I would also strongly encourage the authors to include an artifact (the submission page indicates "undecided" for that question), which could allay some of the concerns about, e.g., how the actual code generation is done. 


As an example, let's go through the code generation procedure of $M2$. $M2$ computation is represented as follows in STUR:
$M2(i, col) = f(i) * (0 \leq i < n) * f(j) * (0 \leq j < n) * f(k) * (0 \leq k < n) * (col = j * n + k)$ 
$=$
$M2(i, col) = f(i) * f(j) * f(k)  * (0 \leq i < n) * (0 \leq j < n) * (0 \leq k < n) * (col = j * n + k)$ 
Figure 10 provides the structure inference rule for a self outer product of two vectors. We have implemented a general version of that rule inside STUR that can infer the structure for the self outer product of $n$ vectors. Based on that rule, the unique set of $M2$ is:
$M2_U(i, col) = (0 \leq i \leq j \leq k < n) * (col = j * n + k)$
As mentioned in the paper, a unique set is provided as a sum of products. This unique set only has one product inside its body. The code generator reads the body and extracts all the variables inside it ($i,j,k,col$). Then, the code generator proceeds to detect the boundaries for each variable. They are as follows:
$i \rightarrow (0, n)$ and $j \rightarrow (i, n)$ and $k \rightarrow (j, n)$ and $col \rightarrow (j * n + k, j * n + k  + 1)$.
Here $a -> (lower, upper)$ means that $lower \leq a < upper$. We make sure that each variable is only dependent on previous variables, in the same order that they are provided to input. As the next step, loops, if conditions, or assignments will be generated based on the detected boundaries. Note that assignment is the specific case of loop where $upper = lower + 1$. Finally, the computation will be generated for the input expression. Therefore, the code that is provided in lines 270-276 will be generated. 

Due to lack of space, we did not go through each step of code generation with an example. We will clarify our code generation algorithm in section 5.5. We will also use parts of the extra pages given for revision to add another section called "Putting it all together". In this section, we will go through our motivating example again and explain how each step works from the very beginning to the end. Additionally, as we mentioned to Reviewer A, we will submit our code for the artifact evaluation and will make it open source after providing proper documentation. 



> (In particular, I had trouble with the line, "If a variable’s lower or upper bound is not defined, gen_loop function will not generate anything (cf. Algorithm 2, lines 7-11)." Why is it correct not to generate anything at all? Also, as aforementioned, I did not think the pseudocode helped me figure out what code would be generated.)


As we clarified to Reviewer A, dimensions of the tensor are required in order to generate the code. If the dimension is provided, then boundaries of variables are defined, and this case will not happen. The only cases that might have a variable without a boundary are where the user introduces a new variable but mistakenly does not set a boundary for it. For example:
$M(i, c) = T(i) * V(j) * (j \leq c)$
In this case, $c$ only has a lower bound and no upper bound. Generating a code for that results in a loop with a known starting point ($j$) but no upper limit, thus an infinite loop. Therefore, since it can only be caused by user mistakes, the code generator will not generate a code for this expression.


> I am not certain I followed the definitions for the uniqueness set and redundancy map entirely. For example, the text concerns itself with nonzero elements of the tensors (which is reasonable), but can the tensors have negative elements? In that case, you can have the sum of two tensors where all elements are nonzero result in a tensor of all zeroes, which does not seem to follow the rule for addition in Fig. 9.

We focused on our inference rules being sound rather than complete. Meaning that our approach to the unique set and redundancy map is conservative, and we consider the elements that might be non-zero after computation as non-zero since we do not know the actual values. In the scenario that you mentioned, those zero values caused by adding a negative value with its positive value will be treated as non-zero, and StructTensor will perform extra iterations over those zero values to make sure the computation is correct (even though it will not be the most efficient way). We will clarify this point in the paper.

> Another potential misunderstanding on my part: In Fig. 6, why would the free variables of the sum be the intersection of the free variables of the terms? Wouldn't a free variable in one term still be free even if it doesn't appear in the other term?

Consider the following example: 
$T1(i) := T2(i,j) + T3(i,k)$ 
where $T2(i,j) = (0 \leq i < n) * (j = i)$ and $T3(i,k) = (n \leq i < 2*n) * (k = i)$. In this computation, $k$ is unbounded for $T2$ and $j$ is unbounded for $T3$. Therefore, if we do not sum over $k$ in $T2$ and $j$ in $T3$, it is impossible to perform the computation. We will clarify this point using the example in the paper.

> In Fig. 15, what is the difference between the naive baseline and "no optimization"? Clearly from the results, the latter includes some improvements over the baseline, so what optimizations does that entail? Perhaps "no optimization" is a misnomer.

Naive is when one writes the code without considering any structure (e.g., sparsity or redundancy). So they iterate and do the computation over all elements without caring about the existing structure. No optimization is the generated code using StructTensor which by default takes the structure into consideration, but there are no code motion and data layout optimizations applied to it. We will clarify this in the figure by applying the following changes:
-   Naive -> Naive    
-   No optimization -> StructTensor (No Opt.)
-   Code Motion -> StructTensor (Code Motion)
-   Data Layout -> StructTensor (Data Layout)
-   Both -> StructTensor (Code Motion & Data Layout)

## Reviewer C

> However, the evaluation of the paper can be improved. In particular, the benchmarks used for the evaluation are selected to highlight how performance can be improved significantly when exploiting sparsity and redundancy together. However, none of the baselines are designed to leverage both sparsity and redundancy patterns (except for very specific kernels). I would like to see a comparison with the closest work that leverages both sparsity and redundancy patterns, such as LGen and Sympiler. The paper mentions that those existing works do not support high-dimensional tensors. I wonder if that is a fundamental limitation of the existing works or if they can be extended to support high-dimensional tensors. If the latter, the paper should attempt to compare against those works even if they only support fixed sizes. If the former, the paper should discuss in detail what the fundamental limitations of the existing works are.
> 
> Can one extend existing works such as LGen and Sympiler to support high-dimensional tensors? What would it take to do so?

LGen is aiming for small scale fixed size basic linear algebra operations. Therefore, they have a predefined set of structures for matrices and implement the structure inference rules for them. Also, their SInfo and AInfo that keep the structure information only work with fixed size matrices. In order to extend LGen to support higher order tensors, one should redesign their whole intermediate representation and add supports for more advanced computations such as einsum. To handle the variable size computation for higher order tensors, one should extend LGen from inside by using libraries such as Barvinok. If all of these changes are applied to the core of LGen, the result would be similar to StructTensor.

Sympiler, as opposed to LGen, can support variable size matrices. However, their whole design is focused on sparse matrices given a specific numerical kernel. In order to make them support higher order tensors, one needs to change and redesign the internal representation of Sympiler. Even with that, Sympiler can not perform arbitrary computation easily. To benchmark Sympiler on any new kernel, the AST of the kernel must be provided to Sympiler internally. Therefore, extending Sympiler to support tensors and using it for arbitrary kernels requires essential changes to the design and structure of the framework. 

We will clarify this in the related works section.

> Although some kernels being evaluated are fairly important, it is unclear how useful this technique is for other types of HPC workloads and machine learning applications such as neural networks. I would like to see end-to-end performance evaluation on more diverse types of programs. It would also be very helpful to compare against existing baselines for the end-to-end performance evaluation as well.
> 
> What are other types of applications and workloads that will benefit from this work?

Using StructTensor inside sparsified neural networks is an interesting application. However, it is similar to chaining a series of sparse matrix-vector multiplications or sparse matrix-matrix multiplication. For example, if the weight matrix of a deep neural network ends up with a tridiagonal structure, StructTensor can leverage the structure and enhance the computation. In our experimental section, we have shown several examples of various kernels that can benefit from StructTensor. Due to lack of space, we decided not to add another end-to-end experiment where computations similar to its underlying components are shown to be improved.

> On sparse tensor kernel evaluation, I wonder why StructTensor always performs better than or on par with TACO. TACO is known for generating efficient code for sparse tensor kernels, especially because of its ability to support different formats for sparse tensors. Because of this, I would expect TACO to perform better than StructTensor if the kernels are sparse but have no redundancy. I would like to see a discussion on why StructTensor outperforms TACO on these benchmarks. Is it because the symbolic representation is more effective or because of something else? Please elaborate.
> 
> Why does StructTensor perform better than TACO on sparse tensor kernels (with no redundancy)? 

A major difference between StructTensor and TACO is that StructTensor is aware of sparsity patterns in compile time, while TACO needs to handle it at runtime. Therefore, the generated code by StructTensor has direct access to tensor elements while TACO uses indirect access. Furthermore, having direct access can activate the compiler's auto-vectorization and enhance the computation further for StructTensor, while this is absent for TACO. As an example, consider the THP: Diagonal (Plane) kernel. The computation is:
$A(i, j, k) := B(i, j, k) * C(i, j, k) * (i = j)$
The generated code by StructTensor is:
```c
for (int i = 0; i < std::min({sizeI, sizeJ}); ++i) {
	auto &cm1 = A[i];
	auto &cm2 = C[i];
	auto &cm3 = cm1[i]; // j = i;
	auto &cm4 = cm2[i]; // j = i;
	for (int k = 0; k < sizeK; ++k) 
		cm3[k] += (B[((i * sizeK) + k)] * cm4[k]);
}
```
and the generated code by TACO for the smart version is:
```c
int32_t jA = 0;
for (int32_t i = 0; i < sizeI; i++) {
  for (int32_t jB = B2_pos[i]; jB < B2_pos[(i + 1)]; jB++) {
    int32_t j = B2_crd[jB];
    int32_t jC = i * sizeI + j;
    for (int32_t k = 0; k < sizeK; k++) {
      int32_t kA = jA * sizeK + k;
      int32_t kB = jB * sizeK + k;
      int32_t kC = jC * sizeK + k;
      A_vals[kA] = B_vals[kB] * C_vals[kC];
    }
    jA++;
  }
}
```

As shown in the generated codes, StructTensor directly accesses the tensor elements. However, TACO needs to retrieve the sparse elements using their position (`pos`) and coordinate (`crd`) mappings.

We will clarify the reason that we perform better than TACO in the final version of our paper.