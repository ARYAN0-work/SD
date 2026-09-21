# Horizontal Scaling — Add more servers

Eventually one machine isn't enough.

             ┌── Server 1
             │
Users → ??? ─┼── Server 2
             │
             └── Server 3

Now we have multiple backend instances.

Core idea: More machines.

But now we have a new problem:

Who decides which server receives each request?

That leads directly to...