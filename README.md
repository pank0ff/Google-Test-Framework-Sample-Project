# Google-Test-Framework-Sample-Project

Structure of project:

![image](https://github.com/pank0ff/Google-Test-Framework-Sample-Project/assets/90576203/bb04d280-c807-4864-b149-f05e5d59425e)

The codegear folder contains libraries for code coverage.

The include folder contains gmock/gtest library.

The lcov folder contains all for generating index.html with code coverage.

The make folder contains the Makefile, the build files and the out package with coverage.

The sample folder contains your code + tests for this code.

The src folder contains files for gtest/gmock library.

Building:

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

