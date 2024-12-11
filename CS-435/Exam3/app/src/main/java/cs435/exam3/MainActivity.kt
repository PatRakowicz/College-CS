package cs435.exam3

import android.database.Cursor
import android.os.Bundle
import android.view.View
import android.webkit.WebView
import android.widget.ArrayAdapter
import android.widget.Button
import android.widget.EditText
import android.widget.ListView
import android.widget.SimpleCursorAdapter
import android.widget.TextView
import androidx.appcompat.widget.Toolbar
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class MainActivity : AppCompatActivity() {
    private lateinit var db : dbController

    private lateinit var searchText: EditText
    private lateinit var searchButton: Button
    private lateinit var moviePoster: WebView
    private lateinit var movieTitle : TextView
    private lateinit var movieYear : TextView
    private lateinit var movieGenre : TextView
    private lateinit var saveButton: Button

    private lateinit var listView : ListView
    private lateinit var adapter : SimpleCursorAdapter


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

        db = dbController(this)

        searchText = findViewById(R.id.searchEditText)
        searchButton = findViewById(R.id.searchButton)
        moviePoster = findViewById(R.id.moviePosterWebView)
        movieTitle = findViewById(R.id.moviesTitle)
        movieYear = findViewById(R.id.movieYearTextView)
        movieGenre = findViewById(R.id.movieGenreTextView)
        saveButton = findViewById(R.id.actionButton)

        listView = findViewById(R.id.moviesListView)
        adapter = SimpleCursorAdapter(this, android.R.layout.simple_list_item_1, intArrayOf(android.R.id.text1, android.R.id.text2))

        db.fetchAPIData("Wizard of Oz")

        val cursor = db.getAllData()
        val list = mutableListOf<String>()
        while (cursor.moveToFirst()) {
            list.add(cursor.getString(0))
        }
        adapter.addAll(list)
        cursor.close()

    }

    fun movieSearch(view: View) {
        db.fetchAPIData(searchText.toString())

        val cursor : Cursor = db.getData()
        if (cursor.moveToFirst()) {
            val title = cursor.getString(cursor.getColumnIndexOrThrow("title"))
            val year = cursor.getInt(cursor.getColumnIndexOrThrow("year"))
            val genre = cursor.getString(cursor.getColumnIndexOrThrow("genre"))
            val poster = cursor.getString(cursor.getColumnIndexOrThrow("poster"))

            // update view with given values above
        }
    }
}