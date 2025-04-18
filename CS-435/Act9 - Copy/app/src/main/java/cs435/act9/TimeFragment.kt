package cs435.act9

import android.app.Dialog
import android.app.TimePickerDialog
import android.os.Bundle
import android.text.format.DateFormat
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TimePicker
import androidx.fragment.app.DialogFragment

class TimeFragment : DialogFragment(), TimePickerDialog.OnTimeSetListener {

    private lateinit var listener: OnTimeSetListener

    interface OnTimeSetListener { fun onTimeSelected(hourOfDay: Int, minute: Int) }
    fun setOnTimeSetListener(listener: OnTimeSetListener) { this.listener = listener }

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        // Inflate the layout for this fragment
        val view = inflater.inflate(R.layout.fragment_time, container, false)
        return view
    }

    override fun onCreateDialog(savedInstanceState: Bundle?): Dialog {
        val hour = 12
        val minute = 0
        return TimePickerDialog(activity, this, hour, minute, true)
    }

    override fun onTimeSet(view: TimePicker, hourOfDay: Int, minute: Int) {
        listener.onTimeSelected(hourOfDay, minute)
    }
}