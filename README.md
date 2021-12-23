# wcwidth-comparision

A comparision of the results returned by glibc's `wcwidth`, rust's `unicode-width`
and xterm's version, all three of which are in use today!!
```
make
./a.out [any argument treats Ambiguous category cjk characters as 2-wide]
```
This script runs through all unicode codepoints from 0 to U+10FFFF.
I wonder why the columns are misaligned!
A pager is highly recommended for an optimal experience.

(At the moment I still hold some hope there is a mistake in my translation of the rust
code, or some other error)
