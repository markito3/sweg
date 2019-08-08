#!/usr/bin/env python
import mysql.connector

mydb = mysql.connector.connect(
  host="localhost",
  user="marki",
  passwd="hybrid",
  database="mydatabase"
)

mycursor = mydb.cursor()

mycursor.execute("SELECT * FROM customers")

myresult = mycursor.fetchall()

for x in myresult:
  print(x)
