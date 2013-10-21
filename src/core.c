/*Core C file for the Lithium Database system.*/
#include "core.h"
// Documentation for the functions in this routine can be found in core.h

Database_t newDatabase(IN char* name)
{
    Database_t* p_database = (Database_t*) malloc(sizeof Database_t);
    Database_t database = *p_database;
    database.name = name;
    database.tables = NULL;
    return database;
}

int deleteDatabase(MODIFY Database_t* database);
{
    // delete the file
    (*database).tables = NULL;
}

DbTable_t addTable(MODIFY Database_t* database, IN char* tableName, IN char** columnNames)
{
    DbTable_t* p_table = (DbTable_t*) malloc(sizeof DbTable_t);
    DbTable_t table = *p_table;
    table.name = tableName;
    table.columns = columnNames;
    int newLength = (sizeof DbTable_t) * ((*database).numTables + 1);
    (*database).tables = (DbTable_t*) realloc((*database).tables, newLength);
    (*database).tables[newLength - 1] = table;
    return table;
}

DbTable_t getTableByName(IN Database_t database, IN char* tableName)
{
    for(int i = 0; i < ((sizeof database.tables) / (sizeof DbTable_t)); i++)
    {
        if(strcmp(database.tables[i].name, tableName) != 0)
        {
            return database.tables[i];
        }
    }
    return NULL;
}

DbRow_t addRow(MODIFY DbTable_t table /* TODO pass fields as parameter */)
{
    int newLength = (sizeof DbRow_t) * ((*table).numRows + 1);
    (*table).rows= (DbRow_t)* realloc((*table).rows, newLength);
    // insert the item
}

int saveDatabase(IN Database_t database)
{
    // write it to the file
}
