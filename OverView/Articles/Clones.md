# it introduces the basic architecture behind horizontal scaling.

Imagine we have :

User
 ↓
Server 1
 ↓
Database

Now traffic increases. One server can't handle everything.

So we create multiple identical copies (clones) of the application server:

              ┌── Server 1
              │
User → Load Balancer ── Server 2
              │
              └── Server 3

The load balancer distributes incoming requests among these servers.

For example:

Request 1 → Server 2
Request 2 → Server 9
Request 3 → Server 2

The user doesn't care which server handles their request.

he important part of this article

The article says:

Every server should contain exactly the same codebase and shouldn't store user-specific data locally.

Why?

Imagine you log in and your session is stored only inside Server 1:

Login
 ↓
Server 1
 ↓
Session stored on Server 1

Then your next request goes to Server 2:

Request
 ↓
Load Balancer
 ↓
Server 2
 ↓
"Who are you?" ❌

Server 2 doesn't know about your session.

Solution

Store shared data somewhere all servers can access:

             ┌── Server 1 ──┐
             │              │
User → Load Balancer        ├──→ Redis
             │              │
             └── Server 2 ──┘

This is why the article mentions Redis.

Another important idea: identical servers

Suppose you deploy your backend like:

Server 1 → v1 code
Server 2 → v1 code
Server 3 → v1 code

You don't want:

Server 1 → v2
Server 2 → v1
Server 3 → v1

because the load balancer might send users to different versions and produce inconsistent behavior.

So the servers should ideally run the same application version.

The article then introduces the idea of creating a reusable server image/template so new instances can be launched with the latest code.

You don't need to worry about AMI/AWS deployment details right now. That's secondary for our system-design foundation.

The mental model you should keep

This whole section boils down to:

                    ┌── App Server 1
                    │
Users → Load Balancer ── App Server 2
                    │
                    └── App Server 3
                           │
                           ↓
                     Shared Storage
                     (DB / Redis)
Why?

More traffic → more servers → load balancer → shared state

That's the core lesson.

Notebook — 3 words

Identical stateless servers.

Server 2 doesn't have the user's session, because the session was stored only in Server 1's memory.

So Server 2 might treat the user as unauthenticated.

That's the reason we move shared state out of individual application servers:

Server 1 ──┐
Server 2 ──┼──→ Redis / Database
Server 3 ──┘

Now whichever server receives the request can access the same session.

Interview version

Application servers should ideally be stateless so any server can handle any request. Shared state should be stored in an external shared data store such as Redis or a database.

3 words: Servers stay stateless.



`````bash
LINK: https://web.archive.org/web/20220530193911/https://www.lecloud.net/post/7295452622/scalability-for-dummies-part-1-clones#notes/locked

`````