# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /opt/local/bin/cmake

# The command to remove a file.
RM = /opt/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/fmt-4.0.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib

# Include any dependencies generated for this target.
include test/CMakeFiles/header-only-test.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/header-only-test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/header-only-test.dir/flags.make

test/CMakeFiles/header-only-test.dir/header-only-test.cc.o: test/CMakeFiles/header-only-test.dir/flags.make
test/CMakeFiles/header-only-test.dir/header-only-test.cc.o: fmt-4.0.0/test/header-only-test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/header-only-test.dir/header-only-test.cc.o"
	cd /Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/header-only-test.dir/header-only-test.cc.o -c /Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/fmt-4.0.0/test/header-only-test.cc

test/CMakeFiles/header-only-test.dir/header-only-test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/header-only-test.dir/header-only-test.cc.i"
	cd /Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/fmt-4.0.0/test/header-only-test.cc > CMakeFiles/header-only-test.dir/header-only-test.cc.i

test/CMakeFiles/header-only-test.dir/header-only-test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/header-only-test.dir/header-only-test.cc.s"
	cd /Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/fmt-4.0.0/test/header-only-test.cc -o CMakeFiles/header-only-test.dir/header-only-test.cc.s

test/CMakeFiles/header-only-test.dir/header-only-test.cc.o.requires:

.PHONY : test/CMakeFiles/header-only-test.dir/header-only-test.cc.o.requires

test/CMakeFiles/header-only-test.dir/header-only-test.cc.o.provides: test/CMakeFiles/header-only-test.dir/header-only-test.cc.o.requires
	$(MAKE) -f test/CMakeFiles/header-only-test.dir/build.make test/CMakeFiles/header-only-test.dir/header-only-test.cc.o.provides.build
.PHONY : test/CMakeFiles/header-only-test.dir/header-only-test.cc.o.provides

test/CMakeFiles/header-only-test.dir/header-only-test.cc.o.provides.build: test/CMakeFiles/header-only-test.dir/header-only-test.cc.o


test/CMakeFiles/header-only-test.dir/header-only-test2.cc.o: test/CMakeFiles/header-only-test.dir/flags.make
test/CMakeFiles/header-only-test.dir/header-only-test2.cc.o: fmt-4.0.0/test/header-only-test2.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/header-only-test.dir/header-only-test2.cc.o"
	cd /Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/header-only-test.dir/header-only-test2.cc.o -c /Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/fmt-4.0.0/test/header-only-test2.cc

test/CMakeFiles/header-only-test.dir/header-only-test2.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/header-only-test.dir/header-only-test2.cc.i"
	cd /Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/fmt-4.0.0/test/header-only-test2.cc > CMakeFiles/header-only-test.dir/header-only-test2.cc.i

test/CMakeFiles/header-only-test.dir/header-only-test2.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/header-only-test.dir/header-only-test2.cc.s"
	cd /Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/fmt-4.0.0/test/header-only-test2.cc -o CMakeFiles/header-only-test.dir/header-only-test2.cc.s

test/CMakeFiles/header-only-test.dir/header-only-test2.cc.o.requires:

.PHONY : test/CMakeFiles/header-only-test.dir/header-only-test2.cc.o.requires

test/CMakeFiles/header-only-test.dir/header-only-test2.cc.o.provides: test/CMakeFiles/header-only-test.dir/header-only-test2.cc.o.requires
	$(MAKE) -f test/CMakeFiles/header-only-test.dir/build.make test/CMakeFiles/header-only-test.dir/header-only-test2.cc.o.provides.build
.PHONY : test/CMakeFiles/header-only-test.dir/header-only-test2.cc.o.provides

test/CMakeFiles/header-only-test.dir/header-only-test2.cc.o.provides.build: test/CMakeFiles/header-only-test.dir/header-only-test2.cc.o


test/CMakeFiles/header-only-test.dir/test-main.cc.o: test/CMakeFiles/header-only-test.dir/flags.make
test/CMakeFiles/header-only-test.dir/test-main.cc.o: fmt-4.0.0/test/test-main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object test/CMakeFiles/header-only-test.dir/test-main.cc.o"
	cd /Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/header-only-test.dir/test-main.cc.o -c /Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/fmt-4.0.0/test/test-main.cc

test/CMakeFiles/header-only-test.dir/test-main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/header-only-test.dir/test-main.cc.i"
	cd /Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/fmt-4.0.0/test/test-main.cc > CMakeFiles/header-only-test.dir/test-main.cc.i

test/CMakeFiles/header-only-test.dir/test-main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/header-only-test.dir/test-main.cc.s"
	cd /Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/fmt-4.0.0/test/test-main.cc -o CMakeFiles/header-only-test.dir/test-main.cc.s

test/CMakeFiles/header-only-test.dir/test-main.cc.o.requires:

.PHONY : test/CMakeFiles/header-only-test.dir/test-main.cc.o.requires

test/CMakeFiles/header-only-test.dir/test-main.cc.o.provides: test/CMakeFiles/header-only-test.dir/test-main.cc.o.requires
	$(MAKE) -f test/CMakeFiles/header-only-test.dir/build.make test/CMakeFiles/header-only-test.dir/test-main.cc.o.provides.build
.PHONY : test/CMakeFiles/header-only-test.dir/test-main.cc.o.provides

test/CMakeFiles/header-only-test.dir/test-main.cc.o.provides.build: test/CMakeFiles/header-only-test.dir/test-main.cc.o


# Object files for target header-only-test
header__only__test_OBJECTS = \
"CMakeFiles/header-only-test.dir/header-only-test.cc.o" \
"CMakeFiles/header-only-test.dir/header-only-test2.cc.o" \
"CMakeFiles/header-only-test.dir/test-main.cc.o"

# External object files for target header-only-test
header__only__test_EXTERNAL_OBJECTS =

bin/header-only-test: test/CMakeFiles/header-only-test.dir/header-only-test.cc.o
bin/header-only-test: test/CMakeFiles/header-only-test.dir/header-only-test2.cc.o
bin/header-only-test: test/CMakeFiles/header-only-test.dir/test-main.cc.o
bin/header-only-test: test/CMakeFiles/header-only-test.dir/build.make
bin/header-only-test: test/libgmock.a
bin/header-only-test: test/CMakeFiles/header-only-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../bin/header-only-test"
	cd /Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/header-only-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/header-only-test.dir/build: bin/header-only-test

.PHONY : test/CMakeFiles/header-only-test.dir/build

test/CMakeFiles/header-only-test.dir/requires: test/CMakeFiles/header-only-test.dir/header-only-test.cc.o.requires
test/CMakeFiles/header-only-test.dir/requires: test/CMakeFiles/header-only-test.dir/header-only-test2.cc.o.requires
test/CMakeFiles/header-only-test.dir/requires: test/CMakeFiles/header-only-test.dir/test-main.cc.o.requires

.PHONY : test/CMakeFiles/header-only-test.dir/requires

test/CMakeFiles/header-only-test.dir/clean:
	cd /Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/test && $(CMAKE_COMMAND) -P CMakeFiles/header-only-test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/header-only-test.dir/clean

test/CMakeFiles/header-only-test.dir/depend:
	cd /Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/fmt-4.0.0 /Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/fmt-4.0.0/test /Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib /Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/test /Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/test/CMakeFiles/header-only-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/header-only-test.dir/depend

