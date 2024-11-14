package cs435.hw11

import android.database.Cursor
import android.os.Bundle
import android.view.Menu
import android.view.MenuItem
import android.widget.EditText
import android.widget.ProgressBar
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AlertDialog
import androidx.appcompat.app.AppCompatActivity
import androidx.appcompat.widget.Toolbar
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch
import kotlinx.coroutines.withContext

class MainActivity : AppCompatActivity() {
    private lateinit var databaseHelper : ColorDBHelper
    private lateinit var recyclerAdapter: RecyclerAdapter
    private lateinit var progressBar: ProgressBar

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

        databaseHelper = ColorDBHelper(this)
        progressBar = findViewById(R.id.progressBar)

        val recyclerView = findViewById<RecyclerView>(R.id.recyclerView)
        val initCursor : Cursor = databaseHelper.getAllColors()

        recyclerView.layoutManager = LinearLayoutManager(this)
        recyclerAdapter = RecyclerAdapter(initCursor)
        recyclerView.adapter = recyclerAdapter


        loadColorsFromDB()
    }

    override fun onCreateOptionsMenu(menu: Menu?): Boolean {
        menuInflater.inflate(R.menu.menu_toolbar, menu)
        return true
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        return when (item.itemId) {
            R.id.action_add -> {
                val editText = EditText(this)
                editText.hint = "Enter number of colors"

                AlertDialog.Builder(this)
                    .setTitle("Add Random Colors")
                    .setMessage("How many random colors do you want")
                    .setView(editText)
                    .setPositiveButton("Add") {_, _ ->
                        val numberOfNewColors = editText.text.toString().toIntOrNull() ?: 0
                        if (numberOfNewColors > 0) {
                            progressBar.visibility = android.view.View.VISIBLE
                            // https://nickand.medium.com/getting-started-with-kotlin-coroutines-in-android-bfa8283fcf60
                            CoroutineScope(Dispatchers.IO).launch {
                                databaseHelper.insertRandomColors(numberOfNewColors)
                                withContext(Dispatchers.Main) {
                                    progressBar.visibility = android.view.View.GONE
                                    loadColorsFromDB()
                                }
                            }
                        }
                    }
                    .setNegativeButton("Cancel", null)
                    .show()
                true
            }
            R.id.action_sort -> {
                val options = arrayOf("Sort by Red", "Sort by Green", "Sort by Blue", "Sort by Favorites", "Original Order")
                AlertDialog.Builder(this)
                    .setTitle("Sort Colors")
                    .setItems(options) {_ , which ->
                        when (which) {
                            0 -> loadSortedColors("red")
                            1 -> loadSortedColors("green")
                            2 -> loadSortedColors("blue")
                            3 -> null //sortByFavorites() // Placeholder does not work currently
                            4 -> loadColorsFromDB()
                        }
                    }
                    .show()
                true
            }
        else -> super.onOptionsItemSelected(item)
        }
    }

    private fun loadSortedColors(sortBy: String) {
        val cursor : Cursor = databaseHelper.getSortedColors(sortBy)
        recyclerAdapter.updateColors(cursor)
    }

    private fun loadColorsFromDB() {
        val cursor : Cursor = databaseHelper.getAllColors()
        recyclerAdapter.updateColors(cursor)
    }

    override fun onStop() {
        super.onStop()
        CoroutineScope(Dispatchers.IO).launch {
            databaseHelper.clearDatabase()
        }
    }

}