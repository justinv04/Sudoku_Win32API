# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\jvinc\CMake\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\jvinc\CMake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\jvinc\OneDrive\Desktop\Stuff\Coding Files\C++ Code\Sudoku"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\jvinc\OneDrive\Desktop\Stuff\Coding Files\C++ Code\Sudoku\build"

# Include any dependencies generated for this target.
include CMakeFiles/sudoku.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sudoku.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sudoku.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sudoku.dir/flags.make

CMakeFiles/sudoku.dir/main.cpp.obj: CMakeFiles/sudoku.dir/flags.make
CMakeFiles/sudoku.dir/main.cpp.obj: C:/Users/jvinc/OneDrive/Desktop/Stuff/Coding\ Files/C++\ Code/Sudoku/main.cpp
CMakeFiles/sudoku.dir/main.cpp.obj: CMakeFiles/sudoku.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\jvinc\OneDrive\Desktop\Stuff\Coding Files\C++ Code\Sudoku\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sudoku.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sudoku.dir/main.cpp.obj -MF CMakeFiles\sudoku.dir\main.cpp.obj.d -o CMakeFiles\sudoku.dir\main.cpp.obj -c "C:\Users\jvinc\OneDrive\Desktop\Stuff\Coding Files\C++ Code\Sudoku\main.cpp"

CMakeFiles/sudoku.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sudoku.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\jvinc\OneDrive\Desktop\Stuff\Coding Files\C++ Code\Sudoku\main.cpp" > CMakeFiles\sudoku.dir\main.cpp.i

CMakeFiles/sudoku.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sudoku.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\jvinc\OneDrive\Desktop\Stuff\Coding Files\C++ Code\Sudoku\main.cpp" -o CMakeFiles\sudoku.dir\main.cpp.s

CMakeFiles/sudoku.dir/Sudoku.cpp.obj: CMakeFiles/sudoku.dir/flags.make
CMakeFiles/sudoku.dir/Sudoku.cpp.obj: C:/Users/jvinc/OneDrive/Desktop/Stuff/Coding\ Files/C++\ Code/Sudoku/Sudoku.cpp
CMakeFiles/sudoku.dir/Sudoku.cpp.obj: CMakeFiles/sudoku.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\jvinc\OneDrive\Desktop\Stuff\Coding Files\C++ Code\Sudoku\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sudoku.dir/Sudoku.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sudoku.dir/Sudoku.cpp.obj -MF CMakeFiles\sudoku.dir\Sudoku.cpp.obj.d -o CMakeFiles\sudoku.dir\Sudoku.cpp.obj -c "C:\Users\jvinc\OneDrive\Desktop\Stuff\Coding Files\C++ Code\Sudoku\Sudoku.cpp"

CMakeFiles/sudoku.dir/Sudoku.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sudoku.dir/Sudoku.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\jvinc\OneDrive\Desktop\Stuff\Coding Files\C++ Code\Sudoku\Sudoku.cpp" > CMakeFiles\sudoku.dir\Sudoku.cpp.i

CMakeFiles/sudoku.dir/Sudoku.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sudoku.dir/Sudoku.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\jvinc\OneDrive\Desktop\Stuff\Coding Files\C++ Code\Sudoku\Sudoku.cpp" -o CMakeFiles\sudoku.dir\Sudoku.cpp.s

CMakeFiles/sudoku.dir/Cell.cpp.obj: CMakeFiles/sudoku.dir/flags.make
CMakeFiles/sudoku.dir/Cell.cpp.obj: C:/Users/jvinc/OneDrive/Desktop/Stuff/Coding\ Files/C++\ Code/Sudoku/Cell.cpp
CMakeFiles/sudoku.dir/Cell.cpp.obj: CMakeFiles/sudoku.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\jvinc\OneDrive\Desktop\Stuff\Coding Files\C++ Code\Sudoku\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sudoku.dir/Cell.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sudoku.dir/Cell.cpp.obj -MF CMakeFiles\sudoku.dir\Cell.cpp.obj.d -o CMakeFiles\sudoku.dir\Cell.cpp.obj -c "C:\Users\jvinc\OneDrive\Desktop\Stuff\Coding Files\C++ Code\Sudoku\Cell.cpp"

CMakeFiles/sudoku.dir/Cell.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sudoku.dir/Cell.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\jvinc\OneDrive\Desktop\Stuff\Coding Files\C++ Code\Sudoku\Cell.cpp" > CMakeFiles\sudoku.dir\Cell.cpp.i

CMakeFiles/sudoku.dir/Cell.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sudoku.dir/Cell.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\jvinc\OneDrive\Desktop\Stuff\Coding Files\C++ Code\Sudoku\Cell.cpp" -o CMakeFiles\sudoku.dir\Cell.cpp.s

CMakeFiles/sudoku.dir/SudokuSolver.cpp.obj: CMakeFiles/sudoku.dir/flags.make
CMakeFiles/sudoku.dir/SudokuSolver.cpp.obj: C:/Users/jvinc/OneDrive/Desktop/Stuff/Coding\ Files/C++\ Code/Sudoku/SudokuSolver.cpp
CMakeFiles/sudoku.dir/SudokuSolver.cpp.obj: CMakeFiles/sudoku.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\jvinc\OneDrive\Desktop\Stuff\Coding Files\C++ Code\Sudoku\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sudoku.dir/SudokuSolver.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sudoku.dir/SudokuSolver.cpp.obj -MF CMakeFiles\sudoku.dir\SudokuSolver.cpp.obj.d -o CMakeFiles\sudoku.dir\SudokuSolver.cpp.obj -c "C:\Users\jvinc\OneDrive\Desktop\Stuff\Coding Files\C++ Code\Sudoku\SudokuSolver.cpp"

CMakeFiles/sudoku.dir/SudokuSolver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sudoku.dir/SudokuSolver.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\jvinc\OneDrive\Desktop\Stuff\Coding Files\C++ Code\Sudoku\SudokuSolver.cpp" > CMakeFiles\sudoku.dir\SudokuSolver.cpp.i

CMakeFiles/sudoku.dir/SudokuSolver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sudoku.dir/SudokuSolver.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\jvinc\OneDrive\Desktop\Stuff\Coding Files\C++ Code\Sudoku\SudokuSolver.cpp" -o CMakeFiles\sudoku.dir\SudokuSolver.cpp.s

# Object files for target sudoku
sudoku_OBJECTS = \
"CMakeFiles/sudoku.dir/main.cpp.obj" \
"CMakeFiles/sudoku.dir/Sudoku.cpp.obj" \
"CMakeFiles/sudoku.dir/Cell.cpp.obj" \
"CMakeFiles/sudoku.dir/SudokuSolver.cpp.obj"

# External object files for target sudoku
sudoku_EXTERNAL_OBJECTS =

sudoku.exe: CMakeFiles/sudoku.dir/main.cpp.obj
sudoku.exe: CMakeFiles/sudoku.dir/Sudoku.cpp.obj
sudoku.exe: CMakeFiles/sudoku.dir/Cell.cpp.obj
sudoku.exe: CMakeFiles/sudoku.dir/SudokuSolver.cpp.obj
sudoku.exe: CMakeFiles/sudoku.dir/build.make
sudoku.exe: CMakeFiles/sudoku.dir/linkLibs.rsp
sudoku.exe: CMakeFiles/sudoku.dir/objects1.rsp
sudoku.exe: CMakeFiles/sudoku.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="C:\Users\jvinc\OneDrive\Desktop\Stuff\Coding Files\C++ Code\Sudoku\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable sudoku.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\sudoku.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sudoku.dir/build: sudoku.exe
.PHONY : CMakeFiles/sudoku.dir/build

CMakeFiles/sudoku.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\sudoku.dir\cmake_clean.cmake
.PHONY : CMakeFiles/sudoku.dir/clean

CMakeFiles/sudoku.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\jvinc\OneDrive\Desktop\Stuff\Coding Files\C++ Code\Sudoku" "C:\Users\jvinc\OneDrive\Desktop\Stuff\Coding Files\C++ Code\Sudoku" "C:\Users\jvinc\OneDrive\Desktop\Stuff\Coding Files\C++ Code\Sudoku\build" "C:\Users\jvinc\OneDrive\Desktop\Stuff\Coding Files\C++ Code\Sudoku\build" "C:\Users\jvinc\OneDrive\Desktop\Stuff\Coding Files\C++ Code\Sudoku\build\CMakeFiles\sudoku.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/sudoku.dir/depend

