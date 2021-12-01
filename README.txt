# Project

when data file, data.txt is: 

2021-11-18 Ayam 2 10 20
2021-11-18 Ikan 3 10 30
2021-11-18 Nasi 5 4 20
2021-11-19 Ayam 2 10 20
2021-11-19 Ikan 3 10 30
2021-11-20 Nasi 5 4 20
2021-11-20 Ayam 2 10 20
2021-11-20 Ikan 3 10 30
2021-11-20 Nasi 5 4 20
2021-11-20 Ayam 2 10 20
2021-12-01 Ikan 3 10 30
2021-12-01 Nasi 5 4 20

the output would be:

Date            Item    Quantity        Unitprice       Amount
2021-12-01    Nasi    5            4                20
2021-12-01    Ikan    3            10               30
2021-11-20    Ayam    2            10               20
2021-11-20    Nasi    5            4                20
2021-11-20    Ikan    3            10               30
2021-11-20    Ayam    2            10               20
2021-11-20    Nasi    5            4                20
2021-11-19    Ikan    3            10               30
2021-11-19    Ayam    2            10               20
2021-11-18    Nasi    5            4                20
2021-11-18    Ikan    3            10               30
2021-11-18    Ayam    2            10               20
Read Success.......

when the data file data.txt is:
2021-11-18,Ayam,2,10,20
2021-11-18,Ikan,3,10,30
2021-11-18,Nasi,5,4,20
2021-11-19,Ayam,2,10,20
2021-11-19,Ikan,3,10,30
2021-11-20,Nasi,5,4,20
2021-11-20,Ayam,2,10,20
2021-11-20,Ikan,3,10,30
2021-11-20,Nasi,5,4,20
2021-11-20,Ayam,2,10,20
2021-12-01,Ikan,3,10,30
2021-12-01,Nasi,5,4,20

the output would be:
Date            Item    Quantity        Unitprice       Amount
2021-12-01,Ikan,3,10,30    2021-12-01,Nasi,5,4,20    2021-11-20,Ikan,3,10,30               2021-11-20,Nasi,5,4,20
    2021-11-20,Ayam,2,10,20
2021-11-20,Nasi,5,4,20    2021-11-20,Ayam,2,10,20    2021-11-20,Ikan,3,10,30               2021-11-20,Nasi,5,4,20
    2021-11-20,Ayam,2,10,20
2021-11-18,Ayam,2,10,20    2021-11-18,Ikan,3,10,30    2021-11-18,Nasi,5,4,20               2021-11-19,Ayam,2,10,20
    2021-11-19,Ikan,3,10,30
Read Success.......


data output would not be sorted in a rows if there is a coma between data
