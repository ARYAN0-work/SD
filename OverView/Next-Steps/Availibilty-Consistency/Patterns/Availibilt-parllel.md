# availability when multiple components are involved.

1. Components in sequence → availability goes DOWN

Example:

User → API → Database

Both API and DB must work.

If:

API = 99.9%
DB = 99.9%

Then:

Total = 99.9% × 99.9% = 99.8%

So:

In sequence → multiply availability.

2. Components in parallel → availability goes UP

Example:

        ┌→ Server A
User → LB
        └→ Server B

You only need one server to work.

If both are 99.9% available, the chance that both fail is:

0.1% × 0.1% = 0.0001%

Therefore availability is:

1 − 0.0001% = 99.9999%

So:

In parallel → redundancy increases availability.

Remember
SEQUENCE  → all must work → availability ↓
PARALLEL  → one can work  → availability ↑

That's the important part. Now the next section is DNS, exactly where you wanted to stop.