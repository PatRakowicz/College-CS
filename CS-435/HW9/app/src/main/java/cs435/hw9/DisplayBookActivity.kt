package cs435.hw9

import android.os.Bundle
import android.widget.Button
import android.widget.ImageView
import android.widget.TextView
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class DisplayBookActivity : AppCompatActivity() {
    private var bookId: Int = -1

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_display_book)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        bookId = intent.getIntExtra("bookId", -1)

        val book = Books.books.find { it.id == bookId }

        val bookCover: ImageView = findViewById(R.id.bookCover)
        val bookTitle: TextView = findViewById(R.id.bookTitle)
        val bookAuthor: TextView = findViewById(R.id.bookAuthor)
        val addToCartButton: Button = findViewById(R.id.addToCartButton)

        if (book != null) {
            bookCover.setImageResource(book.coverImage)
            bookTitle.text = book.title
            bookAuthor.text = book.author
        }

        addToCartButton.setOnClickListener {
            Cart.addToCartById(bookId)
            Toast.makeText(this, "Book added", Toast.LENGTH_SHORT).show()
            finish()
        }
    }
}