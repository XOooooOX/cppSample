#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <ranges>
#include <map>
#include <fstream>
#include <concepts>
#include <set>
using namespace std;
#include <csignal>
#include <array>
#include <unordered_map>
#include <limits>
using namespace std;

using ll = long long;
// cin vrody dade
// cout khoroji
// ofstream zakhire

// ofstream khoroji
// ifstream vorody
//fstream vrody va khorojy
// ios out neveshtan
// ios in khandan
// ios app ezafe kardan be enteha
// iod binary halat binary
// ios truncate pak kardan mohtavaye ghabli default

int work_with_file() {
    //ios app baraye inke mohtava pak nashe
    ofstream file("data.txt",ios::app);

    if (!file) {
        cerr << "Can't open file" << endl;
        return 1;
    }

    file << "hello" << endl;
    file << "ali" << endl;
    file.close();

    // read from file
    ifstream input("data.txt");
    string word;
    // dade ro bar asas new line joda mikone
    while (input >> word) {
        cout << word << endl;
    }


}

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
    work_with_file();
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
    // inja adad 0 yani in tabe hatman bayad dar kelass haye farzand piade sazi she
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


// template or generic
template<typename T> T add(T a,T b) {
    return a + b;
}

template<typename T1,typename T2>
auto multiply(T1 a,T2 b) {
    return a * b;
}

// template for class , like generic cclass
template<typename T>
class Box {
    T value;
    public:
    Box(T v): value(v) {}
    T get() {return value;}
};

// template fucntion specialization
// explicit specilization
template <typename T>
void print(T val) {
    cout << "Generic: " << val << endl;
}
template<>
void print<string>(string val) {
    cout << val << endl;
}

// stl standard template library and Containers
// Containers -> vector , list,map, set
// algorithms -> sort,find,count,for_each
// iterators -> pol beyn algoritn va container

// squence container
    /// vector,list, deque, array -> dade ha be tartibe negahdary mishan
/// associative container
///     set,map,multieset,multimap dade ha bar asas kelid moratab mishan
/// unorderd container
///     unorderd_map,unorder_set mesl map vali bedone tartibe
///
///    vecotr like list in c#
///
// mesl list khodesh hafeza ro modirayat va bozorg mikone
void myfunction() {
    vector<int> v = {1,2,3,4,5};
    v.push_back(6);
    v.push_back(7);

    v.pop_back();// hazf akharin onsor
    v.clear();// pak kardan kol

    for (int x: v) {
        cout << x << endl;
    }

    cout << v.size() << endl;


    // linked list
    list<string> l = {"hosein","ali"};
    l.push_front("hosein");
    l.push_front("ali");
    // darj va hazf vasat list sari tare vali dastresi be endis nadari

    //set - majmoe bedon tekrar
    set<int> s = {3,4,5,6};
    // hamishe moratab va bedon ozv tekrary hast

    // map shabih dictionary dar c#
    // bar asas kilid sort mishe
    map<string,int> maymap ;
    maymap["hosein"] = 34;


    // unorderd map bar paye hash table
    // tartib moshakashi nadare
    unordered_map<string,int> mpoint ={
        {"ali",2}
    };
    mpoint["hosein"] = 34;

    // iterators
    // shabih eshare gar ha vali barye container ha
    vector<int> vv = {1,2,3,4,5};

    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << endl;


    }

    // algoritm
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    auto it = find(v.begin(), v.end(),4);


    sort(v.begin(), v.end(),greater<int>());

    // reverse iterator
    //for (auto it = v.rbegin(); it != v.end(); it++) {}

    auto itr = find(v.begin(), v.end(), 30);
    if (itr != v.end())
        cout << "Found: " << *itr;

// one way
    int c = count(v.begin(), v.end(), 20);
    // or
    int cc = count(&v[0], &v[0]+v.size(), 20);

    // lambda
    auto itsss = find_if(v.begin(), v.end(), [](int n) {
        return n == 20;
    });

    for_each(v.begin(), v.end(), [](int n) {
        cout << n << endl;
    });


    // transform
    vector<int> squard;
    transform(v.begin(), v.end(), back_inserter(squard), [](int n) {
        return n * n;
    });

    // filter
    vector<int> evens;
    copy_if(v.begin(), v.end(), back_inserter(evens), [](int n) {
        return n % 2 == 0;
    });

    //remove if
    v.erase(remove_if(v.begin(), v.end(), [](int n) {
        return n % 2 == 0;
    }));


    //lambda
    //[capture] (parameters) -> return type {}
    // capture motaghyer hayi ke az birom be lambda ghabel dastresi bashe
    // parameter argoman haye tabe

    auto sum = [](int a,int b) {
        return a + b;
    };

    int azbiron = 7;
    auto sum2 = [azbiron](int a,int b) {

        return a + b + azbiron;
    };

    cout << [](int a,int b){return a* b;}(5,6) ;


    // capture by refrence
    int limit =10;
    auto check =[&limit](int a) {
        return a > limit;
    };

    // capter all by value and refrcne
    auto f1 = [=](int a) {};
    auto f2 = [&](int a) {};

    // lambda with retrun vlue
    auto divide = [] (int a, int b )-> double {
        return (double)a / b;
    };

    int x = 5, y = 10;

    auto sum22 = [=, &y](int z) {
        y += z;
        return x + y;
    };

    // mutable lambda
    // ba [=] be sorat pish farz read only gast
    int counter =0;
    auto fff = [counter]() mutable {
        counter++;
        cout << counter << endl;
    };
    }


void process(int n, const function<void(int)>& func) {
    func(n);
}

void all_type_smart_pointer() {
    // unique ptr -> malekitat enhesay shabih refrence local c#
    // shared pth -> malekiter eshteraki shabih gc managed object dar c#
    // weak ptr -> eshare gar zaef baraye jelogiry az loop mesl weak refrnce
    unique_ptr<int> p = make_unique<int>(5);
    // ghabel copy nist
    // vali mishe malekiat ro montaghel kard


    shared_ptr<int> sp = make_shared<int>(5);
    // mishe copy kard
    // vaghti akharin shey pak beshe khodesh pak mishe


    weak_ptr<int> wee = weak_ptr<int>(sp);
    // malekiaty ijad nemikone
    // mesal

    struct Node {
        shared_ptr<Node> next;
        weak_ptr<Node> prev;
    };

    auto n1 = make_shared<Node>();
    auto n2 = make_shared<Node>();

    n1->next = n2;
    n2->prev = n1; // weak_ptr، پس loop مالکیتی ایجاد نمی‌کنه

    // agar inja az share ptr estefade mikardi hich vaght hafeze azad nemishe



    unique_ptr<int[]> arr = make_unique<int[]>(5);
}


// eceptions
 void myexcetion () {
    // basic gurantee - hich manbae leak nemishe
    // strong gruantee - ya amaliat kamel anjam mishe ya roolback mishe
    // no-throw gurantee - hich estesnaye partab nemishe

}

class Buffer {
    unique_ptr<char[]> data;
    size_t size;
public:
    Buffer(size_t s): data(make_unique<char[]>(s)), size(s) {}
    char* get() { return data.get(); }
};

// har vaght file az scope kharej beshe on lambda ejra mishe

auto fileCloser = [](FILE* f) {
    if (f) fclose(f);
};

unique_ptr<FILE, decltype(fileCloser)> file(fopen("log.txt", "w"), fileCloser);


template <typename T>
concept Addable = requires(T a, T b) {
    a + b;  // باید عملگر + برای نوع T تعریف شده باشه
};

template <std::integral T>
T add(T a, T b) {
    return a + b;
}


void rnages () {
    // befor
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> evens;

    copy_if(nums.begin(), nums.end(), back_inserter(evens),
            [](int n){ return n % 2 == 0; });

    // after c++ 20
    for (int n : nums | std::views::filter([](int n){ return n % 2 == 0; }))
        cout << n << " ";


    auto result = nums
    | std::views::filter([](int n){ return n > 2; })
    | std::views::transform([](int n){ return n*10; });

}


int sum(int n) {
    if (n == 0) return 0;

    return n + sum(n - 1);
}

//template <typename T> like template<class T>

