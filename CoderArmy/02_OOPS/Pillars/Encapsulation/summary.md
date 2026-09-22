# Encapsulation

**Encapsulation** is about combining an object's **data (attributes)** and **behaviors (methods)** together inside a single unit, usually a **class**.

Encapsulation mainly focuses on **two things**:

## 1. Binding Data and Methods Together

An object has:

* **Characteristics / Attributes** → data or properties
* **Behaviors** → methods or functions

We combine these together inside a **class**.

For example, a `Car` class can contain:

```cpp
class Car {
    string color;
    int speed;

    void accelerate();
    void brake();
};
```

Here, the data (`color`, `speed`) and behaviors (`accelerate`, `brake`) are encapsulated together inside the `Car` class.

A class acts as a **blueprint for objects**.

---

## 2. Data Security / Access Control

Encapsulation also means protecting certain data from being directly accessed from outside the class.

We can use **access modifiers** such as:

* `private`
* `public`
* `protected`

For example:

```cpp
class BankAccount {
private:
    double balance;

public:
    double getBalance() {
        return balance;
    }

    void setBalance(double amount) {
        balance = amount;
    }
};
```

Here, `balance` is `private`, so it cannot be directly accessed from outside the class.

Instead, we provide controlled access through **getters and setters**.

This provides **data security and controlled access**.

---

# Abstraction vs Encapsulation

This is an important difference.

### Abstraction → Focuses on Data/Implementation Hiding

Abstraction hides **unnecessary implementation details** from the user.

> **Focus: What should be exposed?**

For example, you use a `for` loop without knowing how the compiler internally implements it.

### Encapsulation → Focuses on Data Security / Access Control

Encapsulation protects data by controlling **who can access or modify it**.

> **Focus: Who can access the data?**

For example, making `balance` private prevents outside code from directly modifying it.

### Simple Difference

| Abstraction                              | Encapsulation                        |
| ---------------------------------------- | ------------------------------------ |
| Hides unnecessary implementation details | Protects and controls access to data |
| Focuses on **what to show/hide**         | Focuses on **how to control access** |
| Mainly concerned with complexity         | Mainly concerned with data security  |

### Easy Way to Remember

> **Abstraction = Hide complexity**
> **Encapsulation = Protect data**

### Important Note

Data hiding and data security are not exactly the same:

* **Data hiding:** Even if someone knows the data exists, the internal implementation/details are hidden.
* **Data security:** Unauthorized code should not be able to directly access or modify protected data.

So, encapsulation combines **data + methods** and provides **controlled access to the data**.

---

## One-Line Definition

> **Encapsulation is the process of bundling data and the methods that operate on that data into a single unit (class), while controlling access to the data.**
