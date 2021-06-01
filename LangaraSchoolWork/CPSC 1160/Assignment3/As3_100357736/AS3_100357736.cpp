#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int SIZE = 20;

struct Employee
{
    int id;
    string department;
    string gender;
    string firstName;
    string lastName;
    double salary;
};
void readData(Employee[]);
void displayAll(Employee[]);
void merge(int array1[], int arraySize, int array2[], int array2Size, int temp[]);
void arrayCopy(int array[], int arrayStart, int target[], int targetStart, int size);
void sort(int array, int arraySize);
void arraycopy(int array[], int arrayStartIndex, int target[], int targetStartIndex, int length);
void displayDepartment(Employee[]);
void displayGender(Employee[]);
int uniqueDepartmentCount(Employee e[]);
void printPerDepartment(string departmentName, Employee e[]);
void genderPrint(Employee e[], string gender);

int main()
{

    Employee emp[SIZE];
    readData(emp);

    int input = 0;

    while (input != 4)
    {
        cout << "\n Please choose the following options: \n 1. Display All \n 2. Group by Department \n 3. Group by Gender \n 4. Exit" << endl;
        cin >> input;
        if (input > 4 || input < 1)
        {
            cout << "Please enter between 1 and 4. ";
        }
        else if (input == 1)
        {
            displayAll(emp);
        }
        else if (input == 2)
        {
            displayDepartment(emp);
        }else if(input == 3){
            displayGender(emp);
        }
    }
}

void readData(Employee e[])
{

    ifstream input;
    string line;
    int pos;
    int index = 0;

    input.open("Employee_Data.csv");
    while (getline(input, line))
    {
        if (index == 0)
        {
            index++;
        }
        else
        {
            pos = line.find(",");

            e[index - 1].id = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);

            pos = line.find(",");

            e[index - 1].firstName = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(",");

            e[index - 1].lastName = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(",");

            e[index - 1].gender = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(",");
            e[index - 1].department = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(",");
            e[index - 1].salary = stod(line.substr(1, pos));

            index++;
        }
    }
    input.close();
}

void sort(int array[], int size)
{
    if (size > 1)
    {

        int *first = new int[size / 2];
        arraycopy(array, 0, first, 0, size / 2);
        sort(first, size / 2);

        int secondLength = size - size / 2;
        int *second = new int[secondLength];
        arraycopy(array, size / 2, second, 0, secondLength);
        sort(second, secondLength);

        merge(first, size / 2, second, secondLength, array);

        delete[] first;
        delete[] second;
    }
}

void arraycopy(int array[], int arrayStartIndex, int target[], int targetStartIndex, int length)
{
    for (int i = 0; i < length; i++)
    {
        target[i + targetStartIndex] = array[i + arrayStartIndex];
    }
}

void merge(int array1[], int array1Size, int array2[], int array2Size, int temp[])
{
    int index1 = 0;
    int index2 = 0;
    int index3 = 0;

    while (index1 < array1Size && index2 < array2Size)
    {
        if (array1[index1] < array2[index2])
        {
            temp[index3++] = array1[index1++];
        }
        else
        {
            temp[index3++] = array2[index2++];
        }
    }
}

void displayAll(Employee e[])
{
    int array[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = e[i].id;
    }

    sort(array, SIZE);

    int totalSalary = 0;

    cout << "\n"
         << left << setw(5) << "id" << setw(15) << "first_name" << setw(15) << "last_name" << setw(15) << "gender" << setw(25) << "department"
         << "salary" << endl;
    for (int j = 0; j < SIZE; j++)
    {
        cout << left << setw(5) << e[j].id << setw(15) << e[j].firstName << setw(15) << e[j].lastName << setw(15) << e[j].gender << setw(25) << e[j].department << "$" << e[j].salary << endl;
        totalSalary += e[j].salary;
    }

    cout << "\n"
         << left << setw(20) << "Total Salary"
         << "$" << totalSalary << endl;
    cout << "Report prepared by Jay Seung Yeon Lee"
         << "\n"
         << endl;
}

void displayDepartment(Employee e[])
{

    int departmentCount = uniqueDepartmentCount(e);
    string *departmentArray = new string[departmentCount];
    int count = 0;
    int departmentArrayIndex = 0;

    for (int i = 0; i < SIZE; i++)
    {
        count = 0;
        for (int j = 0; j < departmentCount; j++)
        {
            if (e[i].department == departmentArray[j])
            {
                count++;
            }
        }
        if (count == 0)
        {
            departmentArray[departmentArrayIndex] = e[i].department;
            departmentArrayIndex++;
        }
    }

    for (int k = 0; k < departmentCount; k++)
    {
        printPerDepartment(departmentArray[k], e);
    }

    double totalSalary = 0;
    for (int m = 0; m < SIZE; m++)
    {
        totalSalary += e[m].salary;
    }

    cout << "Total Salary : " << totalSalary << endl;
    cout << "Report prepared by Jay Seung Yeon Lee" << endl;

    delete[] departmentArray;
}

int uniqueDepartmentCount(Employee e[])
{

    string newSet[SIZE];
    int count = 0;
    int departmentCount = 0;

    for (int i = 0; i < SIZE; i++)
    {
        count = 0;
        for (int j = 0; j < SIZE; j++)
        {
            if (e[i].department == newSet[j])
            {
                count++;
            }
        }
        if (count == 0)
        {
            newSet[i] = e[i].department;
            departmentCount++;
        }
    }
    return departmentCount;
}

void printPerDepartment(string departmentName, Employee e[])
{

    int array[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        array[i] = e[i].id;
    }

    sort(array, SIZE);

    cout << left << "\n"
         << departmentName << endl;
    cout << left << "\n"
         << setw(5) << "id" << setw(15) << "first_name" << setw(15) << "last_name" << setw(15) << "gender"
         << "salary" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        if (e[i].department == departmentName)
        {
            cout << left << setw(5) << e[i].id << setw(15) << e[i].firstName << setw(15) << e[i].lastName << setw(15) << e[i].gender << "$" << e[i].salary << endl;
        }
    }
    cout << endl;
}

void displayGender(Employee e[])
{
    double totalSalary = 0;

    genderPrint(e,"Male");
    genderPrint(e,"Female");

    for(int i = 0; i < SIZE; i++){
        totalSalary += e[i].salary;
    }

    cout << "\n Total Salary : " << totalSalary << endl;
    cout << "Report prepared by Jay Seung Yeon Lee" << endl;
}


void genderPrint(Employee e[], string gender)
{

    double totalSalary =0;
    cout << "\n"
         << gender << endl;
    cout << "\n"
         << left << setw(5) << "id" << setw(15) << "first_name" << setw(15) << "last_name" << setw(25) << "department"
         << "salary" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        if (e[i].gender == gender)
        {
            cout << left << setw(5) << e[i].id << setw(15) << e[i].firstName << setw(15) << e[i].lastName << setw(25) << e[i].department << "$" << e[i].salary << endl;
            totalSalary += e[i].salary;
        }
    }
    cout << "Running Salary : " << totalSalary << endl;
    
}
