package cs435.hw12

import android.database.Cursor
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.webkit.WebView
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView

class RecyclerAdapter(private val cursor: Cursor) :
    RecyclerView.Adapter<RecyclerAdapter.ComicViewHolder>() {

    class ComicViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView) {
        val comicId: TextView = itemView.findViewById(R.id.comic_id)
        val comicTitle: TextView = itemView.findViewById(R.id.comic_title)
        val comicImage: WebView = itemView.findViewById(R.id.comic_image)
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ComicViewHolder {
        val view = LayoutInflater.from(parent.context).inflate(R.layout.item_comic, parent, false)
        return ComicViewHolder(view)
    }

    override fun onBindViewHolder(holder: ComicViewHolder, position: Int) {
        if (cursor.moveToPosition(position)) {
            val num = cursor.getInt(cursor.getColumnIndexOrThrow("num"))
            val title = cursor.getString(cursor.getColumnIndexOrThrow("title"))
            val imgUrl = cursor.getString(cursor.getColumnIndexOrThrow("img"))

            holder.comicId.text = "ID: $num"
            holder.comicTitle.text = title

            // Use WebView to load the image URL
            holder.comicImage.loadUrl(imgUrl)
        }
    }

    override fun getItemCount(): Int {
        return cursor.count
    }
}