import cs435.act5.R

class Beer(
    var name: String? = null,
    var description: String? = null,
    var imageResourceID: Int? = null
) {
    companion object {
        val beers = arrayOf(
            Beer("Boneyard RPM", "IPA from bend, OR", R.drawable.boneyard),
            Beer("Curx Pilz", "Delicious Pislner", R.drawable.crux)
        )
    }

    override fun toString(): String {
        return name?: ""
    }
}
