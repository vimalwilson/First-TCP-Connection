# First TCP Connection (C++)

This is a very small C++ program I wrote while learning
the basics of networking and cyber security.

The program tries to connect to a single TCP port
on a target IP address and tells you whether the
connection was successful or not

This is a learning project, not a professional tool.

---

## What this project teaches

- What a TCP connection is
- What it means when a port is open or closed
- How programs talk to the operating system
- Basic socket programming in C++

---

## How to build

This program uses no external libraries.

On Linux:

```bash
g++ main.cpp -o tcp_test
