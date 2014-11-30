# UTF-8 BOM (Byte-Order-Mark) Strip


## Introduction

Bomstrip is a very simple tool that reads UTF-8 text from the standard input (stdin), removes BOMs (byte-order-marks), then writes to the standard out (stdout).

This tool is written in C. If you don't have a C compiler, or want some tool do the same thing but in other language, you can take a look at Mechiel Lukkien's [bomstrip project](http://www.ueber.net/who/mjl/projects/bomstrip/).

It also includes a set of snippets that all do the same thing in multiple programming languages：

- Python
- C

## What is a UTF-8 BOM
The UTF-8 BOM can be found at the start of some files. It consists of three bytes: \xEF \xBB \xBF. This is the UTF-8 encoding of unicode character FEFF.

## Reasons for not having a BOM in UTF-8 encoded files

- It breaks compatibility with ASCII.
- It may breaks shell scripts.
- It may breaks all kind of text processing.
- It looks ugly in your editor. Unless it thinks it should be smart and decides it needs to hide it from you.
- Since UTF-8 is interpreted as a sequence of bytes, there is no endian problem as there is for encoding forms that use 16-bit or 32-bit code units. Where a BOM is used with UTF-8, it is only used as an encoding signature to distinguish UTF-8 from other encodings — it has nothing to do with byte order. ( From unicode.org's [UTF-8, UTF-16, UTF-32 & BOM FAQ](http://www.unicode.org/faq/utf_bom.html#BOM) )

## How can I help

Implimentations in following languages are wanted:

- awk
- Brainfuck
- C++
- C# / Mono
- Common LISP
- Erlang
- Forth
- Go
- Haskell
- Java
- LUA
- Limbo
- OCAML
- Objective-C
- ook!
- Pascal ( tested on FreePascal, GNU Pasal )
- Perl
- PHP
- Postscript
- Prolog
- Ruby
- sed
- TCL/TK
- Unlambda

You can send it to me < <zer4tul@gmail.com> >, or clone this repo and send me a pull request.

## Credits

- Mechiel Lukkien < <mechiel@ueber.net> > ( This project comes from  his [bomstrip](http://www.ueber.net/who/mjl/projects/bomstrip/) project )
- [Timothy Boronczyk](https://github.com/tboronczyk), source code of UTF-8 handling in init version of bomstrip CLI tool comes from his [article](http://zaemis.blogspot.com/2011/06/reading-unicode-UTF-8-by-hand-in-c.html).
