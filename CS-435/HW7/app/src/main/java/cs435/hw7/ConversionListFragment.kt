package cs435.hw7

import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.AdapterView
import android.widget.ArrayAdapter
import android.widget.ListView
import android.widget.TextView
import androidx.fragment.app.FragmentManager

class ConversionListFragment : Fragment() {

    private lateinit var conversionList: ListView

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        val view = inflater.inflate(R.layout.fragment_conversion_list, container, false)

        conversionList = view.findViewById(R.id.conversion_list)

        val isTablet = activity?.findViewById<TextView>(R.id.is_tablet) != null

        val fragmentManager: FragmentManager? = activity?.supportFragmentManager

        val conversionNames = Conversion.conversions.map { it.name }
        val adapter = ArrayAdapter(
            requireContext(),
            android.R.layout.simple_list_item_1,
            conversionNames
        )
        conversionList.adapter = adapter

        conversionList.onItemClickListener = AdapterView.OnItemClickListener { _, _, _, _ ->
            val fragmentTransaction = fragmentManager?.beginTransaction()

            if (isTablet) {
                fragmentTransaction?.replace(R.id.fragment_detail_and_history_container, DetailAndHistoryFragment())
            } else {
                fragmentTransaction?.replace(R.id.fragment_container, DetailAndHistoryFragment())
                    ?.addToBackStack(null)
            }

            fragmentTransaction?.commit()
        }

        return view
    }
}