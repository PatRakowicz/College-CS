package cs435.act7

import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Button
import android.widget.EditText
import android.widget.TextView

class ChildFragment : Fragment(), View.OnClickListener {
    private lateinit var editText: EditText
    private lateinit var textView: TextView
    private lateinit var button: Button

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        val view = inflater.inflate(R.layout.fragment_child, container, false)
        editText = view.findViewById(R.id.textView)
        textView = view.findViewById(R.id.textViewResult)
        button = view.findViewById(R.id.buttonClick)
        button.setOnClickListener(this)

        return view
    }

    override fun onClick(p0: View?) {
        fun click(view: View) {
            val input = editText.text.toString()
            textView.text = input
        }
    }
}