package cd435.lab9

import android.app.Dialog
import android.app.TimePickerDialog
import android.os.Bundle
import android.text.format.DateFormat
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TimePicker
import android.widget.Toast
import androidx.fragment.app.DialogFragment

class TimeFragment : DialogFragment(), TimePickerDialog.OnTimeSetListener {
    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        // Inflate the layout for this fragment
        val view = inflater.inflate(R.layout.fragment_time, container, false)
        return view
    }

    override fun onCreateDialog(savedInstanceState: Bundle?): Dialog {
        val defaultHour = 12
        val defaultMinute = 0

        return TimePickerDialog(activity, this, defaultHour, defaultMinute, DateFormat.is24HourFormat(activity))
    }


    override fun onTimeSet(view: TimePicker?, hourOfDay: Int, minute: Int) {
        val time = String.format("%02d:%02d", hourOfDay, minute)
        Toast.makeText(activity, "Selected time: $time", Toast.LENGTH_SHORT).show()
    }
}