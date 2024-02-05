<h1 align="center">
  password-generator
</h1>

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

Install it via make

```sh
sudo make install
```

## Usage

```sh
password-generator
```

will output a random String with the default parameters

Optional flags can be supplied.

| flag          | function                           |
| ------------- | ---------------------------------- |
| -l <amount>   | specify the amount of characters   |

example:

```sh
password-generator -l 12
```
will output a 12 character string.
