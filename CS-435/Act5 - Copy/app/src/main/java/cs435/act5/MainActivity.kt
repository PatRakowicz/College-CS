package cs435.act5

import Beer
import android.content.ContentValues
import android.content.Intent
import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.AdapterView
import android.widget.ListView
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class MainActivity : AppCompatActivity() {

    private lateinit var listView: ListView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        listView = findViewById(R.id.ListViewDrinks)

        val beerDBHelper = BeerDBHelper(applicationContext)
        val sqLiteDatabase = beerDBHelper.readableDatabase

        /*val updateBeerValues = ContentValues().apply {
            put("description", "delicious")
        }
        sqLiteDatabase.update("beer", updateBeerValues, )*/

        /*val queryInsert = ContentValues().apply {
            put("name", "Coors")
            put("description", "like water")
        }

        sqLiteDatabase.insert("beer", null, queryInsert)*/

        sqLiteDatabase.delete("beer", "name = ?", arrayOf("Coors"))
        sqLiteDatabase.execSQL("DELETE from beer where name = ? limit 1", arrayOf("Coors"))


        //Lambda Route
        listView.onItemClickListener = AdapterView.OnItemClickListener { adapterView, view, i, l ->
            if (i == 0) {
                Toast.makeText(applicationContext, "BEER", Toast.LENGTH_LONG).show()
                val intent = Intent(this, BeerCategoryActivity::class.java)
                startActivity(intent)
            }
        }

        /*listView.setOnItemClickListener(object : AdapterView.OnItemClickListener {
            override fun onItemClick(
                parent: AdapterView<*>?,
                view: View?,
                position: Int,
                id: Long) {
                }

        })*/

    }
}