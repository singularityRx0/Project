# Project

## So far into the project:
- [x] Read text file into linked list.
- [x] File input for linked list info.
- [x] Linked List as development 
- [x] Display all the data from the linked list.
- [ ] Analysis for Daily sales.
- [ ] Analysis for Monthly sales.
- [ ] Extra fucntions.  
- [ ] All tasks are complete :tada:


### Logs:

1. Changed the project for easier function adding and debugging.
   - you do not need the `readData.cpp` anymore.
   - File 01 and 02 are definitions for the linked list.
   - File 03 to 07 are the source code.

2. **(2021-12-13)** Added function `dailyReport()` and code to ignore text on the top of `.txt` file
   - `dailyReport` only output selected date
   - Now project igonre text on the top of the `.txt` file.
   - Can now have file header: `Date`, `Item`, `Quantity`, `Unitprice`, `Amount`

Please run the code with all the file 01 to 07, remove the numbering in the file when you need to run the programme.

## OUTPUT:

 |      Date      |      Item     |    Quantity   |    Unitprice  |     Amount    |
 |----------------|---------------|---------------|---------------|---------------|
 |2021-12-01      |Nasi           |5              |4              |20             |
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
 
 If entered data is: 2021-12-01
 
 |      Date      |      Item     |    Quantity   |    Unitprice  |     Amount    |
 |----------------|---------------|---------------|---------------|---------------|
 |2021-12-01      |Nasi           |5              |4              |20             |
 |2021-12-01      |Nasi           |5              |4              |20             |
 |2021-12-01      |Ikan           |3              |10             |30             |
 
