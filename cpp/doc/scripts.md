# Scripts

Retrieves all the warnings after compiling the documentation and put them in a file called `warnings.txt`
 - alias GetWarning='doxygen 2> tmp.txt && sed -E '\''s/.*?include//'\'' tmp.txt > warnings.txt && rm tmp.txt'
