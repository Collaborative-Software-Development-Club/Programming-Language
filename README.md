This is a repository for a C++-based interpreted language.

NOTE ABOUT BRANCHES: main will host all file/class skeletons, test cases, and miscelleneous files about the language (such as the parse tree and grammar). All other branches are expansions of the language.

HOW TO RUN ON YOUR MACHINE:

1. Install the latest version of VSCode from here: https://code.visualstudio.com/
2. Create a GitHub account. (DM the current project leader with your github username to be added to the organization)
3. Open VSCode
4. Install the C/C++ extension (via the extensions tab on the left, search 'C/C++'.
5. Install a C++ compiler. I recommend using g++/gcc using MinGW for Windows (installation instructions found here: https://code.visualstudio.com/docs/cpp/config-mingw) or Clang for MacOS (found here: https://code.visualstudio.com/docs/cpp/config-clang-mac) or g++/gcc for Linux (found at: https://code.visualstudio.com/docs/cpp/config-linux)
6. Ensure your compiler is working by creating a simple hello world program file (name it 'hello.cpp', 'test.cpp', or something similar)
7. Write:
   #include <iostream>

  int main() {
      std::cout << "Hello, World!" << std::endl;
      return 0;
  }
8. Save this file.
9. On the VSCode command line, type 'g++ [your program name here] -o test
10. Now, run ./test
11. If "Hello, world!" appears, you've successfuilly installed the compiler.
