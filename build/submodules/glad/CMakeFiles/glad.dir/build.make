# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\astone\Documents\Personal-Graphics-Playgound

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\astone\Documents\Personal-Graphics-Playgound\build

# Include any dependencies generated for this target.
include submodules/glad/CMakeFiles/glad.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include submodules/glad/CMakeFiles/glad.dir/compiler_depend.make

# Include the progress variables for this target.
include submodules/glad/CMakeFiles/glad.dir/progress.make

# Include the compile flags for this target's objects.
include submodules/glad/CMakeFiles/glad.dir/flags.make

submodules/glad/CMakeFiles/glad.dir/src/glad.c.obj: submodules/glad/CMakeFiles/glad.dir/flags.make
submodules/glad/CMakeFiles/glad.dir/src/glad.c.obj: submodules/glad/CMakeFiles/glad.dir/includes_C.rsp
submodules/glad/CMakeFiles/glad.dir/src/glad.c.obj: ../submodules/glad/src/glad.c
submodules/glad/CMakeFiles/glad.dir/src/glad.c.obj: submodules/glad/CMakeFiles/glad.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\astone\Documents\Personal-Graphics-Playgound\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object submodules/glad/CMakeFiles/glad.dir/src/glad.c.obj"
	cd /d C:\Users\astone\Documents\Personal-Graphics-Playgound\build\submodules\glad && C:\MinGW\bin\mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT submodules/glad/CMakeFiles/glad.dir/src/glad.c.obj -MF CMakeFiles\glad.dir\src\glad.c.obj.d -o CMakeFiles\glad.dir\src\glad.c.obj -c C:\Users\astone\Documents\Personal-Graphics-Playgound\submodules\glad\src\glad.c

submodules/glad/CMakeFiles/glad.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glad.dir/src/glad.c.i"
	cd /d C:\Users\astone\Documents\Personal-Graphics-Playgound\build\submodules\glad && C:\MinGW\bin\mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\astone\Documents\Personal-Graphics-Playgound\submodules\glad\src\glad.c > CMakeFiles\glad.dir\src\glad.c.i

submodules/glad/CMakeFiles/glad.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glad.dir/src/glad.c.s"
	cd /d C:\Users\astone\Documents\Personal-Graphics-Playgound\build\submodules\glad && C:\MinGW\bin\mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\astone\Documents\Personal-Graphics-Playgound\submodules\glad\src\glad.c -o CMakeFiles\glad.dir\src\glad.c.s

# Object files for target glad
glad_OBJECTS = \
"CMakeFiles/glad.dir/src/glad.c.obj"

# External object files for target glad
glad_EXTERNAL_OBJECTS =

submodules/glad/libglad.a: submodules/glad/CMakeFiles/glad.dir/src/glad.c.obj
submodules/glad/libglad.a: submodules/glad/CMakeFiles/glad.dir/build.make
submodules/glad/libglad.a: submodules/glad/CMakeFiles/glad.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\astone\Documents\Personal-Graphics-Playgound\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libglad.a"
	cd /d C:\Users\astone\Documents\Personal-Graphics-Playgound\build\submodules\glad && $(CMAKE_COMMAND) -P CMakeFiles\glad.dir\cmake_clean_target.cmake
	cd /d C:\Users\astone\Documents\Personal-Graphics-Playgound\build\submodules\glad && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\glad.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
submodules/glad/CMakeFiles/glad.dir/build: submodules/glad/libglad.a
.PHONY : submodules/glad/CMakeFiles/glad.dir/build

submodules/glad/CMakeFiles/glad.dir/clean:
	cd /d C:\Users\astone\Documents\Personal-Graphics-Playgound\build\submodules\glad && $(CMAKE_COMMAND) -P CMakeFiles\glad.dir\cmake_clean.cmake
.PHONY : submodules/glad/CMakeFiles/glad.dir/clean

submodules/glad/CMakeFiles/glad.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\astone\Documents\Personal-Graphics-Playgound C:\Users\astone\Documents\Personal-Graphics-Playgound\submodules\glad C:\Users\astone\Documents\Personal-Graphics-Playgound\build C:\Users\astone\Documents\Personal-Graphics-Playgound\build\submodules\glad C:\Users\astone\Documents\Personal-Graphics-Playgound\build\submodules\glad\CMakeFiles\glad.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : submodules/glad/CMakeFiles/glad.dir/depend
