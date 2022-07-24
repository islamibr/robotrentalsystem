#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <string>
using namespace std;

class users{
public:
    string name, email;
    long long phone;
    char all[999];

    void getUserDetials()
    {
        ofstream out("old-users.txt", ios::app);
        {
        cout << "Enter User's Name: ";
        cin >> name;
        cout << "Enter User's Email: ";
        cin >> email;
        cout << "Enter User's Phone: ";
        cin >> phone;
        }
        out << "\nName: " << name << "\nEmail: " << email << "\nPhone: " << phone << endl;
        out.close();
        cout << "\nSaved" << endl;
    }

    void showUserDetials()
    {
        ifstream in("old-users.txt");
        {
            if(!in)
            {
                cout << "File Error!" << endl;
            }
            while(!in.eof())
            {
                in.getline(all, 999);
                cout << all << endl;
            }
            in.close();
        }
    }
};

class robots{
public:
    int robotChoice;
    string robotName;
    float cost;
    int functions[5];
    char all[999];
    int s;

void getRobotDetials()
        {
            ofstream out("old-robots.txt", ios::app);
            {
            cout << "Enter robot's Name: ";
            cin >> robotName;
            cout << "Enter robots cost: ";
            cin >> cost;
            cout << "Choose the Functions of the Robots:" << endl;
            cout << "1. Cleaner Robot" << endl;
            cout << "2. Driver Robot" << endl;
            cout << "3. Assienment Solver Robot" << endl;
            cout << "4. Cook Robot" << endl;
            cout << "5. HairStylist Robot" << endl;
            cout << "If you finished type '0'" << endl;

            for (int i = 0; i < 4; i++)
            {
                cin >> s;
                if (s == 0)
                {
                    break;
                }
                else
                {
                    functions[i] = s;
                }
            }
            }
            out << "\nName: " << robotName << "\nfunctions: " << functions << "\nprice per day: " << cost << endl;
            out.close();
            cout << "\nSaved" << endl;
        }

        void showRobotDetials()
        {
            ifstream in("old-robots.txt");
            {
                if(!in)
                {
                    cout << "File Error!" << endl;
                }
                while(!in.eof())
                {
                    in.getline(all, 999);
                    cout << all << endl;
                }
                in.close();
            }
        }
};
class rented{
public:
    bool rented;
    string uname;
    string rname;
    string enddate;
    int days;
    int d, m, y;
    string date;
    char all[999];
    int hireRobot;
    float cost;

void rent()
    {
        ofstream out("rent.txt", ios::app);
            {
                    users b2;
                    b2.showUserDetials();
                    cout << "Enter Name of User: " << endl;
                    cin >> uname;
                    robots b1;
                    b1.showRobotDetials();
                    cout << "Enter Name of robot: " << endl;
                    cin >> rname;
                    cout << "Enter number of days: " << endl;
                    cin >> days;
                    cout << "Enter cost of day: " << endl;
                    cin >> cost;
                    cout << "The Cost is: " << days * cost << endl;
                    cout << "Type 1 to countine and 0 to return" << endl;
                    cin >> hireRobot;
                    system("CLS");

                if (hireRobot == 0){
                        rent();
                    }
                else if (hireRobot == 1)
                    {
                    rented = 1;
                    cout << "Enter date of starting" << endl;
                    cout << "Enter day of starting: " << endl;
                    cin >> d;
                    if (d>31 | d<1){
                        cout << "Wrong date";
                        cout << "Enter day of starting: " << endl;
                        cin >> d;
                    }
                    cout << "Enter month of starting: " << endl;
                    cin >> m;
                    if (m>12 | m<1){
                        cout << "Wrong date";
                        cout << "Enter month of starting: " << endl;
                        cin >> m;
                    }
                    cout << "Enter year of starting: " << endl;
                    cin >> y;
                    if (y>2022 | y<1){
                        cout << "Wrong date";
                        cout << "Enter year of starting: " << endl;
                        cin >> y;
                    }
                    date = to_string(d) + "/" + to_string(m) + "/" + to_string(y);
                    enddate = to_string(d+days) + "/" + to_string(m) + "/" + to_string(y);

                    }
               else
                    {
                        cout << "INVALID" << endl;
                        Sleep(999);
                        system("CLS");
                        rent();
                    }
                    }
            out << "\nName of robot: " << rname << "\nName of user: " << uname << "\nprice: " << cost*days << "\ndays rented: " << days <<"\ndate of start: " << date << "\ndate ended: " << enddate <<  endl;
            out.close();
            cout << "\nSaved" << endl;
    }
    void rentDetials()
        {
            ifstream in("rent.txt");
            {
                if(!in)
                {
                    cout << "File Error!" << endl;
                }
                while(!in.eof())
                {
                    in.getline(all, 999);
                    cout << all << endl;
                }
                in.close();
            }
        }
};

void menu()
{
    int mainChoice;
    int inChoice;

    cout << "1. Users Mangement" << endl;
    cout << "2. Robots Mangement" << endl;
    cout << "3. Rent" << endl;
    cout << "Press any to Exit" << endl;

    cout << "\n Enter your choice" << endl;
    cin >> mainChoice;
    system("CLS");

    users a1;
    robots a2;
    rented a3;
    // bills a3;

    if (mainChoice ==1)
    {
        cout << "1. Enter new users" << endl;
        cout << "2. See all users" << endl;

        cout << "\n Enter your choice" << endl;
        cin >> inChoice;
        system("CLS");

        if (inChoice == 1)
        {
            a1.getUserDetials();
        }
        else if (inChoice == 2)
        {
            a1.showUserDetials();
        }
        else
        {
            cout << "INVALID" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
    }
    else if (mainChoice == 2)
    {
        cout << "1. Enter new robots" << endl;
        cout << "2. See all robots" << endl;
        cout << "\n Enter your choice" << endl;
        cin >> inChoice;
        system("CLS");

        if (inChoice == 1)
        {
            a2.getRobotDetials();
        }
        else if (inChoice == 2)
        {
            a2.showRobotDetials();
        }
        else
        {
            cout << "INVALID" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
    }
    else if (mainChoice == 3)
        {
        cout << "1. Enter new rent order" << endl;
        cout << "2. See all rents" << endl;
        cout << "\n Enter your choice" << endl;
        cin >> inChoice;
        system("CLS");

        if (inChoice == 1)
        {
            a3.rent();
        }
        else if (inChoice == 2)
        {
            a3.rentDetials();
        }
        else
        {
            cout << "INVALID" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
        }

    else
    {
        Sleep(1100);
        system("CLS");
        menu();
    }
}

int main()
{
    menu();
    return 0;
}
