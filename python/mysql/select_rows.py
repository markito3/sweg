#!/usr/bin/env python
import mysql.connector

mycon = mysql.connector.connect(
  host="localhost",
  user="marki",
  passwd="hybrid",
  database="mydatabase"
)

mycursor = mycon.cursor()

mycursor.execute("SELECT * FROM customers")

myresult = mycursor.fetchall()

for x in myresult:
  print(x)
