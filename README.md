# ShelfSync 📚

A modular, high-performance inventory and point-of-sale (POS) management system built in C++. This project demonstrates Object-Oriented Programming (OOP) principles, relational database management, cross-platform build capabilities, and secure data handling.

## ✨ Features
* **Secure Authentication:** Basic administrative login flow with parameterized SQL queries to prevent SQL injection.
* **Persistent Data Storage:** Fully integrated with SQLite3 for reliable, serverless database management (`shelfsync.db`).
* **Inventory Management:** Full CRUD capabilities for adding, updating, and viewing stock seamlessly.
* **Sales Processing:** Dynamic inventory deduction with automated stock-level validations.
* **Modern C++:** Built utilizing C++17 standards, memory-safe data structures (`std::vector`), and a clean modular architecture.

## 🛠️ Tech Stack
* **Language:** C++ (C++17)
* **Database:** SQLite3 (C-language library)
* **Build System:** CMake
* **Environment:** MSYS2 / GCC (Windows), Clang/GCC (macOS/Linux)

## 🚀 Getting Started

### 1. Clone the repository
    git clone https://github.com/shehandfernando/ShelfSync.git
    cd ShelfSync

### 2. Install dependencies
Ensure you have a C++17 compatible compiler, CMake, and SQLite3 installed.

* **Windows (MSYS2):**
    pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-cmake mingw-w64-ucrt-x86_64-sqlite3

* **Linux (Debian/Ubuntu):**
    sudo apt install g++ cmake libsqlite3-dev

* **macOS:**
    brew install cmake sqlite

### 3. Build the application
This project uses CMake for an out-of-source build. Run the following commands:

    mkdir build
    cd build
    cmake ..
    cmake --build .

### 4. Run the application
    # On Windows
    .\ShelfSync.exe

    # On macOS/Linux
    ./ShelfSync

## 📁 Project Structure
    ShelfSync/
    ├── CMakeLists.txt              # CMake build configuration and linking
    ├── README.md                   # Project documentation
    ├── include/                    
    │   └── DatabaseManager.h       # OOP declarations & data structures
    └── src/                        
        ├── main.cpp                # App entry point & presentation layer
        └── DatabaseManager.cpp     # Database connection & SQL execution logic

## 📝 License
This project is open-source and available under the [MIT License](LICENSE).

---
*Developed by [Shehan Fernando](https://github.com/shehandfernando)*
