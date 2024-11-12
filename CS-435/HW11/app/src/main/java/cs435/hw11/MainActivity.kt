package cs435.hw11

import android.database.Cursor
import android.os.Bundle
import android.view.Menu
import android.view.MenuItem
import android.widget.EditText
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AlertDialog
import androidx.appcompat.app.AppCompatActivity
import androidx.appcompat.widget.Toolbar
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView

class MainActivity : AppCompatActivity() {
    private lateinit var databaseHelper : ColorDBHelper
    private lateinit var colorAdapter: ColorAdapter

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

        val recyclerView = findViewById<RecyclerView>(R.id.recyclerView)
        recyclerView.layoutManager = LinearLayoutManager(this)
        // https://stackoverflow.com/questions/48741473/what-is-the-function-of-emptylist-in-kotlin
        colorAdapter = ColorAdapter(emptyList())
        recyclerView.adapter = colorAdapter


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
                            databaseHelper.insertRandomColors(numberOfNewColors)
                            loadColorsFromDB()
                        }
                    }
                    .setNegativeButton("Cancel", null)
                    .show()
                true
            }
            R.id.action_sort -> {
                // "sort" logic
                true
            }
        else -> super.onOptionsItemSelected(item)
        }
    }

    private fun loadColorsFromDB() {
        val cursor : Cursor = databaseHelper.getAllColors()
        val colors = mutableListOf<List<Int>>()

        if (cursor.moveToFirst()) {
            do {
                val red = cursor.getInt(cursor.getColumnIndexOrThrow("red"))
                val green = cursor.getInt(cursor.getColumnIndexOrThrow("green"))
                val blue = cursor.getInt(cursor.getColumnIndexOrThrow("blue"))
                colors.add(listOf(red, green, blue))
            } while (cursor.moveToNext())
        }
        cursor.close()
        colorAdapter.updateColors(colors)
    }
}