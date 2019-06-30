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
include programs/pkey/CMakeFiles/pk_encrypt.dir/depend.make

# Include the progress variables for this target.
include programs/pkey/CMakeFiles/pk_encrypt.dir/progress.make

# Include the compile flags for this target's objects.
include programs/pkey/CMakeFiles/pk_encrypt.dir/flags.make

programs/pkey/CMakeFiles/pk_encrypt.dir/pk_encrypt.c.o: programs/pkey/CMakeFiles/pk_encrypt.dir/flags.make
programs/pkey/CMakeFiles/pk_encrypt.dir/pk_encrypt.c.o: /home/grace/Desktop/polarssl_test/mbedtls/programs/pkey/pk_encrypt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/grace/Desktop/polarssl_test/klee_test/obj_llvm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object programs/pkey/CMakeFiles/pk_encrypt.dir/pk_encrypt.c.o"
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/programs/pkey && /usr/local/bin/wllvm  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/pk_encrypt.dir/pk_encrypt.c.o   -c /home/grace/Desktop/polarssl_test/mbedtls/programs/pkey/pk_encrypt.c

programs/pkey/CMakeFiles/pk_encrypt.dir/pk_encrypt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pk_encrypt.dir/pk_encrypt.c.i"
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/programs/pkey && /usr/local/bin/wllvm  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/grace/Desktop/polarssl_test/mbedtls/programs/pkey/pk_encrypt.c > CMakeFiles/pk_encrypt.dir/pk_encrypt.c.i

programs/pkey/CMakeFiles/pk_encrypt.dir/pk_encrypt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pk_encrypt.dir/pk_encrypt.c.s"
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/programs/pkey && /usr/local/bin/wllvm  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/grace/Desktop/polarssl_test/mbedtls/programs/pkey/pk_encrypt.c -o CMakeFiles/pk_encrypt.dir/pk_encrypt.c.s

programs/pkey/CMakeFiles/pk_encrypt.dir/pk_encrypt.c.o.requires:

.PHONY : programs/pkey/CMakeFiles/pk_encrypt.dir/pk_encrypt.c.o.requires

programs/pkey/CMakeFiles/pk_encrypt.dir/pk_encrypt.c.o.provides: programs/pkey/CMakeFiles/pk_encrypt.dir/pk_encrypt.c.o.requires
	$(MAKE) -f programs/pkey/CMakeFiles/pk_encrypt.dir/build.make programs/pkey/CMakeFiles/pk_encrypt.dir/pk_encrypt.c.o.provides.build
.PHONY : programs/pkey/CMakeFiles/pk_encrypt.dir/pk_encrypt.c.o.provides

programs/pkey/CMakeFiles/pk_encrypt.dir/pk_encrypt.c.o.provides.build: programs/pkey/CMakeFiles/pk_encrypt.dir/pk_encrypt.c.o


# Object files for target pk_encrypt
pk_encrypt_OBJECTS = \
"CMakeFiles/pk_encrypt.dir/pk_encrypt.c.o"

# External object files for target pk_encrypt
pk_encrypt_EXTERNAL_OBJECTS =

programs/pkey/pk_encrypt: programs/pkey/CMakeFiles/pk_encrypt.dir/pk_encrypt.c.o
programs/pkey/pk_encrypt: programs/pkey/CMakeFiles/pk_encrypt.dir/build.make
programs/pkey/pk_encrypt: library/libmbedtls.a
programs/pkey/pk_encrypt: library/libmbedx509.a
programs/pkey/pk_encrypt: crypto/library/libmbedcrypto.a
programs/pkey/pk_encrypt: programs/pkey/CMakeFiles/pk_encrypt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/grace/Desktop/polarssl_test/klee_test/obj_llvm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable pk_encrypt"
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/programs/pkey && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pk_encrypt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
programs/pkey/CMakeFiles/pk_encrypt.dir/build: programs/pkey/pk_encrypt

.PHONY : programs/pkey/CMakeFiles/pk_encrypt.dir/build

# Object files for target pk_encrypt
pk_encrypt_OBJECTS = \
"CMakeFiles/pk_encrypt.dir/pk_encrypt.c.o"

# External object files for target pk_encrypt
pk_encrypt_EXTERNAL_OBJECTS =

programs/pkey/CMakeFiles/CMakeRelink.dir/pk_encrypt: programs/pkey/CMakeFiles/pk_encrypt.dir/pk_encrypt.c.o
programs/pkey/CMakeFiles/CMakeRelink.dir/pk_encrypt: programs/pkey/CMakeFiles/pk_encrypt.dir/build.make
programs/pkey/CMakeFiles/CMakeRelink.dir/pk_encrypt: library/libmbedtls.a
programs/pkey/CMakeFiles/CMakeRelink.dir/pk_encrypt: library/libmbedx509.a
programs/pkey/CMakeFiles/CMakeRelink.dir/pk_encrypt: crypto/library/libmbedcrypto.a
programs/pkey/CMakeFiles/CMakeRelink.dir/pk_encrypt: programs/pkey/CMakeFiles/pk_encrypt.dir/relink.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/grace/Desktop/polarssl_test/klee_test/obj_llvm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable CMakeFiles/CMakeRelink.dir/pk_encrypt"
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/programs/pkey && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pk_encrypt.dir/relink.txt --verbose=$(VERBOSE)

# Rule to relink during preinstall.
programs/pkey/CMakeFiles/pk_encrypt.dir/preinstall: programs/pkey/CMakeFiles/CMakeRelink.dir/pk_encrypt

.PHONY : programs/pkey/CMakeFiles/pk_encrypt.dir/preinstall

programs/pkey/CMakeFiles/pk_encrypt.dir/requires: programs/pkey/CMakeFiles/pk_encrypt.dir/pk_encrypt.c.o.requires

.PHONY : programs/pkey/CMakeFiles/pk_encrypt.dir/requires

programs/pkey/CMakeFiles/pk_encrypt.dir/clean:
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/programs/pkey && $(CMAKE_COMMAND) -P CMakeFiles/pk_encrypt.dir/cmake_clean.cmake
.PHONY : programs/pkey/CMakeFiles/pk_encrypt.dir/clean

programs/pkey/CMakeFiles/pk_encrypt.dir/depend:
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/grace/Desktop/polarssl_test/mbedtls /home/grace/Desktop/polarssl_test/mbedtls/programs/pkey /home/grace/Desktop/polarssl_test/klee_test/obj_llvm /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/programs/pkey /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/programs/pkey/CMakeFiles/pk_encrypt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : programs/pkey/CMakeFiles/pk_encrypt.dir/depend

