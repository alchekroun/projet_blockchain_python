import bip39 as bp
import re
def test_generate(word_count):
    gen = bp.Bip39("en")
    s1 = gen.generate(word_count)
    s2 = gen.generate(word_count)
    if(s1==s2):
        print("KO not random")
    else :
        print("OK is random")


def test_generate_given_entropy(word_count):
    gen = bp.Bip39("en")
    s1 = gen.generate(word_count)
    e = gen.get_entropy()
    s2 = gen.generate_given_entropy(e)
    if(s1!=s2):
        print("KO doesn't generate same sentence")
    else:
        print("OK generate same sentence")

def test_retrieve_entropy(word_count):
    gen = bp.Bip39("en")
    s = gen.generate(word_count)
    e1 = gen.get_entropy()
    e2 = gen.retrieve_entropy(s)
    if(e1!=e2):
        print("KO doesn't retrieve same entropy")
    print("OK retrieve same entropy")

def test_get_entropy(word_count):
    gen = bp.Bip39("en")
    s = gen.generate(word_count)
    e1 = gen.get_entropy()
    hexaPattern = re.compile(r'(\n--)([0-9a-f]+)(--)?', re.I | re.S | re.M)
    hex = re.search(hexaPattern, e1)
    if hex:
        print ("OK is hexadecimal format")
    
    else:
        print("KO not hexadecimal format")