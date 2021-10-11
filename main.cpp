#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class vehicle
{
public:
    time_t entryTime;
    string vehicleNo;
    string ownerName;

    virtual void getInfo() = 0;
    virtual void checkOut() = 0;
};

class twoWheeler : public vehicle
{
public:
    static int availableSpace;

    static void update(int space)
    {
        availableSpace += space;
    }

    void getInfo()
    {
        cout << "Enter Owner's Name\n";
        cin >> ownerName;
        cout << "Enter Vehicle(two-Wheeler) Number\n";
        cin >> vehicleNo;
        entryTime = time(NULL);
        availableSpace--;
    }
    void checkOut()
    {
        long amount = (time(NULL) - entryTime) * 2 * 100;
        cout << "Vehicle Details:\n";
        cout << "Owner Name: " << ownerName << '\n';
        cout << "Vehicle Number: " << vehicleNo << '\n';
        cout << "Parking fees: " << amount << '\n';
        availableSpace++;
    }
};

class fourWheeler : public vehicle
{
public:
    static int availableSpace;

    static void update(int space)
    {
        availableSpace += space;
    }

    void getInfo()
    {
        cout << "Enter Owner's Name\n";
        cin >> ownerName;
        cout << "Enter Vehicle(four-Wheeler) Number\n";
        cin >> vehicleNo;
        entryTime = time(NULL);
        availableSpace--;
    }
    void checkOut()
    {
        long amount = (time(NULL) - entryTime) * 4 * 100;
        cout << "Vehicle Details:\n";
        cout << "Owner Name: " << ownerName << '\n';
        cout << "Vehicle Number: " << vehicleNo << '\n';
        cout << "Parking fees: " << amount << '\n';
        availableSpace++;
    }
};

class heavyVehicle : public vehicle
{
public:
    static int availableSpace;

    static void update(int space)
    {
        availableSpace += space;
    }

    void getInfo()
    {
        cout << "Enter Owner's Name\n";
        cin >> ownerName;
        cout << "Enter Vehicle(heavy-vehicle) Number\n";
        cin >> vehicleNo;
        entryTime = time(NULL);
        availableSpace--;
    }
    void checkOut()
    {
        long amount = (time(NULL) - entryTime) * 6 * 100;
        cout << "Vehicle Details:\n";
        cout << "Owner Name: " << ownerName << '\n';
        cout << "Vehicle Number: " << vehicleNo << '\n';
        cout << "Parking fees: " << amount << '\n';
        availableSpace++;
    }
};
int twoWheeler::availableSpace = 10;
int fourWheeler::availableSpace = 10;
int heavyVehicle::availableSpace = 5;
vector<vehicle *> parkingLot;

void printMenu()
{
    cout << "-----Main menu-----\n";
    cout << "\t1.Park a vehicle\n";
    cout << "\t2.See available slots\n";
    cout << "\t3.Find your vehicle\n";
    cout << "\t4.Leave the parking lot\n";
    cout << "\t5.Exit\n";
}

void customer()
{
    int ch1, ch2;
    string vehicleNum;
    char choice;
    vector<vehicle *>::iterator it;
    do
    {
        system("clear");
        printMenu();
        cout << "\tEnter your choice\n";
        cin >> ch1;
        switch (ch1)
        {
        case 1:
            cout << "\t1. Two-Wheeler\n";
            cout << "\t2. Four-Wheeler\n";
            cout << "\t3. Heavy-Vehicle\n";
            cin >> ch2;
            switch (ch2)
            {
            case 1:
                if (twoWheeler::availableSpace == 0)
                {
                    cout << "No Two-Wheeler Space Available\n";
                }
                else
                {
                    parkingLot.push_back(new twoWheeler());
                    parkingLot.back()->getInfo();
                }
                break;
            case 2:
                if (fourWheeler::availableSpace == 0)
                {
                    cout << "No Four-Wheeler Space Available\n";
                }
                else
                {
                    parkingLot.push_back(new fourWheeler());
                    parkingLot.back()->getInfo();
                }
                break;
            case 3:
                if (heavyVehicle::availableSpace == 0)
                {
                    cout << "No Heavy-Vehicle Space Available\n";
                }
                else
                {
                    parkingLot.push_back(new heavyVehicle());
                    parkingLot.back()->getInfo();
                }
                break;
            }
            break;
        case 2:
            cout << "Available space \n";
            cout << "Two-Wheeler : " << twoWheeler::availableSpace << '\n';
            cout << "Four-Wheeler : " << fourWheeler::availableSpace << '\n';
            cout << "Heavy Vehicle : " << heavyVehicle::availableSpace << '\n';
            break;
        case 3:
            cout << "Enter your vehicle number\n";
            cin >> vehicleNum;
            for (it = parkingLot.begin(); it != parkingLot.end(); it++)
            {
                if ((*it)->vehicleNo == vehicleNum)
                {
                    cout << "Vehicle Details:\n";
                    cout << "Owner Name: " << (*it)->ownerName << '\n';
                    cout << "Vehicle Number: " << (*it)->vehicleNo << '\n';
                    cout << "Slot No: " << it - parkingLot.begin() << '\n';
                    break;
                }
            }
            if (it == parkingLot.end())
            {
                cout << "Vehicle not found\n";
            }
            break;
        case 4:
            cout << "Enter your vehicle number\n";
            cin >> vehicleNum;
            for (it = parkingLot.begin(); it != parkingLot.end(); it++)
            {
                if ((*it)->vehicleNo == vehicleNum)
                {
                    (*it)->checkOut();
                    delete *it;
                    break;
                }
            }

            if (it == parkingLot.end())
            {
                cout << "Vehicle not found\n";
            }
            else
            {
                parkingLot.erase(it);
            }
            break;
        case 5:
            return;
        default:
            cout << "Enter valid choice\n";
            return;
            break;
        }
        cout << "Do you want to continue(y/n)\n";
        cin >> choice;
    } while (choice == 'y');
}

void admin()
{
    int ch;
    char choice;
    int twoWheelerSpace, fourWheelerSpace, heavyVehicleSpace;
    vector<vehicle *>::iterator it;
    do
    {
        system("clear");
        cout << "1.View all vehicles Parked\n";
        cout << "2.Update number of slots\n";
        cout << "3.Exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            for (it = parkingLot.begin(); it != parkingLot.end(); it++)
            {
                cout << "Vehicle Details:\n";
                cout << "Owner Name: " << (*it)->ownerName << '\n';
                cout << "Vehicle Number: " << (*it)->vehicleNo << '\n';
                cout << "Slot No: " << it - parkingLot.begin() << '\n';
            }
            break;
        case 2:
            cout << "Enter the number of slots to be added(Two wheeler,Four wheeler,Heavy vehicle)\n";
            cin >> twoWheelerSpace >> fourWheelerSpace >> heavyVehicleSpace;
            twoWheeler::update(twoWheelerSpace);
            fourWheeler::update(fourWheelerSpace);
            heavyVehicle::update(heavyVehicleSpace);
            break;
        case 3:
            return;
            break;
        default:
            cout << "Enter a valid choice\n";
            return;
            break;
        }
        cout << "Do you want to continue(y/n)\n";
        cin >> choice;
    } while (choice == 'y');
}

int main()
{
    int ch;
    while (1)
    {
        system("clear");
        cout << "-----LOGIN-----\n";
        cout << "1.Admin\n";
        cout << "2.Customer\n";
        cout << "3.Exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            admin();
            break;
        case 2:
            customer();
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "Enter a valid choice\n";
            exit(0);
            break;
        }
    }

    return 0;
}