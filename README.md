# Anti-CheatEngine
A simple program made in C++ that detects cheat engine by its process name.

How to compile.
Release - x86
Make sure character set is multibyte or one certain function called "push_back" doesn't work.
Make sure C++ date is 17-20-latest.
Finally build and run.

Program should not detect cheat engine until its running or opened.

Also this is just a simple way to detect any process. 
I like to call this the lazy way.

Cool things you could possibly make on your own is to put 
every known enemy process name into a array of strings and parse through them.

example:
std::vector<std::string> knownProcs = {"CheatEngine", "Reclass.NET", "OllyDbg", "x64dbg"};
