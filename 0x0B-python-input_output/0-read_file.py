#!/usr/bin/python3
def read_file(filename=""):
    """Read a text file (UTF8) and print its content to stdout."""
    with open(filename, 'r', encoding='utf-8') as file:
        print(file.read())
