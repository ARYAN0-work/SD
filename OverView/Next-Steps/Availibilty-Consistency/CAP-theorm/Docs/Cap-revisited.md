# First, lock in the 3 CAP terms



Consistency (C) → every read gets the latest write.
Availability (A) → every non-failing node gives a response within a reasonable time.
Partition Tolerance (P) → system keeps operating despite network communication failures between nodes.

`````bash

NOTE: 

The important thing:

P isn't really optional in a distributed system.

Networks fail. Nodes lose communication. You can't simply say "our system won't have partitions."

So when a partition happens, your real choice is:

C vs A

`````

2. CP — Consistency + Partition Tolerance

Suppose we have:

        User
          |
       Request
          |
    ┌─────┴─────┐
    │           │
  Node A      Node B

Node A and Node B normally communicate.

Now imagine the network breaks:

    Node A    X    Node B

A user asks Node A:

"What is my account balance?"

But Node A isn't sure whether Node B has a newer value.

A CP system says:

"I'd rather give you an error/wait than give you potentially incorrect data."

So:

Consistency ✅
Partition Tolerance ✅
Availability ❌

The article describes this as waiting for the partitioned node or returning an error when necessary.

Typical thinking: financial/accounting-style data where stale data can be dangerous.

3. AP — Availability + Partition Tolerance

Now imagine:

    Node A    X    Node B

Again, communication is broken.

Node A has an older copy of the data.

An AP system says:

"I'll give you the data I currently have, even if it might be stale."

So:

Availability ✅
Partition Tolerance ✅
Consistency ❌

The system continues working and synchronizes later when communication comes back.

This is useful when being temporarily stale is better than being unavailable.

For example, the article mentions things like shopping carts.

4. The most important interview understanding

Don't memorize:

"CAP means you can choose any 2 of 3."

That's the simplified version.

Instead remember:

              CAP
               |
       Network Partition
               |
          ┌────┴────┐
          ↓         ↓
         CP        AP
      consistent  available
      but may     but may
      reject      be stale
      request     temporarily

Partition happens → choose your behavior.

CP: "I'd rather reject/wait."

AP: "I'd rather respond with what I have."

That's the core of CAP.

The article explicitly makes this point: because network failures are unavoidable, the practical software decision is Consistency vs Availability during a partition.

5. One subtle thing you should know for interviews

CAP is about behavior during a network partition.

It does not mean:

"This database is always consistent"
"This database is always available"

Instead:

What happens when distributed nodes cannot communicate?

That's the question CAP answers.