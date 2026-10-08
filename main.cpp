#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Hotel
{
public:
    int roomNo;
    string name;
    int days;

    void reserveRoom()
    {
        cout << "\nEnter Room Number (1-10): ";
        cin >> roomNo;

        cout << "Enter Customer Name: ";
        cin >> name;

        cout << "Enter Number of Days: ";
        cin >> days;
    }

    void display()
    {
        cout << "\nRoom Number    : " << roomNo;
        cout << "\nCustomer Name  : " << name;
        cout << "\nNumber of Days : " << days << endl;
    }
};

int main()
{
    Hotel h[10];

    int occupied[10] = {0};
    int choice;
    int count = 0;

    do
    {
        cout << "\n\n========== HOTEL MANAGEMENT ==========\n";
        cout << "1. Reserve Room\n";
        cout << "2. Display Empty Rooms\n";
        cout << "3. Display Reservations\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                if(count >= 5)
                {
                    cout << "\nMaximum 5 records can be stored.\n";
                    break;
                }

                int room;

                cout << "\nEnter room number (1-10): ";
                cin >> room;

                if(room < 1 || room > 10)
                {
                    cout << "Invalid room number!\n";
                    break;
                }

                if(occupied[room - 1] == 1)
                {
                    cout << "Room is already reserved!\n";
                    break;
                }

                h[count].roomNo = room;

                cout << "Enter Customer Name: ";
                cin >> h[count].name;

                cout << "Enter Number of Days: ";
                cin >> h[count].days;

                occupied[room - 1] = 1;
                count++;

                cout << "\nRoom reserved successfully!\n";

                break;
            }

            case 2:
            {
                int emptyRooms = 0;

                cout << "\n========== EMPTY ROOMS ==========\n";

                for(int i = 0; i < 10; i++)
                {
                    if(occupied[i] == 0)
                    {
                        cout << "Room " << i + 1 << " is empty.\n";
                        emptyRooms++;
                    }
                }

                cout << "\nNumber of Empty Rooms: "
                     << emptyRooms << endl;

                break;
            }

            case 3:
            {
                cout << "\n========== RESERVATION DETAILS ==========\n";

                if(count == 0)
                {
                    cout << "No reservations found.\n";
                }
                else
                {
                    for(int i = 0; i < count; i++)
                    {
                        cout << "\nRecord " << i + 1;
                        h[i].display();
                    }
                }

                break;
            }

            case 4:
            {
                cout << "\nThank you for using Hotel Management System!\n";
                break;
            }

            default:
            {
                cout << "\nInvalid choice!\n";
            }
        }

    } while(choice != 4);

    return 0;
}