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
CMAKE_COMMAND = /opt/cmake-3.28.1/bin/cmake

# The command to remove a file.
RM = /opt/cmake-3.28.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zyd/wksp/test/CnS/libs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zyd/wksp/test/CnS/libs/build

# Include any dependencies generated for this target.
include CMakeFiles/libs.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/libs.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/libs.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libs.dir/flags.make

CMakeFiles/libs.dir/common.cpp.o: CMakeFiles/libs.dir/flags.make
CMakeFiles/libs.dir/common.cpp.o: /home/zyd/wksp/test/CnS/libs/common.cpp
CMakeFiles/libs.dir/common.cpp.o: CMakeFiles/libs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zyd/wksp/test/CnS/libs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/libs.dir/common.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libs.dir/common.cpp.o -MF CMakeFiles/libs.dir/common.cpp.o.d -o CMakeFiles/libs.dir/common.cpp.o -c /home/zyd/wksp/test/CnS/libs/common.cpp

CMakeFiles/libs.dir/common.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/libs.dir/common.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zyd/wksp/test/CnS/libs/common.cpp > CMakeFiles/libs.dir/common.cpp.i

CMakeFiles/libs.dir/common.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/libs.dir/common.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zyd/wksp/test/CnS/libs/common.cpp -o CMakeFiles/libs.dir/common.cpp.s

CMakeFiles/libs.dir/system.cpp.o: CMakeFiles/libs.dir/flags.make
CMakeFiles/libs.dir/system.cpp.o: /home/zyd/wksp/test/CnS/libs/system.cpp
CMakeFiles/libs.dir/system.cpp.o: CMakeFiles/libs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zyd/wksp/test/CnS/libs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/libs.dir/system.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libs.dir/system.cpp.o -MF CMakeFiles/libs.dir/system.cpp.o.d -o CMakeFiles/libs.dir/system.cpp.o -c /home/zyd/wksp/test/CnS/libs/system.cpp

CMakeFiles/libs.dir/system.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/libs.dir/system.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zyd/wksp/test/CnS/libs/system.cpp > CMakeFiles/libs.dir/system.cpp.i

CMakeFiles/libs.dir/system.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/libs.dir/system.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zyd/wksp/test/CnS/libs/system.cpp -o CMakeFiles/libs.dir/system.cpp.s

CMakeFiles/libs.dir/netstring.cpp.o: CMakeFiles/libs.dir/flags.make
CMakeFiles/libs.dir/netstring.cpp.o: /home/zyd/wksp/test/CnS/libs/netstring.cpp
CMakeFiles/libs.dir/netstring.cpp.o: CMakeFiles/libs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zyd/wksp/test/CnS/libs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/libs.dir/netstring.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libs.dir/netstring.cpp.o -MF CMakeFiles/libs.dir/netstring.cpp.o.d -o CMakeFiles/libs.dir/netstring.cpp.o -c /home/zyd/wksp/test/CnS/libs/netstring.cpp

CMakeFiles/libs.dir/netstring.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/libs.dir/netstring.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zyd/wksp/test/CnS/libs/netstring.cpp > CMakeFiles/libs.dir/netstring.cpp.i

CMakeFiles/libs.dir/netstring.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/libs.dir/netstring.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zyd/wksp/test/CnS/libs/netstring.cpp -o CMakeFiles/libs.dir/netstring.cpp.s

CMakeFiles/libs.dir/networking.cpp.o: CMakeFiles/libs.dir/flags.make
CMakeFiles/libs.dir/networking.cpp.o: /home/zyd/wksp/test/CnS/libs/networking.cpp
CMakeFiles/libs.dir/networking.cpp.o: CMakeFiles/libs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zyd/wksp/test/CnS/libs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/libs.dir/networking.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libs.dir/networking.cpp.o -MF CMakeFiles/libs.dir/networking.cpp.o.d -o CMakeFiles/libs.dir/networking.cpp.o -c /home/zyd/wksp/test/CnS/libs/networking.cpp

CMakeFiles/libs.dir/networking.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/libs.dir/networking.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zyd/wksp/test/CnS/libs/networking.cpp > CMakeFiles/libs.dir/networking.cpp.i

CMakeFiles/libs.dir/networking.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/libs.dir/networking.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zyd/wksp/test/CnS/libs/networking.cpp -o CMakeFiles/libs.dir/networking.cpp.s

CMakeFiles/libs.dir/jsonrpc_client.cpp.o: CMakeFiles/libs.dir/flags.make
CMakeFiles/libs.dir/jsonrpc_client.cpp.o: /home/zyd/wksp/test/CnS/libs/jsonrpc_client.cpp
CMakeFiles/libs.dir/jsonrpc_client.cpp.o: CMakeFiles/libs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zyd/wksp/test/CnS/libs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/libs.dir/jsonrpc_client.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libs.dir/jsonrpc_client.cpp.o -MF CMakeFiles/libs.dir/jsonrpc_client.cpp.o.d -o CMakeFiles/libs.dir/jsonrpc_client.cpp.o -c /home/zyd/wksp/test/CnS/libs/jsonrpc_client.cpp

CMakeFiles/libs.dir/jsonrpc_client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/libs.dir/jsonrpc_client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zyd/wksp/test/CnS/libs/jsonrpc_client.cpp > CMakeFiles/libs.dir/jsonrpc_client.cpp.i

CMakeFiles/libs.dir/jsonrpc_client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/libs.dir/jsonrpc_client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zyd/wksp/test/CnS/libs/jsonrpc_client.cpp -o CMakeFiles/libs.dir/jsonrpc_client.cpp.s

CMakeFiles/libs.dir/jsonrpc_handler.cpp.o: CMakeFiles/libs.dir/flags.make
CMakeFiles/libs.dir/jsonrpc_handler.cpp.o: /home/zyd/wksp/test/CnS/libs/jsonrpc_handler.cpp
CMakeFiles/libs.dir/jsonrpc_handler.cpp.o: CMakeFiles/libs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zyd/wksp/test/CnS/libs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/libs.dir/jsonrpc_handler.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libs.dir/jsonrpc_handler.cpp.o -MF CMakeFiles/libs.dir/jsonrpc_handler.cpp.o.d -o CMakeFiles/libs.dir/jsonrpc_handler.cpp.o -c /home/zyd/wksp/test/CnS/libs/jsonrpc_handler.cpp

CMakeFiles/libs.dir/jsonrpc_handler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/libs.dir/jsonrpc_handler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zyd/wksp/test/CnS/libs/jsonrpc_handler.cpp > CMakeFiles/libs.dir/jsonrpc_handler.cpp.i

CMakeFiles/libs.dir/jsonrpc_handler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/libs.dir/jsonrpc_handler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zyd/wksp/test/CnS/libs/jsonrpc_handler.cpp -o CMakeFiles/libs.dir/jsonrpc_handler.cpp.s

CMakeFiles/libs.dir/jsonrpc_httpclient.cpp.o: CMakeFiles/libs.dir/flags.make
CMakeFiles/libs.dir/jsonrpc_httpclient.cpp.o: /home/zyd/wksp/test/CnS/libs/jsonrpc_httpclient.cpp
CMakeFiles/libs.dir/jsonrpc_httpclient.cpp.o: CMakeFiles/libs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zyd/wksp/test/CnS/libs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/libs.dir/jsonrpc_httpclient.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libs.dir/jsonrpc_httpclient.cpp.o -MF CMakeFiles/libs.dir/jsonrpc_httpclient.cpp.o.d -o CMakeFiles/libs.dir/jsonrpc_httpclient.cpp.o -c /home/zyd/wksp/test/CnS/libs/jsonrpc_httpclient.cpp

CMakeFiles/libs.dir/jsonrpc_httpclient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/libs.dir/jsonrpc_httpclient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zyd/wksp/test/CnS/libs/jsonrpc_httpclient.cpp > CMakeFiles/libs.dir/jsonrpc_httpclient.cpp.i

CMakeFiles/libs.dir/jsonrpc_httpclient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/libs.dir/jsonrpc_httpclient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zyd/wksp/test/CnS/libs/jsonrpc_httpclient.cpp -o CMakeFiles/libs.dir/jsonrpc_httpclient.cpp.s

CMakeFiles/libs.dir/jsonrpc_server.cpp.o: CMakeFiles/libs.dir/flags.make
CMakeFiles/libs.dir/jsonrpc_server.cpp.o: /home/zyd/wksp/test/CnS/libs/jsonrpc_server.cpp
CMakeFiles/libs.dir/jsonrpc_server.cpp.o: CMakeFiles/libs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zyd/wksp/test/CnS/libs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/libs.dir/jsonrpc_server.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libs.dir/jsonrpc_server.cpp.o -MF CMakeFiles/libs.dir/jsonrpc_server.cpp.o.d -o CMakeFiles/libs.dir/jsonrpc_server.cpp.o -c /home/zyd/wksp/test/CnS/libs/jsonrpc_server.cpp

CMakeFiles/libs.dir/jsonrpc_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/libs.dir/jsonrpc_server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zyd/wksp/test/CnS/libs/jsonrpc_server.cpp > CMakeFiles/libs.dir/jsonrpc_server.cpp.i

CMakeFiles/libs.dir/jsonrpc_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/libs.dir/jsonrpc_server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zyd/wksp/test/CnS/libs/jsonrpc_server.cpp -o CMakeFiles/libs.dir/jsonrpc_server.cpp.s

CMakeFiles/libs.dir/jsonrpc_tcpclient.cpp.o: CMakeFiles/libs.dir/flags.make
CMakeFiles/libs.dir/jsonrpc_tcpclient.cpp.o: /home/zyd/wksp/test/CnS/libs/jsonrpc_tcpclient.cpp
CMakeFiles/libs.dir/jsonrpc_tcpclient.cpp.o: CMakeFiles/libs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zyd/wksp/test/CnS/libs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/libs.dir/jsonrpc_tcpclient.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libs.dir/jsonrpc_tcpclient.cpp.o -MF CMakeFiles/libs.dir/jsonrpc_tcpclient.cpp.o.d -o CMakeFiles/libs.dir/jsonrpc_tcpclient.cpp.o -c /home/zyd/wksp/test/CnS/libs/jsonrpc_tcpclient.cpp

CMakeFiles/libs.dir/jsonrpc_tcpclient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/libs.dir/jsonrpc_tcpclient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zyd/wksp/test/CnS/libs/jsonrpc_tcpclient.cpp > CMakeFiles/libs.dir/jsonrpc_tcpclient.cpp.i

CMakeFiles/libs.dir/jsonrpc_tcpclient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/libs.dir/jsonrpc_tcpclient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zyd/wksp/test/CnS/libs/jsonrpc_tcpclient.cpp -o CMakeFiles/libs.dir/jsonrpc_tcpclient.cpp.s

CMakeFiles/libs.dir/jsonrpc_tcpserver.cpp.o: CMakeFiles/libs.dir/flags.make
CMakeFiles/libs.dir/jsonrpc_tcpserver.cpp.o: /home/zyd/wksp/test/CnS/libs/jsonrpc_tcpserver.cpp
CMakeFiles/libs.dir/jsonrpc_tcpserver.cpp.o: CMakeFiles/libs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zyd/wksp/test/CnS/libs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/libs.dir/jsonrpc_tcpserver.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libs.dir/jsonrpc_tcpserver.cpp.o -MF CMakeFiles/libs.dir/jsonrpc_tcpserver.cpp.o.d -o CMakeFiles/libs.dir/jsonrpc_tcpserver.cpp.o -c /home/zyd/wksp/test/CnS/libs/jsonrpc_tcpserver.cpp

CMakeFiles/libs.dir/jsonrpc_tcpserver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/libs.dir/jsonrpc_tcpserver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zyd/wksp/test/CnS/libs/jsonrpc_tcpserver.cpp > CMakeFiles/libs.dir/jsonrpc_tcpserver.cpp.i

CMakeFiles/libs.dir/jsonrpc_tcpserver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/libs.dir/jsonrpc_tcpserver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zyd/wksp/test/CnS/libs/jsonrpc_tcpserver.cpp -o CMakeFiles/libs.dir/jsonrpc_tcpserver.cpp.s

CMakeFiles/libs.dir/jsonrpc_udpclient.cpp.o: CMakeFiles/libs.dir/flags.make
CMakeFiles/libs.dir/jsonrpc_udpclient.cpp.o: /home/zyd/wksp/test/CnS/libs/jsonrpc_udpclient.cpp
CMakeFiles/libs.dir/jsonrpc_udpclient.cpp.o: CMakeFiles/libs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zyd/wksp/test/CnS/libs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/libs.dir/jsonrpc_udpclient.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libs.dir/jsonrpc_udpclient.cpp.o -MF CMakeFiles/libs.dir/jsonrpc_udpclient.cpp.o.d -o CMakeFiles/libs.dir/jsonrpc_udpclient.cpp.o -c /home/zyd/wksp/test/CnS/libs/jsonrpc_udpclient.cpp

CMakeFiles/libs.dir/jsonrpc_udpclient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/libs.dir/jsonrpc_udpclient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zyd/wksp/test/CnS/libs/jsonrpc_udpclient.cpp > CMakeFiles/libs.dir/jsonrpc_udpclient.cpp.i

CMakeFiles/libs.dir/jsonrpc_udpclient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/libs.dir/jsonrpc_udpclient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zyd/wksp/test/CnS/libs/jsonrpc_udpclient.cpp -o CMakeFiles/libs.dir/jsonrpc_udpclient.cpp.s

CMakeFiles/libs.dir/jsonrpc_udpserver.cpp.o: CMakeFiles/libs.dir/flags.make
CMakeFiles/libs.dir/jsonrpc_udpserver.cpp.o: /home/zyd/wksp/test/CnS/libs/jsonrpc_udpserver.cpp
CMakeFiles/libs.dir/jsonrpc_udpserver.cpp.o: CMakeFiles/libs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zyd/wksp/test/CnS/libs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/libs.dir/jsonrpc_udpserver.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libs.dir/jsonrpc_udpserver.cpp.o -MF CMakeFiles/libs.dir/jsonrpc_udpserver.cpp.o.d -o CMakeFiles/libs.dir/jsonrpc_udpserver.cpp.o -c /home/zyd/wksp/test/CnS/libs/jsonrpc_udpserver.cpp

CMakeFiles/libs.dir/jsonrpc_udpserver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/libs.dir/jsonrpc_udpserver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zyd/wksp/test/CnS/libs/jsonrpc_udpserver.cpp > CMakeFiles/libs.dir/jsonrpc_udpserver.cpp.i

CMakeFiles/libs.dir/jsonrpc_udpserver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/libs.dir/jsonrpc_udpserver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zyd/wksp/test/CnS/libs/jsonrpc_udpserver.cpp -o CMakeFiles/libs.dir/jsonrpc_udpserver.cpp.s

# Object files for target libs
libs_OBJECTS = \
"CMakeFiles/libs.dir/common.cpp.o" \
"CMakeFiles/libs.dir/system.cpp.o" \
"CMakeFiles/libs.dir/netstring.cpp.o" \
"CMakeFiles/libs.dir/networking.cpp.o" \
"CMakeFiles/libs.dir/jsonrpc_client.cpp.o" \
"CMakeFiles/libs.dir/jsonrpc_handler.cpp.o" \
"CMakeFiles/libs.dir/jsonrpc_httpclient.cpp.o" \
"CMakeFiles/libs.dir/jsonrpc_server.cpp.o" \
"CMakeFiles/libs.dir/jsonrpc_tcpclient.cpp.o" \
"CMakeFiles/libs.dir/jsonrpc_tcpserver.cpp.o" \
"CMakeFiles/libs.dir/jsonrpc_udpclient.cpp.o" \
"CMakeFiles/libs.dir/jsonrpc_udpserver.cpp.o"

# External object files for target libs
libs_EXTERNAL_OBJECTS =

liblibs.so: CMakeFiles/libs.dir/common.cpp.o
liblibs.so: CMakeFiles/libs.dir/system.cpp.o
liblibs.so: CMakeFiles/libs.dir/netstring.cpp.o
liblibs.so: CMakeFiles/libs.dir/networking.cpp.o
liblibs.so: CMakeFiles/libs.dir/jsonrpc_client.cpp.o
liblibs.so: CMakeFiles/libs.dir/jsonrpc_handler.cpp.o
liblibs.so: CMakeFiles/libs.dir/jsonrpc_httpclient.cpp.o
liblibs.so: CMakeFiles/libs.dir/jsonrpc_server.cpp.o
liblibs.so: CMakeFiles/libs.dir/jsonrpc_tcpclient.cpp.o
liblibs.so: CMakeFiles/libs.dir/jsonrpc_tcpserver.cpp.o
liblibs.so: CMakeFiles/libs.dir/jsonrpc_udpclient.cpp.o
liblibs.so: CMakeFiles/libs.dir/jsonrpc_udpserver.cpp.o
liblibs.so: CMakeFiles/libs.dir/build.make
liblibs.so: CMakeFiles/libs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/zyd/wksp/test/CnS/libs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX shared library liblibs.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libs.dir/build: liblibs.so
.PHONY : CMakeFiles/libs.dir/build

CMakeFiles/libs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libs.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libs.dir/clean

CMakeFiles/libs.dir/depend:
	cd /home/zyd/wksp/test/CnS/libs/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zyd/wksp/test/CnS/libs /home/zyd/wksp/test/CnS/libs /home/zyd/wksp/test/CnS/libs/build /home/zyd/wksp/test/CnS/libs/build /home/zyd/wksp/test/CnS/libs/build/CMakeFiles/libs.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/libs.dir/depend

