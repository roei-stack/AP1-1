# ass1 - knn classifier

************By************
Itamar Gefen
Roei Cohen

*******Instructions*******
0. Clone the project
1. Make sure you have classified.csv and unclassified.csv in the same folder as the project
2. execute the code
3. a file named "output.csv" will be created
4. the k value is defined in main.cpp to 5

******The algorithm*******
0. created 2 reader instances (to handle file reading and the parsing), from a path to both input files.
1. used it's method that 2 databases for classified and unclassified (one from each instance).
2. passed classified data, and a k value for a classifier, that contains the method classify (takes an unclassified classifiable and classifies it)
3. for each classifiable in unclassified data:
  3.1 classify it
4. the data is written/overwritten to an output file "output.csv"

*******Optimizations******
1. Code was written with respect to OOP rules and coding style in mind
2. used the "select" algorith to find the k nearest neibours which takes O(n) time, instead of sorting which takes at least O(nlogn)
**************************
