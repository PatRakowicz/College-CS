package com.example.lab11

import android.os.Bundle
import android.view.View
import android.widget.EditText
import android.widget.SimpleCursorAdapter
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView

class MainActivity : AppCompatActivity() {

    private lateinit var recyclerView: RecyclerView
    private lateinit var adapter: ItemAdapter

    private lateinit var textName : EditText
    private lateinit var textAge : EditText

    private lateinit var dbHelper: DatabaseHelper

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        dbHelper = DatabaseHelper(applicationContext)

        textName = findViewById(R.id.editTextName)
        textAge = findViewById(R.id.editTextAge)

        recyclerView = findViewById(R.id.recyclerView)
        adapter = ItemAdapter(dbHelper.getAllItems())
        recyclerView.adapter = adapter
        recyclerView.layoutManager = LinearLayoutManager(this)
    }

    fun addItems(view: View) {
        var name = textName.text.toString()
        var age = textAge.text.toString().toInt()
        dbHelper.insertItem(name, age)
        adapter.notifyDataSetChanged()
    }

}