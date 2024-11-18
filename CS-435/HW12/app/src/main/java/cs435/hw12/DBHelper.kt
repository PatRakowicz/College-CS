package cs435.hw12

import android.content.ContentValues
import android.content.Context
import android.database.Cursor
import android.database.sqlite.SQLiteDatabase
import android.database.sqlite.SQLiteOpenHelper
import org.json.JSONObject
import java.io.BufferedReader
import java.io.InputStreamReader
import java.net.HttpURLConnection
import java.net.URL

class DBHelper(context: Context) : SQLiteOpenHelper(context, DATABASE_NAME, null, DATABASE_VERSION) {

    // Not sure if you want to dynamically check new comics
    private val recentComic = 3012;

    companion object {
        private const val DATABASE_NAME = "comic.db"
        private const val DATABASE_VERSION = 1
    }

    override fun onCreate(db: SQLiteDatabase) {
        val createTable = """
            CREATE TABLE comics (
                _id INTEGER PRIMARY KEY AUTOINCREMENT,
                num INTEGER,
                title TEXT,
                img TEXT
            );
        """.trimIndent()
        db.execSQL(createTable)
    }

    override fun onUpgrade(db: SQLiteDatabase?, oldVersion: Int, newVersion: Int) {
        // Not needed
    }

    fun recent100Comics() {
        val db = writableDatabase
        for (i in recentComic downTo (recentComic - 99)) {
            val urlString = "https://xkcd.com/$i/info.0.json"
            var httpURLConnection: HttpURLConnection? = null
            try {
                val url = URL(urlString)
                httpURLConnection = url.openConnection() as HttpURLConnection
                httpURLConnection.requestMethod = "GET"

                if (httpURLConnection.responseCode == HttpURLConnection.HTTP_OK) {
                    val bufferedReader = BufferedReader(InputStreamReader(httpURLConnection.inputStream))
                    val result = bufferedReader.readText()
                    bufferedReader.close()

                    val jsonObject = JSONObject(result)
                    val num = jsonObject.getInt("num")
                    val title = jsonObject.getString("title")
                    val imageUrl = jsonObject.getString("img")

                    val contentValues = ContentValues().apply {
                        put("num", num)
                        put("title", title)
                        put("img", imageUrl)
                    }

                    db.insert("comics", null, contentValues)
                }
            } catch (e: Exception) {
                e.printStackTrace()
            } finally {
                httpURLConnection?.disconnect()
            }
        }
        db.close()
    } // error stating its requires a return, when it doesn't.. not sure what my IDE is telling me

    fun getAllComics(): Cursor {
        val db = readableDatabase
        return db.query("comics",
            null, null, null, null, null, null)
    }

    fun getComic(comicId: Int) : Cursor {
        val db = readableDatabase
        return db.query(
            "comics",
            null,
            "num = ?",
            arrayOf(comicId.toString()),
            null, null, null
        )
    }
}