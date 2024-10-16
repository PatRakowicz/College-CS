/// Enum representing different roles a user can have
#[derive(Debug, Clone, PartialEq)]
pub enum Role {
    Admin,
    Editor,
    Viewer,
}

/// Struct representing a user's roles.
pub struct UserRole {
    pub roles: Vec<Role>,  // Stores a list of assigned roles for a user
}

impl UserRole {
    /// Creates a new `UserRole` instance with a default `Viewer` role
    pub fn new() -> Self {
        Self { roles: vec![Role::Viewer] }  // Start with a default role
    }

    /// Displays the list of roles assigned to the user
    pub fn display(&self) {
        println!("User Roles: {:?}", self.roles);
    }

    /// Adds a new role to the user's roles.
    pub fn add_role(&mut self, new_role: Role) {
        self.roles.push(new_role);
    }

    /// Removes a specific role from the user's roles using `retain`.
    /// This function keeps only the roles that do **not** match the specified role.
    pub fn remove_role(&mut self, role: Role) {
        let mut i = 0;
        while i < self.roles.len() {
            if self.roles[i] == role { self.roles.remove(i); }
            else { i += 1; }
        }
    }
}