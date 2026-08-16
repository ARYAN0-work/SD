# EXAMPLE

Synchronous approach

You order:

You
 ↓
Bakery
 ↓
"Wait here for 2 hours."
 ↓
Cake

That's terrible for a web application.

The user would have to keep the request open while your server does expensive work.

Asynchronous approach

Instead:

You
 ↓
Bakery
 ↓
"Your order is accepted."
 ↓
You leave

The bakery makes the cake in the background.

Later:

Cake finished
     ↓
Notify user

That's asynchronous processing.

Don't make the user wait for work that doesn't need to finish immediately.

# Async #1 — Pre-compute

The article's first example is basically:

Do expensive work before the user asks for it.

Imagine a website where generating the homepage takes a lot of computation.

Instead of doing:

User requests page
        ↓
Generate page
        ↓
Return page

we can periodically generate it:

Background job
      ↓
Generate page
      ↓
Store ready-made page


User
  ↓
Ready-made page ⚡

This is pre-computation.

It's useful when the data/content can be prepared ahead of time.

# Async #2 — Job Queue + Workers

This one is very important for backend development.

Imagine WorkSpaceHub has an endpoint:

POST /reports/generate

Generating the report takes 5 minutes.

Bad design
User
 ↓
Node.js
 ↓
Generate report
 ↓
5 minutes...
 ↓
Response

The user is sitting there waiting.

Better design
User
 ↓
Node.js
 ↓
Job Queue
 ↓
"Your job is processing."

Then workers process the job:

              ┌── Worker 1
              │
Job Queue ────┼── Worker 2
              │
              └── Worker 3

A worker takes the job:

Worker
 ↓
Generate report
 ↓
Store result
 ↓
Mark job completed

The user can then be notified or check:

GET /reports/:id/status

Why is this useful for scalability?

Imagine you suddenly have 10,000 expensive jobs.

Without a queue:

10,000 users
      ↓
10,000 expensive operations
      ↓
🔥 Backend overloaded

With a queue:

10,000 jobs
      ↓
   Job Queue
      ↓
┌─────┼─────┐
Worker Worker Worker

The workers process jobs at a controlled rate.

And we can add more workers:

3 workers → 10 workers → 50 workers

That's another form of horizontal scaling.

The architecture you should remember
                ┌── Worker 1
                │
User → API → Queue ── Worker 2
                │
                └── Worker 3

The API's job is:

Accept the request and enqueue the work.

The worker's job is:

Actually perform the expensive work.

One important distinction

Don't confuse:

Caching with Asynchronism.

Caching

"Don't do/fetch this expensive thing again."

Cache → fast result
Asynchronism

"Don't make the user wait while we do this expensive thing."

Queue → Worker → result later


