package cs435.act5

import android.os.Bundle
import android.widget.ImageView
import android.widget.TextView
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class BeerActivity : AppCompatActivity() {
    private lateinit var textName:TextView
    private lateinit var textDesc : TextView
    private lateinit var imageResorce : ImageView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_beer)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        textDesc = findViewById(R.id.textViewDesc)
        textName = findViewById(R.id.textViewName)
        imageResorce = findViewById(R.id.imageViewBeers)


        val index = intent.getIntExtra("INDEX", 0)
        val beer = Beer.beers[index]

        textDesc.text = beer.description
        textName.text = beer.name
        beer.imageResourceID?.let { imageResorce.setImageResource(it) }
    }
}