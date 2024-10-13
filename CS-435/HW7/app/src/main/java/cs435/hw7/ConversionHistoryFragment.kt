package cs435.hw7

import android.os.Bundle
import android.util.Log
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ArrayAdapter
import android.widget.ListView
import android.widget.TextView

class ConversionHistoryFragment : Fragment() {

    private lateinit var conversionHistory: TextView
    private lateinit var historyList: ListView

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        // Inflate the layout for this fragment
        val view = inflater.inflate(R.layout.fragment_conversion_history, container, false)

        conversionHistory = view.findViewById(R.id.conversion_history)
        historyList = view.findViewById(R.id.history_list)

        updateHistory()

        return view
    }

    fun updateHistory() {
        val historyItems = Conversion.getHistory()
//        Log.d("history", historyItems.toString())
        val adapter = ArrayAdapter(requireContext(), android.R.layout.simple_list_item_1, historyItems)
        historyList.adapter = adapter
    }

    override fun onResume() {
        super.onResume()
        updateHistory()
    }
}