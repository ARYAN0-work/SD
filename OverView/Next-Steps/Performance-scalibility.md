Performance vs Scalability

Performance = How fast the system works for one/few users.

Scalability = How well the system handles more users/load when we add resources (servers, CPU, memory, etc.).

Simple example

Imagine an API:

1 user → response takes 100 ms ✅ → good performance
10,000 users → response takes 5 seconds ❌ → scalability problem

So remember:

Performance = Fast now
Scalability = Stays fast as load increases

## A word on Scalibilty

`````bash

LINK: https://www.allthingsdistributed.com/2006/03/a_word_on_scalability.html

`````

A Word on Scalability — simple version

The article's main idea is:

A system is scalable when adding more resources gives you more performance.

For example:

1 server → 1,000 requests/sec
2 servers → ~2,000 requests/sec

That's good scalability.

But if:

1 server → 1,000 req/sec
2 servers → 1,100 req/sec

then simply adding resources isn't helping much → poor scalability.

Why scalability is difficult

The article highlights 3 important things:

You must design for scalability from the beginning.
You can't always bolt it on later.
Algorithms can become expensive as the system grows.
More users
More requests
Bigger datasets
More servers
More servers create complexity.
Servers may have different capabilities.
They may be in different locations.
Your system has to handle this efficiently.
What you should remember for interviews

Scalability = ability to grow by adding resources without the system becoming proportionally worse.

And the big lesson from the article:

Don't wait until your system is huge to think about scalability. Design for growth from the start.