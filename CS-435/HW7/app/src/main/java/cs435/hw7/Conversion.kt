package cs435.hw7

class Conversion(
    var name: String? = null,
) {
    companion object {
        val conversions = arrayOf(
            Conversion("Fahrenheit to Celsius"),
            Conversion("Miles to Kilometers"),
            Conversion("Yards to Meters"),
            Conversion("Gallons to Liters")
        )
    }
// TODO: Need logic for conversion
    override fun toString(): String {
        return name ?: ""
    }
}