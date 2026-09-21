# The Story

The story → distributed system

Initially, there is only you maintaining one notebook:

Customer
   |
   v
 You
   |
Notebook

No problem. There is only one copy of the data.

Then the business grows, so you add your wife:

             PBX
            /   \
           /     \
       You        Wife
        |           |
    Notebook    Notebook

Now we have two copies of the same data.

That's where distributed-system problems begin.

# The first problem: Consistency

Customer tells you:

"My neighbor's birthday is January 2."

You write:

Your notebook:
Neighbor birthday → Jan 2

But your wife doesn't know about it yet:

Your notebook:    Jan 2
Wife's notebook:  ??? 

If the next request goes to your wife, she may return something different.

That's a consistency problem.

The article's definition is essentially:

Once information is updated, subsequent reads should see the latest information.

# The second problem: Availability

The second problem: Availability

Suppose you're sick.

Your wife is still working:

Customer
   |
   v
  Wife ✅

The customer can still get a response.

So the system remains available.

This is why adding another node helps availability.

# Now comes the important one: Partition Tolerance

Imagine:

        You                  Wife
         |                     |
     Notebook              Notebook


              ❌
        Communication
           broken

You're both working, but you cannot communicate with each other.

That's a network partition.

Your wife receives:

"Change the birthday to January 5."

She writes:

Wife → Jan 5

But you don't know about it.

Then another customer asks you:

"What's the birthday?"

You say:

Jan 2

Wife says:

Jan 5

💥 Now you have the CAP problem.

The article uses this exact idea to explain why a system that is both consistent and available isn't automatically partition tolerant.

# Solutions

So what can we do?

When communication between you and your wife breaks, you have two choices.

Choice 1 — CP

You say:

"Until we can communicate again, don't accept requests."

You ❌
Wife ❌

You sacrifice Availability to preserve Consistency.

C ✅
A ❌
P ✅

This is CP.

Choice 2 — AP

You both continue accepting requests:

You  ✅
Wife ✅

But you might temporarily have:

You  → Jan 2
Wife → Jan 5

So the system remains Available, but consistency can temporarily be violated.

C ❌
A ✅
P ✅

Later, when communication returns, you synchronize the notebooks.

That's the idea behind eventual consistency.

The bonus section is VERY important

The article introduces a "running clerk":

You ──────┐
          │
          ▼
       Clerk
          │
          ▼
        Wife

You update your local notebook immediately.

The clerk later propagates the update to your wife.

That means:

Write doesn't have to wait for every replica.

This is basically the intuition behind asynchronous replication.

But there's a small window:

T1: You update → Jan 5


T2: Clerk hasn't synchronized yet


T3: Customer asks Wife


T4: Wife still says → Jan 2

So for a short period:

Different replicas
       ↓
Different values

Eventually:

You  → Jan 5
Wife → Jan 5

That's eventual consistency.

# IMP

              NETWORK PARTITION
                     |
          ┌──────────┴──────────┐
          ↓                     ↓
        CP                      AP
          |                     |
  "Don't answer until     "Answer with what
   data is synchronized"    we currently have"
          |                     |
    Consistency ↑          Availability ↑
    Availability ↓         Consistency ↓


When a network partition occurs, a distributed system must choose between preserving consistency and preserving availability.