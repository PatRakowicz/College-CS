use std::fmt::Debug;
use std::cmp::PartialOrd;
use std::cmp::Ord;

/// Struct representing a user profile with generic user ID
// Since we are borrowing a reference of &str, we need to include a lifetime to allow the compiler
// to ensure that the reference will live long enough to be valid for the life of the Profile struct
// the lifetime is instantiated with '
pub struct Profile<'lt, T: Debug + PartialOrd + Ord> {
    pub user_id: T,     // Unique identifier for the user
    pub name: &'lt str,   // User's name
    pub email: &'lt str,  // User's email address
}

// we need to specify the lifetime inside the impl as well because we are accepting a reference &str
// which has a lifetime given above.
impl<'lt, T: Debug + PartialOrd + Ord> Profile<'lt, T> {
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
        println!("User ID: {:?}", self.user_id);  // Requires Debug trait for `T`
        println!("Name: {}", self.name);
        println!("Email: {}", self.email);
    }
}