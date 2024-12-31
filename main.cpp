#include <duckdb.h>
#include <stdio.h>

int main()
{
    duckdb_database db;
    duckdb_connection conn;

    if (duckdb_open(NULL, &db) == DuckDBError)
    {
        printf("Error opening database\n");
        return 1;
    }

    if (duckdb_connect(db, &conn) == DuckDBError)
    {
        printf("Error connecting\n");
        return 1;
    }

    duckdb_disconnect(&conn);
    duckdb_close(&db);

    return 0;
}