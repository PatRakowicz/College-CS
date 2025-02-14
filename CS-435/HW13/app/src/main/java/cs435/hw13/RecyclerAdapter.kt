package cs435.hw13

import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView

class RecyclerAdapter(
    private var favorites: List<Favorites>,
    private val listener: OnFavClickListener
) : RecyclerView.Adapter<RecyclerAdapter.ViewHolder>() {

    interface OnFavClickListener { fun onFavClick(favorites: Favorites) }

    class ViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView) {
        val countryName: TextView = itemView.findViewById(R.id.country_name)
        val capitalName: TextView = itemView.findViewById(R.id.capital_name)
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ViewHolder {
        val view =
            LayoutInflater.from(parent.context).inflate(R.layout.recycler_item, parent, false)
        return ViewHolder(view)
    }

    override fun onBindViewHolder(holder: ViewHolder, position: Int) {
        val item = favorites[position]
        holder.countryName.text = item.country
        holder.capitalName.text = item.capital

        holder.itemView.setOnClickListener { listener.onFavClick(item) }
    }

    override fun getItemCount(): Int {
        return favorites.size
    }
}
