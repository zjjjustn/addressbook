#pragma once

#include <iostream>
#include "addressbookinterface.hpp"

using namespace std;

class AddressbookUi
{
private:
public:
    AddressbookUi() = default;

    void pause()
    {
        cout << "Enter any key to continue " << endl;
        char ch;
        cin >> ch;
    }

    template <typename T>
    void reglog(const T &data)
    {
        string s_data;
        cout << "input name :" << endl;
        cin >> s_data;
        data.set_name(s_data);

        cout << "input password :" << endl;
        cin >> s_data;
        data.set_password(s_data);
    }

    template <typename T>
    void insert(T &data)
    {
        int i_data;
        string s_data;

        cout << "input name" << endl;
        cin >> s_data;
        data.set_name(s_data);

        cout << "input age" << endl;
        cin >> i_data;
        data.set_age(i_data);

        cout << "input sex" << endl;
        cin >> s_data;
        data.set_sex(s_data);

        cout << "input address" << endl;
        cin >> s_data;
        data.set_address(s_data);

        cout << "input phone" << endl;
        cin >> s_data;
        data.set_phone(s_data);

        cout << "input email" << endl;
        cin >> s_data;
        data.set_email(s_data);
    }

    void search_num(int &num)
    {
        cout << "input search number" << endl;
        cin >> num;
    }

    void update_num(int &num)
    {
        cout << "input update number" << endl;
        cin >> num;
    }

    template <typename T>
    void update(T &data)
    {
        int i_data;
        string s_data;

        cout << "input name" << endl;
        cin >> s_data;
        data.set_name(s_data);
        
        cout << "input age" << endl;
        cin >> i_data;
        data.set_age(i_data);
       
        cout << "input sex" << endl;
        cin >> s_data;
        data.set_sex(s_data);
       
        cout << "input address" << endl;
        cin >> s_data;
        data.set_address(s_data);
       
        cout << "input phone" << endl;
        cin >> s_data;
        data.set_phone(s_data);
      
        cout << "input email" << endl;
        cin >> s_data;
        data.set_email(s_data);
    
    }

    void delete_num(int &num)
    {
        cout << "input deleting number" << endl;
        cin >> num;
    }

    ~AddressbookUi() = default;
};