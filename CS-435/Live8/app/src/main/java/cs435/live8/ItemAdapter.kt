package cs435.live8

import android.graphics.Color
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView

class ItemAdapter(private val itemAdapterListener: ItemAdapterListener) : RecyclerView.Adapter<ItemAdapter.ViewHolder>() {

    interface ItemAdapterListener {
        fun click(position: Int)
    }
    
    class ViewHolder(itemView: View, private val itemAdapterListener: ItemAdapterListener) : RecyclerView.ViewHolder(itemView) {

        init {
            itemView.setOnClickListener {
                val position = adapterPosition
                itemAdapterListener.click(position)
            }
        }

        private val textViewRed: TextView = itemView.findViewById(R.id.textViewRed)
        private val textViewGreen: TextView = itemView.findViewById(R.id.textViewGreen)
        private val textViewBlue: TextView = itemView.findViewById(R.id.textViewBlue)

        fun update(item: Item) {
            textViewRed.text = item.red.toString() + ", 0, 0"
            textViewGreen.text = "0, " + item.green.toString() + ", 0"
            textViewBlue.text = "0, 0, " + item.blue.toString()

            textViewRed.setBackgroundColor(Color.rgb(item.red?:0,0,0))
            textViewGreen.setBackgroundColor(Color.rgb(0, item.green?:0,0))
            textViewBlue.setBackgroundColor(Color.rgb(0, 0,item.blue?:0,))
        }
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ItemAdapter.ViewHolder {
        val view = LayoutInflater.from(parent.context).inflate(R.layout.item_layout, parent, false)
        return ViewHolder(view, itemAdapterListener)
    }

    override fun onBindViewHolder(holder: ItemAdapter.ViewHolder, position: Int) {
        val item = Model.items[position]
        holder.update(item)
    }

    override fun getItemCount(): Int {
        return Model.items.size
    }

}