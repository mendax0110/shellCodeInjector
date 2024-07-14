## ShellCodeInjector

This is a simple shellcode injector that injects shellcode into a running process. The shellcode is executed in the context of the target process. The injector is written in C++ and uses the Windows API to interact with the target process.

### Build Instructions
To use shellCodeInjector, follow these steps:

1. Clone the repository.
````bash
git clone https://github.com/mendax0110/shellCodeInjector.git
````

2. Change the working directory to the cloned repository.
````bash
cd shellCodeInjector
````

3. Create the build directory.
````bash
mkdir build
````

4. Change the working directory to the build directory.
````bash
cd build
````

5. Generate the build files using CMake.
````bash
cmake ..
````

6. Build the project.
````bash
cmake --build .
````

### Usage

To use the shellCodeInjector, follow these steps:

1. Use genShellCode to generate the binary file which conatins the shellcode.
````bash
genShellCode <output>.bin
````

2. Run the shellCodeInjector with the following arguments:
````bash
shellCodeInjector <shellcode_file>.bin
````

## Supported Platforms
- Windows