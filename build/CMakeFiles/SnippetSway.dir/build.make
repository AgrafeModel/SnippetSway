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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/corentindeguisne/projets/SnippetSway

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/corentindeguisne/projets/SnippetSway/build

# Include any dependencies generated for this target.
include CMakeFiles/SnippetSway.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SnippetSway.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SnippetSway.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SnippetSway.dir/flags.make

CMakeFiles/SnippetSway.dir/src/SnippetManager.cpp.o: CMakeFiles/SnippetSway.dir/flags.make
CMakeFiles/SnippetSway.dir/src/SnippetManager.cpp.o: /Users/corentindeguisne/projets/SnippetSway/src/SnippetManager.cpp
CMakeFiles/SnippetSway.dir/src/SnippetManager.cpp.o: CMakeFiles/SnippetSway.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/corentindeguisne/projets/SnippetSway/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SnippetSway.dir/src/SnippetManager.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SnippetSway.dir/src/SnippetManager.cpp.o -MF CMakeFiles/SnippetSway.dir/src/SnippetManager.cpp.o.d -o CMakeFiles/SnippetSway.dir/src/SnippetManager.cpp.o -c /Users/corentindeguisne/projets/SnippetSway/src/SnippetManager.cpp

CMakeFiles/SnippetSway.dir/src/SnippetManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SnippetSway.dir/src/SnippetManager.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/corentindeguisne/projets/SnippetSway/src/SnippetManager.cpp > CMakeFiles/SnippetSway.dir/src/SnippetManager.cpp.i

CMakeFiles/SnippetSway.dir/src/SnippetManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SnippetSway.dir/src/SnippetManager.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/corentindeguisne/projets/SnippetSway/src/SnippetManager.cpp -o CMakeFiles/SnippetSway.dir/src/SnippetManager.cpp.s

CMakeFiles/SnippetSway.dir/src/main.cpp.o: CMakeFiles/SnippetSway.dir/flags.make
CMakeFiles/SnippetSway.dir/src/main.cpp.o: /Users/corentindeguisne/projets/SnippetSway/src/main.cpp
CMakeFiles/SnippetSway.dir/src/main.cpp.o: CMakeFiles/SnippetSway.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/corentindeguisne/projets/SnippetSway/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SnippetSway.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SnippetSway.dir/src/main.cpp.o -MF CMakeFiles/SnippetSway.dir/src/main.cpp.o.d -o CMakeFiles/SnippetSway.dir/src/main.cpp.o -c /Users/corentindeguisne/projets/SnippetSway/src/main.cpp

CMakeFiles/SnippetSway.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SnippetSway.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/corentindeguisne/projets/SnippetSway/src/main.cpp > CMakeFiles/SnippetSway.dir/src/main.cpp.i

CMakeFiles/SnippetSway.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SnippetSway.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/corentindeguisne/projets/SnippetSway/src/main.cpp -o CMakeFiles/SnippetSway.dir/src/main.cpp.s

CMakeFiles/SnippetSway.dir/src/utils/Database.cpp.o: CMakeFiles/SnippetSway.dir/flags.make
CMakeFiles/SnippetSway.dir/src/utils/Database.cpp.o: /Users/corentindeguisne/projets/SnippetSway/src/utils/Database.cpp
CMakeFiles/SnippetSway.dir/src/utils/Database.cpp.o: CMakeFiles/SnippetSway.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/corentindeguisne/projets/SnippetSway/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SnippetSway.dir/src/utils/Database.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SnippetSway.dir/src/utils/Database.cpp.o -MF CMakeFiles/SnippetSway.dir/src/utils/Database.cpp.o.d -o CMakeFiles/SnippetSway.dir/src/utils/Database.cpp.o -c /Users/corentindeguisne/projets/SnippetSway/src/utils/Database.cpp

CMakeFiles/SnippetSway.dir/src/utils/Database.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SnippetSway.dir/src/utils/Database.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/corentindeguisne/projets/SnippetSway/src/utils/Database.cpp > CMakeFiles/SnippetSway.dir/src/utils/Database.cpp.i

CMakeFiles/SnippetSway.dir/src/utils/Database.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SnippetSway.dir/src/utils/Database.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/corentindeguisne/projets/SnippetSway/src/utils/Database.cpp -o CMakeFiles/SnippetSway.dir/src/utils/Database.cpp.s

# Object files for target SnippetSway
SnippetSway_OBJECTS = \
"CMakeFiles/SnippetSway.dir/src/SnippetManager.cpp.o" \
"CMakeFiles/SnippetSway.dir/src/main.cpp.o" \
"CMakeFiles/SnippetSway.dir/src/utils/Database.cpp.o"

# External object files for target SnippetSway
SnippetSway_EXTERNAL_OBJECTS =

SnippetSway: CMakeFiles/SnippetSway.dir/src/SnippetManager.cpp.o
SnippetSway: CMakeFiles/SnippetSway.dir/src/main.cpp.o
SnippetSway: CMakeFiles/SnippetSway.dir/src/utils/Database.cpp.o
SnippetSway: CMakeFiles/SnippetSway.dir/build.make
SnippetSway: CMakeFiles/SnippetSway.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/corentindeguisne/projets/SnippetSway/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable SnippetSway"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SnippetSway.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SnippetSway.dir/build: SnippetSway
.PHONY : CMakeFiles/SnippetSway.dir/build

CMakeFiles/SnippetSway.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SnippetSway.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SnippetSway.dir/clean

CMakeFiles/SnippetSway.dir/depend:
	cd /Users/corentindeguisne/projets/SnippetSway/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/corentindeguisne/projets/SnippetSway /Users/corentindeguisne/projets/SnippetSway /Users/corentindeguisne/projets/SnippetSway/build /Users/corentindeguisne/projets/SnippetSway/build /Users/corentindeguisne/projets/SnippetSway/build/CMakeFiles/SnippetSway.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/SnippetSway.dir/depend

