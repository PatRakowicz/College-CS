package cs435.hw12

import android.content.Context
import android.database.Cursor
import android.database.sqlite.SQLiteDatabase
import android.database.sqlite.SQLiteOpenHelper

class DBHelper(context: Context) :
    SQLiteOpenHelper(context, DATABASE_NAME, null, DATABASE_VERSION) {

    companion object {
        private const val DATABASE_NAME = "comic.db"
        private const val DATABASE_VERSION = 1
    }

    override fun onCreate(db: SQLiteDatabase?) {
        val createTable = """
            CREATE TABLE comics (
                num INTEGER PRIMARY KEY,
                title TEXT,
                img TEXT
            );
        """.trimIndent()
        db?.execSQL(createTable)
    }

    override fun onUpgrade(db: SQLiteDatabase?, oldVersion: Int, newVersion: Int) {
        // Not needed
    }

    fun getRecent100Comics(): Cursor {
        val db = this.readableDatabase
        return db.query(
            "comics",
            arrayOf("num", "title", "img"),
            null, null, null, null,
            "num DESC", // Order by num in descending order
            "100"       // Limit to 100 records
        )
    }
}