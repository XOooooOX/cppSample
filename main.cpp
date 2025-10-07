#include <iostream>
#include <memory>
#include <vector>
using namespace std;
#include <csignal>
#include <array>
#include <limits>

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


// recursive function

unsigned long long factorial(unsigned long long n) {
    if (n <= 1) return 1;
    auto next = factorial(n - 1);
    if (n > std::numeric_limits<unsigned long long>::max() / next)
        throw overflow_error("عدد خیلی بزرگه!");
    return n * next;
}

// slient overflow
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);;
}


class Car {
 int speed;
   public:void setSpeed(int s) {speed = s;}

    public:int number;
};
struct Point { int x, y; };
void signalHandler(int signum) {
    cout << "❌ خطای سیستم (" << signum << "): دسترسی به حافظه غیرمجاز!\n";
    exit(signum); // یا هر واکنشی که بخوای



}

//Type Promotion in overloading

void show(double x) {cout << x << '\n';}
void show(int x) {cout << x << '\n';}

void showw(int* p)  { cout << "pointer\n"; }
void showw(int& r)  { cout << "reference\n"; }


void test(int& x)       { cout << "by ref\n"; }
void test(const int& x) { cout << "by const ref\n"; }



template<typename T> T square2(T x) {return x * x;}

int myfuncforpointer(int a, int b ) {return a + b;}


int main() {

    // poitner to method
    int(*mynewfunc)(int,int) =myfuncforpointer;
    cout << mynewfunc(10,20) << '\n';

    int ariiiir[3] = {10, 20, 30};

    cout << ariiiir;     // آدرس عنصر اول
    cout << *ariiiir;    // مقدار عنصر اول (10)
    cout << *(ariiiir+1); // 20

    int * nullispointer = nullptr;

    // modern array
    array<int,5> modernArray = {1,2,3,4,5};

    for (int x : modernArray)
        cout << x << " ";

    int n;
    cin >> n;
    int* arr = new int[n]; // در heap

    delete[] arr;


    // undifaind behavior
    int numbers[5] = {1, 2, 3, 4, 5};

    cout << sizeof(numbers) << '\n';// size araye
    cout << sizeof(numbers[0]) << '\n'; // size yek ozv
    cout << sizeof(numbers)/ sizeof(numbers[0]) << '\n'; // tedad araye
    cout << *(numbers + 2);
    cout << numbers[0] << '\n';
    cout << numbers[1000] << '\n';

   cout << square2(3) << endl;

    int a = 5;
    test(a);       // non-const ref
    test(10);      // const ref (چون literal نمی‌تونه به ref معمولی متصل بشه)

    showw(&a);  // pointer version
    showw(a);   // reference version

show(5);
    show(10.2);
    show('a');// type promotion - char to int


    signal(SIGSEGV, signalHandler); // هندل کردن Segmentation Fault
    try {
   //cout << "factoraial = " << factorial(1200000) << endl;

    } catch (const overflow_error& e) {
        cout << "overflow error: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "exception: " << e.what() << endl;
    }

// smart pointer
    auto car = std::make_unique<Car>();

    // unique can not copy only move
    auto car2 = std::move(car);

    auto orcar = std::make_shared<Point>(1,2);

    // but you can use multi on share

    auto car3 = orcar;

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
cout << (*stdp).name << endl;
s1.print();

    // dynamic struct
    App::Student* mystudent = new App::Student{"mahsa",35,18};

    cout << mystudent->name << endl;

    delete mystudent;


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
    int wwa = 10; // clasic method
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

    auto mohammad = 67;

  if (mohammad == 43) {
      std::cout << "ki";
  }
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


// pass by reff
void change(int& x) {
    x = 100;
}
// pass by value
void change(int x) {
    // dont work
    x = 100;
}
// pass by pointer
void change(int* x) {
    *x = 100;
}

// default paramter
void hi(const string &name = "hosein") {
    cout << name << endl;
}

// function overload
void hhhh(int n);
void hhhh(string s);

// inline function
// be jaye jump be tabe , codesh mostaghiman dar mahal seda zadan jaygozine mishi
inline int square(int x) {
    return x * x;
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



// 2 type of nested namespace

namespace  A {
    namespace B {}
}

namespace C::A{
}


// anonymous namespace
namespace {

}


class Base {
    public:
    Base() {cout << "base constructor" << endl;}
    ~Base() {cout << "base destructor" << endl;}

    protected:
    void protected_function() {}
    int value = 5;

    private:
    void private_function(int x) {}
};

class Derived : public Base {
    public:
    Derived() {cout << "derived constructor" << endl;}
    ~Derived() {cout << "derived destructor" << endl;}

    protected:
    void protected_function() {cout << value << endl;}

    public:
    void show(){}
};

class AA {

};

class BB {

};

class CC:AA,BB {

};



// agar dar yek class hata yek tabe pure function
// vojod dashte bashe nemitoni azash nemone besaze
// chon kol class abstract mishe
// faghat az ershbari mitone azash besazi
// sakhtan pointer mojaze
class Animal {
    public:
    virtual void speak() { cout << "speak" << endl;}
    // pure virtual function like abstract
    virtual void draw() = 0;
};

class Dog : public Animal {
    public:
    void speak() override { cout << "woof" << endl;}
    void draw() override { cout << "hello" << endl;}
};

// agar ba eshare gar az no base be farzand eshare
// koni , agar destructor class base virtual nabashe
// monkene faghat paye pak she
// bedon virtual faghat base nabod mishe va nasht hafeze etefagh mi ofte

// dar posht sahne vaghti class virtual dare
// compiler yek jadval be name vtable misaze va adress tamam method haye
// virtual da on negah dashte mishe
// har  shey ham yek eshare be vtable
// barname az vtable mifahme bayad kocom ejra she
