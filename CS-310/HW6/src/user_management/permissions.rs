use std::collections::HashMap;

/// Struct representing user permissions
pub struct UserPermission { pub permissions: HashMap<String, bool> }  // Maps permission names to their boolean states


impl UserPermission {
    /// Creates a new `UserPermission` instance with no initial permissions
    pub fn new() -> Self {
        let permissions = HashMap::new();
        Self { permissions }
    }

    /// Displays the current permissions for a user
    pub fn display(&self) {
        println!("Permissions:");
        for (perm, allowed) in &self.permissions {
            println!("{}: {}", perm, allowed);
        }
    }

    /// Adds a permission and sets its state to true
    pub fn add_permission(&mut self, permission: &str) {
        self.permissions.insert(permission.to_string(), true);
    }

    /// Removes a permission by setting its state to false
    pub fn remove_permission(&mut self, permission: &str) {
        self.permissions.insert(permission.to_string(), false);
    }

    /// Checks if a permission exists. If not adds it with a default value of false
    pub fn check_permission(&mut self, permission: &str) -> bool {
        self.permissions.get(permission).cloned().unwrap_or_else(|| {
            self.permissions.insert(permission.to_string(), false);
            false
        })
    }
}