# Project

## So far into the project:
- [x] Read text file into linked list.
- [x] File input for linked list info.
- [x] Linked List as development 
- [x] Display all the data from the linked list.
- [x] Analysis for Daily sales.
- [x] Analysis for Monthly sales.
- [ ] Extra fucntions.  
- [ ] All tasks are complete :tada:


## Logs:

1. Changed the project for easier function adding and debugging.
   - you do not need the `readData.cpp` anymore.
   - File 01 and 02 are definitions for the linked list.
   - File 03 to 07 are the source code.

2. **(2021-12-13)** Added function `dailyReport()` and code to ignore text on the top of `.txt` file.
   - `dailyReport()` only output selected date. Located in `dataListType.cpp` & `dataListType.h`
   - Now project igonre text on the top of the `.txt` file. Located at `source.cpp` in `createDataList`, `din.ignore(numeric_limits<streamsize>::max(), '\n');`
   - Can now have `.txt` file header: `Date`, `Item`, `Quantity`, `Unitprice`, `Amount`

3. **(2021-12-15)** Added function `monthlyReport()` and overloaded `dataType` for `>=` and `<=` and suggested enter function.
   - Able to generate monthly report for month 12 but any other month would make it print the whole table.
   - Overloaded `dataType` for use as a boolean. Able to compare `string` data types with other `string` data types. If the comparison is `True` it would give `0` allowing the   code under the `statements` to run. If comparison is `False` it would give `1` stopping for excuting.
   - Function `bool dataSearch(string date) const` in `dataListType` can be kept as a function as it allows user to know if a `date` exist in the `.txt` file.

## Bug Fixes:

1. Fixed dupliacte node in linked list.
2. Compiler does not recognize `first` and `last` in `unorderedLinkedList.cpp`. 2phase Look up.
3. `nullptr` does not work on Dev-C++.

Please run the code with all the file 01 to 07, remove the numbering in the file when you need to run the programme.

## OUTPUT:

 |      Date      |      Item     |    Quantity   |    Unitprice  |     Amount    |
 |----------------|---------------|---------------|---------------|---------------|
 |2021-12-01      |Nasi           |5              |4              |20             |
 |2021-12-01      |Ikan           |3              |10             |30             |
 |2021-11-20      |Ayam           |2              |10             |20             |
 |2021-11-20      |Nasi           |5              |4              |20             |
 |2021-11-20      |Ikan           |3              |10             |30             |
 |2021-11-20      |Ayam           |2              |10             |20             |
 |2021-11-20      |Nasi           |5              |4              |20             |
 |2021-11-19      |Ikan           |3              |10             |30             |
 |2021-11-19      |Ayam           |2              |10             |20             |
 |2021-11-18      |Nasi           |5              |4              |20             |
 |2021-11-18      |Ikan           |3              |10             |30             |
 |2021-11-18      |Ayam           |2              |10             |20             |
 
 Dont know why the last linked list Date is slanted to the left. Maybe a complier bug?
 
 ## OUTPUT for Daily Report:
 
 If entered data is: `2021-12-01`
 
 |      Date      |      Item     |    Quantity   |    Unitprice  |     Amount    |
 |----------------|---------------|---------------|---------------|---------------|
 |2021-12-01      |Nasi           |5              |4              |20             |
 |2021-12-01      |Ikan           |3              |10             |30             |
 
 ## OUTPUT for Monthly Report:
 
 If entered data is: `2021-12-`
 
 |      Date      |      Item     |    Quantity   |    Unitprice  |     Amount    |
 |----------------|---------------|---------------|---------------|---------------|
 |2021-12-01      |Nasi           |5              |4              |20             |
 |2021-12-01      |Ikan           |3              |10             |30             |
 
 But if entered date is: `2021-11-`
 
 |      Date      |      Item     |    Quantity   |    Unitprice  |     Amount    |
 |----------------|---------------|---------------|---------------|---------------|
 |2021-12-01      |Nasi           |5              |4              |20             |
 |2021-12-01      |Ikan           |3              |10             |30             |
 |2021-11-20      |Ayam           |2              |10             |20             |
 |2021-11-20      |Nasi           |5              |4              |20             |
 |2021-11-20      |Ikan           |3              |10             |30             |
 |2021-11-20      |Ayam           |2              |10             |20             |
 |2021-11-20      |Nasi           |5              |4              |20             |
 |2021-11-19      |Ikan           |3              |10             |30             |
 |2021-11-19      |Ayam           |2              |10             |20             |
 |2021-11-18      |Nasi           |5              |4              |20             |
 |2021-11-18      |Ikan           |3              |10             |30             |
 |2021-11-18      |Ayam           |2              |10             |20             |
 
 FIXED
 
 Entered data: `2021-12`
 
 |      Date      |      Item     |    Quantity   |    Unitprice  |     Amount    |
 |----------------|---------------|---------------|---------------|---------------|
 |2021-12-01      |Nasi           |5              |4              |20             |
 |2021-12-01      |Ikan           |3              |10             |30             |
 
 Entered data: `2021-11`
 
 |      Date      |      Item     |    Quantity   |    Unitprice  |     Amount    |
 |----------------|---------------|---------------|---------------|---------------|
 |2021-11-20      |Ayam           |2              |10             |20             |
 |2021-11-20      |Nasi           |5              |4              |20             |
 |2021-11-20      |Ikan           |3              |10             |30             |
 |2021-11-20      |Ayam           |2              |10             |20             |
 |2021-11-20      |Nasi           |5              |4              |20             |
 |2021-11-19      |Ikan           |3              |10             |30             |
 |2021-11-19      |Ayam           |2              |10             |20             |
 |2021-11-18      |Nasi           |5              |4              |20             |
 |2021-11-18      |Ikan           |3              |10             |30             |
 |2021-11-18      |Ayam           |2              |10             |20             |
 
 
