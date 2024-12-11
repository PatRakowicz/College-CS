package cs435.exam3

import android.content.ContentValues
import android.content.Context
import android.database.Cursor
import android.database.sqlite.SQLiteDatabase
import android.database.sqlite.SQLiteOpenHelper
import android.util.Log
import org.json.JSONArray
import org.json.JSONObject
import java.io.BufferedReader
import java.io.InputStreamReader
import java.net.HttpURLConnection
import java.net.URL

class dbController(context: Context) : SQLiteOpenHelper(context, DATABASE_NAME, null, DATABASE_VERSION) {

    companion object {
        private const val DATABASE_NAME = "movies.db"
        private const val DATABASE_VERSION = 1
        private const val TAG = "dbController"
    }

    override fun onCreate(db: SQLiteDatabase?) {
        val createTable = """
            create table movie (
                _id integer  primary key autoincrement,
                title text,
                year integer,
                genre text,
                poster text
            );
        """.trimIndent()
        db?.execSQL(createTable)
    }

    override fun onUpgrade(db: SQLiteDatabase?, OldVersion: Int, NewVersion: Int) {
        TODO("Not yet implemented")
    }

    fun fetchAPIData(movieName: String) {
        val db = writableDatabase
        var httpURLConnection: HttpURLConnection? = null

        try {
            val url = URL("https://www.omdbapi.com/?i=tt3896198&apikey=f8a75f1&t=$movieName")
            httpURLConnection = url.openConnection() as HttpURLConnection

            if (httpURLConnection.responseCode == HttpURLConnection.HTTP_OK) {
                val bufferedReader = BufferedReader(InputStreamReader(httpURLConnection.inputStream))
                val result = bufferedReader.readText()

                val jsonObject = JSONObject(result)

                val title = jsonObject.getString("Title")
                val year = jsonObject.getInt("Year")
                val genre = jsonObject.getString("Genre")
                val poster = jsonObject.getString("Poster")
                Log.d(TAG, "${result.toString()}")

                val contentValues = ContentValues().apply {
                    put("title", title)
                    put("year", year)
                    put("genre", genre)
                    put("poster", poster)
                }

                db.insert("movie", null, contentValues)
            }
        } catch (e:Exception) {
            e.printStackTrace()
        } finally {
            httpURLConnection?.disconnect()
        }
        db.close()
    }

    fun getAllData() : Cursor {
        return readableDatabase.rawQuery("select * from movie", null)
    }

    fun getData() : Cursor {
        val db = readableDatabase
        return db.query("movie", null, null, null, null, null, null)
        )
    }
}