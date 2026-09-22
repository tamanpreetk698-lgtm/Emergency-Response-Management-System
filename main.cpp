#include <iostream>
#include <string>
using namespace std;

class Emergency
{
public:
    int id;
    string name;
    string problem;
    string location;
    int priority;
    string status;

    void input()
    {
        cout << "\nEnter Emergency ID: ";
        cin >> id;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Problem: ";
        cin >> problem;

        cout << "Enter Location: ";
        cin >> location;

        cout << "Enter Priority (1 = High, 2 = Medium, 3 = Low): ";
        cin >> priority;

        status = "Pending";
    }

    void display()
    {
        cout << "\n-----------------------------";
        cout << "\nID: " << id;
        cout << "\nName: " << name;
        cout << "\nProblem: " << problem;
        cout << "\nLocation: " << location;

        cout << "\nPriority: ";

        if(priority == 1)
            cout << "HIGH";
        else if(priority == 2)
            cout << "MEDIUM";
        else
            cout << "LOW";

        cout << "\nStatus: " << status;
        cout << "\n-----------------------------";
    }
};


int main()
{
    Emergency requests[100];

    int count = 0;
    int choice;

    do
    {
        cout << "\n\n===== EMERGENCY RESPONSE SYSTEM =====";
        cout << "\n1. Add Emergency Request";
        cout << "\n2. Display All Requests";
        cout << "\n3. Search Request";
        cout << "\n4. Update Priority";
        cout << "\n5. Resolve Request";
        cout << "\n6. Delete Request";
        cout << "\n7. Sort by Priority";
        cout << "\n8. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;


        // ADD
        if(choice == 1)
        {
            requests[count].input();
            count++;

            cout << "\nRequest added successfully!";
        }


        // DISPLAY
        else if(choice == 2)
        {
            if(count == 0)
            {
                cout << "\nNo emergency requests available.";
            }

            for(int i = 0; i < count; i++)
            {
                requests[i].display();
            }
        }


        // SEARCH
        else if(choice == 3)
        {
            int id;
            bool found = false;

            cout << "\nEnter Emergency ID: ";
            cin >> id;

            for(int i = 0; i < count; i++)
            {
                if(requests[i].id == id)
                {
                    requests[i].display();
                    found = true;
                    break;
                }
            }

            if(found == false)
            {
                cout << "\nRequest not found.";
            }
        }


        // UPDATE PRIORITY
        else if(choice == 4)
        {
            int id;
            bool found = false;

            cout << "\nEnter Emergency ID: ";
            cin >> id;

            for(int i = 0; i < count; i++)
            {
                if(requests[i].id == id)
                {
                    cout << "\nEnter new priority";
                    cout << "\n1 = High";
                    cout << "\n2 = Medium";
                    cout << "\n3 = Low";

                    cout << "\nEnter: ";
                    cin >> requests[i].priority;

                    cout << "\nPriority updated!";
                    found = true;
                    break;
                }
            }

            if(found == false)
            {
                cout << "\nRequest not found.";
            }
        }


        // RESOLVE
        else if(choice == 5)
        {
            int id;
            bool found = false;

            cout << "\nEnter Emergency ID: ";
            cin >> id;

            for(int i = 0; i < count; i++)
            {
                if(requests[i].id == id)
                {
                    requests[i].status = "Resolved";

                    cout << "\nRequest resolved!";
                    found = true;
                    break;
                }
            }

            if(found == false)
            {
                cout << "\nRequest not found.";
            }
        }


        // DELETE
        else if(choice == 6)
        {
            int id;
            bool found = false;

            cout << "\nEnter Emergency ID: ";
            cin >> id;

            for(int i = 0; i < count; i++)
            {
                if(requests[i].id == id)
                {
                    for(int j = i; j < count - 1; j++)
                    {
                        requests[j] = requests[j + 1];
                    }

                    count--;

                    cout << "\nRequest deleted!";
                    found = true;
                    break;
                }
            }

            if(found == false)
            {
                cout << "\nRequest not found.";
            }
        }


        // SORT
        else if(choice == 7)
        {
            for(int i = 0; i < count - 1; i++)
            {
                for(int j = 0; j < count - i - 1; j++)
                {
                    if(requests[j].priority >
                       requests[j + 1].priority)
                    {
                        Emergency temp;

                        temp = requests[j];
                        requests[j] = requests[j + 1];
                        requests[j + 1] = temp;
                    }
                }
            }

            cout << "\nRequests sorted by priority!";
        }


        // EXIT
        else if(choice == 8)
        {
            cout << "\nThank you for using the system!";
        }


        else
        {
            cout << "\nInvalid choice!";
        }

    }
    while(choice != 8);


    return 0;
}
