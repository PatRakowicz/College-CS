package com.example.activity11

import android.content.ContentValues
import android.content.Context
import android.database.sqlite.SQLiteDatabase
import android.database.sqlite.SQLiteOpenHelper

class BeerDatabaseHelper(context: Context): SQLiteOpenHelper(context, DB_NAME, null, DB_VERSION) {

    companion object {
        private const val DB_NAME = "beer.sqlite"
        private const val DB_VERSION = 3
    }

    override fun onCreate(db: SQLiteDatabase?) {
        val query = """
            CREATE TABLE beer (
                _id INTEGER PRIMARY KEY AUTOINCREMENT,
                name TEXT,
                description TEXT,
                image_resource_id INTEGER
            );
        """.trimIndent()
        db?.execSQL(query)

        var beerValues = ContentValues().apply {
            put("name", "Crux Pilz")
            put("description", "delicious, post biking beer")
            put("image_resource_id", R.drawable.crux)
        }
        db?.insert("beer", null, beerValues)

        val beerValues2 = ContentValues().apply {
            put("name", "Boneyard RPM")
            put("description", "well-balanced IPA from Bend, OR")
            put("image_resource_id", R.drawable.boneyard)
        }
        db?.insert("beer", null, beerValues2)

        val beerValues3 = ContentValues().apply {
            put("name", "Deschutes Obsidian Stout")
            put("description", "good dark beer for post skiing")
            put("image_resource_id", R.drawable.stout)
        }
        db?.insert("beer", null, beerValues3)
    }

    override fun onUpgrade(db: SQLiteDatabase?, oldVersion: Int, newVersion: Int) {
        if (oldVersion == 2) {
            val query = "alter table beer add column favorite numeric"
            db?.execSQL(query)
        }
    }


}