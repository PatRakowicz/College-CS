package cs435.hw9

class Cart {
    companion object {
        private val cartItems = mutableListOf<Books>()
        var deliveryDate: String? = null
        var deliveryTime: String? = null

        fun addToCart(book: Books) {
            cartItems.add(book)
        }

        fun removeFromCart(bookId: Int) {
            cartItems.removeAll { it.id == bookId }
        }

        fun getCartItems(): List<Books> {
            return cartItems
        }

        fun clearCart() {
            cartItems.clear()
            deliveryDate = null
            deliveryTime = null
        }

        fun addToCartById(bookId: Int) {
            val book = Books.books.find { it.id == bookId }
            if (book != null) { cartItems.add(book) }
        }
    }
}