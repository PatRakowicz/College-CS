package cs435.act5


import Beer
import android.content.Intent
import android.os.Bundle
import android.view.View
import android.widget.AdapterView
import android.widget.ArrayAdapter
import android.widget.ListView
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class BeerCategoryActivity : AppCompatActivity() {

    private lateinit var listDrinks: ListView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_beer_category)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        listDrinks = findViewById(R.id.ListViewBeers)

        val adapter = ArrayAdapter(
            applicationContext,
            android.R.layout.simple_list_item_1,
            Beer.beers
        )

        listDrinks.adapter = adapter

        listDrinks.onItemClickListener =
            AdapterView.OnItemClickListener { adapterView, view, i, l ->
                val intent = Intent(this, BeerActivity::class.java)
                startActivity(intent)
                intent.putExtra("INDEX", i)
            }
    }
}