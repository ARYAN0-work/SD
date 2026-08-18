## Avalibilty vs Consistency

1. Availability

Availability means:

The system always gives you a response, even if something goes wrong.

Example:

You open Instagram and request your feed.

If the system is highly available:

Request → Server → Response ✅

Even if one server/database is having problems, another can respond.

2. Consistency

Consistency means:

Every read gets the latest/correct data.

Example:

You change your username from:

Aryan → Aryan Kumar

Then immediately you request your profile.

With strong consistency:

You always see Aryan Kumar ✅

You don't get the old Aryan.

The important difference

Imagine we have two database servers:

        Database 1
            ↕
        Database 2

You update Database 1:

Name = Aryan Kumar

But Database 2 hasn't received the update yet.

Now a user reads from Database 2.

They might get:

Name = Aryan

So we have a choice:

Consistency:
"Wait until all databases have the latest data."

Availability:
"Give the user whatever data we currently have rather than making them wait."

And this leads directly to the CAP theorem, which is what the page is explaining next.

Remember these two lines

Availability = Will I get a response?

Consistency = Will I get the latest data?

