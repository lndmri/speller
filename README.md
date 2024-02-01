# speller

* This is my solution of the CS50 speller problem set, using C. https://cs50.harvard.edu/x/2023/psets/5/speller/ This problem set required implemnetation of a program which spell-checks a file (from a list of words, i.e. the dictionaries provided by CS50). NOTE: Copying this data and using it for your submission will breach the academic honesty https://cs50.harvard.edu/x/2023/honesty/. I would recommend trying it yourself before consulting the solution here. I can assure you it is worth trying it!

* Speller.c, implements a program that’s designed to spell-check a file after loading a dictionary of words from disk into memory. 
* That dictionary, meanwhile, is implemented in a file called dictionary.c.

* This problem required the implementation of the following functions (all within dictionary.c);
- load.
- hash.
- size.
- check.
- unload.

* Optimization is achieved in the way words are stored in a data structure. In this problem we load a dictionary of words into a hashmap to enhance the speed on how we can check a text against the words of the dictionary that is stored in the data structure.


# Usage: 
* speller [dictionary] textfile -> these are command line arguments
* example: ./speller dictionaries/large text

# Additional info
* For Full Problem presentation see https://cs50.harvard.edu/x/2023/psets/5/speller/
