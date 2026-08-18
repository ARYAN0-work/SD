# CAP Theorem

CAP stands for:

C — Consistency

Every request gets the latest data.

Example:

You update balance → ₹500
You immediately read → ₹500

Everyone sees the same/latest value.

A — Availability

Every request gets a response, even if some part of the system is failing.

Request → Response ✅

The response might not contain the newest data, but the system doesn't simply refuse to respond.

P — Partition Tolerance

The system continues working even when network communication between servers breaks.

Imagine:

Server 1  X  Server 2
          ↑
     network failure

The servers can't communicate with each other.

A partition has happened.

Partition tolerance = the system can survive this situation.

The important part

The CAP theorem says:

In a distributed system, when a network partition happens, you have to choose between Consistency and Availability.

So:

             CAP
              |
      ┌───────┼───────┐
      C       A       P
 Consistency Availability Partition
                      Tolerance

Because network failures can happen, we generally need P.

Therefore, during a partition:

CP

Choose:

Consistency + Partition Tolerance

You'd rather reject/delay requests than give potentially stale data.

AP

Choose:

Availability + Partition Tolerance

You'd rather keep responding even if the data might temporarily be stale.

One very important correction

Don't memorize:

❌ "You can only choose any 2 of C, A, P."

That's an oversimplification.

The useful interview version is:

When a network partition occurs, you must trade off Consistency vs Availability.

That's the part I want you to understand.

``````bash

Link: https://robertgreiner.com/cap-theorem-revisited

``````

CAP Theorem Revisited — what you need

The key point is:

CAP is about what happens when a network partition occurs.

Imagine:

Node A  ───────X───────  Node B
             network
             failure

A and B can no longer communicate.

That's P — Partition Tolerance.

Now you have a choice:

Option 1 — Consistency

Node A says:

"I can't communicate with Node B, so I won't give you an answer until I know the data is correct."

You preserve C but sacrifice A.

➡️ CP

Option 2 — Availability

Node A says:

"I can't communicate with Node B, but I'll still give you the data I currently have."

You preserve A but may temporarily sacrifice C.

➡️ AP

The important takeaway

Don't think:

❌ "A distributed system chooses any 2 of C, A and P."

Think:

✅ When a partition happens, you choose between Consistency and Availability.

Because in a real distributed system, P is not something you can simply ignore—network failures happen.

For our notes

Remember just this:

Concept	Meaning
C	Latest/correct data
A	Always respond
P	Survive network failure
CP	Correct data > response
AP	Response > immediately correct data

``````bash

Neither is better overall. It depends on what your system needs.

CP → choose Consistency over Availability.
Use when wrong/stale data is dangerous.
Examples: banking, payments, inventory.
AP → choose Availability over immediate Consistency.
Use when staying online is more important than temporarily stale data.
Examples: social media feeds, likes, recommendations.
Easy memory

CP: “Give me correct data, even if you have to wait.”
AP: “Give me a response, even if the data might be slightly old.”

`````````