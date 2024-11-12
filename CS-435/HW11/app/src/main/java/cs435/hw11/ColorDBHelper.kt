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
                blue integer
            );
        """.trimIndent()
        db?.execSQL(createTable)
    }

    override fun onUpgrade(db: SQLiteDatabase?, oldVersion: Int, newVersion: Int) {
        TODO("Not yet implemented")
    }

    fun insertColor(red: Int, green: Int, blue: Int) {
        val db = this.writableDatabase
        val values = ContentValues().apply {
            put("red", red)
            put("green", green)
            put("blue", blue)
        }
        db.insert("colors", null, values)
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
            }
            db.insert("colors", null, values)
        }
    }

    fun getAllColors(): Cursor {
        val db = this.readableDatabase
        return db.query(
            "colors",
            arrayOf("_id", "red", "green", "blue"),
            null, null, null, null, null
        )
    }
}
