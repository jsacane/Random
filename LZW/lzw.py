"""Compresses/decompresses standard text files based on the LZW alogrithm."""

def compress(filename):
    """Compresses a text file to a list of output symbols."""

    # Initialize the character dictionary
    dict_size = 256
    dictionary = {chr(i):i for i in range(dict_size)}

    string = ""
    result = []

    # Begin reading characters from file
    with open(filename) as fileobj:
        for line in fileobj:
            for ch in line:

                # Build string with each new character until a new string is found
                if (string + ch) in dictionary:
                    string = string + ch
                # Once a new string is found, add the old string's symbol to the results list
                # and add the new string to the dictionary
                else:
                    result.append(dictionary[string])
                    dictionary[string + ch] = dict_size
                    dict_size += 1
                    string = ch

    # Output the code for string
    if string:
        result.append(dictionary[string])

    return result


"""def decompress(symbols, output_file = "out.txt"):
    Decompresses a list of symbols into a text file.

    # Initialize the character dictionary
    dict_size = 256
    dictionary = {chr(i):i for i in range(dict_size)}

    for symbol in symbols:
        if symbol in dictionary:
            pass"""
