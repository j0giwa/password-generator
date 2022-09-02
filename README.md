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

- [Install](#Install)
- [Usage](#Usage)
- [Disclaimer](#Disclaimer)

## Install

It is recomended to recompile via the MakeFile first

```sh
make
```
You can copy the binary inside the ./bin into your usr/bin directory. 

```sh
sudo cp ./bin /usr/bin
```

## Usage


```sh
password-generator
```

will output a random String with the default parameters

Optional flags can be suplied,
however doing so will reset all default values,
so you need to set at leas on of these(-L,-S,-U)

|  flag  |           function           |
| ------ | -----------------------------|
|   -l   |  specify the length          |
|   -L   |  enable lowercase characters |
|   -U   |  enable uppercase characters |
|   -S   |  enable sepcial characters   |

example:

```sh
password-generator -l 12 -U -L
```
will output a 12 character string containing upper- and lowercase chacracters.


## Disclaimer

Since this is my first project written in C,
It won't be as well structured or usable as the projects made by seasoned developers,
however I will do my best.