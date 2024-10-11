package cs435.hw7

import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ListView

class ConversionListFragment : Fragment() {

    private lateinit var conversionList : ListView

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        // Inflate the layout for this fragment
        val view =  inflater.inflate(R.layout.fragment_conversion_list, container, false)

        conversionList = view.findViewById(R.id.conversion_list)

        return view
    }
}