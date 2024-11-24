package cs435.hw13

import android.util.Log
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.withContext
import org.json.JSONArray
import org.json.JSONException
import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.net.HttpURLConnection
import java.net.URL

class CountryCapital {
    var country: String = ""
    var capital: String = ""
}

class Model {
    suspend fun fetchCountryCapital(apiUrl: String): CountryCapital? {
        var result = ""
        val countryCapitalList = mutableListOf<CountryCapital>()

        withContext(Dispatchers.IO) {
            var connection: HttpURLConnection? = null

            try {
                val url = URL(apiUrl)
                connection = url.openConnection() as HttpURLConnection
                connection.requestMethod = "GET"

                if (connection.responseCode == HttpURLConnection.HTTP_OK) {
                    val bufferedReader = BufferedReader(InputStreamReader(connection.inputStream))
                    result = bufferedReader.readText()
                    bufferedReader.close()
                } else {
                    Log.d("HTTP_ERROR", "Response Code: ${connection.responseCode}")
                }
            } catch (e: IOException) {
                Log.d("HTTP_ERROR", "IOException: ${e.message}")
                e.printStackTrace()
            } finally {
                connection?.disconnect()
            }

//            Log.d("RAW_JSON", result)

            if (result.isNotEmpty()) {
                try {
                    val jsonArray = JSONArray(result)

                    for (i in 0 until jsonArray.length()) {
                        val json = jsonArray.getJSONObject(i)
                        val nameObject = json.optJSONObject("name")

                        val countryName = nameObject?.optString("common") ?: "NA"

                        val capitalArray = json.optJSONArray("capital")
                        val capitalName = capitalArray?.optString(0) ?: "NA"

                        val countryCapital = CountryCapital().apply {
                            country = countryName
                            capital = capitalName
                        }
                        countryCapitalList.add(countryCapital)
                    }

                } catch (e: JSONException) {
                    Log.d("JSON_ERROR", "Failed to parse JSON: ${e.message}")
                    e.printStackTrace()
                }
            }
        }
        // https://developer.android.com/reference/java/util/Random | Dev Notes
        // https://stackoverflow.com/questions/45685026/how-can-i-get-a-random-number-in-kotlin | Example
        return countryCapitalList.random()
    }

    fun fetchWeatherData(apiUrl: String, accessKey: String, capital: String) {
        var result = ""
        var httpURLConnection: HttpURLConnection? = null

        try {
            val url = URL("$apiUrl?access_key=$accessKey&query=$capital")
            httpURLConnection = url.openConnection() as HttpURLConnection
            httpURLConnection.requestMethod = "GET"

            if (httpURLConnection.responseCode == HttpURLConnection.HTTP_OK) {
                val bufferedReader =
                    BufferedReader(InputStreamReader(httpURLConnection.inputStream))
                result = bufferedReader.readText()
                bufferedReader.close()
            }
        } catch (e: Exception) {
            e.printStackTrace()
        } finally {
            httpURLConnection?.disconnect()
        }

        Log.d("weatherData: ", result)
    }
}