package cs435.hw9

import android.content.Context
import android.content.Intent
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView

class BooksAdapter(
    private val booksList: List<Books>,
    private val context : Context
) : RecyclerView.Adapter<BooksAdapter.BooksViewHolder>() {
    class BooksViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView) {
        val bookTitle: TextView = itemView.findViewById(R.id.bookTitle)
        val bookAuthor: TextView = itemView.findViewById(R.id.bookAuthor)
        val bookCover: ImageView = itemView.findViewById(R.id.bookCover)
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): BooksViewHolder {
        val view = LayoutInflater.from(parent.context).inflate(R.layout.item_book, parent, false)
        return BooksViewHolder(view)
    }

    override fun onBindViewHolder(holder: BooksViewHolder, position: Int) {
        val book = booksList[position]
        holder.bookTitle.text = book.title
        holder.bookAuthor.text = book.author
        holder.bookCover.setImageResource(book.coverImage)

        holder.itemView.setOnClickListener {
            val intent = Intent(context, DisplayBookActivity::class.java)
            intent.putExtra("bookId", book.id)
            context.startActivity(intent)
        }
    }

    override fun getItemCount(): Int {
        return booksList.size
    }
}