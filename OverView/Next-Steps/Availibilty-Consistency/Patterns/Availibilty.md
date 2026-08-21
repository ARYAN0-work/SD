1. Failover

If the main server fails, another server takes over.

Active–Passive

Traffic → Active ✅
             ↓ fails
         Passive → takes over
Only active server handles traffic.
Passive server waits as backup.
Simple, but some resources may sit idle.

Active–Active

        ┌→ Server A ✅
Traffic ┤
        └→ Server B ✅
Both servers handle traffic.
Better resource utilization.
More complex because traffic must be distributed.

2. Replication

Keep copies of data/services on multiple servers.

       Primary
       /     \
      ↓       ↓
 Replica A  Replica B

If one server fails, another copy can serve the request.

Main difference

Failover = backup server takes over when one fails.

Replication = multiple copies exist so data/service can survive failures.

And remember the tradeoff from the screenshot:

Failover adds hardware + complexity, and data can potentially be lost if replication hasn't caught up.

That's enough for Availability Patterns for now.