#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>
#include <cstring>
#include <cctype>
#include <sstream>
#include <fstream>
#include <numeric>

using namespace std;

struct Student
{
    string  d_name;
    string  d_lastname;
    size_t  d_number;
    float   d_grade;
};

void readStudents(char* filename, vector<Student> &students)
{
    ifstream ifs(filename);
    string input;

    while (getline(ifs, input))
    {
        Student new_student{};
        stringstream stream(input);

        while (stream.good())
        {
            stream >> input;
            stream >> ws;

            if (isdigit(stream.peek()))
            {
                new_student.d_lastname = input;
                stream >> new_student.d_number;
                stream >> new_student.d_grade;
            }
            
            new_student.d_name += input;
            new_student.d_name += ' ';
        }
        students.push_back(new_student);
    }
}

void writeNames(vector<Student> &students, ostream &out)
{
    sort(students.begin(), students.end(), 
        [&](Student &stu1, Student &stu2)
        {
            return (strcasecmp(stu1.d_lastname.c_str(),
                    stu2.d_lastname.c_str()) < 0);
        }
    );

    for (auto iter = students.begin(); iter != students.end(); ++iter)
        out << setw(20) << iter->d_name << setw(15) << iter->d_number 
            << ' ' << setw(10) << iter->d_grade << '\n';
}

void writeNrs(vector<Student> const &students, ostream &out)
{
    vector<size_t> indices(students.size());
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(),
        [&](size_t index1, size_t index2)
        {
            return (students[index1].d_number < students[index2].d_number);
        }
    );

    for (auto iter = indices.begin(); iter != indices.end(); ++iter)
        out << setw(35) << students[*iter].d_number << ' ' 
            << setw(10) << students[*iter].d_grade << '\n';
}

int main(int argc, char* argv[])
{
    vector<Student> students;
    readStudents(argv[1], students);
    writeNames(students, cout);
    cout << '\n';
    writeNrs(students, cout);
}