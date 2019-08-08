#!/usr/bin/env python

import mysql.connector

#if this page is executed with no errors, you have the "mysql.connector" module installed.

mydb = mysql.connector.connect(
  host="localhost",
  user="marki",
  passwd="hybrid"
)

print(mydb)

mycursor = mydb.cursor()

mycursor.execute("SHOW DATABASES")

for x in mycursor:
    print(x)
