package cs435.finalProject

import android.content.ContentValues
import android.content.Context
import android.database.sqlite.SQLiteDatabase
import android.database.sqlite.SQLiteOpenHelper
import org.json.JSONObject
import java.io.BufferedReader
import java.io.InputStreamReader
import java.net.HttpURLConnection
import java.net.URL

class DBController (context: Context): SQLiteOpenHelper(context, DATABASE_NAME, null, DATABASE_VERSION) {
    companion object {
        private const val DATABASE_NAME = "weather.db"
        private const val DATABASE_VERSION = 1
    }

    override fun onCreate(db: SQLiteDatabase?) {
        val createTable = """
            CREATE TABLE WeatherData (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                date TEXT NOT NULL,
                temperature REAL NOT NULL,
                humidity REAL NOT NULL,
                other_metrics TEXT
            );
        """.trimIndent()
        db?.execSQL(createTable)
    }

    override fun onUpgrade(db: SQLiteDatabase?, oldVersion: Int, newVersion: Int) {
        db?.execSQL("DROP TABLE IF EXISTS WeatherData")
        onCreate(db)
    }

    fun fetchWeatherData(deviceIp: String) {
        val db = writableDatabase
        val apiUrl = "http://$deviceIp/api/weather"
        var httpURLConnection: HttpURLConnection? = null

        try {
            val url = URL(apiUrl)
            httpURLConnection = url.openConnection() as HttpURLConnection
            httpURLConnection.requestMethod = "GET"

            if (httpURLConnection.responseCode == HttpURLConnection.HTTP_OK) {
                val bufferedReader = BufferedReader(InputStreamReader(httpURLConnection.inputStream))
                val result = bufferedReader.readText()
                bufferedReader.close()

                val jsonObject = JSONObject(result)
                val temperature = jsonObject.getDouble("temperature")
                val humidity = jsonObject.getDouble("humidity")
                val timestamp = jsonObject.getString("timestamp")

                val contentValue = ContentValues().apply {
                    put("date", timestamp)
                    put("temperature", temperature)
                    put("humidity", humidity)
//                    put("otherMetric", otherMetric) | if needed
                }
                db.insert("WeatherData", null, contentValue)
            }
        } catch (e: Exception) {
            e.printStackTrace()
        } finally {
            httpURLConnection?.disconnect()
            db.close()
        }
    }
}