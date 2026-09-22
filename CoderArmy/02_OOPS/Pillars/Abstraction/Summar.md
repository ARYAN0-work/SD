# Data Abstraction

**Abstraction** means hiding unnecessary internal details and showing only the information that is required to the user.

### Real-Life Example

In real life, all data is not required by every person. We hide unnecessary information and expose only what is needed.

Similarly, in programming, we can **hide implementation details** and expose only the functionality that is required.

### Abstraction Using Abstract Classes

An **abstract class** can define the methods that are required to interact with some business logic.

A child class (subclass) then **extends the abstract class** and provides implementations for its abstract methods.

So, the user interacts with the required methods without needing to know how the internal implementation works.

### Programming Languages as an Example of Abstraction

Programming languages such as **C++, Java, and Python** are also examples of abstraction.

They provide us with simple, human-readable keywords such as:

* `if` → for conditions
* `for` → for loops
* `while` → for loops
* `class` → for creating classes

We don't need to know exactly what happens internally when we write these keywords.

For example, when we write:

```cpp
if (x > 10) {
    // code
}
```

the compiler handles the complex process of converting our high-level code into **machine-level instructions** that the computer can execute.

Therefore, programming languages **abstract away the low-level implementation details** and allow us to write code using simple, human-readable syntax.

## Key Idea

> **Abstraction = Hide the unnecessary implementation details and expose only what is necessary to the user.**

### In Simple Words

**You use something without needing to know how it works internally.**

For example, you use a `for` loop without knowing how the compiler converts it into machine instructions.
