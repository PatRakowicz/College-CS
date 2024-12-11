package cs435.exam3notes

import android.content.ContentValues
import android.database.Cursor
import android.database.sqlite.SQLiteDatabase
import android.database.sqlite.SQLiteOpenHelper
import org.json.JSONArray
import java.io.BufferedReader
import java.io.InputStreamReader
import java.net.HttpURLConnection
import java.net.URL

class dbController(context: android.content.Context) :
    SQLiteOpenHelper(context, DATABASE_NAME, null, DATABASE_VERSION) {

    companion object {
        private const val DATABASE_NAME = "app.db"
        private const val DATABASE_VERSION = 1
    }

    override fun onCreate(db: SQLiteDatabase) {
        val createTable = """
                CREATE TABLE data (
                    _id INTEGER PRIMARY KEY AUTOINCREMENT,
                    name TEXT,
                    value INTEGER
                );
            """.trimIndent()
        db.execSQL(createTable)
    }

    override fun onUpgrade(db: SQLiteDatabase, oldVersion: Int, newVersion: Int) {
        db.execSQL("DROP TABLE IF EXISTS data")
        onCreate(db)
    }

    fun fetchApiData(urlString: String) {
        val db = writableDatabase
        var httpURLConnection: HttpURLConnection? = null
        try {
            val url = URL(urlString)
            httpURLConnection = url.openConnection() as HttpURLConnection
            httpURLConnection.requestMethod = "GET"

            if (httpURLConnection.responseCode == HttpURLConnection.HTTP_OK) {
                val bufferedReader = BufferedReader(InputStreamReader(httpURLConnection.inputStream))
                val result = bufferedReader.readText()
                bufferedReader.close()

                val jsonArray = JSONArray(result)
                db.execSQL("DELETE FROM data")

                for (i in 0 until jsonArray.length()) {
                    val jsonObject = jsonArray.getJSONObject(i)
                    val name = jsonObject.getString("name")
                    val value = jsonObject.getInt("value")

                    val contentValues = ContentValues().apply {
                        put("name", name)
                        put("value", value)
                    }

                    db.insert("data", null, contentValues)
                }
            }
        } catch (e: Exception) {
            e.printStackTrace()
        } finally {
            httpURLConnection?.disconnect()
        }
        db.close()
    }

    fun getAllData(): Cursor {
        return readableDatabase.rawQuery("SELECT name || ' - ' || value FROM data", null)
    }
}