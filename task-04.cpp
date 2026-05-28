#include <iostream>
#include <vector>
#include <string>

using namespace std;


// ---------- Transaction Class ----------
class Transaction
{
public:

    string transactionType;
    double amount;

    Transaction(string type, double money)
    {
        transactionType = type;
        amount = money;
    }
};


// ---------- Account Class ----------
class Account
{
private:

    int accountNumber;
    double balance;

    vector<Transaction> transactionHistory;

public:

    // Constructor
    Account(int accNo, double initialBalance = 0)
    {
        accountNumber = accNo;
        balance = initialBalance;
    }


    // Get Account Number
    int getAccountNumber()
    {
        return accountNumber;
    }


    // Get Balance
    double getBalance()
    {
        return balance;
    }


    // Deposit Function
    void depositMoney(double amount)
    {
        if(amount <= 0)
        {
            cout << "Invalid Deposit Amount.\n";
            return;
        }

        balance += amount;

        transactionHistory.push_back(
            Transaction("Deposit", amount)
        );

        cout << "Deposit Successful.\n";
    }


    // Withdraw Function
    void withdrawMoney(double amount)
    {
        if(amount <= 0)
        {
            cout << "Invalid Withdrawal Amount.\n";
            return;
        }

        if(amount > balance)
        {
            cout << "Insufficient Balance.\n";
            return;
        }

        balance -= amount;

        transactionHistory.push_back(
            Transaction("Withdraw", amount)
        );

        cout << "Withdrawal Successful.\n";
    }


    // Transfer Money
    void transferMoney(Account &receiver, double amount)
    {
        if(amount <= 0)
        {
            cout << "Invalid Transfer Amount.\n";
            return;
        }

        if(amount > balance)
        {
            cout << "Insufficient Balance.\n";
            return;
        }

        balance -= amount;
        receiver.balance += amount;

        transactionHistory.push_back(
            Transaction("Transfer Sent", amount)
        );

        receiver.transactionHistory.push_back(
            Transaction("Transfer Received", amount)
        );

        cout << "Transfer Successful.\n";
    }


    // Show Transactions
    void showTransactions()
    {
        cout << "\n----- TRANSACTION HISTORY -----\n";

        if(transactionHistory.empty())
        {
            cout << "No Transactions Available.\n";
            return;
        }

        for(int i = 0; i < transactionHistory.size(); i++)
        {
            cout << i + 1 << ". ";

            cout << transactionHistory[i].transactionType
                 << " : Rs. "
                 << transactionHistory[i].amount
                 << endl;
        }
    }


    // Display Account Info
    void displayAccountInfo()
    {
        cout << "\n----- ACCOUNT DETAILS -----\n";

        cout << "Account Number : " << accountNumber << endl;
        cout << "Current Balance: Rs. " << balance << endl;
    }
};



// ---------- Customer Class ----------
class Customer
{
private:

    int customerID;
    string customerName;

    Account account;

public:

    // Constructor
    Customer(int id, string name, int accNo, double balance)
        : account(accNo, balance)
    {
        customerID = id;
        customerName = name;
    }


    // Get Customer ID
    int getCustomerID()
    {
        return customerID;
    }


    // Get Account Object
    Account& getAccount()
    {
        return account;
    }


    // Show Customer Info
    void displayCustomerInfo()
    {
        cout << "\n=================================\n";

        cout << "Customer ID   : " << customerID << endl;
        cout << "Customer Name : " << customerName << endl;

        account.displayAccountInfo();

        cout << "=================================\n";
    }
};



// ---------- Find Customer ----------
int findCustomer(vector<Customer> &customers, int id)
{
    for(int i = 0; i < customers.size(); i++)
    {
        if(customers[i].getCustomerID() == id)
        {
            return i;
        }
    }

    return -1;
}



// ---------- Main Function ----------
int main()
{
    vector<Customer> customers;

    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "         BANKING MANAGEMENT SYSTEM\n";
        cout << "=====================================\n";

        cout << "1. Create Customer Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Transfer Funds\n";
        cout << "5. View Account Details\n";
        cout << "6. View Transaction History\n";
        cout << "7. Show All Customers\n";
        cout << "0. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;


        switch(choice)
        {
            case 1:
            {
                int customerID;
                int accountNumber;

                string customerName;

                double initialBalance;

                cout << "\nEnter Customer ID: ";
                cin >> customerID;

                if(findCustomer(customers, customerID) != -1)
                {
                    cout << "Customer ID already exists.\n";
                    break;
                }

                cin.ignore();

                cout << "Enter Customer Name: ";
                getline(cin, customerName);

                cout << "Enter Account Number: ";
                cin >> accountNumber;

                cout << "Enter Initial Balance: ";
                cin >> initialBalance;

                customers.push_back(
                    Customer(
                        customerID,
                        customerName,
                        accountNumber,
                        initialBalance
                    )
                );

                cout << "\nCustomer Account Created Successfully.\n";

                break;
            }


            case 2:
            {
                int customerID;
                double amount;

                cout << "\nEnter Customer ID: ";
                cin >> customerID;

                int index = findCustomer(customers, customerID);

                if(index == -1)
                {
                    cout << "Customer Not Found.\n";
                    break;
                }

                cout << "Enter Deposit Amount: ";
                cin >> amount;

                customers[index].getAccount().depositMoney(amount);

                break;
            }


            case 3:
            {
                int customerID;
                double amount;

                cout << "\nEnter Customer ID: ";
                cin >> customerID;

                int index = findCustomer(customers, customerID);

                if(index == -1)
                {
                    cout << "Customer Not Found.\n";
                    break;
                }

                cout << "Enter Withdrawal Amount: ";
                cin >> amount;

                customers[index].getAccount().withdrawMoney(amount);

                break;
            }


            case 4:
            {
                int senderID, receiverID;

                double amount;

                cout << "\nEnter Sender Customer ID: ";
                cin >> senderID;

                cout << "Enter Receiver Customer ID: ";
                cin >> receiverID;

                int senderIndex = findCustomer(customers, senderID);
                int receiverIndex = findCustomer(customers, receiverID);

                if(senderIndex == -1 || receiverIndex == -1)
                {
                    cout << "Invalid Customer ID.\n";
                    break;
                }

                cout << "Enter Transfer Amount: ";
                cin >> amount;

                customers[senderIndex]
                    .getAccount()
                    .transferMoney(
                        customers[receiverIndex].getAccount(),
                        amount
                    );

                break;
            }


            case 5:
            {
                int customerID;

                cout << "\nEnter Customer ID: ";
                cin >> customerID;

                int index = findCustomer(customers, customerID);

                if(index == -1)
                {
                    cout << "Customer Not Found.\n";
                    break;
                }

                customers[index].displayCustomerInfo();

                break;
            }


            case 6:
            {
                int customerID;

                cout << "\nEnter Customer ID: ";
                cin >> customerID;

                int index = findCustomer(customers, customerID);

                if(index == -1)
                {
                    cout << "Customer Not Found.\n";
                    break;
                }

                customers[index]
                    .getAccount()
                    .showTransactions();

                break;
            }


            case 7:
            {
                if(customers.empty())
                {
                    cout << "\nNo Customers Available.\n";
                    break;
                }

                for(int i = 0; i < customers.size(); i++)
                {
                    customers[i].displayCustomerInfo();
                }

                break;
            }


            case 0:
            {
                cout << "\nProgram Closed.\n";
                break;
            }


            default:
            {
                cout << "\nInvalid Choice.\n";
            }
        }

    } while(choice != 0);

    return 0;
}