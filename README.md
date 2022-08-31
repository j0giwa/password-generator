<h1 align="center">
  password-generator
</h1>
<h2 align="center">
  An educational project to teach myself the C programming language.
</h2>
<p align=center>
  <br>
  <img src="https://img.shields.io/badge/os-linux-brightgreen">
  <img src="https://img.shields.io/badge/os-mac-brightgreen">
</p>

## Table of Contents

- [Development goals](#Development-goals)
- [Install](#Install)
- [Usage](#Usage)
- [Disclaimer](#Disclaimer)


## Development goals

|               function                  | implemented |
| --------------------------------------- | ----------- |
| Generate lowercase letters              |     yes     |
| Generate uppercase letters              |     yes     |
| Generate symbols                        |     yes     |
| Join the generated strings              |     yes     |
| Randomise to order of the joined string |     yes     |
| Documentation (man page / --help)       |      no     |
| Commandline flags                       |      no     |
| make install target                     |      no     |


## Install
 
The current way of installing it is via the MakeFile

```sh
make
```

The binary is placed in the bin/ directory of the project files.


## Usage
 
The current version is still in development, so errors should be expected.

```sh
password-generator
```

will output a random String with the default parameters


Optional flags can be suplied

|  flag  |           function           |
| ------ | -----------------------------|
|   -l   |  specify the length (WIP)    |
|   -L   |  enable lowercase characters |
|   -U   |  enable uppercase characters |
|   -S   |  enable sepcial characters   |

example:

```sh
password-generator -l 12 -U -L
```

will output a 12 character long strin containing only upper- and lowercase chacracters


## Disclaimer

Since this is my first project written in C,
It won't be as well structured or usable as the projects made by seasoned developers,
however I will do my best.
