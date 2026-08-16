# After scaling the database, users can still experience slow responses when the application repeatedly fetches data.

So we introduce:

User
 ↓
Application
 ↓
Cache
 ↓
Database

The cache is an in-memory key-value store, such as Redis.

Because memory is very fast, reading from the cache is much faster than repeatedly querying the database.

````bash

Link: https://web.archive.org/web/20230126233752/https://www.lecloud.net/post/9246290032/scalability-for-dummies-part-3-cache

````
## The two patterns mentioned

# Cached Database Queries

The application asks:

"Have I already cached the result of this database query?"

Request
  ↓
Cache
  ├── HIT  → return cached result ✅
  │
  └── MISS → Database
                ↓
             Cache result

The problem is cache invalidation.

Suppose the database says:

Username = Aryan

Cache has:

Username = Aryan

Then the user changes it:

Database → Rahul
Cache    → Aryan ❌

Now we have stale data.

That's one of the famous problems in system design:

How do we know when cached data should be removed/updated?

# 2. Cached Object

Instead of caching the result of individual database queries, you can cache the assembled object/data your application actually needs.

For example:

Product
├── name
├── price
├── images
└── reviews

Instead of repeatedly performing several database operations to construct that product, you can store the completed object in the cache.

Then:

Request
 ↓
Redis
 ↓
Complete Product Object ✅

This can reduce database work significantly.

Again, don't memorize this implementation yet.

What should you take from this section?

Just understand:

Cache = fast temporary storage
Database
   ↑
   │ cache miss
   │
Cache ← frequently accessed data
   ↑
   │ cache hit
   │
Application

Cache hit → data found in cache.

Cache miss → data isn't there → go to database.

And the big challenge:

Cache invalidation → keeping cached data correct/fresh.

One correction to the old article

The article strongly recommends Redis over Memcached. Don't treat that as a system-design rule.

In interviews, you should be able to say:

"I'd use an in-memory cache such as Redis, depending on the requirements."

Then explain why.

We care about the reasoning, not blindly choosing Redis.

For your notebook

Cache hit = fast.
Cache miss = database.
Invalidation = freshness.

3 words: Cache speeds reads.
