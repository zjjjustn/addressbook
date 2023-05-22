#pragma once

#include <iostream>

using namespace std;

class Interface
{
public:
     Interface() = default;

     virtual void set_interface(const char *dition = nullptr) = 0;
     virtual void set_userface() = 0;
     virtual void set_reglogin(int &options) = 0;

     virtual ~Interface()
     {
     }
};

class Interface1 : public Interface
{
public:
     Interface1() = default;

     void set_interface(const char *edition = nullptr) override
     {
          cout << endl
               << endl;
          cout << '\t' << "Interface  " << '\t' << '\t' << edition << endl;
          cout << endl
               << endl;
          cout << '\t' << "(1)insert " << '\t' << '\t' << "(2)view" << endl
               << endl
               << endl;
          cout << '\t' << "(3)search " << '\t' << '\t' << "(4)delete" << endl
               << endl
               << endl;
          cout << '\t' << "(5)modify " << '\t' << '\t' << "(6)quit" << endl
               << endl
               << endl;
          cout << '\t' << "Please enter your choice(like 1 or 6)." << endl
               << endl
               << endl;
     }

     void set_userface() override
     {
          cout << endl
               << endl;
          cout << '\t' << "(1)id " << '\t' << '\t' << "(2)name" << endl
               << endl
               << endl;
          cout << '\t' << "(3)age " << '\t' << '\t' << "(4)sex" << endl
               << endl
               << endl;
          cout << '\t' << "(5)address " << '\t' << '\t' << "(6)phone" << endl
               << endl
               << endl;
          cout << '\t' << "(7)mail " << '\t' << '\t' << "(8)quit" << endl
               << endl
               << endl;
          cout << '\t' << "Please enter your choice(like 1 or 2)." << endl
               << endl
               << endl;
     }

     void set_reglogin(int &options) override
     {
          cout << endl
               << endl;
          cout << "(1)register" << '\t' << '\t' << "(2)login" << endl;
          cout << endl
               << endl;
          cout << "input 1 or 2" << endl;
          cin >> options;
     }

     ~Interface1()
     {
     }
};