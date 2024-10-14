package cs435.hw7

import android.util.Log

class Conversion(
    var name: String? = null,
    private val logic: (Double) -> Double
) {
    companion object {
        private val conversionHistory = mutableListOf<String>()

        val conversions = arrayOf(
            Conversion("Fahrenheit to Celsius") { value -> (value - 32) * 5/9 },
            Conversion("Miles to Kilometers") { value -> value * 1.609 },
            Conversion("Yards to Meters") { value -> value / 1.094  },
            Conversion("Gallons to Liters") { value -> value * 3.785 }
        )

        fun saveToHistory(inputValue: Double, conversionName: String, result: Double) {
            val formattedInput = String.format("%.2f", inputValue)
            val formattedResult = String.format("%.2f", result)
            val historyEntry = "$formattedInput $conversionName = $formattedResult"
            conversionHistory.add(historyEntry)
        }

        fun getHistory(): List<String> {
            return conversionHistory
        }
    }

    fun convert(value: Double): Double {
        return logic(value)
    }

    override fun toString(): String {
        return name ?: ""
    }
}