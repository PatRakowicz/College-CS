package cs435.hw13

import android.os.Bundle
import android.widget.ArrayAdapter
import android.widget.ListView
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView

class FavListActivity : AppCompatActivity() {
    private val model = Model()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_fav_list_acivity)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        val recyclerView = findViewById<RecyclerView>(R.id.recyclerView)
        val initAdapter = RecyclerAdapter(model.getFavList())

        // Placeholder data
//        val countries = listOf("United States", "France", "Japan", "Germany", "India")
//        val capitals = listOf("Washington, D.C.", "Paris", "Tokyo", "Berlin", "New Delhi")

        recyclerView.layoutManager = LinearLayoutManager(this)
        recyclerView.adapter = initAdapter
    }
}