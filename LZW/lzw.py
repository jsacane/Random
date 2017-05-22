"""Compresses/decompresses standard text files based on the LZW alogrithm."""

def compress(filename):
    """Compresses a text file to a list of output symbols."""

    # Initialize the chararacter dictionary
    dict_size = 256
    dictionary = {chr(i):i for i in range(dict_size)}

    string = ""
    result = []

    # Begin reading chararacters from file
    with open(filename) as fileobj:
        for line in fileobj:
            for char in line:

                # Build string with each new character until a new string is found
                if (string + char) in dictionary:
                    string = string + char
                # Once a new string is found, add the old string's symbol to the results list
                # and add the new string to the dictionary
                else:
                    result.append(dictionary[string])
                    dictionary[string + char] = dict_size
                    dict_size += 1
                    string = char

    # Output the code for string
    if string:
        result.append(dictionary[string])

    return result


def decompress(symbols, output_file="out.txt"):
    """Decompresses a list of symbols into a text file."""

    # Initialize the chararacter dictionary
    dict_size = 256
    dictionary = {i:chr(i) for i in range(dict_size)} # inverted dictionary is ok since it's 1-to-1

    # Begin writing to output file
    with open(output_file, 'w') as fileobj:

        string = chr(symbols.pop(0))
        fileobj.write(string)

        for symbol in symbols:

            if symbol in dictionary:
                entry = dictionary[symbol]
            elif symbol == dict_size:
                entry = string + string[0]
            else:
                raise ValueError('Bad compressed symbol: %s' % symbol)

            fileobj.write(entry)

            # Add string + entry[0] to the dictionary
            dictionary[dict_size] = string + entry[0]
            dict_size += 1

            string = entry


# Test code
if __name__ == '__main__':
    compressed = compress('test.txt')
    print(compressed)
    decompress(compressed)
