enum Availability {
    Available,
    Loaned(String),
}

enum Genre {
    Fiction,
    NonFiction,
    Mystery,
    Fantasy,
}

struct Book {
    title: String,
    author: String,
    is_available: Availability,
    genre: Genre,
}

struct Library {
    books: [Option<Book>; 3],
}

impl Library {
    fn new() -> Self {
        Library {
            books: [None, None, None],
        }
    }

    fn add_book(&mut self, book: Book, index: usize) {
        self.books[index] = Some(book);
    }

    fn list_books(&self) {
        for i in 0..self.books.len() {
            match &self.books[i] {
                Some(book) => println!("Book {}: '{}' by {}", i + 1, book.title, book.author),
                None => println!("Book {}: [Empty Slot]", i + 1),
            }
        }
    }
}

fn main() {
    let mut library = Library::new();

    let book1 = Book {
        title: String::from("The Hobbit"),
        author: String::from("J.R.R. Tolkien"),
        is_available: Availability::Available,
        genre: Genre::Fantasy,
    };

    let book2 = Book {
        title: String::from("1984"),
        author: String::from("George Orwell"),
        is_available: Availability::Loaned(String::from("Alice")),
        genre: Genre::Fiction,
    };

    library.add_book(book1, 0);
    library.add_book(book2, 1);

    library.list_books();
}
