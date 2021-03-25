#include <iostream>
#include <vector>
using namespace std;

class People
{
protected:
    string name;
    int ID;

public:
    void setName(string name)
    {
        this->name = name;
    }
    void setID(int id)
    {
        ID = id;
    }
};

class Ticket
{
private:
    int value;
    string flightName;

public:
    Ticket() {}
    Ticket(int value, string flightName)
    {
        setValue(value);
        setFligtName(flightName);
    }
    void setFligtName(string flightName)
    {
        this->flightName = flightName;
    }
    void setValue(int value)
    {
        this->value = value;
    }
    int getValue() { return value; }
};

class Customer : public People
{
private:
    int quantity;
    vector<Ticket> ticket;

public:
    vector<Ticket> &getTicketList()
    {
        return ticket;
    }
};

void inputDetailsCustomer(int numberOfCustomer, Customer *&customerList)
{
    for (int i = 0; i < numberOfCustomer; i++)
    {
        cout << "Input details for customer " << i + 1 << ": " << endl;
        cout << "Name? ";
        string name = "";
        cin >> name;
        customerList[i].setName(name);
        cout << "ID? ";
        int id = 0;
        cin >> id;
        customerList[i].setID(id);
        cout << "How many ticket? ";
        int numOfTickets = 0;
        cin >> numOfTickets;
        for (int j = 0; j < numOfTickets; j++)
        {
            cout << "Input fligt name for ticket " << j + 1 << "? ";
            string flightName = "";
            cin >> flightName;
            cout << "Input value for ticket " << j + 1 << "? ";
            int value = 0;
            cin >> value;
            customerList[i].getTicketList().push_back(Ticket(value, flightName));
        }
    }
}
int main()
{
    cout << "Enter number of customer: ";
    int numBerOfCustomer = 0;
    cin >> numBerOfCustomer;
    Customer *customerList = new Customer[numBerOfCustomer];
    inputDetailsCustomer(numBerOfCustomer, customerList);
    cout << "Which customer with sum value? ";
    int whichCustomer = 0;
    cin >> whichCustomer;
    int sum = 0;
    vector<Ticket> temp = customerList[whichCustomer - 1].getTicketList();
    for (auto &it : temp)
    {
        sum += it.getValue();
    }
    cout << "Sum value of customer " << whichCustomer << ": " << sum;
    delete customerList;
}