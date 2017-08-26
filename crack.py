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
        
    salt = sys.argv[1][0] + sys.argv[1][1]
    
    for i in range(1, 5):
        generator = map(''.join, itertools.product(string.ascii_letters, repeat=i))
        
        for x in generator:
            if crypt.crypt(x, salt) == sys.argv[1]:
                print("plaintext: {}".format(x))
                exit(0)
            
if __name__ == "__main__":
    main()