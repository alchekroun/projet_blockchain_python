# BIP39 generator

## Authors

Forked from [Jose Luu](https://github.com/jluuM2) repository [project_blockchain_python](https://github.com/jluuM2/projet_blockchain_python)

The dev team is :
- [Estelle Hu](https://github.com/EstelleHu)
- [Mengru Gao](https://github.com/Mengrulune)
- [Alexandre Chekroun](https://github.com/alchekroun)

## Specification

Check the specification of our [BIP39](doc/bip39.md) component.

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
