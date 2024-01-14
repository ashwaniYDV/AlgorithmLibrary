// https://medium.com/@mithoonkumar/design-an-in-memory-nosql-database-ood-428d48b68dfa

/*
Problem: Design an in-memory database using object-oriented principles.
Suppose you face this question in a design interview. How would you think to solve this problem using object-oriented principles?

Let's start by figuring out the classes that we can have in the system. We can have classes like Database, Table, Row and DatabaseManager.
*/



/*
What are the properties we can think of in a Row class? 

It can have properties like rowId (to uniquely identify a row), columnValuesMap (key-value pairs), createdAt and updateAt. 
Below is an implementation of Row class in java.
*/

import java.util.Date;
import java.util.HashMap;

public class Row {
    private String rowId;
    private HashMap<String, String> columnValuesMap;
    private Date createdAt;
    private Date UpdatedAt;

    public Row(String rowId, HashMap<String, String> columnsMap, Date createdAt, Date updatedAt) {
        this.rowId = rowId;
        this.columnValuesMap = columnsMap;
        this.createdAt = createdAt;
        UpdatedAt = updatedAt;
    }

    public HashMap<String, String> getColumnValuesMap() {
        return columnValuesMap;
    }

    public void setColumnValuesMap(HashMap<String, String> columnValuesMap) {
        this.columnValuesMap = columnValuesMap;
    }

    public String getRowId() {
        return rowId;
    }

    public void setRowId(String rowId) {
        this.rowId = rowId;
    }

    public Date getCreatedAt() {
        return createdAt;
    }

    public void setCreatedAt(Date createdAt) {
        this.createdAt = createdAt;
    }

    public Date getUpdatedAt() {
        return UpdatedAt;
    }

    public void setUpdatedAt(Date updatedAt) {
        UpdatedAt = updatedAt;
    }
}




/*
A table will consist of several rows. It should support all the CRUD operations. 
It should support functionality like adding a row, updating a row, deleting a row, and reading a row. 
Below is an implementation of a Table class in java.
*/

import java.util.Date;
import java.util.HashMap;

public class Table {
    private String tableName;
    private HashMap<String, Row> rows;
    private Date createdAt;

    public Table(String tableName) {
        this.tableName = tableName;
        this.rows = new HashMap<>();
        this.createdAt = new Date();
    }

    public void insertEntry(String rowId, HashMap<String, String> columnsMap) {
        if (rows.containsKey(rowId)) {
            System.out.println("Duplicate primary key : " + " Insertion failed");
        } else {
            Row row =  new Row(rowId, columnsMap, new Date(), new Date());
            rows.put(rowId, row);
            System.out.println("Successfully added a row");
        }
    }

    public void updateEntry(String rowId, HashMap<String, String>valuesMap) {
        Row row = rows.get(rowId);
        valuesMap.forEach( (k, v) -> {
            row.getColumnValuesMap().put(k, v);
        });
        System.out.println("Row successfully updated");
        row.setUpdatedAt(new Date());
    }

    public void deleteEntry(String rowId) {
        System.out.println("Row successfully deleted");
        rows.remove(rowId);
    }

    public HashMap<String, String> readEntry(String rowId) {
        return rows.get(rowId).getColumnValuesMap();
    }


    public HashMap<String, Row> getRows() {
        return rows;
    }

    public void setRows(HashMap<String, Row> rows) {
        this.rows = rows;
    }

    public String getTableName() {
        return tableName;
    }

    public void setTableName(String tableName) {
        this.tableName = tableName;
    }

    public Date getCreatedAt() {
        return createdAt;
    }

    public void setCreatedAt(Date createdAt) {
        this.createdAt = createdAt;
    }
}



/*
Every table is a part of a database. This indicates that a Database will have a map of tables. 
Also, it should support operations like creating a table and deleting a table. This is how a Database class’s implementation looks like.
*/

import java.util.Date;
import java.util.HashMap;

public class Database {
    private String name;
    private HashMap<String, Table> tableHashMap;
    private Date createdAt;

    public Database(String name) {
        this.name = name;
        this.tableHashMap = new HashMap<>();
        this.createdAt = new Date();
    }

    public Table createTable(String tableName) {
        if (tableHashMap.containsKey(tableName)) {
            System.out.println("A table already exists with the given name");
        } else {
            Table table = new Table(tableName);
            tableHashMap.put(tableName, table);
            System.out.println("Table successfully created");
        }
        return tableHashMap.get(tableName);
    }

    public void dropTable(String tableName) {
        tableHashMap.remove(tableName);
        System.out.println("Table successfully dropped");
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public HashMap<String, Table> getTableHashMap() {
        return tableHashMap;
    }

    public void setTableHashMap(HashMap<String, Table> tableHashMap) {
        this.tableHashMap = tableHashMap;
    }

    public Date getCreatedAt() {
        return createdAt;
    }

    public void setCreatedAt(Date createdAt) {
        this.createdAt = createdAt;
    }
}


/*
As we know that in a database management system we can create a database and delete a database. 
For this purpose, we need a DatabaseManager class to manage the database.
*/

import java.util.HashMap;

public class DatabaseManager {
    private HashMap<String, Database> databaseHashMap;

    public DatabaseManager() {
        this.databaseHashMap = new HashMap<>();
    }

    public Database createDatabase(String databaseName) {
        if (databaseHashMap.containsKey(databaseName)) {
            System.out.println("A database already exists with this name");
        } else {
            databaseHashMap.put(databaseName, new Database(databaseName));
        }
        return databaseHashMap.get(databaseName);
    }

    public void deleteDatabase(String databaseName) {
        databaseHashMap.remove(databaseName);
    }

    public HashMap<String, Database> getDatabaseHashMap() {
        return databaseHashMap;
    }

    public void setDatabaseHashMap(HashMap<String, Database> databaseHashMap) {
        this.databaseHashMap = databaseHashMap;
    }
}
