#pragma once

#include <iostream>
#include "addressbookuser.hpp"
#include "MySqlite3.hpp"

using namespace std;

template <typename T>
class Addressbook
{
private:
public:
    Addressbook() = default;

    virtual void my_insert(T &value) = 0;
    virtual void my_update(int &id, T &value) = 0;
    virtual void my_delete(T &value) = 0;
    virtual void my_select(T &value) = 0;
    virtual void my_view(void) = 0;
    virtual void my_create(void) = 0;

    virtual ~Addressbook()
    {
    }
};

template <typename T>
class Sql : public Addressbook<User>
{
private:
    MySqlite3 my_sql;

public:
    Sql() = default;
    Sql(MySqlite3 sql) : my_sql(sql)
    {
    }

    void my_create(void) override
    {
        string sql = "create table if not exists addbook(id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,name varchar(255),age integer,sex varchar(255),address varchar(255),phone varchar(255),email varchar(255));";
        if (this->my_sql.run_sqlite3(sql))
        {
            cout << "create success" << endl;
        }
    }

    void my_insert(T &value) override
    {
        cout << "2:" << value << endl;
        char sql[1024];
        sprintf(sql, "insert into addbook(name,age,sex,address,phone,email) values(%s,%d,%s,%s,%s,%s)",
                value.get_name().c_str(), value.get_age(), value.get_sex().c_str(), value.get_address().c_str(), value.get_phone().c_str(), value.get_email().c_str());
        if (this->my_sql.run_sqlite3(sql))
        {
            cout << "insert success" << endl;
        }
    }

    void my_select(T &value) override
    {
        char sql[1024];
        sprintf(sql, "select * from addbook where id = '%d'", value.get_id());
        this->my_sql.run_sqlite3(sql, value);
        cout << "select over " << endl;
    }

    void my_view(void)
    {
        User view_user;
        string sql = "select * from addbook";
        this->my_sql.run_sqlite3(sql, view_user);
        cout << "view over " << endl;
    }

    void my_delete(T &value) override
    {
        char sql[1024];
        sprintf(sql, "delete from addbook where id = '%d' ", value.get_id());
        if (this->my_sql.run_sqlite3(sql))
        {
            cout << "delete successfully" << endl;
        }
    }

    void my_update(int &id, T &value) override
    {
        char sql[1024];
        sprintf(sql, "update addbook set name = '%s',age = '%d',sex = '%s',address = '%s',phone = '%s',email = '%s' where id = '%d'",
                value.get_name().c_str(), value.get_age(), value.get_sex().c_str(),
                value.get_address().c_str(), value.get_phone().c_str(), value.get_email().c_str(), id);
        if (this->my_sql.run_sqlite3(sql))
        {
            cout << "update successfully" << endl;
        }
    }

    ~Sql()
    {
    }
};
