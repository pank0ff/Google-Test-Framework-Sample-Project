# Google-Test-Framework-Sample-Project

# Structure of project:

![image](https://github.com/pank0ff/Google-Test-Framework-Sample-Project/assets/90576203/bb04d280-c807-4864-b149-f05e5d59425e)

The codegear folder contains libraries for code coverage.

The include folder contains gmock/gtest library.

The lcov folder contains all for generating index.html with code coverage.

The make folder contains the Makefile, the build files and the out package with coverage.

The sample folder contains your code + tests for this code.

The src folder contains files for gtest/gmock library.

# Struct of Makefile:
## Variables
```
GTEST_DIR = ..
```
Specifies the path to the GoogleTest (and GoogleMock) directory.
You can modify this variable if: Your GTest library is stored in another location.
Example:
```
GTEST_DIR = /usr/local/src/googletest
```
---
```
USER_DIR = ../samples
```
Path to your own source code (the directory containing your sample.c and test.cpp).
You can modify this variable if: Your test or source files are in another folder.
Example:
```
USER_DIR = ./src
```
---
```
CPPFLAGS += -isystem $(GTEST_DIR)/include
```
Adds the GTest include directory to the compiler’s system include path.
Don’t change unless your includes are elsewhere.

---
```
CXXFLAGS += -g -Wall -Wextra
```
Sets compiler flags for debugging (-g) and enables most warnings (-Wall -Wextra).
You can modify to add optimization flags like -O2.

---
```
CFLAG = -fPIC -fprofile-arcs -ftest-coverage
```
Additional compiler flags:
	•	-fPIC — position-independent code (needed for static/shared libraries)
	•	-fprofile-arcs and -ftest-coverage — enable code coverage using gcov or lcov
Modify if: You don’t need coverage → remove -fprofile-arcs -ftest-coverage.

---
```
TESTS = test
```
Name of the final test executable to be built.
You can rename it if you prefer another binary name.
Example:
```
TESTS = run_tests
```
---
```
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h \
				$(GTEST_DIR)/include/gmock/*.h \
                $(GTEST_DIR)/include/gmock/internal/*.h
```
Lists all header files from GoogleTest and GoogleMock.
Used as dependencies to rebuild when headers change.
No need to modify unless your GTest structure differs.

---

## Build Targets
```
all : $(TESTS)
```
Default build target — builds your test executable.
Running make in terminal will execute this by default.

---
```
clean :
	rm -rf $(TESTS) gtest.a gtest_main.a *.o *.gcno *.gcda *.info out
```

Removes all generated files (executables, object files, coverage data). Run:
```
make clean
```
to reset the build.

---

## GoogleTest and GoogleMock Compilation
```
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)
```
Defines all GoogleTest source and header files for compilation.

---
```
gtest-all.o : $(GTEST_SRCS_)
	$(CXX)  $(CFLAG) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c $(GTEST_DIR)/src/gtest-all.cc
```
Compiles gtest-all.cc into an object file.
Note: Needed to build the static GTest library.

---
```
gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) $(CFLAG) -I$(GTEST_DIR) $(CXXFLAGS) -c $(GTEST_DIR)/src/gtest_main.cc
```
Compiles the main function for running tests.
Used in gtest_main.a.

---
```
gmock-all.o : $(GTEST_SRCS_)
	$(CXX)  $(CFLAG) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c $(GTEST_DIR)/src/gmock-all.cc
```

Compiles the GoogleMock sources into an object file.

---
```
gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^
```

Creates a static library archive gtest.a from the compiled object.
($@ = output file, $^ = all dependencies)

---
```
gmock.a : gmock-all.o
	$(AR) $(ARFLAGS) $@ $^
```

Creates the static library gmock.a.

---
```
gtest_main.a : gtest-all.o gmock-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^
```

Combines GoogleTest, GoogleMock, and gtest_main into a single static library.

---
```
sample.o : $(USER_DIR)/sample.c $(USER_DIR)/sample.h $(GTEST_HEADERS)
	$(CXX) $(CFLAG) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/sample.c
```
Compiles your sample source file (sample.c) into an object file.
You can modify: Your file name or path differs.
Example:
```
sample.o : $(USER_DIR)/math_utils.c $(USER_DIR)/math_utils.h
```

---
```
test.o : $(USER_DIR)/test.cpp $(USER_DIR)/sample.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/test.cpp
```
Links all compiled object files and static libraries into the final executable.
Produces the test binary named test (or whatever you set in TESTS).
To run tests:
```
./test
```
---

## Example Build Commands
```
make        # build all
make clean  # remove build files
./test      # run tests
```

# Building:

For start you need to install the next dependencies:
```
pacman -S make
pacman -S gcc
pacman -S lcov
```
For build your tests open make folder and write "make all". You will see output in the console like that, if all successfully:

![image](https://github.com/pank0ff/Google-Test-Framework-Sample-Project/assets/90576203/f01fa115-678e-44b9-9fe0-8bba77c6bcec)

And the make folder:

![image](https://github.com/pank0ff/Google-Test-Framework-Sample-Project/assets/90576203/7778c8d2-16c6-4cc2-915a-fd2a0be9a546)


For clean your project ( You should to do this before "make all" command ) write "make clean". You will see output in the console like that, if all successfully:

![image](https://github.com/pank0ff/Google-Test-Framework-Sample-Project/assets/90576203/149851d5-d9e4-4b7f-9ee6-54ec78e9ea20)

And the make folder (only Makefile):

![image](https://github.com/pank0ff/Google-Test-Framework-Sample-Project/assets/90576203/aa501715-3441-4a61-ad26-08c5b9fd7a33)

Code coverage generation:

The following steps can only be performed after running test.exe!!!!!!!

First of all write "lcov --capture --directory . --output-file coverage.info" command for generating coverage.info file ( do this command on the make folder ). You will see output in the console like that, if all successfully:

![image](https://github.com/pank0ff/Google-Test-Framework-Sample-Project/assets/90576203/7ee22e82-fd83-4d47-a118-6c2db7939169)


If you see this message in the console, then run test.exe and re-enter the command. The .gcda file is generated ONLY when the .exe is run.

![image](https://github.com/pank0ff/Google-Test-Framework-Sample-Project/assets/90576203/35dcf91c-7c60-4026-8c13-cb7e1112f59f)

The second command generate index.html file with code coverage ( path to this file is make/out/index.html). Command for this is "genhtml coverage.info --output-directory out". You will see output in the console like that, if all successfully:

![image](https://github.com/pank0ff/Google-Test-Framework-Sample-Project/assets/90576203/f28620ea-5dcf-46cf-97ca-f7e4f90d6968)

