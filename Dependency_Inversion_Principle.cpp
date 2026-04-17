#include <iostream>
using namespace std;

// Abstraction (interface) 
class NotificationSender {
public:
    virtual void sendNotification(const string& message) = 0;
    virtual ~NotificationSender() = default;
};

// Low-level module (Email)
class EmailSender : public NotificationSender {
public:
    void sendNotification(const string& message) override {
        cout << "Email sent: " << message << endl;
    }
};

// High-level module
class NotificationService {
    NotificationSender* sender;

public:
    NotificationService(NotificationSender* sender)
        : sender(sender) {}

    void notify(const string& message) {
        sender->sendNotification(message);
    }
};

int main() {
    EmailSender email;                 // decision made here
    NotificationService service(&email);

    service.notify("Message received, thanks!");
    return 0;
}


/*

FINAL CONCLUSION (very important)
--------------------------------------------
Dependency Inversion Principle is not just runtime polymorphism.
It is about WHO depends on WHOM.

NotificationService (high-level)
→ depends on NotificationSender (abstraction)

EmailSender (low-level)
→ also depends on the same abstraction

main() decides which implementation to use

Because of this:

Adding SmsSender needs NO change in NotificationService

Only main() changes

 DIP is followed
--------------------------------------------

3️ NOTES 
--------------------------------------------
1. High-level module
Contains business logic

Describes what to do
Should NOT depend on concrete classes
Example: NotificationService

2)Low-level module
Handles how things are done

Implements details (Email, SMS, DB, File, etc.)

Example: EmailSender

3) Abstraction
Interface / abstract class

Acts as a contract

Both high-level and low-level depend on it

 Dependency Inversion Principle (DIP)
--------------------------------------------

High-level modules should not depend on low-level modules
Both should depend on abstractions
Details depend on abstractions, not the other way around

Runtime Polymorphism relation
--------------------------------------------
DIP uses runtime polymorphism
Base pointer → derived object
Virtual function → late binding
But polymorphism alone ≠ DIP

Key memory line 
Main creates the object.
The service uses the abstraction.
The behavior changes automatically.*/
