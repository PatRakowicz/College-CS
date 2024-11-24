package cs435.hw13

import android.content.Intent
import android.os.Bundle
import android.util.Log
import android.widget.ArrayAdapter
import android.widget.ListView
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import androidx.lifecycle.lifecycleScope
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import kotlinx.coroutines.launch

class FavListActivity : AppCompatActivity(), RecyclerAdapter.OnFavClickListener {
    private val model = Model

    private lateinit var recyclerView: RecyclerView
    private lateinit var adapter: RecyclerAdapter

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_fav_list_acivity)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        recyclerView = findViewById(R.id.recyclerView)
        recyclerView.layoutManager = LinearLayoutManager(this)

        val favList = model.getFavList()
        Log.d("FAV_LIST", "Initializing with favorites: $favList")

        adapter = RecyclerAdapter(favList, this)
        recyclerView.adapter = adapter
    }

    override fun onFavClick(favorites: Favorites) {
        val intent = Intent(this, MainActivity::class.java)
        intent.putExtra("country", favorites.country)
        intent.putExtra("capital", favorites.capital)
        startActivity(intent)
        finish()
    }
}