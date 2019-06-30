# CMake generated Testfile for 
# Source directory: /home/grace/Desktop/polarssl_test/mbedtls/tests
# Build directory: /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(debug-suite "test_suite_debug" "--verbose")
add_test(ssl-suite "test_suite_ssl" "--verbose")
add_test(version-suite "test_suite_version" "--verbose")
add_test(x509parse-suite "test_suite_x509parse" "--verbose")
add_test(x509write-suite "test_suite_x509write" "--verbose")
