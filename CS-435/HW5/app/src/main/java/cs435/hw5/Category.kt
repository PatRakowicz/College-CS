package cs435.hw5

import WishListItems
import android.content.Intent
import android.os.Bundle
import android.widget.AdapterView
import android.widget.ArrayAdapter
import android.widget.ListView
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class Category : AppCompatActivity() {

    private lateinit var adapter: ArrayAdapter<WishListItems>
    private lateinit var items: ArrayList<WishListItems>

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_category)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        val category = intent.getStringExtra("category")
        val listView = findViewById<ListView>(R.id.itemsListView)

        items = when (category) {
            "Electronics" -> WishListItems.electronicsList
            "Books" -> WishListItems.booksList
            "Clothing" -> WishListItems.clothingList
            else -> arrayListOf()
        }

        adapter = ArrayAdapter(this, android.R.layout.simple_list_item_1, items)
        listView.adapter = adapter

        listView.onItemClickListener = AdapterView.OnItemClickListener { _, _, i, _ ->
            val intent = Intent(this, Detail::class.java)
            intent.putExtra("category", category)
            intent.putExtra("itemPosition", i)
            startActivity(intent)
        }

        listView.setOnItemLongClickListener { _, _, i, _ ->
            items.removeAt(i)
            adapter.notifyDataSetChanged()
            true
        }
    }

    override fun onResume() {
        super.onResume()
        adapter.notifyDataSetChanged()
    }
}