package cs435.hw13

import android.content.Intent
import android.os.Bundle
import android.util.Log
import android.view.Menu
import android.view.MenuItem
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.appcompat.widget.Toolbar
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import androidx.lifecycle.lifecycleScope
import kotlinx.coroutines.launch

class MainActivity : AppCompatActivity() {
    private val model: Model = Model()
    private var currentCC: CountryCapital? = null
    private var currentW: Weather? = null

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

    }

    override fun onCreateOptionsMenu(menu: Menu?): Boolean {
        menuInflater.inflate(R.menu.toolbar_menu, menu)
        return true
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        when (item.itemId) {
            R.id.find_action -> {
                // API requests
                lifecycleScope.launch {
                    val countryCapital =
                        model.fetchCountryCapital("https://restcountries.com/v3.1/all")
                    currentCC = countryCapital
//                    Log.d("SELECTED_COUNTRY | UI push: ", "Country: ${countryCapital.country}, Capital: ${countryCapital.capital}")


                    val weatherData = model.fetchWeatherData(
                        "https://api.weatherstack.com/current",
                        "b9473e8d62a2561e9838aab87bda53a9",
                        countryCapital.country
                    )
                    currentW = weatherData
//                    Log.d("WeatherData fetch", "${countryCapital.country} | WeatherIcon: ${weatherData?.weatherIcon}, Temp: ${weatherData?.temp}, Description: ${weatherData?.weatherDesc}")
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
                    model.addToFav(currentCC!!)
                    Toast.makeText(this,"Saved to favorites: ${currentCC!!.country}, ${currentCC!!.capital}", Toast.LENGTH_LONG).show()
                } else {
                    Toast.makeText(this, "No country selected to save.", Toast.LENGTH_SHORT).show()
                }

                Log.d("PRINT FAV", model.getFavList().toString())
                    return true
            }

            else -> return super.onOptionsItemSelected(item)
        }
    }
}