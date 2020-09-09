import os
import sys

def greeting(name):
  print("Hello, " + name)

def appendCWDtoSYSPATH():
    sys.path.append(os.getcwd())