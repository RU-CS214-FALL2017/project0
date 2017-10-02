Assumptions
===========
*	Csv (comma seperated values) formatted file passed in through stdin.
*	First row contains headers.
*	All rows contain the same number of columns.
*	Rows must be seperated with '\n' newline character.


CLI Usage
=========
Compile using:
	
		make compile

To sort data in a *inputCsvFile* acoording to the column with *header* and output to *outputCsvFile*:

	cat (inputCsvFile) | ./sorter -c (header) > (outputCsvFile)

To find interesting data in a *inputCsvFile*:

	cat (inputCsvFile) | ./sorter -i


Documentation
=============
Documentation for all functions are commented before each prototype.


Design
======
Organization
------------
*	Functions are written in source files.
*	Prototypes for functions that are used only in the same source file are at the top of the source file.
*	Prototyes for functions used in other source files are in the corresponding header files.
*	If a function in another source file is needed, it's correspondeing header file is imported.

Main Sorter
-----------
1.	Reads each line of stdin.
2.	Tokenizes each line and stores each line as a string array.
3.	Creates a 2D string array that refrences to each row and column.
4.	Searches first row for given header.
5.	Checks if corresponding column is alphabetic or numeric.
6.	Uses merge sort to sort according to the column, lexicographically or numerically.
7.	Prints the table.

Extra Credit #1
---------------
1.	Sorts table by each numeric column.
2.	Stores values from alphabetic columns that appear more than 5 times in the first and last 10 rows of each sorted table.
3.	Prints the results.

Extra Credit #2
---------------
Stroing all recordes as strings, including the headers, in a 2D string array is what allows for a generalized sorter.
You can pass any csv file as long as the first row contains the headers and each row has the same number of columns.
If any row doesn't have the same number of columns as the first row, that row is disregarded.

Testing
-------
*	I tested functions independently to perfect them.
*	I used the csv file you provided for testing the whole program.