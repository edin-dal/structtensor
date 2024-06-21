# StructTensor: Compiling Structured Tensor Algebra



## Usage

### Example

To generate code for one of the existing `.stur` codes in the `examples/` directory, use the following command:

```
$ sbt 
sbt:struct-tensor> clean
sbt:struct-tensor> compile
sbt:struct-tensor> run stur --inf examples/<name>.stur --outf <path/to/output.cpp>
```

This will generate a C++ code for the kernel named `<name>.stur`. 

To allocate and initiate the tensors and generate a runnable file, use the following command:

```
$ sbt 
sbt:struct-tensor> clean
sbt:struct-tensor> compile
sbt:struct-tensor> run stur --inf examples/<name>.stur --outf <path/to/output.cpp> --init-tensors --enforce-dims
```

### Command line options

All command line options can be obtained by using the command `run --help`. The output can be seen as follows:

```
struct-tensor 0.1
Usage: sturct-tensor [app|coalesce|stur] [options]

  -s, --sparse            use sparse data layout for the input
  -l, --lang <lang>       select the target language for the generated code
  --no-cm                 disable code motion
  --stur-opt-code-gen     send the code through stur-opt path for code generation
  --help                  prints this usage text
Command: app [options]
run an existing application
  --name <name>           name of the selected application to run
Command: coalesce
run the coalescing pass on the input file
Command: stur [options]
generate code for input file (written in stur)
  --inf <path>            path to the stur input file
  --outf <path>           where to stored the generated code
  --init-tensors          initialize the tensors randomly in the generated code
  --enforce-dims          enforce the dimensions of the tensors in the generated code by multiplying dimensions by unique set (if false, we assume unique set is in the dimension boundaries)
  --compress              generate the compressed code
  --stur-opt-args <args>  arguments to be passed to stur-opt
```