### Dependencies

#### Install MSYS2
Open `.vscode/settings.json`:

```json
{
    "cmake.cmakePath": "C:/msys64/mingw64/bin/cmake.exe",
    "terminal.integrated.shell.windows": "C:/msys64/usr/bin/bash.exe",
    "cmake.generator": "MinGW Makefiles",
    "cmake.mingwMakePath": "C:/msys64/mingw64/bin/mingw32-make.exe"
}
```

#### Prerequisites

```bash
pacman -Syu
pacman -S base-devel
pacman -S mingw-w64-x86_64-toolchain
pacman -S mingw-w64-x86_64-cmake
pacman -S mingw-w64-x86_64-ninja
pacman -S mingw-w64-x86_64-glew
pacman -S mingw-w64-x86_64-glm
pacman -S mingw-w64-x86_64-freeglut
pacman -S mingw-w64-x86_64-DevIL
```

### .bashrc in MSYS2

```bash
export PATH=$PATH:"/c/Users/chamm/AppData/Local/Programs/Microsoft VS Code"
# Add MinGW-w64 path
export PATH="/c/msys64/mingw64/bin:$PATH"

# Set CMake build tools and compilers
export CMAKE_MAKE_PROGRAM="/c/msys64/mingw64/bin/mingw32-make.exe"
export CMAKE_C_COMPILER="/c/msys64/mingw64/bin/gcc.exe"
export CMAKE_CXX_COMPILER="/c/msys64/mingw64/bin/g++.exe"
```

### Execute

```bash
code # in MSYS2
```