# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tunay/UPR

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tunay/UPR/build

# Include any dependencies generated for this target.
include CMakeFiles/UPR.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/UPR.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/UPR.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/UPR.dir/flags.make

CMakeFiles/UPR.dir/src/main.c.o: CMakeFiles/UPR.dir/flags.make
CMakeFiles/UPR.dir/src/main.c.o: /home/tunay/UPR/src/main.c
CMakeFiles/UPR.dir/src/main.c.o: CMakeFiles/UPR.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tunay/UPR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/UPR.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/UPR.dir/src/main.c.o -MF CMakeFiles/UPR.dir/src/main.c.o.d -o CMakeFiles/UPR.dir/src/main.c.o -c /home/tunay/UPR/src/main.c

CMakeFiles/UPR.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/UPR.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tunay/UPR/src/main.c > CMakeFiles/UPR.dir/src/main.c.i

CMakeFiles/UPR.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/UPR.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tunay/UPR/src/main.c -o CMakeFiles/UPR.dir/src/main.c.s

# Object files for target UPR
UPR_OBJECTS = \
"CMakeFiles/UPR.dir/src/main.c.o"

# External object files for target UPR
UPR_EXTERNAL_OBJECTS =

/home/tunay/UPR/UPR: CMakeFiles/UPR.dir/src/main.c.o
/home/tunay/UPR/UPR: CMakeFiles/UPR.dir/build.make
/home/tunay/UPR/UPR: libcore.a
/home/tunay/UPR/UPR: CMakeFiles/UPR.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/tunay/UPR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable /home/tunay/UPR/UPR"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/UPR.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/UPR.dir/build: /home/tunay/UPR/UPR
.PHONY : CMakeFiles/UPR.dir/build

CMakeFiles/UPR.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/UPR.dir/cmake_clean.cmake
.PHONY : CMakeFiles/UPR.dir/clean

CMakeFiles/UPR.dir/depend:
	cd /home/tunay/UPR/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tunay/UPR /home/tunay/UPR /home/tunay/UPR/build /home/tunay/UPR/build /home/tunay/UPR/build/CMakeFiles/UPR.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/UPR.dir/depend

