## The entire story

We're not learning six random technologies.

We're solving a chain of problems:

Traffic increases
      ↓
One server isn't enough
      ↓
Horizontal scaling
      ↓
Multiple servers
      ↓
Need to distribute requests
      ↓
Load balancer
      ↓
Database becomes bottleneck
      ↓
Caching
      ↓
Replication
      ↓
Eventually partition/shard the data

And that's what Step 1 is trying to teach you at a high level

Understand the story of how a backend scales.

Bottleneck = the part of a system that limits the overall system's performance.

So orders start piling up at the chef.

The chef is the bottleneck.

A bottleneck isn't necessarily a "bad" component. It's simply the component that is currently limiting the system.