package cs435.hw9

import android.app.AlertDialog
import android.os.Bundle
import android.view.Menu
import android.view.MenuItem
import android.widget.ArrayAdapter
import android.widget.Button
import android.widget.ListView
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class CartActivity : AppCompatActivity() {
    private lateinit var cartListView: ListView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_cart)

        setSupportActionBar(findViewById(R.id.toolbar))

        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }


        cartListView = findViewById(R.id.cartListView)
        val setDeliveryDateButton: Button = findViewById(R.id.setDeliveryDateButton)
        val setDeliveryTimeButton: Button = findViewById(R.id.setDeliveryTimeButton)
        val submitOrderButton: Button = findViewById(R.id.submitOrderButton)

        loadCartItems()

        // Set up button actions (placeholders for now)
        setDeliveryDateButton.setOnClickListener {
            Cart.deliveryDate = null // Placeholder action
        }

        setDeliveryTimeButton.setOnClickListener {
            Cart.deliveryTime = null // Placeholder action
        }

        submitOrderButton.setOnClickListener {
            Cart.clearCart()
            loadCartItems()
            finish() // Close the activity
        }
    }

    override fun onCreateOptionsMenu(menu: Menu?): Boolean {
        menuInflater.inflate(R.menu.menu_cart, menu)
        return true
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        return when (item.itemId) {
            R.id.action_delete -> {
                AlertDialog.Builder(this)
                    .setTitle("Confirm Deletion")
                    .setMessage("Are you sure you want to delete all items in the cart?")
                    .setPositiveButton("Yes") { dialogInterface, which ->
                        Cart.clearCart()
                        loadCartItems()
                        Toast.makeText(this, "Cart cleared", Toast.LENGTH_SHORT).show()
                    }
                    .setNegativeButton("No", null)
                    .show()
                true
            }
            else -> super.onOptionsItemSelected(item)
        }
    }

    private fun loadCartItems() {
        val cartItems = Cart.getCartItems().map { it.title }
        val adapter = ArrayAdapter(this, android.R.layout.simple_list_item_1, cartItems)
        cartListView.adapter = adapter
    }
}