# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /home/zyd/.local/lib/python3.8/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/zyd/.local/lib/python3.8/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zyd/wksp/test/CnS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zyd/wksp/test/CnS/build

# Include any dependencies generated for this target.
include CMakeFiles/tcpMultiserver.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tcpMultiserver.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tcpMultiserver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tcpMultiserver.dir/flags.make

CMakeFiles/tcpMultiserver.dir/tcpMulti-server.cpp.o: CMakeFiles/tcpMultiserver.dir/flags.make
CMakeFiles/tcpMultiserver.dir/tcpMulti-server.cpp.o: /home/zyd/wksp/test/CnS/tcpMulti-server.cpp
CMakeFiles/tcpMultiserver.dir/tcpMulti-server.cpp.o: CMakeFiles/tcpMultiserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zyd/wksp/test/CnS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tcpMultiserver.dir/tcpMulti-server.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tcpMultiserver.dir/tcpMulti-server.cpp.o -MF CMakeFiles/tcpMultiserver.dir/tcpMulti-server.cpp.o.d -o CMakeFiles/tcpMultiserver.dir/tcpMulti-server.cpp.o -c /home/zyd/wksp/test/CnS/tcpMulti-server.cpp

CMakeFiles/tcpMultiserver.dir/tcpMulti-server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tcpMultiserver.dir/tcpMulti-server.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zyd/wksp/test/CnS/tcpMulti-server.cpp > CMakeFiles/tcpMultiserver.dir/tcpMulti-server.cpp.i

CMakeFiles/tcpMultiserver.dir/tcpMulti-server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tcpMultiserver.dir/tcpMulti-server.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zyd/wksp/test/CnS/tcpMulti-server.cpp -o CMakeFiles/tcpMultiserver.dir/tcpMulti-server.cpp.s

CMakeFiles/tcpMultiserver.dir/libs/common.cpp.o: CMakeFiles/tcpMultiserver.dir/flags.make
CMakeFiles/tcpMultiserver.dir/libs/common.cpp.o: /home/zyd/wksp/test/CnS/libs/common.cpp
CMakeFiles/tcpMultiserver.dir/libs/common.cpp.o: CMakeFiles/tcpMultiserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zyd/wksp/test/CnS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tcpMultiserver.dir/libs/common.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tcpMultiserver.dir/libs/common.cpp.o -MF CMakeFiles/tcpMultiserver.dir/libs/common.cpp.o.d -o CMakeFiles/tcpMultiserver.dir/libs/common.cpp.o -c /home/zyd/wksp/test/CnS/libs/common.cpp

CMakeFiles/tcpMultiserver.dir/libs/common.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tcpMultiserver.dir/libs/common.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zyd/wksp/test/CnS/libs/common.cpp > CMakeFiles/tcpMultiserver.dir/libs/common.cpp.i

CMakeFiles/tcpMultiserver.dir/libs/common.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tcpMultiserver.dir/libs/common.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zyd/wksp/test/CnS/libs/common.cpp -o CMakeFiles/tcpMultiserver.dir/libs/common.cpp.s

# Object files for target tcpMultiserver
tcpMultiserver_OBJECTS = \
"CMakeFiles/tcpMultiserver.dir/tcpMulti-server.cpp.o" \
"CMakeFiles/tcpMultiserver.dir/libs/common.cpp.o"

# External object files for target tcpMultiserver
tcpMultiserver_EXTERNAL_OBJECTS =

tcpMultiserver: CMakeFiles/tcpMultiserver.dir/tcpMulti-server.cpp.o
tcpMultiserver: CMakeFiles/tcpMultiserver.dir/libs/common.cpp.o
tcpMultiserver: CMakeFiles/tcpMultiserver.dir/build.make
tcpMultiserver: CMakeFiles/tcpMultiserver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/zyd/wksp/test/CnS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable tcpMultiserver"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tcpMultiserver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tcpMultiserver.dir/build: tcpMultiserver
.PHONY : CMakeFiles/tcpMultiserver.dir/build

CMakeFiles/tcpMultiserver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tcpMultiserver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tcpMultiserver.dir/clean

CMakeFiles/tcpMultiserver.dir/depend:
	cd /home/zyd/wksp/test/CnS/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zyd/wksp/test/CnS /home/zyd/wksp/test/CnS /home/zyd/wksp/test/CnS/build /home/zyd/wksp/test/CnS/build /home/zyd/wksp/test/CnS/build/CMakeFiles/tcpMultiserver.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/tcpMultiserver.dir/depend

