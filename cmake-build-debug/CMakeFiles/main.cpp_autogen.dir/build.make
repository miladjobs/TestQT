# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/miladjobs/clion-2020.3.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/miladjobs/clion-2020.3.2/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/miladjobs/test2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/miladjobs/test2/cmake-build-debug

# Utility rule file for main.cpp_autogen.

# Include the progress variables for this target.
include CMakeFiles/main.cpp_autogen.dir/progress.make

CMakeFiles/main.cpp_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/miladjobs/test2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target main.cpp"
	/home/miladjobs/clion-2020.3.2/bin/cmake/linux/bin/cmake -E cmake_autogen /home/miladjobs/test2/cmake-build-debug/CMakeFiles/main.cpp_autogen.dir/AutogenInfo.json Debug

main.cpp_autogen: CMakeFiles/main.cpp_autogen
main.cpp_autogen: CMakeFiles/main.cpp_autogen.dir/build.make

.PHONY : main.cpp_autogen

# Rule to build all files generated by this target.
CMakeFiles/main.cpp_autogen.dir/build: main.cpp_autogen

.PHONY : CMakeFiles/main.cpp_autogen.dir/build

CMakeFiles/main.cpp_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.cpp_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.cpp_autogen.dir/clean

CMakeFiles/main.cpp_autogen.dir/depend:
	cd /home/miladjobs/test2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/miladjobs/test2 /home/miladjobs/test2 /home/miladjobs/test2/cmake-build-debug /home/miladjobs/test2/cmake-build-debug /home/miladjobs/test2/cmake-build-debug/CMakeFiles/main.cpp_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.cpp_autogen.dir/depend

