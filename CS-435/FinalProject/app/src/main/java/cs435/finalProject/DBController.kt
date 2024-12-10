package cs435.finalProject

import android.content.ContentValues
import android.content.Context
import android.database.Cursor
import android.database.sqlite.SQLiteDatabase
import android.database.sqlite.SQLiteOpenHelper
import android.util.Log
import org.json.JSONObject
import java.io.BufferedReader
import java.io.InputStreamReader
import java.net.HttpURLConnection
import java.net.URL

class DBController (context: Context): SQLiteOpenHelper(context, DATABASE_NAME, null, DATABASE_VERSION) {
    companion object {
        private const val DATABASE_NAME = "weather.db"
        private const val DATABASE_VERSION = 1
        private const val TAG = "DBController"
    }

    override fun onCreate(db: SQLiteDatabase?) {
        val createTable = """
            CREATE TABLE WeatherData (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                date TEXT NOT NULL,
                temperature REAL NOT NULL,
                humidity REAL NOT NULL,
                uvi REAL NOT NULL,
                windspeed REAL NOT NULL
            );
        """.trimIndent()
        db?.execSQL(createTable)
        Log.d(TAG, "Database created with table WeatherData.")
    }

    override fun onUpgrade(db: SQLiteDatabase?, oldVersion: Int, newVersion: Int) {
        db?.execSQL("DROP TABLE IF EXISTS WeatherData")
        onCreate(db)
        Log.d(TAG, "Database upgraded. V:$newVersion")
    }

    fun fetchWeatherData(deviceIp: String) {
        val db = writableDatabase
        val apiUrl = "http://$deviceIp/api/weather"
        var httpURLConnection: HttpURLConnection? = null

        try {
            Log.d(TAG, "Attempting to fetch weather data from $apiUrl")
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
                val uvi = jsonObject.getDouble("uvi")
                val windspeed = jsonObject.getDouble("wind_speed")


                val contentValue = ContentValues().apply {
                    put("date", timestamp)
                    put("temperature", temperature)
                    put("humidity", humidity)
                    put("uvi", uvi)
                    put("windspeed", windspeed)
                }
                db.insert("WeatherData", null, contentValue)
                Log.d(TAG, "Data inserted successfully: $contentValue")
            } else {
                Log.e(TAG, "Failed to fetch weather data. Response Code: ${httpURLConnection.responseCode}")
            }
        } catch (e: Exception) {
            Log.e(TAG, "Error fetching weather data: ${e.message}", e)
        } finally {
            httpURLConnection?.disconnect()
            db.close()
        }
    }

    fun getLatestWeatherEntry(): Map<String, Any>? {
        val db = readableDatabase
        val query = """
            select date, temperature, humidity, uvi, windspeed
            from WeatherData
            order by date desc
            limit 1
        """.trimIndent()

        db.rawQuery(query, null).use {result ->
            if (result.moveToFirst()) {
                val data = mapOf(
                    "date" to result.getString(0),
                    "temperature" to result.getDouble(1),
                    "humidity" to result.getDouble(2),
                    "uvi" to result.getDouble(3),
                    "windspeed" to result.getDouble(4)
                )
                Log.d(TAG, "Latest weather data retrieved: $data")
                return data
            } else {
                Log.w(TAG, "No data found in WeatherData table.")
                return null
            }
        }
    }
}