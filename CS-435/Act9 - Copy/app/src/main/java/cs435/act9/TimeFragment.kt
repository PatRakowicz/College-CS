package cs435.act9

import android.app.Dialog
import android.app.TimePickerDialog
import android.icu.util.Calendar
import android.os.Bundle
import android.text.format.DateFormat
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TextView
import android.widget.TimePicker
import android.widget.Toast
import androidx.fragment.app.DialogFragment

class TimeFragment : DialogFragment(), TimePickerDialog.OnTimeSetListener {
    interface On

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        // Inflate the layout for this fragment
        return inflater.inflate(R.layout.fragment_time, container, false)
    }

    override fun onCreateDialog(savedInstanceState: Bundle?): Dialog {
        val defHour = 12
        val defMinute = 0
        return TimePickerDialog(activity, this, defHour, defMinute, true)
    }

    override fun onTimeSet(view: TimePicker?, hourOfDay: Int, minute: Int) {
        val time = String.format("%02d:%02d", hourOfDay, minute)

    //        Toast.makeText(activity, "Selected time: $time", Toast.LENGTH_SHORT).show()
    }
}