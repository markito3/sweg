#!/usr/bin/env python

import mysql.connector

#if this page is executed with no errors, you have the "mysql.connector" module installed.

mycon = mysql.connector.connect(
  host="localhost",
  user="marki",
  passwd="hybrid"
)

print(mycon)

mycursor = mycon.cursor()

mycursor.execute("CREATE DATABASE mydatabase")

for x in mycursor:
    print(x)
