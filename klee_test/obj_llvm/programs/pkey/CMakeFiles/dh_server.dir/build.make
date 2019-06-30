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
include programs/pkey/CMakeFiles/dh_server.dir/depend.make

# Include the progress variables for this target.
include programs/pkey/CMakeFiles/dh_server.dir/progress.make

# Include the compile flags for this target's objects.
include programs/pkey/CMakeFiles/dh_server.dir/flags.make

programs/pkey/CMakeFiles/dh_server.dir/dh_server.c.o: programs/pkey/CMakeFiles/dh_server.dir/flags.make
programs/pkey/CMakeFiles/dh_server.dir/dh_server.c.o: /home/grace/Desktop/polarssl_test/mbedtls/programs/pkey/dh_server.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/grace/Desktop/polarssl_test/klee_test/obj_llvm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object programs/pkey/CMakeFiles/dh_server.dir/dh_server.c.o"
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/programs/pkey && /usr/local/bin/wllvm  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dh_server.dir/dh_server.c.o   -c /home/grace/Desktop/polarssl_test/mbedtls/programs/pkey/dh_server.c

programs/pkey/CMakeFiles/dh_server.dir/dh_server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dh_server.dir/dh_server.c.i"
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/programs/pkey && /usr/local/bin/wllvm  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/grace/Desktop/polarssl_test/mbedtls/programs/pkey/dh_server.c > CMakeFiles/dh_server.dir/dh_server.c.i

programs/pkey/CMakeFiles/dh_server.dir/dh_server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dh_server.dir/dh_server.c.s"
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/programs/pkey && /usr/local/bin/wllvm  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/grace/Desktop/polarssl_test/mbedtls/programs/pkey/dh_server.c -o CMakeFiles/dh_server.dir/dh_server.c.s

programs/pkey/CMakeFiles/dh_server.dir/dh_server.c.o.requires:

.PHONY : programs/pkey/CMakeFiles/dh_server.dir/dh_server.c.o.requires

programs/pkey/CMakeFiles/dh_server.dir/dh_server.c.o.provides: programs/pkey/CMakeFiles/dh_server.dir/dh_server.c.o.requires
	$(MAKE) -f programs/pkey/CMakeFiles/dh_server.dir/build.make programs/pkey/CMakeFiles/dh_server.dir/dh_server.c.o.provides.build
.PHONY : programs/pkey/CMakeFiles/dh_server.dir/dh_server.c.o.provides

programs/pkey/CMakeFiles/dh_server.dir/dh_server.c.o.provides.build: programs/pkey/CMakeFiles/dh_server.dir/dh_server.c.o


# Object files for target dh_server
dh_server_OBJECTS = \
"CMakeFiles/dh_server.dir/dh_server.c.o"

# External object files for target dh_server
dh_server_EXTERNAL_OBJECTS =

programs/pkey/dh_server: programs/pkey/CMakeFiles/dh_server.dir/dh_server.c.o
programs/pkey/dh_server: programs/pkey/CMakeFiles/dh_server.dir/build.make
programs/pkey/dh_server: library/libmbedtls.a
programs/pkey/dh_server: library/libmbedx509.a
programs/pkey/dh_server: crypto/library/libmbedcrypto.a
programs/pkey/dh_server: programs/pkey/CMakeFiles/dh_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/grace/Desktop/polarssl_test/klee_test/obj_llvm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable dh_server"
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/programs/pkey && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dh_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
programs/pkey/CMakeFiles/dh_server.dir/build: programs/pkey/dh_server

.PHONY : programs/pkey/CMakeFiles/dh_server.dir/build

# Object files for target dh_server
dh_server_OBJECTS = \
"CMakeFiles/dh_server.dir/dh_server.c.o"

# External object files for target dh_server
dh_server_EXTERNAL_OBJECTS =

programs/pkey/CMakeFiles/CMakeRelink.dir/dh_server: programs/pkey/CMakeFiles/dh_server.dir/dh_server.c.o
programs/pkey/CMakeFiles/CMakeRelink.dir/dh_server: programs/pkey/CMakeFiles/dh_server.dir/build.make
programs/pkey/CMakeFiles/CMakeRelink.dir/dh_server: library/libmbedtls.a
programs/pkey/CMakeFiles/CMakeRelink.dir/dh_server: library/libmbedx509.a
programs/pkey/CMakeFiles/CMakeRelink.dir/dh_server: crypto/library/libmbedcrypto.a
programs/pkey/CMakeFiles/CMakeRelink.dir/dh_server: programs/pkey/CMakeFiles/dh_server.dir/relink.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/grace/Desktop/polarssl_test/klee_test/obj_llvm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable CMakeFiles/CMakeRelink.dir/dh_server"
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/programs/pkey && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dh_server.dir/relink.txt --verbose=$(VERBOSE)

# Rule to relink during preinstall.
programs/pkey/CMakeFiles/dh_server.dir/preinstall: programs/pkey/CMakeFiles/CMakeRelink.dir/dh_server

.PHONY : programs/pkey/CMakeFiles/dh_server.dir/preinstall

programs/pkey/CMakeFiles/dh_server.dir/requires: programs/pkey/CMakeFiles/dh_server.dir/dh_server.c.o.requires

.PHONY : programs/pkey/CMakeFiles/dh_server.dir/requires

programs/pkey/CMakeFiles/dh_server.dir/clean:
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/programs/pkey && $(CMAKE_COMMAND) -P CMakeFiles/dh_server.dir/cmake_clean.cmake
.PHONY : programs/pkey/CMakeFiles/dh_server.dir/clean

programs/pkey/CMakeFiles/dh_server.dir/depend:
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/grace/Desktop/polarssl_test/mbedtls /home/grace/Desktop/polarssl_test/mbedtls/programs/pkey /home/grace/Desktop/polarssl_test/klee_test/obj_llvm /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/programs/pkey /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/programs/pkey/CMakeFiles/dh_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : programs/pkey/CMakeFiles/dh_server.dir/depend

