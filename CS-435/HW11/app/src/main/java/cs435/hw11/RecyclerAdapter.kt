package cs435.hw11

import android.database.Cursor
import android.graphics.Color
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.CheckBox
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView
import androidx.recyclerview.widget.RecyclerView.ViewHolder

class RecyclerAdapter(private var cursor: Cursor, private var dbHelper: ColorDBHelper) : RecyclerView.Adapter<RecyclerAdapter.RecyclerViewHolder>() {
    class RecyclerViewHolder(itemView: View) : ViewHolder(itemView) {
        val colorBox: View = itemView.findViewById(R.id.colorBox)
        val rgbText: TextView = itemView.findViewById(R.id.rgbText)
        val checkBox: CheckBox = itemView.findViewById(R.id.checkBox)
    }

    override fun onCreateViewHolder(
        parent: ViewGroup,
        viewType: Int
    ): RecyclerAdapter.RecyclerViewHolder {
        val view = LayoutInflater.from(parent.context).inflate(R.layout.item_color, parent, false)
        return RecyclerViewHolder(view)
    }

    override fun onBindViewHolder(holder: RecyclerAdapter.RecyclerViewHolder, position: Int) {
        cursor.moveToPosition(position)

        val id = cursor.getInt(cursor.getColumnIndexOrThrow("_id"))
        val red = cursor.getInt(cursor.getColumnIndexOrThrow("red"))
        val green = cursor.getInt(cursor.getColumnIndexOrThrow("green"))
        val blue = cursor.getInt(cursor.getColumnIndexOrThrow("blue"))
        val isFav = cursor.getInt(cursor.getColumnIndexOrThrow("favorite")) == 1

        holder.colorBox.setBackgroundColor(Color.rgb(red, green, blue))
        holder.rgbText.text = "R: $red, G: $green, B: $blue"
        holder.checkBox.isChecked = isFav

        // https://developer.android.com/develop/ui/views/components/checkbox#kotlin
        // Broken somewhere | Not sure will add items when i do not select the item...
        holder.checkBox.setOnCheckedChangeListener { buttonView, isChecked ->
            dbHelper.updateFavoriteStatus(id, isChecked)
        }
    }

    override fun getItemCount(): Int {
        return cursor.count
    }

    fun updateColors(newCursor: Cursor) {
        cursor.close()
        cursor = newCursor
        notifyDataSetChanged()
    }
}
