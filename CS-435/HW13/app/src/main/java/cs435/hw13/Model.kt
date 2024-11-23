package cs435.hw13

import org.json.JSONObject
import java.io.BufferedReader
import java.io.InputStreamReader
import java.net.HttpURLConnection
import java.net.URL
// Simplify this to not make it look like AI


// Class to hold country and capital information
class CountryCapital {
    var country: String = ""
    var capital: String = ""
}

// Class to hold weather information
class Weather {
    var weatherDescriptions: String = ""
    var weatherIcons: String = ""
    var temperature: Double = 0.0
}

class Model {

    // Stores country and capital data
    private val countryCapitalData = mutableListOf<CountryCapital>()

    // Stores weather data
    private val weatherData = mutableListOf<Weather>()

    // Fetches country and capital data and stores it
    fun fetchAndStoreCountryAndCapital(apiUrl: String) {
        var result = ""
        var httpURLConnection: HttpURLConnection? = null

        try {
            val url = URL(apiUrl)
            httpURLConnection = url.openConnection() as HttpURLConnection
            httpURLConnection.requestMethod = "GET"

            if (httpURLConnection.responseCode == HttpURLConnection.HTTP_OK) {
                val bufferedReader = BufferedReader(InputStreamReader(httpURLConnection.inputStream))
                result = bufferedReader.readText()
                bufferedReader.close()

                // Parse JSON result and store in countryCapitalData
                val jsonObject = JSONObject(result)
                val dataArray = jsonObject.getJSONArray("data")

                for (i in 0 until dataArray.length()) {
                    val item = dataArray.getJSONObject(i)
                    val countryCapital = CountryCapital()
                    countryCapital.country = item.getString("common") // Assuming "common" has the country name
                    countryCapital.capital = item.getString("capital") // Assuming "capital" has the capital name
                    countryCapitalData.add(countryCapital)
                }
            }
        } catch (e: Exception) {
            e.printStackTrace()
        } finally {
            httpURLConnection?.disconnect()
        }
    }

    // Fetches weather data and stores it
    fun fetchAndStoreWeatherData(apiUrl: String, accessKey: String, capital: String) {
        var result = ""
        var httpURLConnection: HttpURLConnection? = null

        try {
            val url = URL("$apiUrl?access_key=$accessKey&query=$capital")
            httpURLConnection = url.openConnection() as HttpURLConnection
            httpURLConnection.requestMethod = "GET"

            if (httpURLConnection.responseCode == HttpURLConnection.HTTP_OK) {
                val bufferedReader = BufferedReader(InputStreamReader(httpURLConnection.inputStream))
                result = bufferedReader.readText()
                bufferedReader.close()

                // Parse JSON result and store in weatherData
                val jsonObject = JSONObject(result)
                val current = jsonObject.getJSONObject("current")

                val weather = Weather()
                weather.weatherDescriptions = current.getJSONArray("weather_descriptions").getString(0)
                weather.weatherIcons = current.getJSONArray("weather_icons").getString(0)
                weather.temperature = current.getDouble("temperature")
                weatherData.add(weather)
            }
        } catch (e: Exception) {
            e.printStackTrace()
        } finally {
            httpURLConnection?.disconnect()
        }
    }

    // Getter for country and capital data
    fun getCountryCapitalData(): List<CountryCapital> {
        return countryCapitalData
    }

    // Getter for weather data
    fun getWeatherData(): List<Weather> {
        return weatherData
    }
}