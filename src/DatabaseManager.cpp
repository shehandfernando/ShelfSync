#include "DatabaseManager.h"

DatabaseManager::DatabaseManager(const std::string& dbName) {
    if (sqlite3_open(dbName.c_str(), &db) != SQLITE_OK) {
        std::cerr << "Fatal Error: Cannot open database: " << sqlite3_errmsg(db) << "\n";
    }
}

DatabaseManager::~DatabaseManager() {
    sqlite3_close(db);
}

void DatabaseManager::initializeDatabase() {
    const char* createBooksTable = 
        "CREATE TABLE IF NOT EXISTS books ("
        "id INTEGER PRIMARY KEY, "
        "title TEXT NOT NULL, "
        "author TEXT NOT NULL, "
        "price REAL NOT NULL, "
        "quantity INTEGER NOT NULL);";

    const char* createUsersTable = 
        "CREATE TABLE IF NOT EXISTS users ("
        "username TEXT PRIMARY KEY, "
        "password TEXT NOT NULL);";

    // Insert default admin if table is empty
    const char* insertAdmin = 
        "INSERT OR IGNORE INTO users (username, password) VALUES ('admin', 'admin123');";

    sqlite3_exec(db, createBooksTable, nullptr, nullptr, nullptr);
    sqlite3_exec(db, createUsersTable, nullptr, nullptr, nullptr);
    sqlite3_exec(db, insertAdmin, nullptr, nullptr, nullptr);
}

bool DatabaseManager::authenticate(const std::string& username, const std::string& password) {
    sqlite3_stmt* stmt;
    const char* query = "SELECT * FROM users WHERE username = ? AND password = ?";
    
    if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) != SQLITE_OK) return false;

    // Bind variables to prevent SQL injection
    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC);

    bool isAuthenticated = (sqlite3_step(stmt) == SQLITE_ROW);
    sqlite3_finalize(stmt);
    return isAuthenticated;
}

void DatabaseManager::addBook(const Book& book) {
    std::string query = "INSERT INTO books (id, title, author, price, quantity) VALUES (" +
                        std::to_string(book.id) + ", '" + book.title + "', '" + book.author + "', " +
                        std::to_string(book.price) + ", " + std::to_string(book.quantity) + ");";
    sqlite3_exec(db, query.c_str(), nullptr, nullptr, nullptr);
    std::cout << "Book saved to database.\n";
}

std::vector<Book> DatabaseManager::getAllBooks() {
    std::vector<Book> inventory;
    sqlite3_stmt* stmt;
    const char* query = "SELECT id, title, author, price, quantity FROM books";

    if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            Book b;
            b.id = sqlite3_column_int(stmt, 0);
            b.title = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            b.author = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
            b.price = sqlite3_column_double(stmt, 3);
            b.quantity = sqlite3_column_int(stmt, 4);
            inventory.push_back(b);
        }
    }
    sqlite3_finalize(stmt);
    return inventory;
}

void DatabaseManager::processSale(int bookId, int quantityToSell) {
    sqlite3_stmt* stmt;
    std::string query = "SELECT quantity, price FROM books WHERE id = " + std::to_string(bookId);
    
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            int currentQty = sqlite3_column_int(stmt, 0);
            double price = sqlite3_column_double(stmt, 1);
            
            if (currentQty >= quantityToSell) {
                int newQty = currentQty - quantityToSell;
                std::string updateQuery = "UPDATE books SET quantity = " + std::to_string(newQty) + " WHERE id = " + std::to_string(bookId);
                sqlite3_exec(db, updateQuery.c_str(), nullptr, nullptr, nullptr);
                std::cout << "Sale successful! Total: $" << (price * quantityToSell) << "\n";
            } else {
                std::cout << "Error: Insufficient stock!\n";
            }
        } else {
            std::cout << "Book ID not found.\n";
        }
    }
    sqlite3_finalize(stmt);
}