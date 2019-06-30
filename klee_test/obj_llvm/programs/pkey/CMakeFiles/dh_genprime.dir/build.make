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
include programs/pkey/CMakeFiles/dh_genprime.dir/depend.make

# Include the progress variables for this target.
include programs/pkey/CMakeFiles/dh_genprime.dir/progress.make

# Include the compile flags for this target's objects.
include programs/pkey/CMakeFiles/dh_genprime.dir/flags.make

programs/pkey/CMakeFiles/dh_genprime.dir/dh_genprime.c.o: programs/pkey/CMakeFiles/dh_genprime.dir/flags.make
programs/pkey/CMakeFiles/dh_genprime.dir/dh_genprime.c.o: /home/grace/Desktop/polarssl_test/mbedtls/programs/pkey/dh_genprime.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/grace/Desktop/polarssl_test/klee_test/obj_llvm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object programs/pkey/CMakeFiles/dh_genprime.dir/dh_genprime.c.o"
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/programs/pkey && /usr/local/bin/wllvm  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dh_genprime.dir/dh_genprime.c.o   -c /home/grace/Desktop/polarssl_test/mbedtls/programs/pkey/dh_genprime.c

programs/pkey/CMakeFiles/dh_genprime.dir/dh_genprime.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dh_genprime.dir/dh_genprime.c.i"
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/programs/pkey && /usr/local/bin/wllvm  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/grace/Desktop/polarssl_test/mbedtls/programs/pkey/dh_genprime.c > CMakeFiles/dh_genprime.dir/dh_genprime.c.i

programs/pkey/CMakeFiles/dh_genprime.dir/dh_genprime.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dh_genprime.dir/dh_genprime.c.s"
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/programs/pkey && /usr/local/bin/wllvm  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/grace/Desktop/polarssl_test/mbedtls/programs/pkey/dh_genprime.c -o CMakeFiles/dh_genprime.dir/dh_genprime.c.s

programs/pkey/CMakeFiles/dh_genprime.dir/dh_genprime.c.o.requires:

.PHONY : programs/pkey/CMakeFiles/dh_genprime.dir/dh_genprime.c.o.requires

programs/pkey/CMakeFiles/dh_genprime.dir/dh_genprime.c.o.provides: programs/pkey/CMakeFiles/dh_genprime.dir/dh_genprime.c.o.requires
	$(MAKE) -f programs/pkey/CMakeFiles/dh_genprime.dir/build.make programs/pkey/CMakeFiles/dh_genprime.dir/dh_genprime.c.o.provides.build
.PHONY : programs/pkey/CMakeFiles/dh_genprime.dir/dh_genprime.c.o.provides

programs/pkey/CMakeFiles/dh_genprime.dir/dh_genprime.c.o.provides.build: programs/pkey/CMakeFiles/dh_genprime.dir/dh_genprime.c.o


# Object files for target dh_genprime
dh_genprime_OBJECTS = \
"CMakeFiles/dh_genprime.dir/dh_genprime.c.o"

# External object files for target dh_genprime
dh_genprime_EXTERNAL_OBJECTS =

programs/pkey/dh_genprime: programs/pkey/CMakeFiles/dh_genprime.dir/dh_genprime.c.o
programs/pkey/dh_genprime: programs/pkey/CMakeFiles/dh_genprime.dir/build.make
programs/pkey/dh_genprime: library/libmbedtls.a
programs/pkey/dh_genprime: library/libmbedx509.a
programs/pkey/dh_genprime: crypto/library/libmbedcrypto.a
programs/pkey/dh_genprime: programs/pkey/CMakeFiles/dh_genprime.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/grace/Desktop/polarssl_test/klee_test/obj_llvm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable dh_genprime"
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/programs/pkey && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dh_genprime.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
programs/pkey/CMakeFiles/dh_genprime.dir/build: programs/pkey/dh_genprime

.PHONY : programs/pkey/CMakeFiles/dh_genprime.dir/build

# Object files for target dh_genprime
dh_genprime_OBJECTS = \
"CMakeFiles/dh_genprime.dir/dh_genprime.c.o"

# External object files for target dh_genprime
dh_genprime_EXTERNAL_OBJECTS =

programs/pkey/CMakeFiles/CMakeRelink.dir/dh_genprime: programs/pkey/CMakeFiles/dh_genprime.dir/dh_genprime.c.o
programs/pkey/CMakeFiles/CMakeRelink.dir/dh_genprime: programs/pkey/CMakeFiles/dh_genprime.dir/build.make
programs/pkey/CMakeFiles/CMakeRelink.dir/dh_genprime: library/libmbedtls.a
programs/pkey/CMakeFiles/CMakeRelink.dir/dh_genprime: library/libmbedx509.a
programs/pkey/CMakeFiles/CMakeRelink.dir/dh_genprime: crypto/library/libmbedcrypto.a
programs/pkey/CMakeFiles/CMakeRelink.dir/dh_genprime: programs/pkey/CMakeFiles/dh_genprime.dir/relink.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/grace/Desktop/polarssl_test/klee_test/obj_llvm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable CMakeFiles/CMakeRelink.dir/dh_genprime"
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/programs/pkey && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dh_genprime.dir/relink.txt --verbose=$(VERBOSE)

# Rule to relink during preinstall.
programs/pkey/CMakeFiles/dh_genprime.dir/preinstall: programs/pkey/CMakeFiles/CMakeRelink.dir/dh_genprime

.PHONY : programs/pkey/CMakeFiles/dh_genprime.dir/preinstall

programs/pkey/CMakeFiles/dh_genprime.dir/requires: programs/pkey/CMakeFiles/dh_genprime.dir/dh_genprime.c.o.requires

.PHONY : programs/pkey/CMakeFiles/dh_genprime.dir/requires

programs/pkey/CMakeFiles/dh_genprime.dir/clean:
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/programs/pkey && $(CMAKE_COMMAND) -P CMakeFiles/dh_genprime.dir/cmake_clean.cmake
.PHONY : programs/pkey/CMakeFiles/dh_genprime.dir/clean

programs/pkey/CMakeFiles/dh_genprime.dir/depend:
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/grace/Desktop/polarssl_test/mbedtls /home/grace/Desktop/polarssl_test/mbedtls/programs/pkey /home/grace/Desktop/polarssl_test/klee_test/obj_llvm /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/programs/pkey /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/programs/pkey/CMakeFiles/dh_genprime.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : programs/pkey/CMakeFiles/dh_genprime.dir/depend

