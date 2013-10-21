/*Core header file for the Lithium Database System*/

#include <file.h>
#include <stdlib.h>

#define STATUS_SUCCESS 0 // might replace with enum
#define STATUS_ERROR 1

#define DB_FILE_EXTENSION ".lidb"

// Some labels to show whether a parameter is in, out, or modify.
#define IN
#define OUT
#define MODIFY

struct DbField_t
{
    char* column; // What column this is; not actually saved in the file
    char* type; // TODO might represent with constant or enum
} DbField_t;

struct DbRow_t
{
    DbField_t* fields;
    int numFields;
} DbRow_t;

struct DbTable_t
{
    char* name;
    char** columns;
    DbRow_t* rows;
    int numColumns;
    int numRows;
} DbTable_t;

struct Database_t
{
    char* name;
    DbTable_t* tables;
    int numTables;
} Database_t;

/** Creates a new database
@param char* name- the name.
@return Returns the created database.
*/
Database_t newDatabase(IN char* name);

/**Deletes a database.
@param Database_t database- the database to be deleted.
@return Returns the status- 0 = OK, anything else = error
*/
int deleteDatabase(MODIFY Database_t* database);

/** Adds a table to a database.
@param Database_t* database- the database to which the table should be added.
@param char* tableName- the name of the table.
@param char** fieldNames- the names of the fields.
@return Returns the status.
*/
int addTable(MODIFY Database_t* database, IN char* tableName, IN char** fieldNames);

/** Searches for a database table by name.
@param Database_t database- the database in which the table is to be found.
@param char* tableName- the name of the table to be found.
@return Returns the table if it exists, null if doesn't exist.
*/
DbTable_t getTableByName(IN Database_t database, IN char* tableName);

/** Adds a row to a table.
@param DbTable_t database- the table to which the row has to be added.
// TODO pass fields as parameter
@return The added row.
*/
DbRow_t addRow(MODIFY DbTable_t* table /* TODO pass fields as parameter */);

/** Saves the database to disk.
@param Database_t database- the database to be saved.
@return Returns the status code.
*/
int saveDatabase(IN Database_t database);
