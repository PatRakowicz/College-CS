package cs435.act9

import android.os.Bundle
import android.view.Menu
import android.view.MenuItem
import android.view.View
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AlertDialog
import androidx.appcompat.app.AppCompatActivity
import androidx.appcompat.widget.Toolbar
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)

        val toolbar = findViewById<Toolbar>(R.id.toolbar)
        setSupportActionBar(toolbar)

        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }
    }

    override fun onCreateOptionsMenu(menu: Menu?): Boolean {
        menuInflater.inflate(R.menu.menu, menu)
        return true
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        return when (item.itemId) {
            R.id.menuItemA -> {
                Toast.makeText(this, "A was clicked", Toast.LENGTH_SHORT).show()
                true
            }
            R.id.menuItemB -> {
                Toast.makeText(this, "B was clicked", Toast.LENGTH_SHORT).show()
                true
            }
            else -> super.onOptionsItemSelected(item)
        }
    }

    fun showAlertDialog(view: View) {
        val builder = AlertDialog.Builder(this)
        builder.setTitle("I am an alert")
        builder.setMessage("Is ralph funny or sad?")

        builder.setPositiveButton("Funny") { dialog, which ->
            Toast.makeText(this,"funny", Toast.LENGTH_SHORT).show()
        }
        builder.setNegativeButton("Sad") { dialog, which ->
            Toast.makeText(this, "sad", Toast.LENGTH_SHORT).show()
        }
        builder.show()
    }

    fun onClickDatePicker(view: View) {
        val dateFragment = DateFragment()
        dateFragment.show(supportFragmentManager, null)
    }
}