# BIP39 generator

## Authors

Forked from [Jose Luu](https://github.com/jluuM2) repository [project_blockchain_python](https://github.com/jluuM2/projet_blockchain_python)

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
- 1.1.0 : adding tests function

## Context
This BIP describes the implementation of a mnemonic code for the generation of deterministic wallets.

It consists of two parts: Generation of the mnemonic sentence and its conversion into a binary seed. This seed can later be used to generate deterministic wallets using BIP39 or similar methods.

Our library implements a [BIP39 generator](https://github.com/bitcoin/bips/blob/master/bip-0039.mediawiki) in C++. Fully workable on a python3 environment.

## Interaction with other components
![diagram](//www.plantuml.com/plantuml/png/RS-_2i8m4CVnFKznTAf31nK7EqYhInq4mGSeCJrieBc4wnNnxKs3Vn2SGlXz-C9LesYMoGqgnDSQ6pG9GDQSwiEbgJVBLGPwXDvfyoEo_V6ytgRjQeDICu1YDt-W1AE70Mv8o5emjz7VFNUjyHF9GiscUDiF0-aH7A7pP0sCI89ay7zOsZYp3u_yMqkm14QPc5BiPLI5rCKBdm00)

## Python functions
- ```get_langage()``` : Returns the language of the component.
- ```set_language(string language)``` : Sets the language of the component to French with parameter **"fr"** or to English with parameter **"en"**.
- ```generate(int word_count)``` : Generates the mnemonic sentence with **word_count** of words. **word_count** can only be chosen in the list [12, 15, 18, 21, 24].
- ```generate_given_entropy(string entropy)``` : Generate the mnemonic sentence given an entropy.
- ```retrieve_entropy(string mnemonic_sentence)```: Retrieve entropy given a mnemonic sentence.
- ```get_entropy()``` : Returns the entropy of the object bip39.

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
>>> gen = bp.Bip39("en")
>>> gen.generate(12)
'below judge harvest kitchen math trumpet anchor duck stable window country success'
>>> gen.get_entropy()
'14cf15a5bd8891d3021a1ed3df6cc46c'
```

You can change the langage in the constructor or with the function ```set_langage("fr")```

## Test
- Plan of test:
1. To check all the arguments are right
2. To check the length of entropy
3. To check the sentence of mnemonic with expected sentence

In order to check our component is working properly we have written a test code with the following methods.

```Generate()```: generate a mnemonic sentence. It needs to check the length of the string, then check the randomness by generating the mnemonic several times. Moreover, comparing all the results of test in order to make sure that they are random. We want the number of the words and it will retrun a result that we expect.

```Generate_given_entropy(string entropy)```: generate mnemonic sentence given an entropy, entropy string of the entropy and return a string of the mnemonic sentence in the language that we selected. It needs to check if it returns a result that we expect.

```Retrieve_entropy(string mnemonic_sentence)```: return a  mnemonic sentence. It needs to check if it is the particular entropy that we expect.

```Get_entropy()```: Convert the entropy in hexadecimal format and return the string of it. We take the mnemonic sentence as input and check weather the form is corresponding.

- Results of test:
  - ```Generate()```:
```python
>>> import bip39 as bp
>>> gen = bp.Bip39("en")
>>> gen.generate(12)
'actual unique bright fossil glove face useless acquire armor point space million'
>>> gen.generate(12)
'express wild vanish govern huge extend bar marriage render hope try process'
>>> gen.generate(12)
'water limit label hedgehog umbrella exhibit cabbage forget arrive stand final dentist'
>>> gen.generate(12)
'paddle anger shoot hotel have execute coconut atom gentle describe select simple'
>>> gen.generate(12)
'east nurse bachelor interest warm excite dignity scrap response pencil ice flower'
>>> gen.generate(12)
'uncover bundle orange junk input evil ensure nerve arrange answer tag tray'
>>> gen.generate(12)
'near pioneer chapter learn vendor escape flat elegant glare ignore endorse iron'
>>> gen.generate(12)
'dentist crop rain love leisure erosion have whisper resemble style wall air'
>>> gen.generate(12)
'thumb rival wing marine artwork envelope ivory pulse assume discover gloom nest'
>>> gen.generate(12)
'mask dose edge moon melt enter loud gaze gloom planet source carry'
>>> gen.generate(12)
'consider sign special nasty amused enhance nice crisp retreat artist lamp record'
>>> gen.generate(12)
'stone fire fortune obvious mad endless pledge traffic attend inject trust donate'
>>> gen.generate(12)
'large target plate ordinary add enable record right glide swamp filter south'
>>> gen.generate(12)
'category gospel cotton phrase mouse employ scissors holiday rifle demand seek gadget'
```

We can see that the sentence is always different and has 12 words in it.

  - ```Generate_given_entropy(string entropy)```:

```python
>>> gen.generate(12)
'melt tip push jealous chief clutch choice mimic school base forest suit'
>>> gen.get_entropy()
'8abc52babbc27c590a0c66c0c25d6cec'
>>> gen.generate_given_entropy("8abc52babbc27c590a0c66c0c25d6cec")
'melt tip push jealous chief clutch choice mimic school base forest suit'
```

We can see that ```generate_given_entropy``` can retrieve the correct sentence from an entropy.

  - ```Retrieve_entropy(string mnemonic_sentence)```:
```python
>>> gen.generate(12)
'balcony menu artefact busy betray blast away accident side favorite cake enact'
>>> gen.get_entropy()
'11d164338f91562ec4180bc7ea808124'
>>> gen.retrieve_entropy("balcony menu artefact busy betray blast away accident side favorite cake enact")
'11d164338f91562ec4180bc7ea8081'
```
We can see that ```retrieve_entropy``` can retrieve the correct entropy from a sentence.

  - ```get_entropy()```:
```python
>>> gen.generate(12)
'balcony menu artefact busy betray blast away accident side favorite cake enact'
>>> gen.get_entropy()
'11d164338f91562ec4180bc7ea808124'
>>> gen.retrieve_entropy("balcony menu artefact busy betray blast away accident side favorite cake enact")
'11d164338f91562ec4180bc7ea8081'
>>> gen.generate(12)
'code consider possible private help harvest vapor always follow oblige cover wrong'
>>> gen.get_entropy()
'2d05eaa25596b0d2fc583c5ab304c67f'
>>> gen.generate(15)
'mask dose edge moon melt enter loud gaze gloom planet source card stadium actual screen'
>>> gen.get_entropy()
'8868311947c8aa96e10b056374bf40114d3e05f0'
>>> gen.generate(18)
'remind caught kite shadow connect settle civil rate auto arm rough emerge buzz silver cute egg alcohol polar'
>>> gen.get_entropy()
'b5c48dece262f388ca65910f8176f12451f9918daa360614'
>>> gen.generate(21)
'hammer globe fly cover width curtain game captain basic job choose afraid chalk anger sketch stem seminar method brown switch bean'
>>> gen.get_entropy()
'688c696798cfac6c57c911130f00a102425e11728eaac39184746e11'
>>> gen.generate(24)
'nominee evolve excess grocery palm company wish inhale scale toss state clever ghost soldier dinner unique rhythm naive leopard awesome parade steel glove whale'
>>> gen.get_entropy()
'95e9c53a3369f45d3f239dc01cb7531546199d0f976cb8d25601084a01aa58ef'
```
The entropy is returned and it is always in hexadecimal format.

## Exceptions
You can only generate X words, with X in [12, 15, 18, 21, 24].
```python
>>> gen.generate(30)
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
ValueError: The number of words wanted must be in [12, 15, 18, 21, 24] interval
```
