package cs435.hw13

import android.util.Log
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.withContext
import org.json.JSONArray
import org.json.JSONException
import org.json.JSONObject
import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.net.HttpURLConnection
import java.net.URL

class CountryCapital {
    var country: String = ""
    var capital: String = ""
}

class Weather {
    var weatherIcon: String = ""
    var temp: Int = 0
    var weatherDesc: String = ""
}

class Favorites {
    var country: String = ""
    var capital: String = ""

    override fun toString(): String {
        return "Favorites(country='$country', capital='$capital')"
    }
}

class Model {
    companion object {
        private val favList = mutableListOf<Favorites>()

        fun addToFav(country: String, capital: String) {

            val favorite = Favorites().apply {
                this.country = country
                this.capital = capital
            }

            if (!favList.any { it.country == favorite.country && it.capital == favorite.capital }) {
                favList.add(favorite)
                Log.d("ADD_TO_FAV", "Added to favorites: $favorite")
            } else {
                Log.d("ADD_TO_FAV", "Skipped adding duplicate: $favorite")
            }

        }

        fun getFavList(): List<Favorites> {
            Log.d("GET_FAV_LIST", favList.toString())
            return favList
        }
    }

    suspend fun fetchCountryCapital(apiUrl: String): CountryCapital {
        var result = ""
        val countryCapitalList = mutableListOf<CountryCapital>()

        countryCapitalList.clear()

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

                        val nameObject = json.getJSONObject("name")
                        val countryName = nameObject.getString("common")

                        // States it cant find capital, but does... Not sure
                        // Could use optJSONArray() but is less strict for the case of nothing is in capital
                        // https://developer.android.com/reference/org/json/JSONArray#optJSONArray(int) | Dev notes
                        val capitalName = json.getJSONArray("capital").getString(0)

//                        Log.d("capital Array: ", capitalArray.toString())
//                        Log.d("capital Name: ", capitalName.toString())

                        val countryCapital = CountryCapital().apply {
                            this.country = countryName
                            this.capital = capitalName
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

    suspend fun fetchWeatherData(apiUrl: String, accessKey: String, capital: String): Weather? {
        var result = ""
        var weather: Weather? = null

        withContext(Dispatchers.IO) {
            var connection: HttpURLConnection? = null

            try {
                val url = URL("$apiUrl?access_key=$accessKey&query=$capital")
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

            if (result.isNotEmpty()) {
                try {
                    val jsonObject = JSONObject(result)
                    val current = jsonObject.getJSONObject("current")

                    val weatherIcon = current.getJSONArray("weather_icons").getString(0)
                    val temp = current.getInt("temperature")
                    val weatherDesc = current.getJSONArray("weather_descriptions").getString(0)

                    weather = Weather().apply {
                        this.weatherIcon = weatherIcon
                        this.temp = temp
                        this.weatherDesc = weatherDesc
                    }

//                    Log.d("WEATHER_DATA", "Icon: $weatherIcon, Temp: $temp, Description: $weatherDesc")
                } catch (e: JSONException) {
                    Log.d("JSON_ERROR", "Failed to parse JSON: ${e.message}")
                    e.printStackTrace()
                }
            } else {
                Log.d("WEATHER_DATA", "No valid weather data received.")
            }
        }

        return weather
    }
}