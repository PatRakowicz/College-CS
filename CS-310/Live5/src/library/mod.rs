pub mod catalog;
mod patrons;

pub fn manage_library() {
    let b = catalog::Book::new("1984", "George Orwell");

    patrons::add_patron("Ezekiel");
}
