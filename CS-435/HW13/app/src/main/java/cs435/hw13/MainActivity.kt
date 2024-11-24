package cs435.hw13

import android.content.Intent
import android.os.Bundle
import android.util.Log
import android.view.Menu
import android.view.MenuItem
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.appcompat.widget.Toolbar
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import androidx.lifecycle.lifecycleScope
import kotlinx.coroutines.launch

class MainActivity : AppCompatActivity() {
    private val model: Model = Model()

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
                    val countryCapital = model.fetchCountryCapital("https://restcountries.com/v3.1/all")
                    Log.d("SELECTED_COUNTRY | UI push: ", "Country: ${countryCapital?.country}, Capital: ${countryCapital?.capital}")
                    // call fetchWeatherData(url | APIkey | country)
                }
                return true
            }

            R.id.save_action -> {
                // List saved items
                startActivity(Intent(this, FavListActivity::class.java))
                return true
            }

            R.id.favorite_action -> {
                // add to favorite data model
                return true
            }

            else -> return super.onOptionsItemSelected(item)
        }
    }
}