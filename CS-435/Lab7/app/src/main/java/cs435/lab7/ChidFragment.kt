package cs435.lab7

import android.graphics.Color
import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Button

class ChildFragment : Fragment() {
    private lateinit var btnRed: Button
    private lateinit var btnGreen: Button
    private lateinit var btnBlue: Button

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        val view = inflater.inflate(R.layout.fragment_chid, container, false)

        btnRed = view.findViewById(R.id.btn_red)
        btnGreen = view.findViewById(R.id.btn_green)
        btnBlue = view.findViewById(R.id.btn_blue)

        btnRed.setOnClickListener {
            btnRed.setBackgroundColor(Color.RED)
            btnGreen.setBackgroundColor(Color.RED)
            btnBlue.setBackgroundColor(Color.RED)
        }
        btnGreen.setOnClickListener {
            btnBlue.setBackgroundColor(Color.GREEN)
            btnGreen.setBackgroundColor(Color.GREEN)
            btnRed.setBackgroundColor(Color.GREEN)
        }
        btnBlue.setOnClickListener {
            btnBlue.setBackgroundColor(Color.BLUE)
            btnGreen.setBackgroundColor(Color.BLUE)
            btnRed.setBackgroundColor(Color.BLUE)
        }

        return view
    }
}
