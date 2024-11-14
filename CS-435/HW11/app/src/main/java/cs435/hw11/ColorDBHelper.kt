package cs435.hw11

import android.content.ContentValues
import android.content.Context
import android.database.Cursor
import android.database.sqlite.SQLiteDatabase
import android.database.sqlite.SQLiteOpenHelper
import kotlin.random.Random

class ColorDBHelper(context: Context) :
    SQLiteOpenHelper(context, DATABASE_NAME, null, DATABASE_VERSION) {
    companion object {
        private const val DATABASE_NAME = "colors.db"
        private const val DATABASE_VERSION = 1
    }

    override fun onCreate(db: SQLiteDatabase?) {
        val createTable = """
            CREATE TABLE colors(
                _id integer primary key autoincrement,
                red integer,
                green integer,
                blue integer,
                favorite integer default 0
            );
        """.trimIndent()
        db?.execSQL(createTable)
    }

    override fun onUpgrade(db: SQLiteDatabase?, oldVersion: Int, newVersion: Int) {
        TODO("Not yet implemented")
    }

    fun insertRandomColors(numberOfColors: Int) {
        val db = this.writableDatabase
        for (i in 1..numberOfColors) {
            val red = Random.nextInt(256)
            val green = Random.nextInt(256)
            val blue = Random.nextInt(256)

            val values = ContentValues().apply {
                put("red", red)
                put("green", green)
                put("blue", blue)
                put("favorite", 0)
            }
            db.insert("colors", null, values)
        }
    }

    fun getAllColors(): Cursor {
        val db = this.readableDatabase
        return db.query(
            "colors",
            arrayOf("_id", "red", "green", "blue", "favorite"),
            null, null, null, null, null
        )
    }

    fun getSortedColors(sortBy: String): Cursor {
        val db = this.readableDatabase
        val orderBy = when (sortBy) {
            "red" -> "red DESC"
            "green" -> "green DESC"
            "blue" -> "blue DESC"
            else -> null
        }
        return db.query(
            "colors",
            arrayOf("_id", "red", "green", "blue", "favorite"),
            null, null, null, null, orderBy
        )
    }

    // Broken somewhere | Not sure will add items when i do not select the item...
    fun updateFavoriteStatus(id: Int, isFav: Boolean) {
        val db = this.writableDatabase
        val values = ContentValues().apply {
            put("favorite", if (isFav) 1 else 0)
        }
        db.update("colors", values, "_id = ?", arrayOf(id.toString()))
    }

    fun getFavoriteColors(): Cursor {
        val db = this.readableDatabase
        return db.query(
            "colors",
            arrayOf("_id", "red", "green", "blue", "favorite"),
            "favorite = 1", null, null, null, null
        )
    }

    fun clearDatabase() {
        val db = this.writableDatabase
        db.execSQL("delete from colors")
        db.close()
    }
}
