# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /Users/jordancox/opt/miniconda3/bin/cmake

# The command to remove a file.
RM = /Users/jordancox/opt/miniconda3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/jordancox/Documents/CSPB 2270/Final_Project/CSPB_2270_final_project"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/jordancox/Documents/CSPB 2270/Final_Project/CSPB_2270_final_project/build"

# Include any dependencies generated for this target.
include CMakeFiles/run_app.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/run_app.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/run_app.dir/flags.make

CMakeFiles/run_app.dir/app/main.cpp.o: CMakeFiles/run_app.dir/flags.make
CMakeFiles/run_app.dir/app/main.cpp.o: ../app/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/jordancox/Documents/CSPB 2270/Final_Project/CSPB_2270_final_project/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/run_app.dir/app/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run_app.dir/app/main.cpp.o -c "/Users/jordancox/Documents/CSPB 2270/Final_Project/CSPB_2270_final_project/app/main.cpp"

CMakeFiles/run_app.dir/app/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_app.dir/app/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/jordancox/Documents/CSPB 2270/Final_Project/CSPB_2270_final_project/app/main.cpp" > CMakeFiles/run_app.dir/app/main.cpp.i

CMakeFiles/run_app.dir/app/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_app.dir/app/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/jordancox/Documents/CSPB 2270/Final_Project/CSPB_2270_final_project/app/main.cpp" -o CMakeFiles/run_app.dir/app/main.cpp.s

CMakeFiles/run_app.dir/code/data_structures.cpp.o: CMakeFiles/run_app.dir/flags.make
CMakeFiles/run_app.dir/code/data_structures.cpp.o: ../code/data_structures.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/jordancox/Documents/CSPB 2270/Final_Project/CSPB_2270_final_project/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/run_app.dir/code/data_structures.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run_app.dir/code/data_structures.cpp.o -c "/Users/jordancox/Documents/CSPB 2270/Final_Project/CSPB_2270_final_project/code/data_structures.cpp"

CMakeFiles/run_app.dir/code/data_structures.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_app.dir/code/data_structures.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/jordancox/Documents/CSPB 2270/Final_Project/CSPB_2270_final_project/code/data_structures.cpp" > CMakeFiles/run_app.dir/code/data_structures.cpp.i

CMakeFiles/run_app.dir/code/data_structures.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_app.dir/code/data_structures.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/jordancox/Documents/CSPB 2270/Final_Project/CSPB_2270_final_project/code/data_structures.cpp" -o CMakeFiles/run_app.dir/code/data_structures.cpp.s

# Object files for target run_app
run_app_OBJECTS = \
"CMakeFiles/run_app.dir/app/main.cpp.o" \
"CMakeFiles/run_app.dir/code/data_structures.cpp.o"

# External object files for target run_app
run_app_EXTERNAL_OBJECTS =

run_app: CMakeFiles/run_app.dir/app/main.cpp.o
run_app: CMakeFiles/run_app.dir/code/data_structures.cpp.o
run_app: CMakeFiles/run_app.dir/build.make
run_app: CMakeFiles/run_app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/jordancox/Documents/CSPB 2270/Final_Project/CSPB_2270_final_project/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable run_app"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/run_app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/run_app.dir/build: run_app

.PHONY : CMakeFiles/run_app.dir/build

CMakeFiles/run_app.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/run_app.dir/cmake_clean.cmake
.PHONY : CMakeFiles/run_app.dir/clean

CMakeFiles/run_app.dir/depend:
	cd "/Users/jordancox/Documents/CSPB 2270/Final_Project/CSPB_2270_final_project/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/jordancox/Documents/CSPB 2270/Final_Project/CSPB_2270_final_project" "/Users/jordancox/Documents/CSPB 2270/Final_Project/CSPB_2270_final_project" "/Users/jordancox/Documents/CSPB 2270/Final_Project/CSPB_2270_final_project/build" "/Users/jordancox/Documents/CSPB 2270/Final_Project/CSPB_2270_final_project/build" "/Users/jordancox/Documents/CSPB 2270/Final_Project/CSPB_2270_final_project/build/CMakeFiles/run_app.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/run_app.dir/depend

