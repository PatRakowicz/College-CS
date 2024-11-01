package cs435.lab10

import android.content.Context
import android.database.sqlite.SQLiteDatabase
import android.database.sqlite.SQLiteOpenHelper

class DBHelper(context: Context) : SQLiteOpenHelper(context, DB_NAME, null, DB_VERSION) {
    companion object {
        private const val DB_NAME = "numbersDB.sqlite"
        private const val DB_VERSION = 1
    }
    override fun onCreate(db: SQLiteDatabase?) {
        val query = """
            create table numbers(
                nameID Primary key autoincrement,
                number integer,
                name text
                )
        """.trimIndent()
        db?.execSQL(query)
    }

    override fun onUpgrade(db: SQLiteDatabase?, oldVersion: Int, newVersion: Int) {
        TODO("Not yet implemented")
    }
}