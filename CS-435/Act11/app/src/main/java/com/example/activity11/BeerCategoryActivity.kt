package com.example.activity11

import android.content.Intent
import android.database.Cursor
import android.database.sqlite.SQLiteDatabase
import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.AdapterView
import android.widget.ArrayAdapter
import android.widget.ListView
import android.widget.SimpleCursorAdapter
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class BeerCategoryActivity : AppCompatActivity() {

    private lateinit var listView : ListView
    private lateinit var beerDatabaseHelper: BeerDatabaseHelper
    private lateinit var sqLiteDatabase: SQLiteDatabase
    private lateinit var cursor: Cursor

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_beer_category)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        beerDatabaseHelper = BeerDatabaseHelper(applicationContext)
        sqLiteDatabase = beerDatabaseHelper.readableDatabase

        cursor = sqLiteDatabase.query(
            "beer",
            arrayOf("_id", "name"),
            null, null, null, null, null, null
        )

//        while (cursor.moveToNext()) { Log.d("HERE", cursor.getString(0)) }

        val cursorAdapter = SimpleCursorAdapter(
            applicationContext,
            android.R.layout.simple_list_item_1,
            cursor,
            arrayOf("name"),
            intArrayOf(android.R.id.text1),
            0
        )

        /*val adapter = ArrayAdapter(
            applicationContext,
            android.R.layout.simple_list_item_1,
            Beer.beers
        )*/

        listView = findViewById(R.id.ListViewBeers)
        listView.adapter = cursorAdapter

        listView.setOnItemClickListener(object : AdapterView.OnItemClickListener{
            override fun onItemClick(parent: AdapterView<*>?, view: View?, position: Int, id: Long)
            {
                cursor.moveToPosition(position)
                val index = cursor.getInt(cursor.getColumnIndexOrThrow("_id"))


//                val index = position
                intent = Intent(applicationContext, BeerActivity::class.java)
                intent.putExtra("INDEX", index)
                startActivity(intent)
            }
        })
    }

    override fun onDestroy() {
        super.onDestroy()
        cursor.close()
        sqLiteDatabase.close()
    }
}


