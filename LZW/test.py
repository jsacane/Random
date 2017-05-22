import lzw

print("Compressing text...")
print()
compressed = lzw.compress('darth_plagueis.txt')
print("Compressed text: ")
print(compressed)
print()

print("Decompressing text...")
lzw.decompress(compressed, 'darth_plagueis_out.txt')
