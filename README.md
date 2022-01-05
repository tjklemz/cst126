# CST 126, Winter 2022; Oregon Tech

In this repo are code examples from class and for the labs.

If anything at all is causing confusion, let me know. It's perfectly
fine to not know something at this stage. If you want help understanding
something, no matter how basic, please ask. Maybe the idea of a
compiler is still confusing; maybe something about data types is
confusing; maybe char versus string is confusing. Anything is fair
game! The goal is to learn, and asking questions is one of the best
ways to do that. Never stop asking questions, even if you think you
already understand something.

## Running the Examples

To run any of the examples, either copy the code into your own
project(s) and run with Visual Studio or use a terminal workflow:

```bash
mkdir $HOME/proj
cd $HOME/proj
git clone https://github.com/tjklemz/cst126.git
cd cst126
# set the C++ version. You can also put this in your system startup.
CPPFLAGS=-std=c++17
# notice no .cpp extension when running make. Make will figure this out.
make lab1
# creates an executable with that name based on the lab1.cpp file
./lab1
```

Notice there is no Makefile or any kind of project file. Make can
run without needing a Makefile (many don't know that). If you would
like help setting up this kind of workflow, please let me know. It
is not required, but it _is_ strongly encouraged.

If the Terminal workflow is too confusing for you, focus on the
code and use whatever you're comfortable with, e.g. Visual Studio.
Then, at a later date, try learning the Terminal workflow again.

## Setting the C++ Version

Whether doing a Terminal (CLI=Command Line Interface) workflow or
doing a Visual Studio project workflow (GUI=Graphical User Interface),
you'll need to set the C++ version.

I recommend at least C++14 but preferably the latest (C++20 or
C++23). They have been releasing in 3 year cycles, starting with
C++11. This begins the so-called "Modern C++". When browsing the
[Cpp Reference](https://en.cppreference.com/w/) website, you can
see what features are available for which versions. So be aware at
least that certain syntaxes and features are only available in some
versions. Hence, my recommendation for the latest.

### In Visual Studio

To set the C++ version in Visual Studio, in the menu go to Project
-> Properties -> C/C++ -> Language -> C++ Language Standard. See
[this StackOverflow post](https://stackoverflow.com/a/46759740/958007)
for more info.

### In *nix Environments

In Mac/Linux/BSD or even Windows with the [Linux
subsystem](https://docs.microsoft.com/en-us/windows/wsl/) installed,
you'll likely be using either [GCC (GNU C Compiler)](https://gcc.gnu.org/)
or [LLVM (Low Level Virtual Machine)](https://llvm.org/). There
_are_ other compilers, but these days I would consider LLVM the
standard. Your system might already have these installed. Check by
typing `c++ --version` in your Terminal. That command, `c++`, is
normally aliased to the appropriate compiler and is what Make uses.

To set the version of C++, it's very simple. Set the `CPPFLAGS`
option: `CPPFLAGS=-std=c++17` for instance. You can do this
every time you open a terminal, or you can put this in your Bash
or Zsh rc file, or you can run it on every command. Example:
`CPPFLAGS=-std=c++17 make myfile.cpp`.

## Terminal Workflow

I highly recommend you begin looking into the Terminal if you're
not familiar or are not comfortable with it. There's a reason
Microsoft added the Linux subsystem to Windows. If you need a good
walkthrough of the command line (Linux commands normally transfer
to Mac/BSD), then use this book which is highly respected in the
community: [The Linux Command Line](https://nostarch.com/tlcl2).
No Starch Press has other good books; it's worth browsing there.

## C++ Reference

Learn to live and breathe the [Cpp Reference
website](https://en.cppreference.com/w/). It will be difficult at
first, and you might not get comfortable until Junior or Senior
year. But keep trying! Going here first instead of Googling (which
is okay too!) will make you a better programmer. Always go to the
language docs. I read the docs for whatever language I'm using
everyday, and I learn new things every time. The learning never
stops. :)

## Git

It's unlikely you know how to use git, but it's the industry standard
for version control. I remember being very confused in the beginning.
Learn the CLI (Command Line and Terminal) first, and then [learn
Git here](https://git-scm.com/book/en/v2). (FYI, SCM = Source Control
Management, another way to say version control for code, hence Git
SCM at that link.)

## Iterate

Always strive to do things better. Once you program something,
attempt to do it again a better way. Now, it's difficult to see
what way is "better", so to find "better" you have to iterate. In
other words, you have to do it "another way" to find the "better
way". If you strive for simplicity and conciseness (without
obfuscation!) and think in a data-oriented manner, you should find
that better way as you keep iterating.

It's important to not give up! Everything is difficult in the
beginning. It's okay to fail. Think of a sport:  Do you imagine
that everyone knows what to do in the beginning? There are movements,
exercises, strategies that are all difficult in the beginning. And
those things never cease. A pro basketball player still practices shooting
hoops.

