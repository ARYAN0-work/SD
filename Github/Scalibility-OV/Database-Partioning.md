# Database Partitioning — Split the data

Replication creates copies.

Partitioning is different: we split the data.

Users

A–H → Database 1
I–P → Database 2
Q–Z → Database 3

Instead of every database containing everything, each one handles a portion of the data.

This is commonly called sharding when the data is split across database instances.

Core idea: Divide the data.