#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Employee {
private:
    int empId;
    string name;
    string department;
    char grade;
    double basicSalary;
    bool isActive;
    static int employeeCount;

public:
    // Default Constructor (required for main())
    Employee() {
        employeeCount++;
        empId = 1000 + employeeCount;
        isActive = true;
        name = "Unknown";
        department = "Engineering";
        grade = 'D';
        basicSalary = 10001.0;
    }

    // Parameterized Constructor
    Employee(const string& n, const string& dept, char g, double salary) {
        employeeCount++;
        empId = 1000 + employeeCount;
        isActive = true;

        setName(n);
        setDepartment(dept);
        setGrade(g);
        setBasicSalary(salary);
    }

    // Setters with fixed validation logic
    void setName(const string& n) {
        if (n.empty()) {
            cout << "ERROR: Name cannot be empty." << endl;
            return;
        }
        name = n;
    }

    void setDepartment(const string& dept) {
        if (dept != "Engineering" && dept != "HR" && dept != "Finance" && dept != "Operations") {
            cout << "ERROR: " << dept << " is not a registered department." << endl;
            return;
        }
        department = dept;
    }

    void setGrade(char g) {
        if (g != 'A' && g != 'B' && g != 'C' && g != 'D') {
            cout << "ERROR: Invalid grade '" << g << "'. Accepted values: A, B, C, D." << endl;
            return;
        }
        grade = g;
    }

    void setBasicSalary(double salary) {
        if (salary > 10000 && salary < 500000) {
            basicSalary = salary;
        } else {
            cout << "ERROR: Salary must be between Rs.10,000 and Rs.5,00,000. Value rejected." << endl;
        }
    }

    void deactivate() {
        isActive = false;
    }

    // Getters
    int getEmpId() const {
        return empId;
    }

    string getName() const {
        return name;
    }

    string getDepartment() const {
        return department;
    }

    char getGrade() const {
        return grade;
    }

    double getBasicSalary() const {
        return basicSalary;
    }

    bool getIsActive() const {
        return isActive;
    }

    static int getEmployeeCount() {
        return employeeCount;
    }

    void acceptDetails() {
        string tempDept;
        string tempName;
        char tempGrade;
        double tempSalary;

        cout << "\nEnter Employee Details (ID: " << empId << "):\n";

        cout << "Enter Name: ";
        getline(cin >> ws, tempName);
        setName(tempName);

        cout << "Enter Department (Engineering/HR/Finance/Operations): ";
        cin >> tempDept;
        setDepartment(tempDept);

        cout << "Enter Grade (A/B/C/D): ";
        cin >> tempGrade;
        setGrade(tempGrade);

        cout << "Enter Basic Salary (10001 - 499999): ";
        cin >> tempSalary;
        setBasicSalary(tempSalary);
    }

    double computeAllowances() const {
        switch (grade) {
            case 'A': return 0.40 * basicSalary;
            case 'B': return 0.30 * basicSalary;
            case 'C': return 0.20 * basicSalary;
            case 'D': return 0.10 * basicSalary;
            default:  return 0.0;
        }
    }

    double computeGrossSalary() const {
        return basicSalary + computeAllowances();
    }

    double computeTax() const {
        double gross = computeGrossSalary();
        if (gross <= 50000.0) {
            return 0.0;
        } else if (gross <= 100000.0) {
            return 0.10 * (gross - 50000.0);
        } else {
            return 5000.0 + 0.20 * (gross - 100000.0);
        }
    }

    double computeNetSalary() const {
        return computeGrossSalary() - computeTax();
    }

    void printPayslip() const {
        cout << "\n========================================\n";
        cout << "               PAYSLIP                  \n";
        cout << "========================================\n";
        cout << left << setw(18) << "Employee ID:"   << empId << "\n";
        cout << left << setw(18) << "Name:"          << name << "\n";
        cout << left << setw(18) << "Department:"    << department << "\n";
        cout << left << setw(18) << "Grade:"         << grade << "\n";
        cout << left << setw(18) << "Status:"        << (isActive ? "Active" : "Inactive") << "\n";
        cout << "----------------------------------------\n";
        cout << fixed << setprecision(2);
        cout << left << setw(18) << "Basic Salary:"  << basicSalary << "\n";
        cout << left << setw(18) << "Allowances:"    << computeAllowances() << "\n";
        cout << left << setw(18) << "Gross Salary:"  << computeGrossSalary() << "\n";
        cout << left << setw(18) << "Tax Deducted:"  << computeTax() << "\n";
        cout << "----------------------------------------\n";
        cout << left << setw(18) << "Net Salary:"    << computeNetSalary() << "\n";
        cout << "========================================\n\n";
    }
};

// Initialize static member variable
int Employee::employeeCount = 0;

int main() {
    Employee e1;
    Employee* e2 = new Employee();
    Employee* e3 = new Employee();

    e1.acceptDetails();
    e2->acceptDetails();
    e3->acceptDetails();

    // Compiler errors occur here because 'empId' and 'basicSalary' are private members of class 'Employee'.
    // Direct access from outside the class violates data encapsulation.
    // e1.empId = 999;
    // e1.basicSalary = -1000;

    e1.printPayslip();
    e2->printPayslip();
    e3->printPayslip();

    e3->deactivate();

    if (!e3->getIsActive()) {
        cout << e3->getName() << " is no longer active. Payroll skipped." << endl;
    }

    cout << "Total Employees : " << Employee::getEmployeeCount() << endl;

    delete e2;
    delete e3;

    return 0;
}
