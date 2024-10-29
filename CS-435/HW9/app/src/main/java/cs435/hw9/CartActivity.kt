package cs435.hw9

import android.app.AlertDialog
import android.content.Intent
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

        setDeliveryDateButton.setOnClickListener {
            DatePickerFragment().show(supportFragmentManager, "datePicker")
        }

        setDeliveryTimeButton.setOnClickListener {
            TimePickerFragment().show(supportFragmentManager, "timePicker")
        }

        submitOrderButton.setOnClickListener {
            if (Cart.retrieveDeliveryDate() != null && Cart.retrieveDeliveryTime() != null) {
                startActivity(Intent(this, OrderConfirmActivity::class.java))
            } else {
                Toast.makeText(this, "Please set Delivery date and time", Toast.LENGTH_SHORT).show()
            }
        }
    }

    override fun onCreateOptionsMenu(menu: Menu?): Boolean {
        menuInflater.inflate(R.menu.menu_cart, menu)
        return true
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        return when (item.itemId) {
            R.id.action_delete -> {
                // https://developer.android.com/reference/android/app/AlertDialog.Builder | Dev notes
                // https://commonsware.com/Jetpack/pages/chap-dialog-002.html | Example
                AlertDialog.Builder(this)
                    .setTitle("Confirm Deletion")
                    .setMessage("Are you sure you want to delete all items in the cart?")
                    .setPositiveButton("Yes") { _, _ ->
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