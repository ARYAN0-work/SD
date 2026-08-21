# In Short

Availability is measured in "9s"

The more 9s, the less downtime allowed.

Availability	Name	Downtime/year
99%	Two 9s	~3.65 days
99.9%	Three 9s	~8h 46m
99.99%	Four 9s	~52m
99.999%	Five 9s	~5m 15s
Important interview point

99.99% availability ≠ 100%.

Even highly available systems can have some downtime.

And don't memorize every table value. Just understand:

More 9s → less acceptable downtime → harder and more expensive to achieve.

## Easy Language

Imagine your website runs for 1 year.

99% availability

This means:

The website is working 99% of the year.

So it's allowed to be down for about 1%.

That's roughly 3.65 days of downtime.

99.9% availability

Now we're saying:

The website works 99.9% of the year.

Only 0.1% can be downtime.

That's about:

8 hours 46 minutes/year.

99.99% availability

Now only 0.01% can be downtime.

That's about:

52 minutes/year.

See the pattern?
99%       → ~3.65 days down
99.9%     → ~8.8 hours down
99.99%    → ~52 minutes down
99.999%   → ~5 minutes down

So every extra 9 means:

We are allowing the system to be unavailable for much less time.

Why do we care?

Imagine:

Google Search:
99% availability → potentially days of downtime 😵

That's unacceptable.

So large systems aim for very high availability such as 99.99% or higher, depending on the service.

That's literally all this section is saying.

Don't worry about calculating these numbers right now. Just understand more 9s = less downtime allowed.

## IS 100% achivable

In real-world distributed systems, 100% availability is practically impossible.

Why?

Servers can fail.
Networks can fail.
Databases can fail.
Power/infrastructure can fail.
Software bugs and deployments can cause downtime.

So we aim for:

99.9% → 99.99% → 99.999% → etc.

rather than 100%.

And notice the crazy part:

99.999% = only ~5 minutes of downtime per year.

So the closer you get to 100%, the much harder and more expensive it becomes.

For interviews, remember:

100% availability isn't a realistic guarantee; we measure and design for a target of "nines."