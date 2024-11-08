package com.example.lab11

import android.content.ContentValues
import android.content.Context
import android.database.Cursor
import android.database.sqlite.SQLiteDatabase
import android.database.sqlite.SQLiteOpenHelper

class DatabaseHelper(context: Context) : SQLiteOpenHelper(context, DATABASE_NAME, null, DATABASE_VERSION) {

    companion object {
        private const val DATABASE_NAME = "items.db"
        private const val DATABASE_VERSION = 1
    }

    override fun onCreate(db: SQLiteDatabase) {
        val query = """
            CREATE TABLE item(
            _id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT,
            age INTEGER
            );
        """.trimIndent()
        db.execSQL(query)
    }

    override fun onUpgrade(db: SQLiteDatabase, oldVersion: Int, newVersion: Int) {

    }

    fun insertItem(name: String, age: Int) {
        val db = this.readableDatabase
        var values = ContentValues().apply {
            put("age", age)
            put("name", name)
        }
        db?.insert("item", null, values)
    }

    fun getAllItems(): Cursor {
        val db = this.readableDatabase
        val cursor = db.query(
            "item",
            arrayOf("_id", "name", "age"),
            null, null, null, null, null
        )
        return cursor
    }
}
