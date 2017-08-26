import cs50
import sys
import crypt
import itertools
import string

def main():
    
    # Error if more or less than 1 command line argument
    if len(sys.argv) != 2:
        print("Error.")
        exit(1)
        
    salt = "50"
    
    # For 1 letter passwords
    generator = itertools.product(string.ascii_letters, repeat=1)
    for w in generator:
        p1 = ''.join(w)
        if crypt.crypt(p1, salt) == sys.argv[1]:
            print("plaintext: {}".format(p1))
            exit(0)
    
    # For 2 letter passwords
    generator2 = itertools.product(string.ascii_letters, repeat=2)
    for x in generator2:
        p2 = ''.join(x)
        if crypt.crypt(p2, salt)  == sys.argv[1]:
            print("plaintext: {}".format(p2))
            exit(0)
        
    # For 3 letter passwords
    generator3 = itertools.product(string.ascii_letters, repeat=3)
    for y in generator3:
        p3 = ''.join(y)
        if crypt.crypt(p3, salt) == sys.argv[1]:
            print("plaintext: {}".format(p3))
            exit(0)
            
    # For 4 letter passwords
    generator4 = itertools.product(string.ascii_letters, repeat=4)
    for z in generator4:
        p4 = ''.join(z)
        if crypt.crypt(p4, salt) == sys.argv[1]:
            print("plaintext: {}".format(p4))
            exit(0)
            
if __name__ == "__main__":
    main()