package cs435.act10

import android.content.ContentValues
import android.content.Context
import android.database.sqlite.SQLiteDatabase
import android.database.sqlite.SQLiteOpenHelper

class BeerDBHelper(context: Context) : SQLiteOpenHelper(context, DB_NAME, null, DB_VERSION) {
    companion object {
        private const val DB_NAME = "beer.sqlite"
        private const val  DB_VERSION = 1

    }

    override fun onCreate(db: SQLiteDatabase?) {
        val query = """
            create table beer(
                beerID integer primary key autoincrement,
                name text,
                description text,
                image_resource_id integer
            );
        """.trimIndent()

        db?.execSQL(query)
        val beerValues = ContentValues().apply{
            put("name", "Crux  Pilz")
            put("description", "Delicious, post biking beer")
            put("image_resource_id", R.drawable.crux)
        }
        db?.insert("beer", null, beerValues)
    }

    override fun onUpgrade(db: SQLiteDatabase?, oldVersion: Int, newVersion: Int) {
        TODO("Not yet implemented")
    }
}