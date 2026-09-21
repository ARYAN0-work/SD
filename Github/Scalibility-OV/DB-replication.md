# Database Replication — Multiple copies of the database

Now imagine our backend has 20 servers.

They're all hitting one database.

The database becomes the bottleneck.

So we can create replicas:

                 ┌── Replica 1
                 │
Backend → Primary
                 │
                 └── Replica 2

Data is replicated to other database servers.

This can help with read scalability and availability.

Core idea: Multiple database copies.