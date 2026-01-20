#include <sqlite3.h>
#include <iostream>

int main(int argc, char* argv[]) {
    sqlite3* db;
    sqlite3_open("data/habit.db", &db);

    sqlite3_exec(db,
        "CREATE TABLE IF NOT EXISTS streak (count INTEGER);",
        nullptr, nullptr, nullptr);

    sqlite3_exec(db,
        "INSERT INTO streak SELECT 0 WHERE NOT EXISTS (SELECT * FROM streak);",
        nullptr, nullptr, nullptr);

    if (argc > 1 && std::string(argv[1]) == "add") {
        sqlite3_exec(db, "UPDATE streak SET count = count + 1;", nullptr, nullptr, nullptr);
    }
    if (argc > 1 && std::string(argv[1]) == "reset") {
        sqlite3_exec(db, "UPDATE streak SET count = 0;", nullptr, nullptr, nullptr);
    }

    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, "SELECT count FROM streak;", -1, &stmt, nullptr);
    sqlite3_step(stmt);
    std::cout << sqlite3_column_int(stmt, 0);

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}
