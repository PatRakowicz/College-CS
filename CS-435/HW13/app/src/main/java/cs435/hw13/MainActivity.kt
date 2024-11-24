package cs435.hw13

import android.content.Intent
import android.os.Bundle
import android.util.Log
import android.view.Menu
import android.view.MenuItem
import android.view.View
import android.webkit.WebView
import android.widget.TextView
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.appcompat.widget.Toolbar
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import androidx.lifecycle.lifecycleScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch
import kotlinx.coroutines.withContext

class MainActivity : AppCompatActivity() {
    private val model: Model = Model()
    private var currentCC: CountryCapital? = null

    private lateinit var countryTextView: TextView
    private lateinit var capitalTextView: TextView
    private lateinit var weatherIconView: WebView
    private lateinit var tempTextView: TextView
    private lateinit var weatherDesc: TextView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        val toolbar = findViewById<Toolbar>(R.id.toolbar)
        setSupportActionBar(toolbar)

        countryTextView = findViewById(R.id.countryTextView)
        capitalTextView = findViewById(R.id.capitalTextView)
        weatherIconView = findViewById(R.id.weatherIconWebView)
        tempTextView = findViewById(R.id.tempTextView)
        weatherDesc = findViewById(R.id.weatherDescTextView)

        // Item Clicked from recycler
        val country = intent.getStringExtra("country")
        val capital = intent.getStringExtra("capital")

        if (!country.isNullOrEmpty() && !capital.isNullOrEmpty()) {
            lifecycleScope.launch {
                val weatherData = model.fetchWeatherData(
                    "https://api.weatherstack.com/current",
                    "b9473e8d62a2561e9838aab87bda53a9",
                    capital
                )
                if (weatherData != null) {
                    countryTextView.text = "Country: $country"
                    capitalTextView.text = "Capital: $capital"
                    weatherIconView.loadUrl(weatherData.weatherIcon)
                    tempTextView.text = "Temp: ${weatherData.temp}°C"
                    weatherDesc.text = "${weatherData.weatherDesc}"
                } else {
                    Toast.makeText(
                        this@MainActivity,
                        "Failed to fetch weather data.",
                        Toast.LENGTH_SHORT
                    ).show()
                }
            }
        }
    }

    override fun onCreateOptionsMenu(menu: Menu?): Boolean {
        menuInflater.inflate(R.menu.toolbar_menu, menu)
        return true
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        when (item.itemId) {
            R.id.find_action -> {
                val actionButton = findViewById<View>(R.id.find_action)
                actionButton.isEnabled = false

                // API requests
                lifecycleScope.launch { // Launch by default on main thread
                    try {
                        val countryCapital =
                            model.fetchCountryCapital("https://restcountries.com/v3.1/all")
                        if (countryCapital != null) {
                            currentCC = countryCapital
                            countryTextView.text = "Country: ${countryCapital.country}"
                            capitalTextView.text = "Capital: ${countryCapital.capital}"

                            val weatherData = model.fetchWeatherData(
                                "https://api.weatherstack.com/current",
                                "b9473e8d62a2561e9838aab87bda53a9",
                                countryCapital.capital
                            )
                            if (weatherData != null) {
                                weatherIconView.loadUrl(weatherData.weatherIcon)
                                tempTextView.text = "Temp: ${weatherData.temp}°C"
                                weatherDesc.text = "${weatherData.weatherDesc}"
                            } else {
                                Toast.makeText(
                                    this@MainActivity,
                                    "Failed to fetch weather data.",
                                    Toast.LENGTH_SHORT
                                ).show()
                            }
                        } else {
                            Toast.makeText(
                                this@MainActivity,
                                "Failed to fetch country and capital.",
                                Toast.LENGTH_SHORT
                            ).show()
                        }
                    } catch (e: Exception) {
                        Toast.makeText(
                            this@MainActivity,
                            "An error occurred while fetching data.",
                            Toast.LENGTH_SHORT
                        ).show()
                    } finally {
                        actionButton.isEnabled = true
                    }
                }
                return true
            }

            R.id.save_action -> {
                // List saved items
                startActivity(Intent(this, FavListActivity::class.java))
                return true
            }

            R.id.favorite_action -> {
                if (currentCC != null) {
//                    Log.d("CURRENT_CC", "Country: ${currentCC?.country}, Capital: ${currentCC?.capital}")
                    Model.addToFav(currentCC!!.country, currentCC!!.capital)
                    Toast.makeText(
                        this@MainActivity,
                        "Saved to favorites: ${currentCC!!.country}, ${currentCC!!.capital}",
                        Toast.LENGTH_LONG
                    ).show()

                    val updatedList = Model.getFavList()
//                    Log.d("PRINT_FAV", updatedList.toString())
                } else {
                    Toast.makeText(this, "No country selected to save.", Toast.LENGTH_SHORT).show()
                }
                return true
            }

            else -> return super.onOptionsItemSelected(item)
        }
    }
}