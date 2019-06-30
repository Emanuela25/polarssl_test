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
CMAKE_BINARY_DIR = /home/grace/Desktop/polarssl_test/klee_test/obj_gcov

# Include any dependencies generated for this target.
include programs/ssl/CMakeFiles/ssl_server.dir/depend.make

# Include the progress variables for this target.
include programs/ssl/CMakeFiles/ssl_server.dir/progress.make

# Include the compile flags for this target's objects.
include programs/ssl/CMakeFiles/ssl_server.dir/flags.make

programs/ssl/CMakeFiles/ssl_server.dir/ssl_server.c.o: programs/ssl/CMakeFiles/ssl_server.dir/flags.make
programs/ssl/CMakeFiles/ssl_server.dir/ssl_server.c.o: /home/grace/Desktop/polarssl_test/mbedtls/programs/ssl/ssl_server.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/grace/Desktop/polarssl_test/klee_test/obj_gcov/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object programs/ssl/CMakeFiles/ssl_server.dir/ssl_server.c.o"
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_gcov/programs/ssl && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ssl_server.dir/ssl_server.c.o   -c /home/grace/Desktop/polarssl_test/mbedtls/programs/ssl/ssl_server.c

programs/ssl/CMakeFiles/ssl_server.dir/ssl_server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ssl_server.dir/ssl_server.c.i"
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_gcov/programs/ssl && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/grace/Desktop/polarssl_test/mbedtls/programs/ssl/ssl_server.c > CMakeFiles/ssl_server.dir/ssl_server.c.i

programs/ssl/CMakeFiles/ssl_server.dir/ssl_server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ssl_server.dir/ssl_server.c.s"
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_gcov/programs/ssl && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/grace/Desktop/polarssl_test/mbedtls/programs/ssl/ssl_server.c -o CMakeFiles/ssl_server.dir/ssl_server.c.s

programs/ssl/CMakeFiles/ssl_server.dir/ssl_server.c.o.requires:

.PHONY : programs/ssl/CMakeFiles/ssl_server.dir/ssl_server.c.o.requires

programs/ssl/CMakeFiles/ssl_server.dir/ssl_server.c.o.provides: programs/ssl/CMakeFiles/ssl_server.dir/ssl_server.c.o.requires
	$(MAKE) -f programs/ssl/CMakeFiles/ssl_server.dir/build.make programs/ssl/CMakeFiles/ssl_server.dir/ssl_server.c.o.provides.build
.PHONY : programs/ssl/CMakeFiles/ssl_server.dir/ssl_server.c.o.provides

programs/ssl/CMakeFiles/ssl_server.dir/ssl_server.c.o.provides.build: programs/ssl/CMakeFiles/ssl_server.dir/ssl_server.c.o


# Object files for target ssl_server
ssl_server_OBJECTS = \
"CMakeFiles/ssl_server.dir/ssl_server.c.o"

# External object files for target ssl_server
ssl_server_EXTERNAL_OBJECTS =

programs/ssl/ssl_server: programs/ssl/CMakeFiles/ssl_server.dir/ssl_server.c.o
programs/ssl/ssl_server: programs/ssl/CMakeFiles/ssl_server.dir/build.make
programs/ssl/ssl_server: library/libmbedtls.a
programs/ssl/ssl_server: library/libmbedx509.a
programs/ssl/ssl_server: crypto/library/libmbedcrypto.a
programs/ssl/ssl_server: programs/ssl/CMakeFiles/ssl_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/grace/Desktop/polarssl_test/klee_test/obj_gcov/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ssl_server"
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_gcov/programs/ssl && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ssl_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
programs/ssl/CMakeFiles/ssl_server.dir/build: programs/ssl/ssl_server

.PHONY : programs/ssl/CMakeFiles/ssl_server.dir/build

programs/ssl/CMakeFiles/ssl_server.dir/requires: programs/ssl/CMakeFiles/ssl_server.dir/ssl_server.c.o.requires

.PHONY : programs/ssl/CMakeFiles/ssl_server.dir/requires

programs/ssl/CMakeFiles/ssl_server.dir/clean:
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_gcov/programs/ssl && $(CMAKE_COMMAND) -P CMakeFiles/ssl_server.dir/cmake_clean.cmake
.PHONY : programs/ssl/CMakeFiles/ssl_server.dir/clean

programs/ssl/CMakeFiles/ssl_server.dir/depend:
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_gcov && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/grace/Desktop/polarssl_test/mbedtls /home/grace/Desktop/polarssl_test/mbedtls/programs/ssl /home/grace/Desktop/polarssl_test/klee_test/obj_gcov /home/grace/Desktop/polarssl_test/klee_test/obj_gcov/programs/ssl /home/grace/Desktop/polarssl_test/klee_test/obj_gcov/programs/ssl/CMakeFiles/ssl_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : programs/ssl/CMakeFiles/ssl_server.dir/depend
