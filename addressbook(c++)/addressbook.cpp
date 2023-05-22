#include<iostream>
#include"addressbookuser.hpp"
#include"addressbook.hpp"
#include"addressbookmanage.hpp"
#include"addressbookui.hpp"
#include"addressbookinterface.hpp"
#include"mysqlite3.hpp"
#include<string>
using namespace std;

int main(int argc,char **argv)
{
    User *user = new User();
    AddressbookUi *ui = new AddressbookUi();
    string sqlname = "./addressbook.db";
    MySqlite3 *db = new MySqlite3(sqlname);
    AddressbookManager manager(user,ui,db);
    manager.run();
    return 0;
}