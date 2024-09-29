package cs435.hw5

import android.content.Intent
import android.os.Bundle
import android.widget.Button
import android.widget.ImageView
import android.widget.TextView
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class Detail : AppCompatActivity() {

    private var itemPosition : Int = -1
    private var category : String? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_detail)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        category = intent.getStringExtra("category")
        itemPosition = intent.getIntExtra("itemPosition", -1)
        val item = when (category) {
            "Electronics" -> WishListItems.electronicsList[itemPosition]
            "Books" -> WishListItems.booksList[itemPosition]
            "Clothing" -> WishListItems.clothingList[itemPosition]
            else -> null
        }

        val itemNameView = findViewById<TextView>(R.id.itemNameTextView)
        val itemPriceView = findViewById<TextView>(R.id.itemPriceTextView)
        val itemImageView = findViewById<ImageView>(R.id.itemImageView)
        val deleteButton = findViewById<Button>(R.id.deleteButton)

        itemNameView.text = item?.name
        itemPriceView.text = item?.price
        item?.image?.let {itemImageView.setImageResource(it)}

        deleteButton.setOnClickListener {
            when (category) {
                "Electronics" -> WishListItems.electronicsList.removeAt(itemPosition)
                "Books" -> WishListItems.booksList.removeAt(itemPosition)
                "Clothing" -> WishListItems.clothingList.removeAt(itemPosition)
            }

            finish()
        }
    }
}