#pragma once
#include <string>
#include <vector>
#include <sqlite3.h>
#include <iostream>

struct Book {
    int id;
    std::string title;
    std::string author;
    double price;
    int quantity;
};

class DatabaseManager {
private:
    sqlite3* db;

public:
    DatabaseManager(const std::string& dbName);
    ~DatabaseManager();

    void initializeDatabase();
    bool authenticate(const std::string& username, const std::string& password);
    void addBook(const Book& book);
    std::vector<Book> getAllBooks();
    void processSale(int bookId, int quantity);
};