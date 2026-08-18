# Latency vs Throughput

Latency → How long one action/request takes.

Example:
Request → 200 ms → Response
➡️ Latency = 200 ms

Throughput → How many actions/requests the system can handle per unit of time.

Example:
5,000 requests / second
➡️ Throughput = 5,000 req/s

Easy way to remember

Latency = How fast?
Throughput = How much?

What do we want?

We generally want:

Maximum throughput + acceptable latency

Meaning: handle as many requests as possible, while keeping each request fast enough for users.

````bash

Link: https://community.cadence.com/cadence_blogs_8/b/fv/posts/understanding-latency-vs-throughput

````
For our interview prep, the article is mainly useful for reinforcing the exact distinction:

Latency → time taken to complete one operation
Throughput → amount of work completed over time

The key thing I want you to understand from it is that they are related but not the same.

Simple example

Imagine a server:

Scenario A

Each request takes 100 ms
It handles 10 requests/sec

Latency = 100 ms
Throughput = 10 req/s

Now imagine we add more workers:

Scenario B

Each request still takes 100 ms
But 10 requests can be processed simultaneously
Throughput becomes 100 req/s

👉 Latency didn't improve, but throughput did.

That's an important system-design insight.

One thing to remember

Latency measures the time for work. Throughput measures the rate of work.

And when designing systems:

Maximize throughput while keeping latency acceptable.