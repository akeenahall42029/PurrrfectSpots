# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Users/summerfaliero/Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake

# The command to remove a file.
RM = /Users/summerfaliero/Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/summerfaliero/coral/PurrrfectSpots

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/summerfaliero/coral/PurrrfectSpots/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PurrrfectSpots.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/PurrrfectSpots.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/PurrrfectSpots.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PurrrfectSpots.dir/flags.make

CMakeFiles/PurrrfectSpots.dir/main.cpp.o: CMakeFiles/PurrrfectSpots.dir/flags.make
CMakeFiles/PurrrfectSpots.dir/main.cpp.o: /Users/summerfaliero/coral/PurrrfectSpots/main.cpp
CMakeFiles/PurrrfectSpots.dir/main.cpp.o: CMakeFiles/PurrrfectSpots.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/summerfaliero/coral/PurrrfectSpots/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PurrrfectSpots.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PurrrfectSpots.dir/main.cpp.o -MF CMakeFiles/PurrrfectSpots.dir/main.cpp.o.d -o CMakeFiles/PurrrfectSpots.dir/main.cpp.o -c /Users/summerfaliero/coral/PurrrfectSpots/main.cpp

CMakeFiles/PurrrfectSpots.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/PurrrfectSpots.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/summerfaliero/coral/PurrrfectSpots/main.cpp > CMakeFiles/PurrrfectSpots.dir/main.cpp.i

CMakeFiles/PurrrfectSpots.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/PurrrfectSpots.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/summerfaliero/coral/PurrrfectSpots/main.cpp -o CMakeFiles/PurrrfectSpots.dir/main.cpp.s

CMakeFiles/PurrrfectSpots.dir/Demo.cpp.o: CMakeFiles/PurrrfectSpots.dir/flags.make
CMakeFiles/PurrrfectSpots.dir/Demo.cpp.o: /Users/summerfaliero/coral/PurrrfectSpots/Demo.cpp
CMakeFiles/PurrrfectSpots.dir/Demo.cpp.o: CMakeFiles/PurrrfectSpots.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/summerfaliero/coral/PurrrfectSpots/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PurrrfectSpots.dir/Demo.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PurrrfectSpots.dir/Demo.cpp.o -MF CMakeFiles/PurrrfectSpots.dir/Demo.cpp.o.d -o CMakeFiles/PurrrfectSpots.dir/Demo.cpp.o -c /Users/summerfaliero/coral/PurrrfectSpots/Demo.cpp

CMakeFiles/PurrrfectSpots.dir/Demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/PurrrfectSpots.dir/Demo.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/summerfaliero/coral/PurrrfectSpots/Demo.cpp > CMakeFiles/PurrrfectSpots.dir/Demo.cpp.i

CMakeFiles/PurrrfectSpots.dir/Demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/PurrrfectSpots.dir/Demo.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/summerfaliero/coral/PurrrfectSpots/Demo.cpp -o CMakeFiles/PurrrfectSpots.dir/Demo.cpp.s

# Object files for target PurrrfectSpots
PurrrfectSpots_OBJECTS = \
"CMakeFiles/PurrrfectSpots.dir/main.cpp.o" \
"CMakeFiles/PurrrfectSpots.dir/Demo.cpp.o"

# External object files for target PurrrfectSpots
PurrrfectSpots_EXTERNAL_OBJECTS =

PurrrfectSpots: CMakeFiles/PurrrfectSpots.dir/main.cpp.o
PurrrfectSpots: CMakeFiles/PurrrfectSpots.dir/Demo.cpp.o
PurrrfectSpots: CMakeFiles/PurrrfectSpots.dir/build.make
PurrrfectSpots: CMakeFiles/PurrrfectSpots.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/summerfaliero/coral/PurrrfectSpots/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable PurrrfectSpots"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PurrrfectSpots.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PurrrfectSpots.dir/build: PurrrfectSpots
.PHONY : CMakeFiles/PurrrfectSpots.dir/build

CMakeFiles/PurrrfectSpots.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PurrrfectSpots.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PurrrfectSpots.dir/clean

CMakeFiles/PurrrfectSpots.dir/depend:
	cd /Users/summerfaliero/coral/PurrrfectSpots/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/summerfaliero/coral/PurrrfectSpots /Users/summerfaliero/coral/PurrrfectSpots /Users/summerfaliero/coral/PurrrfectSpots/cmake-build-debug /Users/summerfaliero/coral/PurrrfectSpots/cmake-build-debug /Users/summerfaliero/coral/PurrrfectSpots/cmake-build-debug/CMakeFiles/PurrrfectSpots.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/PurrrfectSpots.dir/depend

