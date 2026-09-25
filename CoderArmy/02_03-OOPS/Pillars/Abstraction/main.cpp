#include <iostream>
#include <string>

using namespace std;

/*
You already saw:

delete myCar;

When you do that, the destructor gets called.

Why virtual?

Because you're doing:

Car* myCar = new SportsCar(...);

The pointer is Car*, but the actual object is SportsCar.

Making the destructor virtual ensures that when:

delete myCar;

happens, C++ properly destroys the SportsCar object first.

So for now remember:

Constructor → object is created
Destructor  → object is destroyed

new    → creates
delete → destroys

And:

virtual ~Car() {}

basically means:

"When a Car-type object is deleted through a Car pointer, make sure the correct child destructor is called too."

You don't need to worry about the {} right now — it's simply an empty destructor body.
*/

class Car {
public:
    virtual void startEngine() = 0;
    virtual void shiftGear(int gear) = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void stopEngine() = 0;
    virtual ~Car() {}// destructor 
};


class SportsCar : public Car {
public:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

    SportsCar(string b, string m) {
        this->brand = b;//The instructor uses this-> because it's a common C++ way of explicitly saying "the variable belonging to this object."
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
    }

    void startEngine() {
        isEngineOn = true;
        cout << brand << " " << model << " : Engine starts with a roar!" << endl;
    }

    void shiftGear(int gear) {
        if (!isEngineOn) {
            cout << brand << " " << model << " : Engine is off! Cannot Shift Gear." << endl;
            return;
        }
        currentGear = gear;
        cout << brand << " " << model << " : Shifted to gear " << currentGear << endl;
    }

    void accelerate() {
        if (!isEngineOn) {
            cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
            return;
        }
        currentSpeed += 20;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" << endl;
    }

    void brake() {
        currentSpeed -= 20;
        if (currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/h" << endl;
    }

    void stopEngine() {
        isEngineOn = false;
        currentGear = 0;
        currentSpeed = 0;
        cout << brand << " " << model << " : Engine turned off." << endl;
    }
};

int main() {

    Car* myCar = new SportsCar("Ford", "Mustang");  

    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();

    delete myCar;    

    return 0;
}

/*
1. What is ->?

When you have a pointer to an object:

Car* myCar;

and you want to access its methods:

myCar->startEngine();

-> means:

"Go to the object that this pointer is pointing to, and access this."

So:

myCar->startEngine();

is basically:

myCar
  ↓
SportsCar object
  ↓
startEngine()

For a normal object, you use .:

SportsCar car("Ford", "Mustang");

car.startEngine();

For a pointer, you use ->:

SportsCar* car = new SportsCar("Ford", "Mustang");

car->startEngine();

Easy rule:

Object → .
Pointer → ->
*/

/*
2. Why delete myCar?

You created the object using:

new SportsCar(...)

That means C++ puts the object in dynamic memory (heap).

When you're finished with it:

delete myCar;

means:

"I'm done with this object. Free the memory."

So the flow is:

new
 ↓
create object in heap
 ↓
use object
 ↓
delete
 ↓
memory is freed

That's why your code has:

Car* myCar = new SportsCar("Ford", "Mustang");

// use it
myCar->startEngine();
myCar->accelerate();

// finished
delete myCar;

One-line memory trick:

new → create it
-> → use it through pointer
delete → destroy/free it
*/