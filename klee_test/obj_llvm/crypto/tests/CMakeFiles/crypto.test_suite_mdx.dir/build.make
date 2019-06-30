# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/grace/Desktop/polarssl_test/mbedtls

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/grace/Desktop/polarssl_test/klee_test/obj_llvm

# Include any dependencies generated for this target.
include crypto/tests/CMakeFiles/crypto.test_suite_mdx.dir/depend.make

# Include the progress variables for this target.
include crypto/tests/CMakeFiles/crypto.test_suite_mdx.dir/progress.make

# Include the compile flags for this target's objects.
include crypto/tests/CMakeFiles/crypto.test_suite_mdx.dir/flags.make

crypto/tests/test_suite_mdx.c: /home/grace/Desktop/polarssl_test/mbedtls/crypto/tests/scripts/generate_test_code.py
crypto/tests/test_suite_mdx.c: crypto/library/libmbedcrypto.a
crypto/tests/test_suite_mdx.c: /home/grace/Desktop/polarssl_test/mbedtls/crypto/tests/suites/helpers.function
crypto/tests/test_suite_mdx.c: /home/grace/Desktop/polarssl_test/mbedtls/crypto/tests/suites/main_test.function
crypto/tests/test_suite_mdx.c: /home/grace/Desktop/polarssl_test/mbedtls/crypto/tests/suites/host_test.function
crypto/tests/test_suite_mdx.c: /home/grace/Desktop/polarssl_test/mbedtls/crypto/tests/suites/test_suite_mdx.function
crypto/tests/test_suite_mdx.c: /home/grace/Desktop/polarssl_test/mbedtls/crypto/tests/suites/test_suite_mdx.data
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/grace/Desktop/polarssl_test/klee_test/obj_llvm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating test_suite_mdx.c"
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/crypto/tests && /usr/bin/python /home/grace/Desktop/polarssl_test/mbedtls/crypto/tests/scripts/generate_test_code.py -f /home/grace/Desktop/polarssl_test/mbedtls/crypto/tests/suites/test_suite_mdx.function -d /home/grace/Desktop/polarssl_test/mbedtls/crypto/tests/suites/test_suite_mdx.data -t /home/grace/Desktop/polarssl_test/mbedtls/crypto/tests/suites/main_test.function -p /home/grace/Desktop/polarssl_test/mbedtls/crypto/tests/suites/host_test.function -s /home/grace/Desktop/polarssl_test/mbedtls/crypto/tests/suites --helpers-file /home/grace/Desktop/polarssl_test/mbedtls/crypto/tests/suites/helpers.function -o .

crypto/tests/CMakeFiles/crypto.test_suite_mdx.dir/test_suite_mdx.c.o: crypto/tests/CMakeFiles/crypto.test_suite_mdx.dir/flags.make
crypto/tests/CMakeFiles/crypto.test_suite_mdx.dir/test_suite_mdx.c.o: crypto/tests/test_suite_mdx.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/grace/Desktop/polarssl_test/klee_test/obj_llvm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object crypto/tests/CMakeFiles/crypto.test_suite_mdx.dir/test_suite_mdx.c.o"
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/crypto/tests && /usr/local/bin/wllvm  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/crypto.test_suite_mdx.dir/test_suite_mdx.c.o   -c /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/crypto/tests/test_suite_mdx.c

crypto/tests/CMakeFiles/crypto.test_suite_mdx.dir/test_suite_mdx.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/crypto.test_suite_mdx.dir/test_suite_mdx.c.i"
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/crypto/tests && /usr/local/bin/wllvm  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/crypto/tests/test_suite_mdx.c > CMakeFiles/crypto.test_suite_mdx.dir/test_suite_mdx.c.i

crypto/tests/CMakeFiles/crypto.test_suite_mdx.dir/test_suite_mdx.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/crypto.test_suite_mdx.dir/test_suite_mdx.c.s"
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/crypto/tests && /usr/local/bin/wllvm  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/crypto/tests/test_suite_mdx.c -o CMakeFiles/crypto.test_suite_mdx.dir/test_suite_mdx.c.s

crypto/tests/CMakeFiles/crypto.test_suite_mdx.dir/test_suite_mdx.c.o.requires:

.PHONY : crypto/tests/CMakeFiles/crypto.test_suite_mdx.dir/test_suite_mdx.c.o.requires

crypto/tests/CMakeFiles/crypto.test_suite_mdx.dir/test_suite_mdx.c.o.provides: crypto/tests/CMakeFiles/crypto.test_suite_mdx.dir/test_suite_mdx.c.o.requires
	$(MAKE) -f crypto/tests/CMakeFiles/crypto.test_suite_mdx.dir/build.make crypto/tests/CMakeFiles/crypto.test_suite_mdx.dir/test_suite_mdx.c.o.provides.build
.PHONY : crypto/tests/CMakeFiles/crypto.test_suite_mdx.dir/test_suite_mdx.c.o.provides

crypto/tests/CMakeFiles/crypto.test_suite_mdx.dir/test_suite_mdx.c.o.provides.build: crypto/tests/CMakeFiles/crypto.test_suite_mdx.dir/test_suite_mdx.c.o


# Object files for target crypto.test_suite_mdx
crypto_test_suite_mdx_OBJECTS = \
"CMakeFiles/crypto.test_suite_mdx.dir/test_suite_mdx.c.o"

# External object files for target crypto.test_suite_mdx
crypto_test_suite_mdx_EXTERNAL_OBJECTS =

crypto/tests/crypto.test_suite_mdx: crypto/tests/CMakeFiles/crypto.test_suite_mdx.dir/test_suite_mdx.c.o
crypto/tests/crypto.test_suite_mdx: crypto/tests/CMakeFiles/crypto.test_suite_mdx.dir/build.make
crypto/tests/crypto.test_suite_mdx: crypto/library/libmbedcrypto.a
crypto/tests/crypto.test_suite_mdx: crypto/tests/CMakeFiles/crypto.test_suite_mdx.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/grace/Desktop/polarssl_test/klee_test/obj_llvm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable crypto.test_suite_mdx"
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/crypto/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/crypto.test_suite_mdx.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
crypto/tests/CMakeFiles/crypto.test_suite_mdx.dir/build: crypto/tests/crypto.test_suite_mdx

.PHONY : crypto/tests/CMakeFiles/crypto.test_suite_mdx.dir/build

crypto/tests/CMakeFiles/crypto.test_suite_mdx.dir/requires: crypto/tests/CMakeFiles/crypto.test_suite_mdx.dir/test_suite_mdx.c.o.requires

.PHONY : crypto/tests/CMakeFiles/crypto.test_suite_mdx.dir/requires

crypto/tests/CMakeFiles/crypto.test_suite_mdx.dir/clean:
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/crypto/tests && $(CMAKE_COMMAND) -P CMakeFiles/crypto.test_suite_mdx.dir/cmake_clean.cmake
.PHONY : crypto/tests/CMakeFiles/crypto.test_suite_mdx.dir/clean

crypto/tests/CMakeFiles/crypto.test_suite_mdx.dir/depend: crypto/tests/test_suite_mdx.c
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/grace/Desktop/polarssl_test/mbedtls /home/grace/Desktop/polarssl_test/mbedtls/crypto/tests /home/grace/Desktop/polarssl_test/klee_test/obj_llvm /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/crypto/tests /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/crypto/tests/CMakeFiles/crypto.test_suite_mdx.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : crypto/tests/CMakeFiles/crypto.test_suite_mdx.dir/depend

