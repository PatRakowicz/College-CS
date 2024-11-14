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

class RecyclerAdapter(private var cursor: Cursor) : RecyclerView.Adapter<RecyclerAdapter.RecyclerViewHolder>() {
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

        val red = cursor.getInt(cursor.getColumnIndexOrThrow("red"))
        val green = cursor.getInt(cursor.getColumnIndexOrThrow("green"))
        val blue = cursor.getInt(cursor.getColumnIndexOrThrow("blue"))

        holder.colorBox.setBackgroundColor(Color.rgb(red, green, blue))
        holder.rgbText.text = "R: $red, G: $green, B: $blue"
        holder.checkBox.isChecked = false
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
