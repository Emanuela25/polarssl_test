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
include programs/test/CMakeFiles/benchmark.dir/depend.make

# Include the progress variables for this target.
include programs/test/CMakeFiles/benchmark.dir/progress.make

# Include the compile flags for this target's objects.
include programs/test/CMakeFiles/benchmark.dir/flags.make

programs/test/CMakeFiles/benchmark.dir/benchmark.c.o: programs/test/CMakeFiles/benchmark.dir/flags.make
programs/test/CMakeFiles/benchmark.dir/benchmark.c.o: /home/grace/Desktop/polarssl_test/mbedtls/programs/test/benchmark.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/grace/Desktop/polarssl_test/klee_test/obj_llvm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object programs/test/CMakeFiles/benchmark.dir/benchmark.c.o"
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/programs/test && /usr/local/bin/wllvm  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/benchmark.dir/benchmark.c.o   -c /home/grace/Desktop/polarssl_test/mbedtls/programs/test/benchmark.c

programs/test/CMakeFiles/benchmark.dir/benchmark.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/benchmark.dir/benchmark.c.i"
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/programs/test && /usr/local/bin/wllvm  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/grace/Desktop/polarssl_test/mbedtls/programs/test/benchmark.c > CMakeFiles/benchmark.dir/benchmark.c.i

programs/test/CMakeFiles/benchmark.dir/benchmark.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/benchmark.dir/benchmark.c.s"
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/programs/test && /usr/local/bin/wllvm  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/grace/Desktop/polarssl_test/mbedtls/programs/test/benchmark.c -o CMakeFiles/benchmark.dir/benchmark.c.s

programs/test/CMakeFiles/benchmark.dir/benchmark.c.o.requires:

.PHONY : programs/test/CMakeFiles/benchmark.dir/benchmark.c.o.requires

programs/test/CMakeFiles/benchmark.dir/benchmark.c.o.provides: programs/test/CMakeFiles/benchmark.dir/benchmark.c.o.requires
	$(MAKE) -f programs/test/CMakeFiles/benchmark.dir/build.make programs/test/CMakeFiles/benchmark.dir/benchmark.c.o.provides.build
.PHONY : programs/test/CMakeFiles/benchmark.dir/benchmark.c.o.provides

programs/test/CMakeFiles/benchmark.dir/benchmark.c.o.provides.build: programs/test/CMakeFiles/benchmark.dir/benchmark.c.o


# Object files for target benchmark
benchmark_OBJECTS = \
"CMakeFiles/benchmark.dir/benchmark.c.o"

# External object files for target benchmark
benchmark_EXTERNAL_OBJECTS =

programs/test/benchmark: programs/test/CMakeFiles/benchmark.dir/benchmark.c.o
programs/test/benchmark: programs/test/CMakeFiles/benchmark.dir/build.make
programs/test/benchmark: library/libmbedtls.a
programs/test/benchmark: library/libmbedx509.a
programs/test/benchmark: crypto/library/libmbedcrypto.a
programs/test/benchmark: programs/test/CMakeFiles/benchmark.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/grace/Desktop/polarssl_test/klee_test/obj_llvm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable benchmark"
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/programs/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/benchmark.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
programs/test/CMakeFiles/benchmark.dir/build: programs/test/benchmark

.PHONY : programs/test/CMakeFiles/benchmark.dir/build

# Object files for target benchmark
benchmark_OBJECTS = \
"CMakeFiles/benchmark.dir/benchmark.c.o"

# External object files for target benchmark
benchmark_EXTERNAL_OBJECTS =

programs/test/CMakeFiles/CMakeRelink.dir/benchmark: programs/test/CMakeFiles/benchmark.dir/benchmark.c.o
programs/test/CMakeFiles/CMakeRelink.dir/benchmark: programs/test/CMakeFiles/benchmark.dir/build.make
programs/test/CMakeFiles/CMakeRelink.dir/benchmark: library/libmbedtls.a
programs/test/CMakeFiles/CMakeRelink.dir/benchmark: library/libmbedx509.a
programs/test/CMakeFiles/CMakeRelink.dir/benchmark: crypto/library/libmbedcrypto.a
programs/test/CMakeFiles/CMakeRelink.dir/benchmark: programs/test/CMakeFiles/benchmark.dir/relink.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/grace/Desktop/polarssl_test/klee_test/obj_llvm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable CMakeFiles/CMakeRelink.dir/benchmark"
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/programs/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/benchmark.dir/relink.txt --verbose=$(VERBOSE)

# Rule to relink during preinstall.
programs/test/CMakeFiles/benchmark.dir/preinstall: programs/test/CMakeFiles/CMakeRelink.dir/benchmark

.PHONY : programs/test/CMakeFiles/benchmark.dir/preinstall

programs/test/CMakeFiles/benchmark.dir/requires: programs/test/CMakeFiles/benchmark.dir/benchmark.c.o.requires

.PHONY : programs/test/CMakeFiles/benchmark.dir/requires

programs/test/CMakeFiles/benchmark.dir/clean:
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/programs/test && $(CMAKE_COMMAND) -P CMakeFiles/benchmark.dir/cmake_clean.cmake
.PHONY : programs/test/CMakeFiles/benchmark.dir/clean

programs/test/CMakeFiles/benchmark.dir/depend:
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/grace/Desktop/polarssl_test/mbedtls /home/grace/Desktop/polarssl_test/mbedtls/programs/test /home/grace/Desktop/polarssl_test/klee_test/obj_llvm /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/programs/test /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/programs/test/CMakeFiles/benchmark.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : programs/test/CMakeFiles/benchmark.dir/depend

