#include <iostream>
using namespace std;
class CSE
{
private:
    int intake;
    char section;
public:
    double tuition_fee;
    string semester, shift;
    CSE()
    {
        intake = tuition_fee = 0;
        section = '\0';
        semester = '\0';
        shift = '\0';
    }
    CSE(int intake, char section)
    {
        CSE();
        this->intake = intake;
        this->section = section;
    }
    void mutator(int intake, string semester)
    {
        this->intake = intake;
        this->semester = semester;
    }
    void mutator(string shift, double tuition_fee)
    {
        this->shift = shift;
        this->tuition_fee = tuition_fee;
    }

    inline double tuition()
    {
        return tuition_fee+2000;
    }

    friend void batch(CSE student);
};
void batch(CSE student)
{
    cout << "Intake: " << student.intake << endl;
    cout << "Section: " << student.section << endl;
    cout << "Semester: " << student.semester << endl;
    cout << "Shift: " << student.shift << endl;
    cout << "Tuition Fee: " << student.tuition() << endl;
}


int main()
{
    CSE st(35, '1');
    st.mutator(35, string("fall2017-18"));
    st.mutator(string("day"), 5000);
    batch(st);
    return 0;
}
