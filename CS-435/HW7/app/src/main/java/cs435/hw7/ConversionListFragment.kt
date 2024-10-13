package cs435.hw7

import android.os.Bundle
import android.util.Log
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
        conversionList.onItemClickListener = AdapterView.OnItemClickListener { parent, view, position, id ->
            val selectedConversionName = conversionNames[position]
            val DHfragment = DetailAndHistoryFragment()
            val bundle = Bundle()

            bundle.putString("conversion_name", selectedConversionName)
//            Log.d("conversionList | bundle", bundle.getString("conversion_name").toString())
//            Log.d("conversionList | selectedConversionName", selectedConversionName.toString())
            DHfragment.arguments = bundle

            val fragmentTransaction = fragmentManager?.beginTransaction()
            if (isTablet) {
                fragmentTransaction?.replace(R.id.fragment_detail_and_history_container, DHfragment)
            } else {
                fragmentTransaction?.replace(R.id.fragment_container, DHfragment)
                    ?.addToBackStack(null)
            }
            fragmentTransaction?.commit()
        }
        return view
    }
}