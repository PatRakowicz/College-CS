import cs435.hw5.R

class WishListItems(var name: String, var image: Int, var price: String) {
    companion object{
        val electronicsList = arrayListOf(
            WishListItems("Laptop", R.drawable.laptop, "$999"),
            WishListItems("Smartphone", R.drawable.smartphone, "$799"),
            WishListItems("Tablet", R.drawable.taplet, "$499")
        )

        val booksList = arrayListOf(
            WishListItems("Novel", R.drawable.novel, "$15"),
            WishListItems("Biography", R.drawable.biography, "$20"),
            WishListItems("Science Book", R.drawable.sciencebook, "$25")
        )

        val clothingList = arrayListOf(
            WishListItems("Shirt", R.drawable.shirt, "$30"),
            WishListItems("Jacket", R.drawable.jacket, "$60"),
            WishListItems("Shoes", R.drawable.shoes, "$50")
        )
    }

    override fun toString(): String {
        return name?: ""
    }
}