package cs435.hw7

import android.os.Bundle
import android.util.Log
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Button
import android.widget.EditText
import android.widget.TextView
import android.widget.Toast

class ConversionDetailFragment : Fragment() {

    private var selectedConversionName: String? = null
    private var selectedConversion: Conversion? = null
    private lateinit var detailEditText: EditText
    private lateinit var convertButton: Button
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

        val bundle = arguments
        if (bundle != null) {
            selectedConversionName = bundle.getString("conversion_name")
            selectedConversion = Conversion.conversions.firstOrNull { it.name == selectedConversionName }

//            Log.d("ConversionDetail", "Selected Conversion Name: $selectedConversionName")
//            Log.d("ConversionDetail", "Selected Conversion: $selectedConversion")
        }

        convertButton.setOnClickListener {
            val inputValue = detailEditText.text.toString().toDoubleOrNull()
//            Log.d("inputValue", inputValue.toString())
//            Log.d("selectedConversion", selectedConversion.toString())

            if (inputValue != null && selectedConversion != null) {
                try {
                    val result = selectedConversion?.convert(inputValue) ?: 0.0

                    Conversion.saveToHistory(inputValue, selectedConversion?.name ?: "", result)
                    resultText.text = String.format("%.2f", result)

                    val parentFragment = parentFragment as? DetailAndHistoryFragment
                    parentFragment?.refreshHistory()
                } catch (e: Exception) {
                    Toast.makeText(requireContext(), "Conversion error: ${e.message}", Toast.LENGTH_LONG).show()
                }
            } else {
                Toast.makeText(requireContext(), "Enter Valid Number", Toast.LENGTH_SHORT).show()
            }
        }
        return view
    }
}