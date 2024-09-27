    package cs435.lab5

    class listRandom (var name: String? = null) {
        companion object  {
            val listRandoms = arrayListOf(
                listRandom("Cherry"),
                listRandom("Blue"),
                listRandom("Red"),
                listRandom("Date"),
                listRandom("Radiation"),
                listRandom("Plutonium")
            )
        }

        override fun toString(): String {
            return name?: ""
        }
    }