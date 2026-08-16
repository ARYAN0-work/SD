# We've already horizontally scaled the application servers, but eventually the application becomes slower because of the database.

Users
  ↓
Load Balancer
  ↓
┌─────────┬─────────┬─────────┐
Server 1  Server 2  Server 3
└─────────┴─────────┴─────────┘
              ↓
          Database

The important idea is:

Instead of replacing the database, improve and distribute its workload.

```bash

Link : https://web.archive.org/web/20220602114024/https://www.lecloud.net/post/7994751381/6scalability-for-dummies-part-2-database/locked

```
# 3 words: Database needs scaling.

What you need to take from this section

For your notebook:

Database bottleneck → scale database

And the major techniques you'll eventually learn are:

Database scaling
├── Replication
├── Partitioning / Sharding
├── Indexing / Query optimization
├── Denormalization
└── Caching

We'll study these properly later in the Primer.