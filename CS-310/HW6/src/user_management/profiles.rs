use std::fmt::Debug;
use std::cmp::PartialOrd;

/// Struct representing a user profile with generic user ID
// Have to do &'lt str to allow for the main to get the correct lifetime, allowing it to be used correctly
// and not have any compiler error. As well as have to do it for name and email since I am inputting a "String"
pub struct Profile<'lt, T: Debug + PartialOrd> {
    pub user_id: T,     // Unique identifier for the user
    pub name: &'lt str,   // User's name
    pub email: &'lt str,  // User's email address
}

impl<'lt, T: Debug + PartialOrd> Profile<'lt, T> {
    /// Creates a new `Profile` with the given user ID, name, and email
    pub fn new(user_id: T, name: &'lt str, email: &'lt str) -> Self {
        Self {
            user_id,
            name,
            email
        }
    }

    /// Displays the profile information
    pub fn display(&self) {
        println!("~~~Profile Information: ");
        println!("User ID: {:?}", self.user_id);
        println!("Name: {}", self.name);
        println!("Email: {}", self.email);
    }
}