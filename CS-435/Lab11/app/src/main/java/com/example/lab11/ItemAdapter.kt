package com.example.lab11

import android.database.Cursor
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView

class ItemAdapter(val cursor: Cursor): RecyclerView.Adapter<ItemAdapter.ViewHolder>() {

    class ViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView) {

        private val textViewName: TextView = itemView.findViewById(R.id.textViewName)
        private val textViewAge: TextView = itemView.findViewById(R.id.textViewAge)

        fun update(cursor: Cursor) {
                val name = cursor.getColumnIndexOrThrow("name")
                val age = cursor.getColumnIndexOrThrow("age")

                textViewName.text = cursor.getString(name)
                textViewAge.text = cursor.getInt(age).toString()
        }
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ViewHolder {
        val view = LayoutInflater.from(parent.context)
            .inflate(R.layout.item_layout, parent, false)
        return ViewHolder(view)
    }

    override fun onBindViewHolder(holder: ViewHolder, position: Int) {
        cursor.moveToPosition(position)
        holder.update(cursor)
    }

    override fun getItemCount(): Int {
        return cursor.count
    }
}
