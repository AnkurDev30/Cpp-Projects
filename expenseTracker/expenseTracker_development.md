**Expense Tracker GUI -- Development Setup Notes**

**1. Project overview**
Project name: Expense Tracker
Purpose: Build a desktop application to record income and expenses,
view transaction history, and generate simple summaries.

Target platforms
- Ubuntu Linux (development environment)
- Windows (cross-platform build and testing target)


**Planned Technology Stack**

| Tool / Technology | Purpose |
|---|---|
| C++ | Application logic |
| Qt 6 Widgets | Desktop graphical user interface |
| VS Code | Code editor |
| GCC / G++ | C++ compiler |
| CMake | Project configuration and build generation |
| Ninja | Build tool |
| Qt Designer | Optional visual UI design |
| SQLite | Planned database for persistent records |
| STL | Data structures and algorithms |

**Qt version note: The Ubuntu environment reports Qt 6.4.2. Qt 6**
requires C++17 or newer. The project will therefore use C++17 with
Qt 6, rather than forcing C++11. C++11 concepts can still be practised
while implementing the application.

**2. Current development environment**
The setup work was carried out on Ubuntu 24.04.
  Component                           Detected version / status
  Ubuntu                              24.04 (inferred from the installed
package/compiler version; confirm
with lsb_release -a)

  GCC / G++                           13.3.0

  VS Code                             1.143.1

  Qt                                  6.4.2

  CMake                               3.28.3


  Ninja                               1.11.1


  pkgconf / pkg-config                1.8.1

Qt6 Widgets development package     QMake version 3.1,  Using Qt version 6.4.2 in /usr/lib/x86_64-linux-gnu

development setup; verify below
Commands used to check the environment
g++ --version
cmake --version
code --version
qmake --version
qmake6 --version
pkg-config --modversion Qt6Widgets
ninja --version
The qmake command was not available, but qmake6 worked and reported
Qt 6.4.2. On this Ubuntu installation, use qmake6 when checking the Qt
version.

**3. Installation steps**
Update the Ubuntu package list:
sudo apt update
Install the compiler/build tools and Qt 6 development packages:
sudo apt install build-essential cmake ninja-build \
qt6-base-dev qt6-base-dev-tools \
qt6-tools-dev qt6-tools-dev-tools
The package manager reported approximately 395 MB of additional disk
space would be used. The user accepted the installation by entering
Y.

Install the pkg-config utility after the command was found to be
missing:
sudo apt install pkgconf
On Ubuntu, the pkgconf package provides the pkg-config command.
What these packages provide
- build-essential: GCC/G++, standard development tools and build
  essentials.
- cmake: CMake build configuration tool.
- ninja-build: Ninja build system.
- qt6-base-dev: Qt 6 base development files, including Widgets
  development support.
- qt6-base-dev-tools: Qt development utilities.
- qt6-tools-dev and qt6-tools-dev-tools: Additional Qt development
  tools.
- pkgconf: Provides the pkg-config command for checking library
  metadata.

**4. Errors encountered and how they were handled**
Issue 1: CMake command not found
Command:
cmake --version
Observed error:
Command 'cmake' not found
Suggested installation command:
sudo apt install cmake
For the project setup, CMake was included in the combined installation
command:
sudo apt install build-essential cmake ninja-build \
qt6-base-dev qt6-base-dev-tools \
qt6-tools-dev qt6-tools-dev-tools
Issue 2: qmake command not found
Command:
qmake --version
Observed error:
Command 'qmake' not found
The terminal suggested installing qtchooser, but the Qt 6-specific
command was checked instead:
qmake6 --version
Successful output:
QMake version 3.1
Using Qt version 6.4.2 in /usr/lib/x86_64-linux-gnu
This confirms that the Qt 6.4.2 qmake tool is available.
Issue 3: pkg-config command not found
Command:
pkg-config --modversion Qt6Widgets
Observed error:
Command 'pkg-config' not found
Installation command:
sudo apt install pkgconf
After installation, run the original check again:
pkg-config --modversion Qt6Widgets
A version number should be printed if the Qt6 Widgets package metadata
is available. The exact output has not yet been recorded.


**5. Final verification checklist**
Run these commands in the Ubuntu terminal and keep the outputs for the
project setup record:
g++ --version
code --version
qmake6 --version
pkg-config --modversion Qt6Widgets
cmake --version
ninja --version
Optional: check the Qt Designer executable:
designer
If the Designer window opens, the visual UI design tool is available. If
the command is not found, check which Designer executable was installed:
dpkg -L qt6-tools-dev-tools | grep '/designer$'
Do not assume that every tool is working until its verification command
succeeds.


**6. VS Code extensions** *(optional, )*
Install these extensions from the VS Code Extensions view:
1. C/C++ -- Microsoft
2. CMake Tools -- Microsoft
3. CMake Language Support -- for CMake syntax support
The extensions assist with editing, code navigation, CMake configuration
and building. The compiler, Qt libraries and CMake packages are
installed separately on Ubuntu.


**7. Planned project features**
The Expense Tracker will be developed in stages.
  Phase                   Feature                 Main concepts
  1                       Main application window QApplication,
QMainWindow, event
loop

  2                       Basic GUI layout        Widgets, layouts,
labels, buttons

  3                       Add income/expense      Classes, objects,
encapsulation

  4                       Transaction history     QTableWidget or
model/view

  5                       Add/delete operations   Signals and slots

  6                       In-memory transaction   std::vector, STL
storage                 

  7                       Save and load records   File handling

  8                       Persistent storage      SQLite

  9                       Monthly summaries       Algorithms and
reporting
10                      Cross-platform testing  CMake builds on Linux
and Windows
Planned folder structure
ExpenseTracker/
├── CMakeLists.txt
├── main.cpp
├── MainWindow.h
├── MainWindow.cpp
├── Transaction.h
├── Transaction.cpp
├── TransactionManager.h
├── TransactionManager.cpp
├── ui/
└── build/
The structure can be adjusted as the application grows.


**8. Create the project directory**
mkdir -p ~/Projects/ExpenseTracker
cd ~/Projects/ExpenseTracker
code .
This creates the project directory under the user's home folder and
opens it in VS Code.


**9. Cross-platform development plan**
- Develop and compile the application on Ubuntu first.
- Keep application logic independent of operating-system-specific
  APIs.
- Use Qt Widgets for the user interface and Qt/C++ APIs for portable
  functionality.
- Use CMake to manage the build.
- Later, install/configure a compatible Qt 6 and C++ compiler
  toolchain on Windows.
- Open the same source project on Windows and build it there.
A Linux executable does not directly run on Windows. The same source
code must be built separately for each operating system.


**10. Current progress**
- [x] GCC/G++ detected (13.3.0)
- [x] VS Code detected (1.143.1)
- [x] Qt 6.4.2 detected using qmake6
- [x] Qt development packages installation initiated and accepted
- [x] CMake, Ninja and pkgconf installation reported completed by
  the user
- [ ] Record successful cmake --version output
- [ ] Record successful ninja --version output
- [ ] Record successful pkg-config --modversion Qt6Widgets output
- [ ] Confirm Qt Designer availability
- [ ] Create the initial CMake-based Qt Widgets application
- [ ] Build and run the first window on Ubuntu
- [ ] Configure and test a Windows build
Next development task: Verify the remaining tool versions, create
the CMake project in VS Code, and build a basic Qt Widgets window.