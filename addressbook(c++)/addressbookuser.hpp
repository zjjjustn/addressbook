#pragma once


#include <string>
#include <iostream>

using namespace std;

class User
{
private:
    int _id;
    int _age;
    string _name;
    string _password;
    string _sex;
    string _address;
    string _phone;
    string _email;

public:
    User() = default;

    User(const User &other) noexcept
    {
        this->_id = other._id;
        this->_age = other._age;
        this->_name = other._name;
        this->_password = other._password;
        this->_sex = other._sex;
        this->_address = other._address;
        this->_phone = other._phone;
        this->_email = other._email;
    }

    User &operator=(const User &other) noexcept
    {
        this->_id = other._id;
        this->_age = other._age;
        this->_name = other._name;
        this->_password = other._password;
        this->_sex = other._sex;
        this->_address = other._address;
        this->_phone = other._phone;
        this->_email = other._email;
        return *this;
    }

    void set_id(const int &id)
    {
        _id = id;
    }

    int get_id()
    {
        return _id;
    }

    void set_age(const int &age)
    {
        _age = age;
    }

    int get_age()
    {
        return _age;
    }
    // const char &name
    void set_name(const string &name)
    {
        _name = name;
    }

    string get_name()
    {
        return _name;
    }

    void set_password(const string &password)
    {
        _password = password;
    }

    string get_password()
    {
        return _password;
    }

    void set_sex(const string &sex)
    {
        _sex = sex;
    }

    string get_sex()
    {
        return _sex;
    }

    void set_address(const string &address)
    {
        _address = address;
    }

    string get_address()
    {
        return _address;
    }

    void set_phone(const string &phone)
    {
        _phone = phone;
    }

    string get_phone()
    {
        return _phone;
    }

    void set_email(const string &email)
    {
        _email = email;
    }

    string get_email()
    {
        return _email;
    }

    friend ostream &operator<<(ostream &out, User &user)
    {
        out << endl;
        out << "id : " << user._id << endl;
        out << "name: " << user._name << endl;
        out << "age : " << user._age << endl;
        out << "sex : " << user._sex << endl;
        out << "phone : " << user._phone << endl;
        out << "address : " << user._address << endl;
        out << "mail : " << user._email << endl;
        out << endl;
        return out;
    }

    virtual ~User() noexcept
    {
    }
};