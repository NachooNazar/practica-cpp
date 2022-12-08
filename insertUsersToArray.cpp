#include <iostream>
#include <vector>

using namespace std;

void menu()
{
    cout << "What do want? \n";
    cout << "1-add user \n";
    cout << "2-edit user \n";
    cout << "3-delete user \n";
    cout << "4-list user \n";
    cout << "0-leave \n";
}
string addUser(vector<string> &users, string name)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i] == name)
        {
            return "error: User already exists";
        }
    }

    users.push_back(name);
    return "User added succesfully";
}

void deleteUser(vector<string> &users, string name)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i] == name)
        {
            users.erase(users.begin() + i);
            break;
        }
    }
}

void editUser(vector<string> &users, string name, string newName)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i] == name)
        {
            users[i] = newName;
            break;
        }
    }
}

const void getUsers(const vector<string> users)
{

    for (string name : users)
    {
        cout << name << endl;
    }
}

int main()
{

    vector<string> users;

    int opc = -1;
    string name = "";

    menu();
    cin >> opc;
    while (opc != 0)
    {
        switch (opc)
        {
        case 1:
        {
            cout << "Insert a name\n";
            cin >> name;
            string res = addUser(users, name);
            cout << res << endl;
            break;
        }
        case 2:
        {
            string newName;
            cout << "Insert the name to edit\n";
            cin >> name;
            cout << "New Name = \n";
            cin >> newName;
            editUser(users, name, newName);
            break;
        }
        case 3:
        {
            cout << "Insert a name\n";
            cin >> name;
            deleteUser(users, name);
            break;
        }
        case 4:
        {
            getUsers(users);
            break;
        }
        default:
            cout << "default\n";
            break;
        }
        menu();
        cin >> opc;
    }

    return 0;
}
