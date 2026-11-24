#include <iostream>
#include <string>
using namespace std;

struct poe{
    string name;
    string school;
    int age;

};

int main(){

    struct poe a;

    cin >> a.name >> a.school >> a.age;

    cout << "Name : " << a.name << "\n";
    cout << "School : " << a.school << "\n";
    cout << "Grade : " << a.age;


    return 0;
}