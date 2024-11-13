package cs435.hw11

import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.CheckBox
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView
import androidx.recyclerview.widget.RecyclerView.ViewHolder

class RecyclerAdapter(private var colorList: List<List<Int>>) : RecyclerView.Adapter<RecyclerAdapter.ColorViewHolder>() {
    class ColorViewHolder(itemView: View) : ViewHolder(itemView) {
        val colorBox: View = itemView.findViewById(R.id.colorBox)
        val rgbText: TextView = itemView.findViewById(R.id.rgbText)
        val checkBox: CheckBox = itemView.findViewById(R.id.checkBox)
    }

    override fun onCreateViewHolder(
        parent: ViewGroup,
        viewType: Int
    ): RecyclerAdapter.ColorViewHolder {
        val view = LayoutInflater.from(parent.context).inflate(R.layout.item_color, parent, false)
        return ColorViewHolder(view)
    }

    override fun onBindViewHolder(holder: RecyclerAdapter.ColorViewHolder, position: Int) {
        val (r, g, b) = colorList[position]
        holder.colorBox.setBackgroundColor(android.graphics.Color.rgb(r, g, b))
        holder.rgbText.text = "R: $r, G: $g, B: $b"
        holder.checkBox.isChecked = false
    }

    override fun getItemCount(): Int {
        return colorList.size
    }

    fun updateColors(newColorList: List<List<Int>>) {
        colorList = newColorList
        notifyDataSetChanged()
    }
}
