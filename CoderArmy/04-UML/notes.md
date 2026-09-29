# aapke pass app banane ka idea hai us idea ko apne dost tak kaise pahuchoge =>

1. write paragraphs
2. Diagram => UML

>Types:-

1. Structural[static] : aapki app ka struc kaise hoga --> 7 [class-dia;sequence-dia]
2. Behavioural[dynamic]: aapki app ka behavour kaise hoga --> 7 []

> baaki specfic case k liye 

# Class Dia:-

- how class are gonna be structred towards each other
1. class structure
2. association/connection

# class car ; characterstic:- class varables ; behaviours:- methods

![alt text](image.png) :- that's how you are gonna represent 

> but we forget access modifiers

- the diffrences ![alt text](image-1.png)

![alt text](image-2.png) now how are we gonna reprent this 

![alt text](image-3.png) use these 

> lets say we want our characters to be public andmethods to be private

![alt text](image-4.png)

> now if we want engine to be protected 

![alt text](image-5.png)

```bash
theres still one thing left 

there's two types of classes:-

abstract and conctret class

1. jisme koi na koi vurtual method hota hai jisme hum koi method dete hai and deckeration karte hai basically child class me define karte hai 

iske liye ![alt text](image-6.png)

agar concrete toh kuch na likho aur voh concrete class
```

# OVERVIEW ![alt text](image-7.png)

## NOW HOW CLASS ASSOCIATION ARE MADE  [ how classes are connected ]

## ASSOCIATION:-

1. class association :- inheriatnce

2. object association :- simple , agreation , composition  [ combinaly-> compostion]

- actual reason progratimcally tino ek hi tarike se reprent hote hai theory wise alag alag hai 


# Inheritance ![alt text](image-8.png)
- is-1 relationship is nothing is just parent child relation 
![alt text](image-16.png)

> reprensentation : ![alt text](image-9.png)


## COMPOSATION HAVE A has-a relation :-

# Simple:-

![alt text](image-10.png)// arrow open  hai 
![alt text](image-11.png)// reprenation arrow operator 

ek simple link hoti hai 

# agregtion:-

![alt text](image-12.png)

main object [room] agregator ka kaam karta hai joki basically ek contationer ka kaam karta hai 

![alt text](image-13.png) // reprentation use diamond operator towards contationer 

# Compostation :-

![alt text](image-14.png) // represntation filled diamond also has-a relation

chair arms ye sub indivudally exist nhi kar sakte 

## NOW IN CODE :- [by the way puri lld me use hoga **IMP]

![alt text](image-15.png)

*** DEKHO inheritance pehancha loge but comosation pehchane me dikkat aayegi islye vaha tumhare upar ans ko dete ho voh depend karta hai ***

### SEQUENCE DIAGRAM [most of the cases me kaam nhi aayega but kuch use cases me kaam aa jayega ]

ye objects k bich inter/communication batata hai 

![alt text](image-17.png)

1. Representaion = dabba

![alt text](image-18.png)

2. Lifeline = voh object kabatak zinda rahega 

![alt text](image-20.png)

3. Activation Bar = voh object kabtak active rahega 

![alt text](image-21.png)

4. Messages 

- Asynnc [ek message k baad dusra bhejte rahte ho]
- Sync [ek message k baad wait karte ho response ka]

![alt text](image-23.png) simple message => syncronus

![alt text](image-24.png) simple message => asyncronus

### THERES A CREATE AND DESTROY MESSAGE 

jab aap ek app banaoge tab bhut saare messages aaynge toh usi me bhut saare message create and destroy k liye hote hai 

![alt text](image-25.png)

# Lost message and found message 

pahucha hi nhi user tak 

![alt text](image-26.png)

## HOW TODRAW SWQUENCE DIA:-

> whole process -> ![alt text](image-27.png)

![alt text](image-28.png)

# now ese approch rahegi

![alt text](image-29.png) => approch

ans -> ![alt text](image-30.png)

> remaing terms

![alt text](image-31.png)
![alt text](image-32.png)
