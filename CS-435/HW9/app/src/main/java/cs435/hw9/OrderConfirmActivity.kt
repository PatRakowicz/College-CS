package cs435.hw9

import android.content.Intent
import android.os.Bundle
import android.widget.ArrayAdapter
import android.widget.Button
import android.widget.ListView
import android.widget.TextView
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class OrderConfirmActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_order_confirm)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        val deliveryDate = Cart.retrieveDeliveryDate()
        val deliveryTime = Cart.retrieveDeliveryTime()

        val deliveryDetails : TextView = findViewById(R.id.deliveryDetailsTextView)
        deliveryDetails.text = "Delivery set for $deliveryDate at $deliveryTime"

        val cartItems = Cart.getCartItems().map { it.title }
        val cartItemsList : ListView = findViewById(R.id.cartItemsListView)
        val adapter = ArrayAdapter(this, android.R.layout.simple_list_item_1, cartItems)
        cartItemsList.adapter = adapter

        val okButton : Button = findViewById(R.id.okButton)
        okButton.setOnClickListener {
            Cart.clearCart()
            startActivity(Intent(this, MainActivity::class.java))
            finish()
        }

    }
}