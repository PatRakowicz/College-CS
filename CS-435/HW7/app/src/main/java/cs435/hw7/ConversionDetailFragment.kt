package cs435.hw7

import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Button
import android.widget.EditText
import android.widget.TextView

class ConversionDetailFragment : Fragment() {

    private lateinit var detailEditText : EditText
    private lateinit var convertButton : Button
    private lateinit var resultText: TextView

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        // Inflate the layout for this fragment
        val view = inflater.inflate(R.layout.fragment_conversion_detail, container, false)

        detailEditText = view.findViewById(R.id.detailEditText)
        convertButton = view.findViewById(R.id.convert_button)
        resultText = view.findViewById(R.id.result_value)

        return view
    }
}