# Caching — Don't repeatedly calculate/fetch the same thing

Imagine WorkSpaceHub has:

GET /workspaces/123

The server needs to return workspace information.

Without caching:

User
 ↓
Node.js
 ↓
MongoDB
 ↓
Node.js
 ↓
User

Every time someone asks for the workspace, we go to MongoDB.

Now imagine 10,000 people request the same workspace.

10,000 requests
       ↓
   Node.js
       ↓
   MongoDB

MongoDB has to repeatedly answer:

"Give me workspace 123."

That's unnecessary work if the data doesn't change frequently.

# Enter the cache

A cache is a fast temporary storage layer.

For example, Redis can act as a cache.

Now:

User
 ↓
Node.js
 ↓
Redis

If Redis already has the workspace:

User
 ↓
Node.js
 ↓
Redis
 ↓
User

We don't need to ask MongoDB.

So the database gets much less traffic.

The key idea

Think of it like this:

Without cache
        ┌──→ Database
Users ──┤
        ├──→ Database
        ├──→ Database
        ├──→ Database
        └──→ Database
With cache
              ┌──→ Cache → Data ✅
Users → Backend│
              └──→ Database (only when needed)

The cache takes some work away from the database.

That's why caching can help when the database becomes a bottleneck.

- Real-life analogy

Imagine you're studying and you keep asking your teacher:

"What's the formula for X?"

Every 2 minutes.

Instead, you write the formula on a sticky note next to your desk.

Next time:

"What's the formula?"

You look at the sticky note.

You don't bother the teacher.

Sticky note = cache
Teacher = database

One important thing

Cache isn't the permanent source of truth.

Usually:

Database = source of truth
Cache    = fast temporary copy

That's why cached data can sometimes be stale.

Your notebook

Write this:

Bottleneck: The part of a system limiting overall performance.
Cache: Fast temporary storage used to avoid repeatedly accessing slower storage.

3 words: Cache reduces database load.