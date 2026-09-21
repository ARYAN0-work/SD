                    SCALABILITY

                         ↓

              How do we handle growth?
                         ↓
        ┌────────────────────────────────┐
        │                                │
   More traffic                    More data/work
        │                                │
        ↓                                ↓
Horizontal scaling                Async processing
        │
        ↓
Load balancer
        │
        ↓
Stateless servers
        │
        ↓
Database bottleneck
        │
   ┌────┴─────┐
   ↓          ↓
Replication  Partitioning
   │
   ↓
Caching

Today's notebook — 3 words each
Vertical scaling: Bigger single machine
Horizontal scaling: Add more machines
Load balancing: Distribute incoming traffic
Stateless servers: Store shared state externally
Bottleneck: System limiting performance
Database scaling: Handle database growth
Caching: Fast temporary storage
Cache hit: Data found quickly
Cache miss: Fetch from database
Asynchronism: Work happens later
Job queue: Buffer background work
And one sentence I want you to remember:

System design is largely about finding bottlenecks and choosing the right way to remove or reduce them.

Today's 3 words: Scalability fundamentals complete. 🔥