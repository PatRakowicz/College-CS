package cs435.act6

class Workout (var name : String? = null, var desc : String? = null) {
    companion object{
        val workouts = arrayOf(
            Workout("Beginner", "10 pushups\n10situps\n10squats"),
            Workout("Intermediate", "50 pushups\n50situps\n50squats"),
            Workout("Advanced", "100 pushups\n100situps\n100squats")
        )
    }

    override fun toString(): String {
        return name?: ""
    }
}


