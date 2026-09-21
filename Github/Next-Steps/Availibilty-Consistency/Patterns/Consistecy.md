## Consistency-Patterns

1. Weak consistency

After a write, a read may or may not see the new data.

Write → Node A
Read  → Node B → old data possible
Fast
Good when temporary missing/stale data is okay
Example: real-time chat/video systems
2. Eventual consistency

After a write, replicas eventually get the new data.

Write → A
       ↓
   replication
       ↓
      B


Eventually: A = B
Usually asynchronous replication
Good for highly available systems
Examples: DNS, email
3. Strong consistency

After a write, every subsequent read sees the new data.

Write → replicated synchronously
Read  → latest data
More reliable
Usually more latency / coordination
Good when correctness matters
Examples: transactions, many RDBMS use cases
Easy way to remember
Pattern	After write	Main benefit
Weak	Maybe updated	Speed
Eventual	Eventually updated	Availability
Strong	Immediately/latest	Correctness

For interviews: know the difference between strong vs eventual consistency especially well. Weak consistency is basically the loosest guarantee.