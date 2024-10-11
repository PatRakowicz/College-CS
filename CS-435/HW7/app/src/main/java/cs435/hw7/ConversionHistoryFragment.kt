package cs435.hw7

import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ListView
import android.widget.TextView

class ConversionHistoryFragment : Fragment() {

    private lateinit var conversionHistory : TextView
    private lateinit var historyList : ListView

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        // Inflate the layout for this fragment
        val view =  inflater.inflate(R.layout.fragment_conversion_history, container, false)

        conversionHistory = view.findViewById(R.id.conversion_history)
        historyList = view.findViewById(R.id.history_list)

        return view
    }
}