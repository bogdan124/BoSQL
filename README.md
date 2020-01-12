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


In the future after version 1.0.1 I will add a python library that will let you to acces the database faster











