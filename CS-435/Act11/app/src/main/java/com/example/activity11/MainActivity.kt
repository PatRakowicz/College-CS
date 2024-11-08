package com.example.activity11

import android.content.ContentValues
import android.content.Intent
import android.database.sqlite.SQLiteDatabase
import android.os.Bundle
import android.view.View
import android.widget.AdapterView
import android.widget.ListView
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch
import kotlinx.coroutines.withContext

class MainActivity : AppCompatActivity() {

    private lateinit var listView : ListView
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }


        val beerDatabaseHelper = BeerDatabaseHelper(applicationContext)
        val sqLiteDatabase = beerDatabaseHelper.readableDatabase

        CoroutineScope(Dispatchers.IO).launch {
            insertBeerInDatabase(sqLiteDatabase)
        }

        listView = findViewById(R.id.ListViewDrinks)

        listView.setOnItemClickListener(object : AdapterView.OnItemClickListener{
            override fun onItemClick(parent: AdapterView<*>?, view: View?, position: Int, id: Long)
            {
                if(position==0){
                    val intent = Intent(applicationContext, BeerCategoryActivity::class.java)
                    startActivity(intent)
                }
            }
        })
    }

    private suspend fun insertBeerInDatabase(sqLiteDatabase: SQLiteDatabase) {
        withContext(Dispatchers.IO) {
            for (i in 1..10) {
                val beerValue = ContentValues().apply {
                    put("name", "Beer $i")
                    put("description", "Description of $i")
                    put("image_resource_id", R.drawable.crux)
                }
                sqLiteDatabase.insert("beer", null, beerValue)
            }
        }
    }
}