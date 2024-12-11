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
    // This variable stores the most recent comic number that will be used as a starting point for fetching the last 100 comics
    private val recentComic = 3012;

    companion object {
        private const val DATABASE_NAME = "comic.db"
        private const val DATABASE_VERSION = 1
    }

    // This method is called when the database is created for the first time. It defines the structure of the 'comics' table
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

    // This method would handle database structure changes if the database version is incremented, though it is currently not implemented
    override fun onUpgrade(db: SQLiteDatabase?, oldVersion: Int, newVersion: Int) {
        // Not needed
    }

    // This function fetches the last 100 comics from the XKCD API and inserts them into the local SQLite database
    fun recent100Comics() {
        val db = writableDatabase
        for (i in recentComic downTo (recentComic - 99)) {
            // This constructs the URL for the API request for each comic by using the comic number in the loop
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

                    // This parses the API response into a JSON object to extract comic details such as number, title, and image URL
                    val jsonObject = JSONObject(result)
                    val num = jsonObject.getInt("num")
                    val title = jsonObject.getString("title")
                    val imageUrl = jsonObject.getString("img")

                    // This creates a map of column names to values for inserting a comic's details into the database
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

    // This function retrieves all records from the 'comics' table and returns a cursor to iterate over the results
    fun getAllComics(): Cursor {
        val db = readableDatabase
        return db.query("comics",
            null, null, null, null, null, null)
    }

    // This function retrieves a specific comic from the database based on its comic number
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