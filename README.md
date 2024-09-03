# C++-Based Interpreted Language

## Overview
This repository is dedicated to the development of a C++-based interpreted language. The `main` branch contains the essential file/class skeletons, test cases, and various miscellaneous files related to the language, such as the parse tree and grammar. All other branches are dedicated to specific expansions of the language.

## Branch Information
- **`main`**: Hosts all file/class skeletons, test cases, and miscellaneous files about the language (e.g., parse tree, grammar).
- **Other branches**: Contain expansions of the language.

## How to Run on Your Machine

### Prerequisites
1. **Visual Studio Code (VSCode)**
   - Install the latest version of VSCode: [Download VSCode](https://code.visualstudio.com/)
2. **GitHub Account**
   - Create a GitHub account if you don't have one.
   - Contact the current project leader with your GitHub username to be added to the organization.

### Setup Instructions
1. **Open VSCode**
2. **Install the C/C++ Extension**
   - Go to the Extensions tab on the left sidebar.
   - Search for "C/C++" and install the extension by Microsoft.
3. **Install a C++ Compiler**
   - **Windows**: Install `g++/gcc` via MinGW. Follow the installation instructions: [MinGW Installation Guide](https://code.visualstudio.com/docs/cpp/config-mingw)
   - **macOS**: Install `Clang`. Follow the installation instructions: [Clang on macOS](https://code.visualstudio.com/docs/cpp/config-clang-mac)
   - **Linux**: Install `g++/gcc`. Follow the installation instructions: [GCC on Linux](https://code.visualstudio.com/docs/cpp/config-linux)

### Verify Your Setup
1. **Create a Simple Program**
   - In VSCode, create a new file (e.g., `hello.cpp` or `test.cpp`).
   - Write the following code:

     ```cpp
     #include <iostream>

     int main() {
         std::cout << "Hello, World!" << std::endl;
         return 0;
     }
     ```

2. **Save the File**
3. **Compile the Program**
   - Open the VSCode terminal and type the following command:

     ```bash
     g++ [your_program_name_here.cpp] -o test
     ```

4. **Run the Program**
   - In the terminal, run the compiled program:

     ```bash
     ./test
     ```

5. **Check the Output**
   - If "Hello, World!" appears in the terminal, you've successfully installed the compiler and configured your environment.
