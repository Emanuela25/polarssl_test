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

# Utility rule file for apidoc.

# Include the progress variables for this target.
include CMakeFiles/apidoc.dir/progress.make

CMakeFiles/apidoc:
	cd /home/grace/Desktop/polarssl_test/mbedtls/doxygen && doxygen mbedtls.doxyfile

apidoc: CMakeFiles/apidoc
apidoc: CMakeFiles/apidoc.dir/build.make

.PHONY : apidoc

# Rule to build all files generated by this target.
CMakeFiles/apidoc.dir/build: apidoc

.PHONY : CMakeFiles/apidoc.dir/build

CMakeFiles/apidoc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/apidoc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/apidoc.dir/clean

CMakeFiles/apidoc.dir/depend:
	cd /home/grace/Desktop/polarssl_test/klee_test/obj_llvm && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/grace/Desktop/polarssl_test/mbedtls /home/grace/Desktop/polarssl_test/mbedtls /home/grace/Desktop/polarssl_test/klee_test/obj_llvm /home/grace/Desktop/polarssl_test/klee_test/obj_llvm /home/grace/Desktop/polarssl_test/klee_test/obj_llvm/CMakeFiles/apidoc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/apidoc.dir/depend

