#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::ifstream;
using std::ofstream;

void write(ofstream &output, unsigned int &value) {
    output.write((char*) &value, sizeof value);
}

void write(ofstream &output, double &value) {
    output.write((char*) &value, sizeof value);
}

void write(ofstream &output, const string & string) {
    const auto len = string.length();
    output.write((char*) &len, sizeof len);
    output.write(string.c_str(), len);
}

void read(ifstream &input, unsigned int &value) {
    input.read((char*) &value, sizeof value);
}

void read(ifstream &input, double &value) {
    input.read((char*) &value, sizeof value);
}

void read(ifstream &input, string& value) {
    typeof value.length() len;
    input.read((char*) &len, sizeof len);
    value.resize(len);
    input.read((char*) value.c_str(), len);
}
struct Stud
{
    string fio;
    unsigned int age;
    unsigned int dis{};
    double mark{};
};

int main () {
    std::ifstream ifout;
    ifout.open ("input.txt", std::ios::in);

    std::ofstream ofout;
    ofout.open ("input.txt", std::ios::out);


    int size;
    cin >> size;
    for (int i = 0; i < size; i++) {
        cout << "Enter user: " << endl;
        Stud student;
        cin.ignore();
        getline(cin, student.fio);
        cin >> student.age;
        cin >> student.dis;
        cin >> student.mark;

            write (ofout, student.fio);
            write (ofout, student.age);
            write (ofout, student.dis);
            write (ofout, student.mark);
    }

    ofout.close();


        while (ifout.peek() != EOF) {
            Stud student;
            read (ifout, student.fio);
            read (ifout, student.age);
            read (ifout, student.dis);
            read (ifout, student.mark);

            cout << "Read user: fio=" << student.fio << ", age="
            <<student.age << ", dis=" << student.dis << ", mark=" << student.mark<<endl;
        }
        ifout.close();
}