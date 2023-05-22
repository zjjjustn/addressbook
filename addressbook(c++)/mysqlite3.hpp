#pragma once

#include <iostream>
#include <sqlite3.h>
#include "addressbookuser.hpp"

using namespace std;

int my_select1(void *param, int column_count, char **column_values, char **column_name)
{
    bool ok = (bool)param;
    ok = true;
    return 0;
}

int my_select2(void *param, int column_count, char **column_values, char **column_name)
{
    User user;

    user.set_id(atoi((column_values[0])));
    user.set_name(column_values[1]);
    user.set_age(atoi((column_values[2])));
    user.set_sex(column_values[3]);
    user.set_address(column_values[4]);
    user.set_phone(column_values[5]);
    user.set_email(column_values[6]);

    // (*(*((User **)param))).set_id(user.get_id());
    cout << user << endl;
    return 0;
}

class MySqlite3
{
private:
    string _name;

public:
    MySqlite3() = default;

    MySqlite3(string &sql_name) : _name(sql_name) 
    {
    }

    // sqlite3* get_db()
    // {
    //     return this->_db;
    // }
    MySqlite3(const MySqlite3 &other) noexcept
    {
        this->_name = other._name;
    }

    bool run_sqlite3(string sql)
    {
        sqlite3 *db;
        sqlite3_open(this->_name.c_str(), &db);
        char *errmsg;
        int ret = sqlite3_exec(db, sql.c_str(), NULL, NULL, &errmsg);
        if (ret == SQLITE_OK)
        {
            sqlite3_close(db);
            return true;
        }
        else
        {
            printf("SQLite3 error : %s\n", sqlite3_errmsg(db));
            sqlite3_close(db);
            return false;
        }
    }

    friend int my_select1(void *param, int column_count, char **column_values, char **column_name);

    friend int my_select2(void *param, int column_count, char **column_values, char **column_name);

    bool run_sqlite3(string sql, bool &exists)
    {
        sqlite3 *db;
        sqlite3_open(this->_name.c_str(), &db);
        char *errmsg;
        int ret = sqlite3_exec(db, sql.c_str(), my_select1, (void *)exists, &errmsg);
        if (ret == SQLITE_OK)
        {
            sqlite3_close(db);
            return true;
        }
        else
        {
            printf("SQLite3 error : %s\n", sqlite3_errmsg(db));
            sqlite3_close(db);
            return false;
        }
    }

    bool run_sqlite3(string sql, User &user)
    {
        sqlite3 *db;
        sqlite3_open(this->_name.c_str(), &db);
        char *errmsg;
        int ret = sqlite3_exec(db, sql.c_str(), my_select2, NULL, &errmsg);
        if (ret == SQLITE_OK)
        {
            sqlite3_close(db);
            return true;
        }
        else
        {
            printf("SQLite3 error : %s\n", sqlite3_errmsg(db));
            sqlite3_close(db);
            return false;
        }
    }

    ~MySqlite3() noexcept
    {

    }
};
