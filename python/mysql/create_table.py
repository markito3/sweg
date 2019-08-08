#!/usr/bin/env python
import mysql.connector

mydb = mysql.connector.connect(
  host="localhost",
  user="marki",
  passwd="hybrid",
  database="mydatabase"
)

mycursor = mydb.cursor()

mycursor.execute("CREATE TABLE customers (name VARCHAR(255), address VARCHAR(255))")
