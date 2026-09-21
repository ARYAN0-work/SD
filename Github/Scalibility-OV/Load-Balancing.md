# Load Balancing — Distribute requests

Users
  ↓
Load Balancer
  ├──→ Server 1
  ├──→ Server 2
  └──→ Server 3

The load balancer distributes traffic across servers.

It also helps with availability because if one server dies, traffic can be directed to healthy servers.

Core idea: Distribute traffic.