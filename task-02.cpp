#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Function Declarations
void registerUser();
void loginUser();
void forgotPassword();
void showUsers();
void deleteAccount();
void changePassword();

bool userExists(string username);

//Main Function
int main()
{
    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "      LOGIN & REGISTRATION SYSTEM\n";
        cout << "=====================================\n";

        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Forgot Password\n";
        cout << "4. Change Password\n";
        cout << "5. Delete Account\n";
        cout << "6. Show All Users\n";
        cout << "0. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                forgotPassword();
                break;

            case 4:
                changePassword();
                break;

            case 5:
                deleteAccount();
                break;

            case 6:
                showUsers();
                break;

            case 0:
                cout << "\nProgram Closed.\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 0);

    return 0;
}


// Check Existing Username
bool userExists(string username)
{
    ifstream file(username + ".txt");

    if(file)
    {
        file.close();
        return true;
    }

    return false;
}


// Registration
void registerUser()
{
    string username, password;

    cout << "\n----- USER REGISTRATION -----\n";

    cout << "Enter Username: ";
    cin >> username;

    // Check duplicate username
    if(userExists(username))
    {
        cout << "Username already exists!\n";
        return;
    }

    cout << "Enter Password: ";
    cin >> password;

    // Simple validation
    if(password.length() < 6)
    {
        cout << "Password must contain at least 6 characters.\n";
        return;
    }

    ofstream file(username + ".txt");

    file << username << endl;
    file << password << endl;

    file.close();

    cout << "\nRegistration Successful!\n";
}


// ---------- Login ----------
void loginUser()
{
    string username, password;
    string storedUser, storedPass;

    cout << "\n----- USER LOGIN -----\n";

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream file(username + ".txt");

    if(!file)
    {
        cout << "Account does not exist.\n";
        return;
    }

    getline(file, storedUser);
    getline(file, storedPass);

    file.close();

    if(username == storedUser && password == storedPass)
    {
        cout << "\nLogin Successful!\n";
        cout << "Welcome, " << username << "!\n";
    }
    else
    {
        cout << "\nIncorrect Password.\n";
    }
}


// ---------- Forgot Password ----------
void forgotPassword()
{
    string username;
    string storedUser, storedPass;

    cout << "\n----- FORGOT PASSWORD -----\n";

    cout << "Enter Username: ";
    cin >> username;

    ifstream file(username + ".txt");

    if(!file)
    {
        cout << "User not found.\n";
        return;
    }

    getline(file, storedUser);
    getline(file, storedPass);

    file.close();

    cout << "Your Password is: " << storedPass << endl;
}


// ---------- Change Password ----------
void changePassword()
{
    string username;
    string oldPass, newPass;
    string storedUser, storedPass;

    cout << "\n----- CHANGE PASSWORD -----\n";

    cout << "Enter Username: ";
    cin >> username;

    ifstream file(username + ".txt");

    if(!file)
    {
        cout << "Account not found.\n";
        return;
    }

    getline(file, storedUser);
    getline(file, storedPass);

    file.close();

    cout << "Enter Old Password: ";
    cin >> oldPass;

    if(oldPass != storedPass)
    {
        cout << "Incorrect Old Password.\n";
        return;
    }

    cout << "Enter New Password: ";
    cin >> newPass;

    ofstream updateFile(username + ".txt");

    updateFile << username << endl;
    updateFile << newPass << endl;

    updateFile.close();

    cout << "Password Updated Successfully!\n";
}


// ---------- Delete Account ----------
void deleteAccount()
{
    string username, password;
    string storedUser, storedPass;

    cout << "\n----- DELETE ACCOUNT -----\n";

    cout << "Enter Username: ";
    cin >> username;

    ifstream file(username + ".txt");

    if(!file)
    {
        cout << "User not found.\n";
        return;
    }

    getline(file, storedUser);
    getline(file, storedPass);

    file.close();

    cout << "Enter Password: ";
    cin >> password;

    if(password == storedPass)
    {
        remove((username + ".txt").c_str());
        cout << "Account Deleted Successfully.\n";
    }
    else
    {
        cout << "Wrong Password.\n";
    }
}


// ---------- Show Users ----------
void showUsers()
{
    cout << "\n----- USER FILES -----\n";
    cout << "All registered users are stored as separate files.\n";
    cout << "Check your project folder to see them.\n";
}