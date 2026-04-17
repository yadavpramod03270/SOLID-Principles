# 🧱 SOLID Principles

The **SOLID** principles are key concepts in software development that promote the design of **robust**, **scalable**, and **maintainable** code.

---

## **S — Single Responsibility Principle (SRP)**

> *A class should have only one well-defined responsibility.*

A class should be responsible for only **one task** or **one aspect** of the system. Instead of having a class that handles both user authentication *and* notification sending, separate these into two distinct classes.

### ✅ Benefits
- Makes code more **modular** — easier to modify and extend
- Simplifies **debugging** — each class focuses on a single concern
- Promotes **code reusability** across different parts of the system

### 📖 Example
In a **library management app**, apply SRP by having:
- A class for **book management**
- A class for **users**
- A class for **transactions**

Each class has its own responsibility, making the code clearer and more maintainable.

---

## **O — Open/Closed Principle (OCP)**

> *Code should be open for extension, but closed for modification.*

When adding new features, **extend** the existing code rather than directly modifying it. Use mechanisms like inheritance, polymorphism, and inversion of control.

### ✅ Benefits
- Makes code more **flexible and extensible**
- New features don't break existing functionality
- Simplifies **unit testing** — existing features remain untouched

### 📖 Example
In a **payment processing app**, create a generic abstract class `PaymentMethod`. Each specific method (e.g., Credit Card, PayPal) extends this base class while retaining shared core functionality.

---

## **L — Liskov Substitution Principle (LSP)**

> *Subclasses should be replaceable for their base classes without breaking the system.*

If class `B` is a subclass of class `A`, then objects of `B` should be usable wherever `A` is expected — without altering the system's behavior.

### ✅ Benefits
- Promotes **modularity** and code reusability
- New subclasses can be added without disrupting existing code
- Ensures **consistency** and avoids unexpected behaviors

### 📖 Example
In a **geometric shapes hierarchy**, if `Circle` and `Rectangle` are subclasses of `Shape`, then instances of either should work wherever a `Shape` is expected — with no surprises.

---

## **I — Interface Segregation Principle (ISP)**

> *Clients should not be forced to implement methods they don't use.*

Define **specific, focused interfaces** for clients instead of one large, monolithic interface.

### ✅ Benefits
- Interfaces become **clearer and more coherent**
- Changes to one interface don't affect unrelated clients
- Code becomes more **flexible and extensible**

### 📖 Example
In an **e-commerce app**, have:
- A separate interface for **online payment methods**
- A separate interface for **offline payment methods**

Each class only implements what's relevant to it — nothing more.

---

## **D — Dependency Inversion Principle (DIP)**

> *High-level modules should not depend on low-level modules. Both should depend on abstractions.*

Rely on **abstract interfaces** rather than concrete implementations. High-level modules should never directly depend on low-level modules.

### ✅ Benefits
- Improves **modularity** — concrete implementations can be swapped easily
- Makes **unit testing** easier via mocking and dependency injection
- Reduces **coupling** between modules

### 📖 Example
Instead of a high-level class depending directly on a low-level class, introduce an **abstract interface** between them. The high-level class depends on the interface — not the concrete class — making substitutions simple.

---

## 📊 Quick Reference

| Letter | Principle | Core Idea |
|--------|-----------|-----------|
| **S** | Single Responsibility | One class, one job |
| **O** | Open/Closed | Extend, don't modify |
| **L** | Liskov Substitution | Subclasses must honor base class contracts |
| **I** | Interface Segregation | Small, focused interfaces |
| **D** | Dependency Inversion | Depend on abstractions, not concretions |
