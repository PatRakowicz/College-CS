package cs435.hw12

import android.content.Intent
import android.os.Bundle
import android.view.View
import android.widget.ProgressBar
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch
import kotlinx.coroutines.withContext

class MainActivity : AppCompatActivity(), RecyclerAdapter.OnClickListener {
    private lateinit var dbHelper: DBHelper
    private lateinit var progressBar: ProgressBar
    private lateinit var recyclerView: RecyclerView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        // Initializes database helper and UI elements
        dbHelper = DBHelper(this)
        progressBar = findViewById(R.id.progressBar)
        recyclerView = findViewById(R.id.recycler_view)
        recyclerView.layoutManager = LinearLayoutManager(this)

        // Shows the progress bar while loading data
        progressBar.visibility = View.VISIBLE
        recyclerView.visibility = View.GONE

        // Launches a coroutine to fetch data from the database
        CoroutineScope(Dispatchers.IO).launch {
            dbHelper.recent100Comics() // Populates database with recent comics

            val cursor = dbHelper.getAllComics() // Retrieves all comics from the database

            // Updates UI on the main thread after data is loaded
            withContext(Dispatchers.Main) {
                recyclerView.adapter = RecyclerAdapter(cursor, this@MainActivity)
                progressBar.visibility = View.GONE
                recyclerView.visibility = View.VISIBLE
            }
        }
    }

    // Handles click events on comics and opens the detail view
    override fun onComicClick(comicId: Int) {
        val intent = Intent(this, ComicDetailActivity::class.java)
        intent.putExtra("comic_id", comicId)
        startActivity(intent)
    }
}