package cs435.hw7

class Conversion(
    var name: String? = null,
    var description: String? = null,
    var factor: Double? = null
) {
    companion object {
        val conversions = arrayOf(
            Conversion("Fahrenheit to Celsius", "Converts Fahrenheit to Celsius", 0.5556),
            Conversion("Miles to Kilometers", "Converts miles to kilometers", 1.60934),
            Conversion("Yards to Meters", "Converts yards to meters", 0.9144),
            Conversion("Gallons to Liters", "Converts gallons to liters", 3.78541)
        )
    }

    fun convert(value: Double): Double {
        return value * (factor ?: 1.0)
    }

    override fun toString(): String {
        return name ?: ""
    }
}