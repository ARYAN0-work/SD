#include <iostream>
#include <string>

using namespace std;

class Car {
public:
    virtual void startEngine() = 0;
    virtual void shiftGear(int gear) = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void stopEngine() = 0;
    virtual ~Car() {}
};


class SportsCar : public Car {
public:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

    SportsCar(string b, string m) {
        this->brand = b;
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

//Car* myCar =>myCar is a pointer that can point to a Car object.

/*
int x=10;
Car*myCar; => Create a variable called myCar that is a pointer to a Car.
myCar doesn't contain the actual Car object => It contains an address/reference to an object, The * is telling C++:,"myCar is a pointer."
*/

/*
new SportsCar("Ford", "Mustang") => Create a new SportsCar object in memory.

Your constructor is:

SportsCar(string b, string m) {
    this->brand = b;
    this->model = m;
    isEngineOn = false;
    currentSpeed = 0;
    currentGear = 0;
}

So:

new SportsCar("Ford", "Mustang");

creates something conceptually like:

SportsCar object
┌─────────────────────┐
│ brand = "Ford"      │
│ model = "Mustang"   │
│ isEngineOn = false  │
│ currentSpeed = 0    │
│ currentGear = 0     │
└─────────────────────┘

And new gives you the address of that object.

Imagine the address is:

0x1000

So:

new SportsCar("Ford", "Mustang")

essentially gives:

0x1000
  ↓
SportsCar object
*/

/*
# why we use new ?

Car* myCar → myCar is a pointer.
new SportsCar(...) → creates a SportsCar object and gives its address.
= → stores that address inside myCar.

new creates the object, and the pointer stores its address.

*/

    Car* myCar = new SportsCar("Ford", "Mustang");  

    /** also right 
    SportsCar car("Ford", "Mustang");
    Car* myCar = &car;
     */

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
. Now combine them

You have:

Car* myCar = new SportsCar("Ford", "Mustang");

Right side:

new SportsCar("Ford", "Mustang")

creates:

              0x1000
                ↓
       ┌─────────────────┐
       │  SportsCar      │
       │                 │
       │ Ford            │
       │ Mustang         │
       │ engine = false  │
       │ speed = 0       │
       │ gear = 0        │
       └─────────────────┘

Then the address 0x1000 gets assigned to:

myCar

So:

myCar
  │
  │ contains address 0x1000
  ↓
0x1000
  │
  ↓
┌─────────────────┐
│  SportsCar      │
│  Ford Mustang   │
│  engine = false │
│  speed = 0      │
│  gear = 0       │
└─────────────────┘

That's literally what this line is doing.
*/