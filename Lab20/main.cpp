#include <iostream>
#include <cstring>

using namespace std;

class Person
{
protected:
    int id;
    char name[20];
public:
//    Constructors
    Person()
    {

    }
    Person(int personId,char* personName)
    {
        id=personId;
        strcpy(name,personName);
    }
//    Setters
    void SetId(int personId)
    {
        id=personId;
    }
    void SetName(char* personName)
    {
        strcpy(name,personName);
    }
//    Getters
    int GetId()
    {
        return id;
    }
    char* GetName()
    {
        return name;
    }
};

class Employee:public Person
{
protected:
    int salary;
public:
//    Constructors
    Employee()
    {
        salary=0;
    }
    Employee(int empSalary)
    {
        salary=empSalary;
    }
    Employee(int empId,char* empName,int empSalary): Person(empId,empName)
    {
        salary=empSalary;
    }
//    Setters
    void SetSalary(int empSalary)
    {
        salary=empSalary;
    }
//    Getters
    int GetSalary()
    {
        return salary;
    }
};

class Customer:public Person
{
    char phone[12];
public:
//    Constructors
    Customer()
    {

    }
    Customer(char* customerPhone)
    {
        strcpy(phone,customerPhone);
    }
    Customer(int customerId,char* customerName,char* customerPhone): Person(customerId,customerName)
    {
        strcpy(phone,customerPhone);
    }
//    Setters
    void SetPhone(char* customerPhone)
    {
        strcpy(phone,customerPhone);
    }
//    Getters
    char* GetPhone()
    {
        return phone;
    }
};

class Contract:public Employee,public Customer
{
protected:
    int price;
public:
//    Constructors
    Contract()
    {

    }
    Contract(int customerId,char* customerName,char* customerPhone,int empId,char* empName,int empSalary,int contractPrice)
    :Customer(customerId,customerName,customerPhone),Employee(empId,empName,empSalary)
    {
        price=contractPrice;
    }
//    Getters
    int GetPrice()
    {
        return price;
    }
};

//Functions
Employee FillEmployeeData();
void PrintEmployeeData(Employee employee);
Customer FillCustomerData();
void PrintCustomerData(Customer customer);
Contract FillContractData();
void PrintContractData(Contract contract);


int main() {
//    Employee employee = FillEmployeeData();
//    cout << "*********************************" << endl;
//    Customer customer = FillCustomerData();
//    cout << "*********************************" << endl;
//    PrintEmployeeData(employee);
//    cout << "*********************************" << endl;
//    PrintCustomerData(customer);

    Contract contract = FillContractData();
    cout << "******************" << endl;
    PrintContractData(contract);
    return 0;
}


Employee FillEmployeeData()
{
    int id;
    char name[20];
    int salary;
    cout << "Employee Id:";
    cin >> id;
    cout << "Employee Name:";
    cin >> name;
    cout << "Employee Salary:";
    cin >> salary;
    return Employee(id,name,salary);
}

void PrintEmployeeData(Employee employee)
{
    cout << "Employee Id:" << employee.GetId() << endl;
    cout << "Employee Name:" << employee.GetName() << endl;
    cout << "Employee Salary:" << employee.GetSalary() << endl;
}

Customer FillCustomerData()
{
    int id;
    char name[20];
    char phone[12];
    cout << "Customer Id:";
    cin >> id;
    cout << "Customer Name:";
    cin >> name;
    cout << "Customer Phone:";
    cin >> phone;
    return Customer(id,name,phone);
}

void PrintCustomerData(Customer customer)
{
    cout << "Customer Id:" << customer.GetId() << endl;
    cout << "Customer Name:" << customer.GetName() << endl;
    cout << "Customer Phone:" << customer.GetPhone() << endl;
}

Contract FillContractData()
{
    int customerId;
    char customerName[20];
    char customerPhone[12];
    int employeeId;
    char employeeName[20];
    int employeeSalary;
    int contractPrice;
    cout << "Customer Id:";
    cin >> customerId;
    cout << "Customer Name:";
    cin >> customerName;
    cout << "Customer Phone:";
    cin >> customerPhone;
    cout << "Employee Id:";
    cin >> employeeId;
    cout << "Employee Name:";
    cin >> employeeName;
    cout << "Employee Salary:";
    cin >> employeeSalary;
    cout << "Contract Price:";
    cin >> contractPrice;
    return Contract(customerId,customerName,customerPhone,employeeId,employeeName,employeeSalary,contractPrice);
}
void PrintContractData(Contract contract)
{
    cout << "Employee Id:" << contract.Employee::GetId() << endl;
    cout << "Employee Name:" << contract.Employee::GetName() << endl;
    cout << "Employee Salary:" << contract.GetSalary() << endl;
    cout << "Customer Id:" << contract.Customer::GetId() << endl;
    cout << "Customer Name:" << contract.Customer::GetName() << endl;
    cout << "Customer Phone:" << contract.GetPhone() << endl;
    cout << "Contract Price:" << contract.GetPrice() << endl;
}

