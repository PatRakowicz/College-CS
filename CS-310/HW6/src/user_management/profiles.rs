/// Struct representing a user profile with generic user ID
pub struct Profile<T> {
    pub user_id: T,     // Unique identifier for the user
    pub name: String,   // User's name
    pub email: String,  // User's email address
}

// Getting error if i dont use ': std::fmt::Debug' given from build
impl<T: std::fmt::Debug> Profile<T> {
    /// Creates a new `Profile` with the given user ID, name, and email
    pub fn new(user_id: T, name: &str, email: &str) -> Self {
        Self {
            user_id,
            name: name.to_string(),
            email: email.to_string(),
        }
    }

    /// Displays the profile information
    pub fn display(&self) {
        println!("~~~Profile Information: ");
        println!("User ID: {:?}", self.user_id);  // Requires Debug trait for `T`
        println!("Name: {}", self.name);
        println!("Email: {}", self.email);
    }
}