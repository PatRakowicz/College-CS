package cs435.hw12

import android.database.Cursor
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.webkit.WebView
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView

class RecyclerAdapter(private val cursor: Cursor, private val listener: OnClickListener) :
    RecyclerView.Adapter<RecyclerAdapter.ComicViewHolder>() {

    // Interface for handling comic item click events
    interface OnClickListener {
        fun onComicClick(comicId: Int)
    }

    // ViewHolder class that holds references to UI elements in each item view
    class ComicViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView) {
        val comicId: TextView = itemView.findViewById(R.id.comic_id)
        val comicTitle: TextView = itemView.findViewById(R.id.comic_title)
        val comicImage: WebView = itemView.findViewById(R.id.comic_image)
    }

    // Creates a new ViewHolder when there are no existing ones to reuse
    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ComicViewHolder {
        val view = LayoutInflater.from(parent.context).inflate(R.layout.item_comic, parent, false)
        return ComicViewHolder(view)
    }

    // Binds data from the cursor to the ViewHolder UI elements
    override fun onBindViewHolder(holder: ComicViewHolder, position: Int) {
        if (cursor.moveToPosition(position)) {
            val num = cursor.getInt(cursor.getColumnIndexOrThrow("num")) // Retrieves comic number
            val title = cursor.getString(cursor.getColumnIndexOrThrow("title")) // Retrieves comic title
            val imgUrl = cursor.getString(cursor.getColumnIndexOrThrow("img")) // Retrieves comic image URL

            holder.comicId.text = "ID: $num" // Sets comic ID text
            holder.comicTitle.text = title // Sets comic title text

            // Loads the comic's image into the WebView
            holder.comicImage.loadUrl(imgUrl)

            // Sets up click listener for each comic item
            holder.itemView.setOnClickListener { listener.onComicClick(num) }
        }
    }

    // Returns the total number of items in the cursor
    override fun getItemCount(): Int {
        return cursor.count
    }
}