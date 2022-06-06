# BIP39 generator

## Authors

Forked from [Jose Luu](https://github.com/jluuM2) repository [project_blockchain_python](https://github.com/jl$

The dev team is :
- [Estelle Hu](https://github.com/EstelleHu)
- [Mengru Gao](https://github.com/Mengrulune)
- [Alexandre Chekroun](https://github.com/alchekroun)

## History of version

 Format : X.Y.Z

X : Major release, many new features
Y : Minor release, few features on a previous major release
Z : Fix for a minor release

- 1.0.0 : implementation of the BIP39 generator
- 1.1.0 : adding tests 
- 1.1.1 : Fixing typo
- 1.1.2 : Fixing minor bugs

## Description
###Context
This BIP describes the implementation of a mnemonic code for the generation of deterministic wallets.

It consists of two parts: Generation of the mnemonic sentence and its conversion into a binary seed. This seed can later be used to generate deterministic wallets using BIP39 or similar methods.

Our library implements a [BIP39 generator](https://github.com/bitcoin/bips/blob/master/bip-0039.mediawiki) in C++. Fully workable on a python3 environment.

## Installation

Initialize dependencies:
```bash
cd project_blockchain_python
git submodule init
git submodule update
```
Then compile:
```bash
cd bip39
make
```

## Usage

Open a python3 console and import the library:

```python
>>> import bip39 as bp
>>> gen = bp.Bip39("en") # By default "en"
>>> gen.generate(12)
'also lab path phrase inner magic metal expose involve roof hire spell'
>>>
```

You can change the langage in the constructor or with the function ```set_langage("fr")```

NB : You can only generate X words, with X in [12, 15, 18, 21, 24].
```python
>>> gen.generate(30)
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
ValueError: The number of words wanted must be in [12, 15, 18, 21, 24] interval
```

