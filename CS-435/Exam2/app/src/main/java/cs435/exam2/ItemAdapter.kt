package cs435.exam2

import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView

class ItemAdapter(private val items: List<Items>) : RecyclerView.Adapter<ItemAdapter.ItemViewHolder>() {
    inner class ItemViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView) {
        val text : TextView = itemView.findViewById(R.id.numTextView)
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ItemViewHolder {
        val view = LayoutInflater.from(parent.context).inflate(R.layout.item_layout), parent, false)
        return view
    }

    override fun onBindViewHolder(holder: ItemViewHolder, position: Int) {
        val items = items[position]
        holder.itemView = items.number
    }

    override fun getItemCount(): Int {
        return items.size
    }

}