package cs435.hw7

import android.os.Bundle
import android.util.Log
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup

class DetailAndHistoryFragment : Fragment() {

    private lateinit var conversionHistoryFragment: ConversionHistoryFragment

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        val view = inflater.inflate(R.layout.fragment_detail_and_history, container, false)

        val selectedConversionName = arguments?.getString("conversion_name")
        val conversionDetailFragment = ConversionDetailFragment()
        val bundle = Bundle()

        bundle.putString("conversion_name", selectedConversionName)
        conversionDetailFragment.arguments = bundle
//        Log.d("detailandhistory", selectedConversionName.toString())

        conversionHistoryFragment = ConversionHistoryFragment()

        childFragmentManager.beginTransaction()
            .replace(R.id.detail_fragment_container, conversionDetailFragment)
            .replace(R.id.history_fragment_container, conversionHistoryFragment)
            .commit()

        return view
    }
    fun refreshHistory() {
        conversionHistoryFragment.updateHistory()
    }
}