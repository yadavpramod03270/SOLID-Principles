#include <iostream>
using namespace std;

/*
LISKOV SUBSTITUTION PRINCIPLE (LSP)
Derived class objects must be substitutable for base class objects
without breaking program behavior.
*/

// Base class
class Notification {
public:
    virtual void send(const string& message) {
        cout << "Sending notification: " << message << endl;
    }

    virtual ~Notification() = default;
};

// Derived class 1
class EmailNotification : public Notification {
public:
    void send(const string& message) override {
        cout << "Sending EMAIL: " << message << endl;
    }
};

// Derived class 2
class SmsNotification : public Notification {
public:
    void send(const string& message) override {
        cout << "Sending SMS: " << message << endl;
    }
};

// Client code (uses base class)
void notifyUser(Notification* notification) {
    notification->send("Hello User");
}

int main() {
    EmailNotification email;
    SmsNotification sms;

    // Base class pointer used for derived objects
    notifyUser(&email);   // works correctly
    notifyUser(&sms);     // works correctly

    return 0;
}
