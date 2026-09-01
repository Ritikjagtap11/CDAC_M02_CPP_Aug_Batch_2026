#include <iostream>


using namespace std;

class Patient {
private:
    int patientId;
    string name;
    int age;
    string ward;
    const string bloodGroup;

public:
    Patient()
        : patientId(0), name("Unknown"), age(0), ward("General"), bloodGroup("O+") {
        cout << "[Constructor] Default patient registered." << endl;
    }

    Patient(int id, const string& name)
        : patientId(id), name(name), age(0), ward("Emergency"), bloodGroup("Unknown") {
        cout << "[Constructor] Emergency: " << this->name << endl;
    }

    Patient(int id, const string& name, int age, const string& ward, const string& bg)
        : patientId(id), name(name), age(age), ward(ward), bloodGroup(bg) {
        cout << "[Constructor] Full admission: " << this->name << endl;
    }

    ~Patient() {
        cout << "[Destructor] Patient " << name << " discharged." << endl;
    }

    void displayRecord() const {
        cout << "\nPatient Record:\n"
             << "  ID        : " << patientId << "\n"
             << "  Name      : " << name << "\n"
             << "  Age       : " << age << "\n"
             << "  Ward      : " << ward << "\n"
             << "  Blood Grp : " << bloodGroup << "\n" << endl;
    }

    void transferWard(const string& newWard) {
        cout << "Ward Transfer: " << name << " -> " << newWard << "\n" << endl;
        ward = newWard;
    }
};

int main() {
    Patient p1(1001, "Meera Joshi", 34, "Cardiology", "B+");
    Patient p2(1002, "Raj Patel");
    Patient p3;

    Patient* wardArray = new Patient[4];

    p1.displayRecord();

    p2.transferWard("ICU");

    delete[] wardArray;

    return 0;
}
