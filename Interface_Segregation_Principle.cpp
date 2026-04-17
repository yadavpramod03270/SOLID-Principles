#include <iostream>
using namespace std;

/*
INTERFACE SEGREGATION PRINCIPLE (ISP)
Clients should not be forced to depend on methods they do not use.
*/

/* Small & focused interfaces */

class Workable {
public:
    virtual void work() = 0;
    virtual ~Workable() = default;
};

class Eatable {
public:
    virtual void eat() = 0;
    virtual ~Eatable() = default;
};

class Sleepable {
public:
    virtual void sleep() = 0;
    virtual ~Sleepable() = default;
};

/* Human can do all actions */

class HumanWorker : public Workable, public Eatable, public Sleepable {
public:
    void work() override {
        cout << "Human is working" << endl;
    }

    void eat() override {
        cout << "Human is eating" << endl;
    }

    void sleep() override {
        cout << "Human is sleeping" << endl;
    }
};

/* Robot can only work */

class RobotWorker : public Workable {
public:
    void work() override {
        cout << "Robot is working" << endl;
    }
};

int main() {
    HumanWorker human;
    RobotWorker robot;

    human.work();
    human.eat();
    human.sleep();

    robot.work();

    return 0;
}
