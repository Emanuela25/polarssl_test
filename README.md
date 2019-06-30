# polarssl_test
Use symbolic execution tools KLEE and angr to test PolarSSL

## Source Code
/mbedtls: clone from https://github.com/ARMmbed/mbedtls

## KLEE 
/klee_test: klee test result
* obj_gcov - build polarssl source code with gcov 
* obj_llvm - build polarssl source code with wllvm
Here is the step by step description of how to test with klee:
https://docs.google.com/document/d/1vyFyC5-7EC8dTBhvMpV87uRenughcb7FKqmHPmeBI9M/edit

## angr
/angr_test - angr test scripts of polarssl and examples from: https://github.com/angr/angr-doc/tree/master/examples
* angr_test.py - test script for polarssl 
  - tried on executables programs/hash/generic_sum(generate_graph) and programs/pkey/gen_key(symbolic_execution)
  - usage: python3 angr_test.py [filename] -g -s
  - modify symbolic_execution function based on the program to test 
* examples - sample scripts of how to use angr python API to explore executables