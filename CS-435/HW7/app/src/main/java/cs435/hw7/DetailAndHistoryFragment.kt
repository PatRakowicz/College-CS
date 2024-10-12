package cs435.hw7

import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup

class DetailAndHistoryFragment : Fragment() {
    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        val view = inflater.inflate(R.layout.fragment_detail_and_history, container, false)

        childFragmentManager.beginTransaction()
            .replace(R.id.detail_fragment_container, ConversionDetailFragment())
            .replace(R.id.history_fragment_container, ConversionHistoryFragment())
            .commit()

        return view
    }
}