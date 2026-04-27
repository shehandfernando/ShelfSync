# ShelfSync 📚

ShelfSync is a lightweight, high-performance inventory and point-of-sale (POS) management system built in C++. Originally conceptualized as a monolithic script, it has been architected into an enterprise-ready backend demonstrating Object-Oriented Programming (OOP) principles, relational database management, and cross-platform build capabilities.

## Features
* **Secure Authentication:** Basic administrative login flow with parameterized SQL queries to prevent SQL injection.
* **Persistent Data Storage:** Fully integrated with SQLite3 for reliable, serverless database management (`shelfsync.db`).
* **Inventory Management:** Full CRUD capabilities for adding, updating, and viewing stock.
* **Sales Processing:** Dynamic inventory deduction with automated stock-level validations.
* **Modern C++:** Built utilizing C++17 standards, memory-safe data structures (`std::vector`), and modular architecture.

## Tech Stack
* **Language:** C++ (C++17)
* **Database:** SQLite3 (C-language library)
* **Build System:** CMake

## Getting Started

### Prerequisites
To build ShelfSync, you will need a C++ compiler supporting C++17, CMake, and the SQLite3 development libraries installed on your machine.

* **Windows:** Use MSYS2 (`pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-cmake mingw-w64-ucrt-x86_64-sqlite3`)
* **Linux (Debian/Ubuntu):** `sudo apt install g++ cmake libsqlite3-dev`
* **macOS:** `brew install cmake sqlite`

### Build Instructions
This project uses CMake for an out-of-source build. Run the following commands in your terminal:

```bash
# Clone the repository
git clone [https://github.com/YourUsername/ShelfSync.git](https://github.com/YourUsername/ShelfSync.git)
cd ShelfSync

# Create build directory and compile
mkdir build
cd build
cmake ..
cmake --build .

# Run the application
./ShelfSync    # (On Windows, use .\ShelfSync.exe)