# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/andrew_nguyen/files/cs/cpp/Encrypted-p2p

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/andrew_nguyen/files/cs/cpp/Encrypted-p2p/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Encrypted_p2p.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Encrypted_p2p.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Encrypted_p2p.dir/flags.make

CMakeFiles/Encrypted_p2p.dir/main.cpp.o: CMakeFiles/Encrypted_p2p.dir/flags.make
CMakeFiles/Encrypted_p2p.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andrew_nguyen/files/cs/cpp/Encrypted-p2p/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Encrypted_p2p.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Encrypted_p2p.dir/main.cpp.o -c /Users/andrew_nguyen/files/cs/cpp/Encrypted-p2p/main.cpp

CMakeFiles/Encrypted_p2p.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Encrypted_p2p.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/andrew_nguyen/files/cs/cpp/Encrypted-p2p/main.cpp > CMakeFiles/Encrypted_p2p.dir/main.cpp.i

CMakeFiles/Encrypted_p2p.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Encrypted_p2p.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/andrew_nguyen/files/cs/cpp/Encrypted-p2p/main.cpp -o CMakeFiles/Encrypted_p2p.dir/main.cpp.s

CMakeFiles/Encrypted_p2p.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Encrypted_p2p.dir/main.cpp.o.requires

CMakeFiles/Encrypted_p2p.dir/main.cpp.o.provides: CMakeFiles/Encrypted_p2p.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Encrypted_p2p.dir/build.make CMakeFiles/Encrypted_p2p.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Encrypted_p2p.dir/main.cpp.o.provides

CMakeFiles/Encrypted_p2p.dir/main.cpp.o.provides.build: CMakeFiles/Encrypted_p2p.dir/main.cpp.o


CMakeFiles/Encrypted_p2p.dir/messageHandler.cpp.o: CMakeFiles/Encrypted_p2p.dir/flags.make
CMakeFiles/Encrypted_p2p.dir/messageHandler.cpp.o: ../messageHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andrew_nguyen/files/cs/cpp/Encrypted-p2p/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Encrypted_p2p.dir/messageHandler.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Encrypted_p2p.dir/messageHandler.cpp.o -c /Users/andrew_nguyen/files/cs/cpp/Encrypted-p2p/messageHandler.cpp

CMakeFiles/Encrypted_p2p.dir/messageHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Encrypted_p2p.dir/messageHandler.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/andrew_nguyen/files/cs/cpp/Encrypted-p2p/messageHandler.cpp > CMakeFiles/Encrypted_p2p.dir/messageHandler.cpp.i

CMakeFiles/Encrypted_p2p.dir/messageHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Encrypted_p2p.dir/messageHandler.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/andrew_nguyen/files/cs/cpp/Encrypted-p2p/messageHandler.cpp -o CMakeFiles/Encrypted_p2p.dir/messageHandler.cpp.s

CMakeFiles/Encrypted_p2p.dir/messageHandler.cpp.o.requires:

.PHONY : CMakeFiles/Encrypted_p2p.dir/messageHandler.cpp.o.requires

CMakeFiles/Encrypted_p2p.dir/messageHandler.cpp.o.provides: CMakeFiles/Encrypted_p2p.dir/messageHandler.cpp.o.requires
	$(MAKE) -f CMakeFiles/Encrypted_p2p.dir/build.make CMakeFiles/Encrypted_p2p.dir/messageHandler.cpp.o.provides.build
.PHONY : CMakeFiles/Encrypted_p2p.dir/messageHandler.cpp.o.provides

CMakeFiles/Encrypted_p2p.dir/messageHandler.cpp.o.provides.build: CMakeFiles/Encrypted_p2p.dir/messageHandler.cpp.o


# Object files for target Encrypted_p2p
Encrypted_p2p_OBJECTS = \
"CMakeFiles/Encrypted_p2p.dir/main.cpp.o" \
"CMakeFiles/Encrypted_p2p.dir/messageHandler.cpp.o"

# External object files for target Encrypted_p2p
Encrypted_p2p_EXTERNAL_OBJECTS =

Encrypted_p2p: CMakeFiles/Encrypted_p2p.dir/main.cpp.o
Encrypted_p2p: CMakeFiles/Encrypted_p2p.dir/messageHandler.cpp.o
Encrypted_p2p: CMakeFiles/Encrypted_p2p.dir/build.make
Encrypted_p2p: /usr/local/lib/libcrypto.dylib
Encrypted_p2p: CMakeFiles/Encrypted_p2p.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/andrew_nguyen/files/cs/cpp/Encrypted-p2p/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Encrypted_p2p"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Encrypted_p2p.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Encrypted_p2p.dir/build: Encrypted_p2p

.PHONY : CMakeFiles/Encrypted_p2p.dir/build

CMakeFiles/Encrypted_p2p.dir/requires: CMakeFiles/Encrypted_p2p.dir/main.cpp.o.requires
CMakeFiles/Encrypted_p2p.dir/requires: CMakeFiles/Encrypted_p2p.dir/messageHandler.cpp.o.requires

.PHONY : CMakeFiles/Encrypted_p2p.dir/requires

CMakeFiles/Encrypted_p2p.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Encrypted_p2p.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Encrypted_p2p.dir/clean

CMakeFiles/Encrypted_p2p.dir/depend:
	cd /Users/andrew_nguyen/files/cs/cpp/Encrypted-p2p/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/andrew_nguyen/files/cs/cpp/Encrypted-p2p /Users/andrew_nguyen/files/cs/cpp/Encrypted-p2p /Users/andrew_nguyen/files/cs/cpp/Encrypted-p2p/cmake-build-debug /Users/andrew_nguyen/files/cs/cpp/Encrypted-p2p/cmake-build-debug /Users/andrew_nguyen/files/cs/cpp/Encrypted-p2p/cmake-build-debug/CMakeFiles/Encrypted_p2p.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Encrypted_p2p.dir/depend

