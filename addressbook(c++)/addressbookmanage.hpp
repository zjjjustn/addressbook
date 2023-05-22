#pragma once

#include <iostream>
#include "AddressbookUi.hpp"
#include "addressbookuser.hpp"
#include "MySqlite3.hpp"
#include "addressbookinterface.hpp"
#include <string.h>
#include "Addressbook.hpp"

using namespace std;

class AddressbookManager
{
private:
    User *user;
    Interface *interface;
    AddressbookUi *ui;
    Addressbook<User> *addressbook;
    int options;

public:
    AddressbookManager() = default;

    AddressbookManager(User *user, AddressbookUi *ui, MySqlite3 *sql) : user(user), ui(ui), options(0)
    {
        interface = new Interface1();
        addressbook = new Sql<User>(*sql);
    }

    void add_insert()
    {
        ui->insert(*(this->user));
        cout << *user << endl;
        addressbook->my_insert(*(this->user));
        ui->pause();
    }

    void add_view()
    {
        addressbook->my_view();
        ui->pause();
    }

    void add_search()
    {
        int num = 0;
        ui->search_num(num);
        this->user->set_id(num);
        addressbook->my_select(*(this->user));
        ui->pause();
    }

    void add_delete()
    {
        int num = 0;
        ui->delete_num(num);
        this->user->set_id(num);
        addressbook->my_delete(*(this->user));
        ui->pause();
    }

    void add_update()
    {
        int num = 0;
        ui->update_num(num);
        User up_user;
        ui->update<User>(up_user);
        addressbook->my_update(num, (up_user));
        ui->pause();
    }

    void run()
    {
        addressbook->my_create();
        while (1)
        {

            interface->set_interface("addressbook 6");
            // scanf("%d", &this->options);
            cin >> this->options;
            switch (this->options)
            {
            case 1:
            {
                this->add_insert();
                break;
            }
            case 2:
            {
                this->add_view();
                break;
            }
            case 3:
            {
                this->add_search();
                break;
            }
            case 4:
            {
                this->add_delete();
                break;
            }
            case 5:
            {
                this->add_update();
                break;
            }
            case 6:
            {
                return;
            }
            default:
            {
                cout << "input a number" << endl;
                break;
            }
            }
        }
    }

    ~AddressbookManager()
    {
    }
};