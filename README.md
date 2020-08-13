# BoSQL
BoSql is an sql language developed by me in c.
Has a lot of bugs,but hey this is the first version BoSql version 1.0.0

<h1>Version 1.0.0</h1>

<b>NOTE</b> all the commands end with (;) check the demo file

what I have ?

``` SELECT * <table_name>``` - is selecting all from <table_name>

``` SELECT (0,10) <table_name> ```- selecting from 0 all unti row 10

``` SELECT (123,0) <table_name>``` - is selecting from 123 until the end

``` SELECT (0,0) <table_name>``` - is selecting all rows

``` SELECT * <table_name> LIKE(<some_thing>,2) ```- is selecting all rows with column 2 equel with <some_thing>

``` SHOW <table_name>``` - is showing all <table_name> including header column and all the rows(don't use when you have many rows)

``` COLUMN <table_name>``` - is showing the header column 

``` INSERT <table_name> (<here_put_content_with_,_between_words>)``` - is inserting data into the database


In this way you can create a table

``` CREATE <table_name>```

``` CONTENT <table_name> (<HEADER_ROW>)```

THIS 2 COMMANDS GO HAND IN HAND


<h1>Version 1.0.1</h1>

I changed the syntax and now my Database is column oriented,in this way i can fetch data a lot easy using data compression( basically you don't look what you don't want). The data for each column is stored in separated files and I use mmap to select the number of bytes that i want to read from data.
In the past version I was looking on 100 milions rows(to do a simple search took me 10 seconds(a lot!!!)) now i can select just a column and do a search in less than one second.(In the next version I will try to add paralelism to look over multiple columns in the same time )









