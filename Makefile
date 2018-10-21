# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/valentin/laurentayme

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/valentin/laurentayme

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/valentin/laurentayme/CMakeFiles /home/valentin/laurentayme/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/valentin/laurentayme/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named client

# Build rule for target.
client: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 client
.PHONY : client

# fast build rule for target.
client/fast:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/build
.PHONY : client/fast

src/client/Abilities.o: src/client/Abilities.cpp.o

.PHONY : src/client/Abilities.o

# target to build an object file
src/client/Abilities.cpp.o:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/Abilities.cpp.o
.PHONY : src/client/Abilities.cpp.o

src/client/Abilities.i: src/client/Abilities.cpp.i

.PHONY : src/client/Abilities.i

# target to preprocess a source file
src/client/Abilities.cpp.i:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/Abilities.cpp.i
.PHONY : src/client/Abilities.cpp.i

src/client/Abilities.s: src/client/Abilities.cpp.s

.PHONY : src/client/Abilities.s

# target to generate assembly for a file
src/client/Abilities.cpp.s:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/Abilities.cpp.s
.PHONY : src/client/Abilities.cpp.s

src/client/Character.o: src/client/Character.cpp.o

.PHONY : src/client/Character.o

# target to build an object file
src/client/Character.cpp.o:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/Character.cpp.o
.PHONY : src/client/Character.cpp.o

src/client/Character.i: src/client/Character.cpp.i

.PHONY : src/client/Character.i

# target to preprocess a source file
src/client/Character.cpp.i:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/Character.cpp.i
.PHONY : src/client/Character.cpp.i

src/client/Character.s: src/client/Character.cpp.s

.PHONY : src/client/Character.s

# target to generate assembly for a file
src/client/Character.cpp.s:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/Character.cpp.s
.PHONY : src/client/Character.cpp.s

src/client/Element.o: src/client/Element.cpp.o

.PHONY : src/client/Element.o

# target to build an object file
src/client/Element.cpp.o:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/Element.cpp.o
.PHONY : src/client/Element.cpp.o

src/client/Element.i: src/client/Element.cpp.i

.PHONY : src/client/Element.i

# target to preprocess a source file
src/client/Element.cpp.i:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/Element.cpp.i
.PHONY : src/client/Element.cpp.i

src/client/Element.s: src/client/Element.cpp.s

.PHONY : src/client/Element.s

# target to generate assembly for a file
src/client/Element.cpp.s:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/Element.cpp.s
.PHONY : src/client/Element.cpp.s

src/client/ElementTab.o: src/client/ElementTab.cpp.o

.PHONY : src/client/ElementTab.o

# target to build an object file
src/client/ElementTab.cpp.o:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/ElementTab.cpp.o
.PHONY : src/client/ElementTab.cpp.o

src/client/ElementTab.i: src/client/ElementTab.cpp.i

.PHONY : src/client/ElementTab.i

# target to preprocess a source file
src/client/ElementTab.cpp.i:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/ElementTab.cpp.i
.PHONY : src/client/ElementTab.cpp.i

src/client/ElementTab.s: src/client/ElementTab.cpp.s

.PHONY : src/client/ElementTab.s

# target to generate assembly for a file
src/client/ElementTab.cpp.s:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/ElementTab.cpp.s
.PHONY : src/client/ElementTab.cpp.s

src/client/Equipment.o: src/client/Equipment.cpp.o

.PHONY : src/client/Equipment.o

# target to build an object file
src/client/Equipment.cpp.o:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/Equipment.cpp.o
.PHONY : src/client/Equipment.cpp.o

src/client/Equipment.i: src/client/Equipment.cpp.i

.PHONY : src/client/Equipment.i

# target to preprocess a source file
src/client/Equipment.cpp.i:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/Equipment.cpp.i
.PHONY : src/client/Equipment.cpp.i

src/client/Equipment.s: src/client/Equipment.cpp.s

.PHONY : src/client/Equipment.s

# target to generate assembly for a file
src/client/Equipment.cpp.s:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/Equipment.cpp.s
.PHONY : src/client/Equipment.cpp.s

src/client/Landscape.o: src/client/Landscape.cpp.o

.PHONY : src/client/Landscape.o

# target to build an object file
src/client/Landscape.cpp.o:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/Landscape.cpp.o
.PHONY : src/client/Landscape.cpp.o

src/client/Landscape.i: src/client/Landscape.cpp.i

.PHONY : src/client/Landscape.i

# target to preprocess a source file
src/client/Landscape.cpp.i:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/Landscape.cpp.i
.PHONY : src/client/Landscape.cpp.i

src/client/Landscape.s: src/client/Landscape.cpp.s

.PHONY : src/client/Landscape.s

# target to generate assembly for a file
src/client/Landscape.cpp.s:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/Landscape.cpp.s
.PHONY : src/client/Landscape.cpp.s

src/client/Obstacle.o: src/client/Obstacle.cpp.o

.PHONY : src/client/Obstacle.o

# target to build an object file
src/client/Obstacle.cpp.o:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/Obstacle.cpp.o
.PHONY : src/client/Obstacle.cpp.o

src/client/Obstacle.i: src/client/Obstacle.cpp.i

.PHONY : src/client/Obstacle.i

# target to preprocess a source file
src/client/Obstacle.cpp.i:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/Obstacle.cpp.i
.PHONY : src/client/Obstacle.cpp.i

src/client/Obstacle.s: src/client/Obstacle.cpp.s

.PHONY : src/client/Obstacle.s

# target to generate assembly for a file
src/client/Obstacle.cpp.s:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/Obstacle.cpp.s
.PHONY : src/client/Obstacle.cpp.s

src/client/Position.o: src/client/Position.cpp.o

.PHONY : src/client/Position.o

# target to build an object file
src/client/Position.cpp.o:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/Position.cpp.o
.PHONY : src/client/Position.cpp.o

src/client/Position.i: src/client/Position.cpp.i

.PHONY : src/client/Position.i

# target to preprocess a source file
src/client/Position.cpp.i:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/Position.cpp.i
.PHONY : src/client/Position.cpp.i

src/client/Position.s: src/client/Position.cpp.s

.PHONY : src/client/Position.s

# target to generate assembly for a file
src/client/Position.cpp.s:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/Position.cpp.s
.PHONY : src/client/Position.cpp.s

src/client/Space.o: src/client/Space.cpp.o

.PHONY : src/client/Space.o

# target to build an object file
src/client/Space.cpp.o:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/Space.cpp.o
.PHONY : src/client/Space.cpp.o

src/client/Space.i: src/client/Space.cpp.i

.PHONY : src/client/Space.i

# target to preprocess a source file
src/client/Space.cpp.i:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/Space.cpp.i
.PHONY : src/client/Space.cpp.i

src/client/Space.s: src/client/Space.cpp.s

.PHONY : src/client/Space.s

# target to generate assembly for a file
src/client/Space.cpp.s:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/Space.cpp.s
.PHONY : src/client/Space.cpp.s

src/client/State.o: src/client/State.cpp.o

.PHONY : src/client/State.o

# target to build an object file
src/client/State.cpp.o:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/State.cpp.o
.PHONY : src/client/State.cpp.o

src/client/State.i: src/client/State.cpp.i

.PHONY : src/client/State.i

# target to preprocess a source file
src/client/State.cpp.i:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/State.cpp.i
.PHONY : src/client/State.cpp.i

src/client/State.s: src/client/State.cpp.s

.PHONY : src/client/State.s

# target to generate assembly for a file
src/client/State.cpp.s:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/State.cpp.s
.PHONY : src/client/State.cpp.s

src/client/StaticElement.o: src/client/StaticElement.cpp.o

.PHONY : src/client/StaticElement.o

# target to build an object file
src/client/StaticElement.cpp.o:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/StaticElement.cpp.o
.PHONY : src/client/StaticElement.cpp.o

src/client/StaticElement.i: src/client/StaticElement.cpp.i

.PHONY : src/client/StaticElement.i

# target to preprocess a source file
src/client/StaticElement.cpp.i:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/StaticElement.cpp.i
.PHONY : src/client/StaticElement.cpp.i

src/client/StaticElement.s: src/client/StaticElement.cpp.s

.PHONY : src/client/StaticElement.s

# target to generate assembly for a file
src/client/StaticElement.cpp.s:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/StaticElement.cpp.s
.PHONY : src/client/StaticElement.cpp.s

src/client/Wall.o: src/client/Wall.cpp.o

.PHONY : src/client/Wall.o

# target to build an object file
src/client/Wall.cpp.o:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/Wall.cpp.o
.PHONY : src/client/Wall.cpp.o

src/client/Wall.i: src/client/Wall.cpp.i

.PHONY : src/client/Wall.i

# target to preprocess a source file
src/client/Wall.cpp.i:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/Wall.cpp.i
.PHONY : src/client/Wall.cpp.i

src/client/Wall.s: src/client/Wall.cpp.s

.PHONY : src/client/Wall.s

# target to generate assembly for a file
src/client/Wall.cpp.s:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/Wall.cpp.s
.PHONY : src/client/Wall.cpp.s

src/client/main.o: src/client/main.cpp.o

.PHONY : src/client/main.o

# target to build an object file
src/client/main.cpp.o:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/main.cpp.o
.PHONY : src/client/main.cpp.o

src/client/main.i: src/client/main.cpp.i

.PHONY : src/client/main.i

# target to preprocess a source file
src/client/main.cpp.i:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/main.cpp.i
.PHONY : src/client/main.cpp.i

src/client/main.s: src/client/main.cpp.s

.PHONY : src/client/main.s

# target to generate assembly for a file
src/client/main.cpp.s:
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/main.cpp.s
.PHONY : src/client/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... client"
	@echo "... src/client/Abilities.o"
	@echo "... src/client/Abilities.i"
	@echo "... src/client/Abilities.s"
	@echo "... src/client/Character.o"
	@echo "... src/client/Character.i"
	@echo "... src/client/Character.s"
	@echo "... src/client/Element.o"
	@echo "... src/client/Element.i"
	@echo "... src/client/Element.s"
	@echo "... src/client/ElementTab.o"
	@echo "... src/client/ElementTab.i"
	@echo "... src/client/ElementTab.s"
	@echo "... src/client/Equipment.o"
	@echo "... src/client/Equipment.i"
	@echo "... src/client/Equipment.s"
	@echo "... src/client/Landscape.o"
	@echo "... src/client/Landscape.i"
	@echo "... src/client/Landscape.s"
	@echo "... src/client/Obstacle.o"
	@echo "... src/client/Obstacle.i"
	@echo "... src/client/Obstacle.s"
	@echo "... src/client/Position.o"
	@echo "... src/client/Position.i"
	@echo "... src/client/Position.s"
	@echo "... src/client/Space.o"
	@echo "... src/client/Space.i"
	@echo "... src/client/Space.s"
	@echo "... src/client/State.o"
	@echo "... src/client/State.i"
	@echo "... src/client/State.s"
	@echo "... src/client/StaticElement.o"
	@echo "... src/client/StaticElement.i"
	@echo "... src/client/StaticElement.s"
	@echo "... src/client/Wall.o"
	@echo "... src/client/Wall.i"
	@echo "... src/client/Wall.s"
	@echo "... src/client/main.o"
	@echo "... src/client/main.i"
	@echo "... src/client/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

