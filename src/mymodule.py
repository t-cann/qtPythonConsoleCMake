# References - 
# https://docs.python.org/3/library/rlcompleter.html

import os
import sys

def greeting(name):
  print("Hello, " + name)

def appendCWDtoSYSPATH():
    sys.path.append(os.getcwd())

# Welcome Message

# clear "clears the console"

# reset "reset the interpreter and clear the console"

# save "save commands up to now in given file"

# load "load commands from given file"

# history "shows the history"

# quit "print information about quitting"

# redirector ( with write method) class
# 1 "initialize the stdout/err redirector"
# 2 "implement the write method to redirect stdout/err"

# Line Completer with rlcompleter and readline ?

# import __builtin__ ?

def main():
  pass

if __name__ == '__main__':
  main()