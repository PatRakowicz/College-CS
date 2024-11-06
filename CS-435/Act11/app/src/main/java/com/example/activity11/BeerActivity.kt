package com.example.activity11

import android.os.Bundle
import android.widget.ImageView
import android.widget.TextView
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class BeerActivity : AppCompatActivity() {
    private lateinit var imageView : ImageView
    private lateinit var textViewName : TextView
    private lateinit var textViewDesc : TextView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_beer)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        imageView = findViewById(R.id.imageViewLogo)
        textViewName = findViewById(R.id.textViewName)
        textViewDesc = findViewById(R.id.textViewDesc)

        val index = intent.getIntExtra("INDEX", 0)
        val beerDatabaseHelper = BeerDatabaseHelper(applicationContext)
        val sqLiteDatabase = beerDatabaseHelper.readableDatabase
        val cursor = sqLiteDatabase.query(
            "beer",
            arrayOf("_id", "name", "description", "image_resource_id"),
            "_id = ?",
            arrayOf(index.toString()),
            null, null, null, null
        )

        if (cursor.moveToFirst()) {
            var column = cursor.getColumnIndexOrThrow("name")
            textViewName.text = cursor.getString(column)

            column = cursor.getColumnIndexOrThrow("description")
            textViewDesc.text = cursor.getString(column)

            column = cursor.getColumnIndexOrThrow("image_resource_id")
            imageView.setImageResource(cursor.getInt(column))
        }
        cursor.close()
        sqLiteDatabase.close()

        /*val beer = Beer.beers[index]
        beer.imageResourceID?.let { imageView.setImageResource(it) }
        textViewName.text = beer.name
        textViewDesc.text = beer.description*/
    }
}
