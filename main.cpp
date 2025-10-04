#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#include "counter.h"

namespace Math {
    int add(int a,int b) { return a+ b;}
}

ll  bignumber = 124;
void increment(int& n) { n++; }  // by reference
int check_permission();
int sum(int a, int b) { return a+b; }
double sum(double a, double b) { return a+b; }
void greet(string name = "Guest") {
    cout << "Hello " << name << '\n';
}

// static -> tol omr ro ista mikone
// extern -> be compiler mige in motaghayer dar file dige tarif shode
// const -> motaghayer ro sabet mikone
// constexpr -> bayad dar zaman compile meghdar dehi she


class Car {
 int speed;
   public:void setSpeed(int s) {speed = s;}
};
struct Point { int x, y; };


int main() {
  Car c1;            // روی stack
    Car* c2 = new Car; // روی heap
    Point p1;          // روی stack
    Point* p2 = new Point; // روی heap


cout<< "counter = " << App::counter << endl;
App::increment();
cout<< "counter = " << App::counter << endl;


App::Student s1;

s1.name = "hosein";
s1.age = 32;
s1.grade = 19.5;

App::Student s2 = {"mahsa",35,18};
App::Student s3{"Baran", 2, 20};
cout << s1.name << "-" << s1.age << "-" << s1.grade << endl;
cout << s2.name << "-" << s2.age << "-" << s2.grade << endl;
cout << s3.name << "-" << s3.age << "-" << s3.grade << endl;

cout << Math::add(2,3) << endl;


App::Student* stdp = &s1;

cout << stdp->name << endl;
s1.print();


App::Student students[3] = {
    {"Ali", 22, 17.5},
    {"Sara", 21, 18.2},
    {"Reza", 23, 19.0}
};


// pass by ref
for (const auto& s : students) {
    cout << s.name << " (" << s.age << "): " << s.grade << '\n';
}

cout << bignumber << endl;
    int a = 10; // clasic method
    double b = 10;
    char c = 'A';
    long d = 3;
    long long e = 4;
    short f = 5;

    int g{10}; // modern method // beter aprocach
    int h(20); //like initial object


    int i{}; // meghdar dehi sefr

    // const
    const double PI = 3.14;


    int dec = 42;
    int hex = 0x2A;
    int bin = 0b101010;
    int octal = 053;

    float fl = 1.3;

    long double fff = 3.4;


    int implicit = 5;

    double imp = implicit;

    int explic = static_cast<int>(imp);


    std::cout << "k" << endl;

    cout << sizeof(int) << endl;
    cout << sizeof(double) << endl;

    wchar_t wc =  L'ش';

    auto z = 53;


    cout << (z << 2) << endl;
    // shift be chap zarb dar 2 be ezaye har bit
    // sift be rast taghsim bar 2 be ezage har bit

    auto ggg = "salam";// char *


    unsigned int aaa = 20;
    unsigned int bbb = 5;

    cout << (aaa & bbb) << endl;
    cout << (aaa | bbb) << endl;
    cout << (aaa ^ bbb) << endl;
    cout << (~aaa) << endl;


    int ar[1];

    int br[] = {1,2,3};

    int cr[3] = {10};

    // tashkis siza arraye

    size_t sizeofarr = sizeof(br) / sizeof(br[0]);

    // vagti yek arraye ro be yek method mifrestem pointer ersal mishe va injory nemishi size ro chek kard va bayad az vector va span estefade koni

    //multidimensional arrayein

    int mat [3][4] ={{1,1},{3,4}};

    // or

    vector<vector<int>> matq(2, vector<int>(3, 0));

    // old way to create dynamic arraye
    int *arrdy = new int[5];

    delete[] arrdy;

    // smart poitner
    vector<int> vv(3);
    vv.push_back(5);

// const can be set in runtime
// constexpr can be set complie

    /// magic bignumber
    constexpr int MAX_USER = 100;


int* null = nullptr;

// eshare gar ya pointer bayad be nam hamon pointer bashe
int xpointer = 43;

int* mypointer = &xpointer;

// eshare gar be eshare gar
int ** ptop = &mypointer;
cout << xpointer << '\n'; //meghdar mostaghim
cout << mypointer << '\n'; // address
cout << *mypointer << '\n'; // meghdar

int * newdy = new int(42);

delete newdy;



int byref = 10;

int& ref =byref;

ref = 30000;

cout << byref << endl;

check_permission();
    auto lang = "C++";
    std::cout << "Hello and welcome to " << lang << "!\n";

    for (int i = 1; i <= 5; i++) {
        std::cout << "i = " << i << std::endl;
    }

    return 0;
}

enum Color {Red,Green,Blue};
enum Status {OK = 200,NotFound=404,Error=500};


int check_permission(){
    const unsigned int READ = 0b001;
    const unsigned int WRITE = 0b010;
    const unsigned int EXEC = 0b100;

    unsigned int permission = READ | WRITE;

    if(permission & EXEC){
        cout << "can execute\n";
    } else{
        cout << "can not execute\n";
    }

    return 0;
}
// bedone copy kardan meghdar ro bekhoni vali tagir nadi
void print(const string& s){
    cout << s << endl;
}



// shadowing
//int x = 10;
//int main() {
  //  int x = 5;   // متغیر سراسری x پنهان میشه
    //cout << x;   // 5
//}

// diff of class and struct

// class dufault private
// struct default pulic