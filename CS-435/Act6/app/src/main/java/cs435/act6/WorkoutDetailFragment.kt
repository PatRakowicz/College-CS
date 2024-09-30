package cs435.act6

import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TextView


class WorkoutDetailFragment : Fragment() {

    private lateinit var textName: TextView
    private lateinit var textDesc: TextView
    private var workoutID: Int = 0

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        val view = inflater.inflate(R.layout.fragment_workout_detail, container, false)

        textName = view.findViewById(R.id.textViewName)
        textDesc = view.findViewById(R.id.textViewDesc)

        return view

    }

    fun setWorkoutID(workoutID: Int) {
        this.workoutID = workoutID
    }

    override fun onStart() {
        super.onStart()
        val workout = Workout.workouts[workoutID]
        textName.text = workout.name
        textDesc.text = workout.desc
    }
}